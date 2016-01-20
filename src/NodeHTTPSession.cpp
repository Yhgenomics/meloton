#include <NodeHTTPSession.h>

void NodeHTTPSession::on_connect( )
{

}

void NodeHTTPSession::on_read( uptr<MRT::Buffer> data )
{
    req_.parse( move_ptr( data ) );
    
    if ( req_.finish( ) &&
         req_.domain( ) == "/download" )
    {
    }
}

void NodeHTTPSession::on_write( uptr<MRT::Buffer> data )
{

}

void NodeHTTPSession::on_close( )
{

}
