#include "FileTable.h"

#include <string>

FileHandler::FileHandler( )
{

}

FileHandler::~FileHandler( )
{
}

FileTable::FileTable( )
{
    this->idx_array_ = new FileIndex*[1024 * 1024 * 10];
    memset( this->idx_array_ , 0 , 1024 * 1024 * 10 * sizeof( FileIndex* ) );
}

FileTable::~FileTable( )
{

}

void FileTable::initial( )
{
    this->file_idx_ = fopen( FILE_IDX_NAME.c_str( ) , "rb+" );
    this->file_table_ = fopen( FILE_DATA_NAME.c_str( ) , "rb+" );

    if ( this->file_idx_ == NULL )
    {
        this->file_idx_ = fopen( FILE_IDX_NAME.c_str( ) , "wb+" );
    }

    if ( this->file_table_ == NULL )
    {
        this->file_table_ = fopen( FILE_DATA_NAME.c_str( ) , "wb+" );
    }

    read_file_index( this->file_idx_ );

    for ( size_t i = 0; i < this->idx_size_; i++ )
    {
        LOG_DEBUG( "%lld : [%lld]%s" , i , this->idx_array_[i]->file_name_hash , this->idx_array_[i]->file_name );
    }
}

sptr<FileHandler> FileTable::create_file( const std::string & file_name ,
                                          const size_t & part_id , 
                                          const size_t & file_size )
{
    mutex_handle_file.wait( );

    sptr<FileHandler> file = make_sptr( FileHandler );
    auto hash  = this->hash_name( file_name.c_str( ) , file_name.length( ) );
    auto index = this->find_index( file_name , part_id );

    if ( index != nullptr )
    {
        this->error_ = FT_ERROR_FILE_EXIST;
        return nullptr;
    } 

    FileIndex* idx = new FileIndex( );
    memcpy( idx->file_name , file_name.c_str( ) , file_name.size( ) );

    idx->file_name_hash     = hash_name( file_name.c_str( ) , file_name.size( ) );
    idx->part_id            = part_id;
    idx->part_size          = file_size;
    file->file_name_hash    = idx->file_name_hash;
    file->h_idx             = ( size_t ) idx;
    fseek( this->file_table_ , 0 , SEEK_END );
    idx->offset             = ftell( this->file_table_ );

    this->add_index( idx );

    size_t bytes_left = file_size;
    const size_t bytes_length = 1024*10;
    size_t bytes_write = bytes_length;
    char buffer[bytes_length] = { 0 };

    while ( bytes_left > 0 )
    {
        bytes_write = bytes_left > bytes_length ? bytes_length : bytes_left;
        auto file_write = fwrite( buffer ,
                                  1 ,
                                  bytes_write ,
                                  file_table_ );
        bytes_left -= file_write; 
    }
    
    mutex_handle_file.release( );

    save_index( idx );

    return file;
}

sptr<FileHandler> FileTable::open_file( const std::string & file_name ,
                                        const size_t & part_id )
{
    sptr<FileHandler> file = make_sptr( FileHandler );

    auto idx = this->find_index( file_name , part_id );

    if ( idx == nullptr )
    {
        return nullptr;
    }

    file->file_name_hash = idx->file_name_hash;
    file->h_idx = ( size_t ) idx;
    file->position = 0;

    return file;
}

size_t FileTable::write_file( sptr<FileHandler> handler , const char * data , const size_t len )
{
    size_t writes = 0;

    if ( handler == nullptr || handler->h_idx == 0 )
    {
        this->error_ = FT_ERROR_FILE_CLOSED;
        return 0;
    }

    FileIndex* idx = ( FileIndex* ) handler->h_idx;

    if ( len > idx->part_size )
    {
        this->error_ = FT_ERROR_WRITE_OUTOFBOUND;
        return 0;
    }

    this->mutex_handle_file.wait( );

    auto hf = fseek( this->file_table_ , 
                     idx->offset + handler->position , 
                     SEEK_SET );

    auto pos = ftell( this->file_table_ );

    writes              = fwrite( data , 1 , len , this->file_table_ );
    handler->position   += writes;

    this->mutex_handle_file.release( );

    return writes;
}

