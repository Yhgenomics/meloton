#include <BlockTable.h>
#include <Utils.h>

BlockTable::BlockTable( )
{
    this->block_index_list_ = new sptr<BlockIndex>[MAX_BLOCK_NUM];
}


void BlockTable::load_from_file( )
{
    this->pfile_index_ = fopen( FILE_INDEX_NAME , "rb+" );
    this->pfile_data_ = fopen( FILE_DATA_NAME , "rb+" );

    if ( this->pfile_index_ == NULL )
    {
        this->pfile_index_ = fopen( FILE_INDEX_NAME , "wb+" );
    }

    if ( this->pfile_data_ == NULL )
    {
        this->pfile_data_ = fopen( FILE_DATA_NAME , "wb+" );
    }

    load_index( this->pfile_index_ );

    for ( size_t i = 0; i < this->block_num_; i++ )
    {
        LOG_DEBUG( "[%lld] %s" , 
                   i , 
                   this->block_index_list_[i]->path);
    }
}


void BlockTable::load_index( FILE * pfile )
{
    size_t total_file_num  = 0;
    this->block_num_ = 0;

    while ( true )
    {
        auto idx = new BlockIndex( );
        auto reads = fread( idx , 1 , sizeof( BlockIndex ) , pfile );
        
        if ( reads == 0 )
        {
            delete idx;
            break;
        }

        auto p_index = sptr<BlockIndex>( idx );
        this->block_index_list_[this->block_num_] = p_index;
       
        if ( !idx->is_used )
        {
            this->block_idle_list_.push_back( p_index );
        }

        this->block_num_++;
    }

}

void BlockTable::save_index( FILE * pfile , size_t index )
{
    auto data = this->block_index_list_[index];
    size_t pos = index* sizeof( BlockIndex );
    fseek( pfile , pos , SEEK_SET );
    fwrite( data.get( ) , sizeof( BlockIndex ) , 1 , pfile );
    fflush( pfile );
}

size_t BlockTable::alloc_data_space( )
{
    size_t pos = 0;
    char* buf = new char[BLOCK_SIZE];
    memset( buf , 0 , BLOCK_SIZE );
    //char buf[BLOCK_SIZE]    = { 0 };
    fseek( this->pfile_data_ , 0 , SEEK_END );
    pos = ftell( this->pfile_data_ );
    fwrite( buf , BLOCK_SIZE , 1 , this->pfile_data_ ); 
    SAFE_DELETE( buf );
    return pos;
}

sptr<BlockIndex> BlockTable::find_block( size_t index )
{
    return this->block_index_list_[index];
}

sptr<BlockIndex> BlockTable::create_block( std::string file_name , 
                                           size_t size , 
                                           size_t block_id)
{
    if ( file_name.size( ) > MAX_PATH_SIZE )
    {
        return nullptr;
    }

    if ( size > BLOCK_SIZE )
    {
        return nullptr;
    }

    sptr<BlockIndex> idx = nullptr;

    if ( this->block_idle_list_.size( ) > 0 )
    {
        idx = *this->block_idle_list_.begin( );
        this->block_idle_list_.erase( this->block_idle_list_.begin( ) );
        
        memset( idx.get( ) , 0 , sizeof( BlockIndex ) );
        memcpy( idx->path , file_name.c_str( ) , file_name.size( ) );
        idx->path_hash  = hash_code( file_name );
        idx->size       = size;
        idx->is_used    = true;
        idx->block_id   = block_id;
        save_index( this->pfile_index_ , idx->index );
    }
    else
    {
        idx = make_sptr( BlockIndex );
        memset( idx.get( ) , 0 , sizeof( BlockIndex ) );
        memcpy( idx->path , file_name.c_str( ) , file_name.size( ) );
        
        idx->path_hash  = hash_code( file_name );
        idx->index      = this->block_num_;
        idx->is_used    = true;
        idx->size       = size;
        idx->block_id   = block_id;
        idx->offset     = alloc_data_space( );
        
        this->block_index_list_[this->block_num_++] = idx;
        save_index( this->pfile_index_ , idx->index );
    }

   
    return idx;
}

sptr<BlockIndex> BlockTable::delete_block( size_t index )
{
    return sptr<BlockIndex>( );
}

uptr<MRT::Buffer> BlockTable::read_block( sptr<BlockIndex> block , 
                                          size_t offset , 
                                          size_t size  )
{
    if ( (offset + size) > block->size )
    {
        return nullptr;
    }

    uptr<MRT::Buffer> buffer = make_uptr( MRT::Buffer , size );
    fseek( this->pfile_data_ , block->offset + offset , SEEK_SET );
    fread( buffer->data( ) , 1 , size , this->pfile_data_ );
    return buffer;
}

size_t BlockTable::write_block( sptr<BlockIndex> block,
                                   const char * data ,
                                   size_t size ,
                                   size_t offset )
{
    if ( (offset + size) > block->size )
    {
        return 0;
    }

    fseek( this->pfile_data_ , block->offset + offset , SEEK_SET );
    fwrite( data , 1 , size , this->pfile_data_ );
    fflush( this->pfile_data_ );
    return size;
}

BlockTable::~BlockTable( )
{

}
