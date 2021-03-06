#include "FS.h"

FS::FS( )
{
    this->root_ = make_sptr( DirectoryMeta , "/" );
}

FS::~FS( )
{
}

sptr<DirectoryMeta> FS::create_dir( std::string str_path )
{
    sptr<DirectoryMeta> dir = this->root_;
    Path path( str_path );
    auto cpath = path.list( );

    for ( std::string & p : cpath )
    {
        auto tmp = dir->get_dir( p );

        if ( tmp == nullptr )
        {
            sptr<DirectoryMeta> tmp_dir = make_sptr( DirectoryMeta , p );
            dir = dir->append_dir( tmp_dir );
            //dir = move_ptr( tmp_dir );
        }
        else
        {
            dir = tmp->get_dir( p );
        }
    }

    return dir;
}

sptr<DirectoryMeta> FS::get_dir( std::string path )
{
    Path p( path );
    sptr<DirectoryMeta> result = this->root_;

    for ( auto & pstr : p.list( ) )
    {
        result = result->get_dir( pstr );

        if ( result == nullptr )
        {
            return result;
        }
    }

    return  sptr<DirectoryMeta>( result );
}

std::vector<sptr<DirectoryMeta>> FS::list_dir( std::string path )
{
    return std::vector<sptr<DirectoryMeta>>( );
}

sptr<FileMeta> FS::create_file( std::string str_path )
{
    Path path( str_path );

    auto dir = this->create_dir( str_path );

    sptr<FileMeta> file = make_sptr( FileMeta , path.filename( ) );
    file = dir->append_file( file );

    return file;
}

bool FS::exist_file( std::string path )
{
    return get_file( path ) != nullptr;
}

sptr<FileMeta> FS::get_file( std::string path )
{
    auto p = make_sptr( Path , path );
    auto dir = get_dir( path );

    if ( dir == nullptr )
    {
        return nullptr;
    }

    auto file = dir->get_file( p->filename( ) );
    return file;
}
