#include "FS.h"

FS::FS( )
{
    this->root_ = make_sptr( DirectoryMeta , "" );
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
        dir = dir->get_dir( str_path );

        if ( dir == nullptr )
        {
            sptr<DirectoryMeta> tmp_dir = make_sptr( DirectoryMeta , p );
            dir->append_dir( tmp_dir );
            dir = tmp_dir;
        }
    }

    return dir;
}

sptr<DirectoryMeta> FS::get_dir( std::string path )
{
    return this->root_->get_dir( make_sptr( Path , path ) );
}

std::vector<sptr<DirectoryMeta>> FS::list_dir( std::string path )
{
    return std::vector<sptr<DirectoryMeta>>();
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
    return this->root_->get_file( make_sptr( Path , path) ) != nullptr ;
}

sptr<FileMeta> FS::get_file( std::string path )
{
     return this->root_->get_file( make_sptr( Path , path) );
}
