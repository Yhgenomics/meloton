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
    for ( auto & f : this->files_ )
    {
        if ( f->name_hash() == meta->name_hash() && 
             f->name( ) == meta->name() )
        {
            return sptr<FileMeta>(f);
        }
    } 

    this->files_.push_back( sptr<FileMeta>( meta ) );

    return meta;
}

sptr<FileMeta> DirectoryMeta::get_file( std::string name )
{
    for ( auto & f : this->files_ )
    {
        if ( f->name( ) == name )
        {
            return sptr<FileMeta> (f);
        }
    }

    return nullptr;
}

//sptr<FileMeta> DirectoryMeta::get_file( sptr<Path> path )
//{
//    auto dir = this->get_dir( path );
//    
//    if ( dir == nullptr ) return nullptr;
//
//    auto result = dir->get_file( path->filename( ) );
//     
//    return result;
//}

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
    this->children_.push_back( sptr<DirectoryMeta> ( meta ) );
    meta->parent_ = sptr<DirectoryMeta>( this );
    return meta;
}

sptr<DirectoryMeta> DirectoryMeta::get_dir( std::string name )
{
    size_t hash = hash_code( name );

    if ( this->name_hash_ == hash &&
         this->name_ == name )
    {
        return shared_from_this();
    }
    
    for ( auto d : this->children_ )
    {
        if ( d->name_hash_ == hash &&
             d->name_ == name )
        {
            return move_ptr( sptr<DirectoryMeta>( d ) );
        }
    }

    return nullptr;
}

//sptr<DirectoryMeta> DirectoryMeta::get_dir( sptr<Path> path )
//{
//    auto p = path->list( );
//
//    DirectoryMeta* rt = this;
//    sptr<DirectoryMeta> result = shared_from_this();
//
//    for ( auto & dir : p )
//    {
//        result = result->get_dir( dir );
//
//        if ( result == nullptr )
//        {
//            return nullptr;
//        }
//
//        return result;
//    }
//
//    return move_ptr( result );
//}

bool DirectoryMeta::dir_exist( std::string name )
{
    return (this->get_dir( name ) != nullptr);
}
