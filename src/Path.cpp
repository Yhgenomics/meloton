#include "Path.h"

Path::Path( )
{

}

Path::Path( std::string path)
{
    this->path_ = path;
    this->parse( this->path_ );
}

Path::~Path( )
{

}

Error Path::parse( std::string path )
{
    Error err( 0 );
    path_list_.clear( );
    std::string tmp = "";
    char buf[256]= { 0 };
    buf[0] = '/';
    const char* pPath = path.c_str( );
    char chr = 0;
    int index = 0;
    int cur_size = 0;
    int size = path.size( );

    do
    {
        while ( index < size )
        {
            chr = *( pPath + index );

            if ( ( chr == '\\' ||
                 chr == '/' ))
            { 
                cur_size = cur_size == 0 ? 1 : cur_size;
                this->path_list_.push_back( std::string( buf , cur_size ) );
                cur_size = 0;
            }
            else
            {
                buf[cur_size++] = chr;
            }

            index++;
        }

        this->path_list_.push_back( std::string( buf , cur_size ) );

        if ( this->path_list_.size( ) == 0 )
        {
            err.code( 1 );
            err.msg( "bad path" );
            break;
        }

        this->filename_ = this->path_list_[path_list_.size( ) - 1];
        this->path_list_.pop_back( );
    }
    while ( false );

    return err;
}

std::vector<std::string> Path::list( )
{
    return std::vector<std::string>( this->path_list_ );
}

std::string Path::filename( )
{
    return this->filename_;
}