size_t FileTable::read_file( sptr<FileHandler> handler , char * buffer , const size_t buffer_size )
{
    size_t buf_size = buffer_size;

    if ( handler == nullptr || handler->h_idx == 0 )
    {
        this->error_ = FT_ERROR_FILE_CLOSED;
        return 0;
    }

    size_t reads = 0;
    FileIndex* idx = ( FileIndex* ) handler->h_idx;

    if ( idx->part_size < buffer_size )
    {
        this->error_ = FT_ERROR_READ_OUTOFBOUND;
        return 0;
    }

    if ( ( handler->position + buffer_size) > buffer_size )
    {
        buf_size = buffer_size - handler->position + 1;
    }

    this->mutex_handle_file.wait( );

    fseek( this->file_table_ , idx->offset + handler->position , SEEK_SET );
    reads = fread( buffer ,  1 , buf_size , file_table_ );
    
    handler->position += reads;

    this->mutex_handle_file.release( );

    return reads;
}

size_t FileTable::seek_file( sptr<FileHandler> handler , const size_t & position )
{
    if ( handler == nullptr || handler->h_idx == 0 )
    {
        this->error_ = FT_ERROR_FILE_CLOSED;
        return 0;
    }

    handler->position = position;
    return handler->position;
}

size_t FileTable::file_size( sptr<FileHandler> handler )
{
    if ( handler == nullptr || handler->h_idx == 0 )
    {
        this->error_ = FT_ERROR_FILE_CLOSED;
        return 0;
    }

    FileIndex* idx = ( FileIndex* ) handler->h_idx;
    return idx->part_size;
}

void FileTable::close_file( sptr<FileHandler> handler )
{
    handler->h_idx = 0;
    handler->position = 0;
    handler->file_name_hash = 0;
}

size_t FileTable::error( )
{
    return this->error_;
}

void FileTable::read_file_index( FILE * file )
{
    size_t total_file_num   = 0;
    this->idx_size_ = 0;
    while ( true )
    {
        auto idx = new FileIndex( );
        auto reads = fread( idx , sizeof( FileIndex ) , 1 , file );
        
        if ( reads == 0 )
        {
            delete idx;
            break;
        }

        this->add_index( idx );
    }

    //fseek( this->file_idx_ ,
    //       0 ,
    //       SEEK_SET );

    //fread( &total_file_num , sizeof( size_t ) , 1 , file );

    //for ( size_t i = 0; i < total_file_num; i++ )
    //{
    //    auto idx = new FileIndex( );
    //    fread( idx , sizeof( FileIndex ) , 1 , file );
    //    this->add_index( idx );
    //}

    //idx_size_ = total_file_num;
}

void FileTable::save_index( FileIndex * index )
{
    file_idx_mutex_.wait( );

    //fseek( this->file_idx_ ,
    //       0 ,
    //       SEEK_SET );
    //
    //fwrite( &this->idx_size_ , sizeof( size_t ) , 1 , file_idx_ );

    int num_size    = sizeof( size_t );
    int offset      = fseek( this->file_idx_ ,
                             0 ,
                             SEEK_END );
    fwrite( index ,
            sizeof( FileIndex ) ,
            1 ,
            this->file_idx_ );

    fflush( file_idx_ );

    file_idx_mutex_.release( );
}

