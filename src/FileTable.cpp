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
}

FileTable::~FileTable( )
{

}

void FileTable::initial( )
{
    const static std::string FILE_IDX_NAME = "file.idx";
    const static std::string FILE_DATA_NAME = "file.data";

    this->file_idx_ = fopen( FILE_IDX_NAME.c_str( ) , "ab+" );
    this->file_table_ = fopen( FILE_DATA_NAME.c_str( ) , "ab+" );
/*
    if ( this->file_idx_ == NULL )
    {
        this->file_idx_ = fopen( FILE_IDX_NAME.c_str( ) , "ab+" );
    }

    if ( this->file_table_ == NULL )
    {
        this->file_table_ = fopen( FILE_DATA_NAME.c_str( ) , "ab+" );
    }
*/
    read_file_index( this->file_idx_ );
}

sptr<FileHandler> FileTable::create_file( const std::string & file_name , const size_t & part_id , size_t file_size )
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

    auto file_pos = 0;
    while ( file_pos < file_size )
    {
        char buffer[1] = { 0 };
        file_pos += fwrite( buffer , 1 , file_size , file_table_ );
    }

    mutex_handle_file.release( );

    save_index( idx );

    return file;
}

sptr<FileHandler> FileTable::open_file( const std::string & file_name , const size_t & part_id )
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

    this->mutex_handle_file.wait( );

    fseek( this->file_table_ , idx->offset + handler->position , SEEK_CUR );
    writes              = fwrite( data , len , 1 , this->file_table_ );
    handler->position   += writes;

    this->mutex_handle_file.release( );

    return writes;
}

size_t FileTable::read_file( sptr<FileHandler> handler , char ** buffer , const size_t buffer_size )
{
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

    this->mutex_handle_file.wait( );

    fseek( this->file_table_ , idx->offset + handler->position , SEEK_CUR );
    reads = fread( *buffer , buffer_size , 1 , file_table_ );
    handler->position += reads;

    this->mutex_handle_file.release( );
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

    fread( &total_file_num , sizeof( size_t ) , 1 , file );

    for ( size_t i = 0; i < total_file_num; i++ )
    {
        auto idx = new FileIndex( );
        fread( idx , sizeof( FileIndex ) , 1 , file );
        this->add_index( idx );
    }

    idx_size_ = total_file_num;
}

void FileTable::save_index( FileIndex * index )
{
    file_idx_mutex_.wait( );

    fseek( this->file_idx_ ,
           0 ,
           SEEK_CUR );
    
    fwrite( &this->idx_size_ , sizeof( size_t ) , 1 , file_idx_ );

    int num_size    = sizeof( size_t );
    int offset      = fseek( this->file_idx_ ,
                             0 ,
                             SEEK_END );
    fwrite( index ,
            sizeof( FileIndex ) ,
            1 ,
            this->file_idx_ );

    file_idx_mutex_.release( );
}

size_t FileTable::add_index( FileIndex * index )
{
    file_idx_mutex_.wait( );

    auto pos_index = this->find_hash( index->file_name_hash );
    size_t pos = 0;

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

FileTable::FileIndex * FileTable::find_index( const std::string & file_name , size_t part_id )
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
    size_t head , tail , cur , hash_name;

    hash_name = hash;
    head = 0;
    tail = this->idx_index_;
    cur  = this->idx_index_ >> 1;

    while ( head != tail )
    {
        if ( this->idx_array_[cur]->file_name_hash == hash_name )
        {
            return this->idx_array_[cur];
        }
        else if ( this->idx_array_[cur]->file_name_hash < hash_name )
        {
            head = ( tail - head + 1 ) >> 1;
            cur  = ( tail - cur )  >> 1;
        }
        else if ( this->idx_array_[cur]->file_name_hash > hash_name )
        {
            tail = tail >> 1;
            cur  = ( cur - head ) >> 1;
        }
    }

    return nullptr;
}


