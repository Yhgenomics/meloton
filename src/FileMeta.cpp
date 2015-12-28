#include "FileMeta.h"

FileMeta::FileMeta( std::string name )
{
    this->name_ = name;
    this->name_hash_ = hash_code( name );
}

std::string FileMeta::name( )
{
    return this->name_;
}

size_t FileMeta::name_hash( )
{
    return this->name_hash_;
}

sptr<BlockMeta> FileMeta::get_block( size_t id )
{
    for ( auto & b : this->blocks_ )
    {
        if ( b->id( ) == id )
        {
            return b;
        }
    }
    
    return nullptr;
}

void FileMeta::add_block( sptr<BlockMeta> block )
{ 
    this->blocks_.push_back( move_ptr( block ) );
}