size_t FileTable::add_index( FileIndex * index )
{
    file_idx_mutex_.wait( );

    auto pos_index = this->find_hash( index->file_name_hash );
    size_t pos = this->idx_index_;

    if ( pos_index != nullptr )
    {
        pos = pos_index->index;
    }
    else
    {
        for ( size_t i = 0; i < this->idx_index_; i++ )
        {
            if ( this->idx_array_[i]->file_name_hash > index->file_name_hash )
            {
                pos = i;
                break;
            }
        }
    }

    for ( size_t i = this->idx_index_; i > pos; i-- )
    {
        this->idx_array_[i] = this->idx_array_[i - 1];
        this->idx_array_[i]->index = i;
    }

    this->idx_array_[pos] =  index;
    index->index = pos;

    ++this->idx_size_;
    ++this->idx_index_;

    file_idx_mutex_.release( );

    return pos;
}

size_t FileTable::hash_name( const char file_name[248] )
{
    size_t result = 0;

    for ( size_t i = 0; i < 248 && file_name[i]; i++ )
    {
        result ^=  ( size_t ) ( ( file_name[i] ) << ( ( i % sizeof( size_t ) ) * 8 ) );
    }

    return result;
}

size_t FileTable::hash_name( const char * file_name , size_t len )
{
    size_t result = 0;

    for ( size_t i = 0; i < len && file_name[i]; i++ )
    {
        result ^=  ( size_t ) ( ( file_name[i] ) << ( ( i % sizeof( size_t ) ) * 8 ) );
    }

    return result;
}

FileTable::FileIndex * FileTable::find_index( const std::string & file_name , 
                                              const size_t & part_id )
{
    size_t head , tail , cur , hash_name;

    hash_name = this->hash_name( file_name.c_str( ) , file_name.size( ) );
    head = 0;
    tail = this->idx_index_;
    cur  = tail >> 1;

    auto idx = find_hash( hash_name );

    if ( idx == nullptr ) return idx;

    auto pos = idx->index;

    // Find right space
    while ( this->idx_array_[pos]->file_name_hash == hash_name )
    {
        if ( !strcmp( this->idx_array_[pos]->file_name , file_name.c_str( ) ) &&
             this->idx_array_[pos]->part_id == part_id )
        {
            return this->idx_array_[pos];
        }
        pos++;
    }

    pos = cur;

    // Find left space
    while ( this->idx_array_[pos]->file_name_hash == hash_name )
    {
        if ( !strcmp( this->idx_array_[pos]->file_name , file_name.c_str( ) ) &&
             this->idx_array_[pos]->part_id == part_id )
        {
            return this->idx_array_[pos];
        }
        pos--;
    }

    return nullptr;
}

FileTable::FileIndex * FileTable::find_hash( size_t hash)
{ 
    if ( this->idx_size_ == 0 )return nullptr;
    
    size_t head , tail , cur , hash_name;

    hash_name   = hash;
    head        = 0;
    tail        = this->idx_size_ - 1;
    cur         = tail >> 1;

    if ( this->idx_array_[cur] == nullptr ) return nullptr;

    while ( head != tail )
    {
        if ( this->idx_array_[cur]->file_name_hash == hash_name )
        {
            return this->idx_array_[cur];
        }
        else if ( this->idx_array_[cur]->file_name_hash < hash_name )
        {
            head += ( tail - head + 1) >> 1;
            cur  += ( tail - cur + 1 )  >> 1;
        }
        else if ( this->idx_array_[cur]->file_name_hash > hash_name )
        {
            tail -=  ( tail - head + 1) >> 1;
            cur  = cur >> 1;
        }
    }
    
    return nullptr;
}

FILE * FileTable::open_table_read( )
{
    return fopen( FILE_DATA_NAME.c_str( ) , "rb+" );
}

FILE * FileTable::open_table_append( )
{
   return fopen( FILE_DATA_NAME.c_str( ) , "ab+" );
}

FILE * FileTable::open_idx_write( )
{
   return fopen( FILE_DATA_NAME.c_str( ) , "wb+" );
}

FILE * FileTable::open_idx_read( )
{
   return fopen( FILE_DATA_NAME.c_str( ) , "rb+" );
}

void FileTable::close_file( FILE * file )
{
    fclose( file );
}
