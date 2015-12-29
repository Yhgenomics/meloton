#include <BlockTable.h>
#include <Utils.h>

BlockTable::BlockTable( )
{
    this->block_index_list_ = scast<sptr<BlockIndex>*>( 
        malloc( MAX_BLOCK_NUM )
    );
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

    for ( size_t i = 0; i < this->block_num; i++ )
    {
        LOG_DEBUG( "[%lld] %s" , 
                   i , 
                   this->block_index_list_[i]->path);
    }
}


void BlockTable::load_index( FILE * pfile )
{
    size_t total_file_num  = 0;
    this->block_num = 0;

    while ( true )
    {
        auto idx = new BlockIndex( );
        auto reads = fread( idx , sizeof( BlockIndex ) , 1 , pfile );
        
        if ( reads == 0 )
        {
            delete idx;
            break;
        }

        auto p_index = sptr<BlockIndex>( idx );
        this->block_index_list_[block_num] = p_index;
       
        if ( !idx->is_used )
        {
            this->block_idle_list_.push_back( p_index );
        }

        block_num++;
    }

}

void BlockTable::save_index( FILE * pfile , size_t index )
{
    auto data = this->block_index_list_[index];
    size_t pos = index* sizeof( BlockIndex );
    fseek( pfile , pos , SEEK_SET );
    fwrite( data.get( ) , sizeof( BlockIndex ) , 1 , pfile );
}

size_t BlockTable::alloc_data_space( )
{
    size_t pos              = 0;
    char buf[BLOCK_SIZE]    = { 0 };
    fseek( this->pfile_data_ , 0 , SEEK_END );
    pos = ftell( this->pfile_data_ );
    fwrite( &buf , BLOCK_SIZE , 1 , this->pfile_data_ ); 
    return pos;
}

sptr<BlockIndex> BlockTable::find_block( size_t index )
{
    return this->block_index_list_[index];
}

sptr<BlockIndex> BlockTable::create_block( std::string file_name , size_t size )
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
        save_index( this->pfile_index_ , idx->index );
    }
    else
    {
        idx = make_sptr( BlockIndex );
        memset( idx.get( ) , 0 , sizeof( BlockIndex ) );
        memcpy( idx->path , file_name.c_str( ) , file_name.size( ) );
        
        idx->path_hash  = hash_code( file_name );
        idx->index      = block_num;
        idx->is_used    = true;
        idx->size       = size;
        idx->offset     = alloc_data_space( );
        
        this->block_index_list_[this->block_num++] = idx;
        save_index( this->pfile_index_ , idx->index );
    }

   
    return idx;
}

sptr<BlockIndex> BlockTable::delete_block( size_t index )
{
    return sptr<BlockIndex>( );
}

BlockTable::~BlockTable( )
{

}
