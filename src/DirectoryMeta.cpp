#include "DirectoryMeta.h"
#include "Utils.h"

DirectoryMeta::DirectoryMeta( std::string name )
{
    this->name_ = name;
    this->name_hash_ = hash_code( name );
}

DirectoryMeta::~DirectoryMeta( )
{
}

sptr<FileMeta> DirectoryMeta::append_file( sptr<FileMeta> meta )
{
    this->files_.push_back( meta );
    return meta;
}

sptr<FileMeta> DirectoryMeta::get_file( std::string name )
{
    for ( auto & f : this->files_ )
    {
        if ( f->name( ) == name )
        {
            return f;
        }
    }

    return nullptr;
}

sptr<FileMeta> DirectoryMeta::get_file( sptr<Path> path )
{
    auto dir = this->get_dir( path );
    
    if ( dir == nullptr ) return nullptr;

    auto result = dir->get_file( path->filename( ) );
    return result;
}

bool DirectoryMeta::file_exist( std::string name )
{
    size_t hash = hash_code( name );
    for ( auto & f : this->files_ )
    {
        if ( f->name_hash() == hash  && 
             f->name( ) == name )
        {
            return true;
        }
    }

    return false;
}

sptr<DirectoryMeta> DirectoryMeta::append_dir( sptr<DirectoryMeta> meta )
{
    this->children_.push_back( meta );
    meta->parent_ = sptr<DirectoryMeta>( this );
    return meta;
}

sptr<DirectoryMeta> DirectoryMeta::get_dir( std::string name )
{
    size_t hash = hash_code( name );

    for ( auto d : this->children_ )
    {
        if ( d->name_hash_ == hash &&
             d->name_ == name )
        {
            return d;
        }
    }

    return nullptr;
}

sptr<DirectoryMeta> DirectoryMeta::get_dir( sptr<Path> path )
{
    auto p = path->list( );
    sptr<DirectoryMeta> cur_dir = sptr<DirectoryMeta>( this );
    
    for ( auto dir : p )
    {
        cur_dir = cur_dir->get_dir( dir );
        if ( cur_dir == nullptr )
        {
            return nullptr;
        }
    }

    return cur_dir;
}

bool DirectoryMeta::dir_exist( std::string name )
{
    return (this->get_dir( name ) != nullptr);
}
