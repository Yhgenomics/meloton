#include "MasterHTTPSession.h"

MasterHTTPSession::MasterHTTPSession( )
{

}

MasterHTTPSession::~MasterHTTPSession( )
{

}

void MasterHTTPSession::send_message( uptr<MRT::HTTPResponse> response )
{

}

void MasterHTTPSession::on_connect( )
{

}

void MasterHTTPSession::on_read( uptr<MRT::Buffer> data )
{
    request_.parse( move_ptr( data ) );

    if ( request_.finish( ) )
    {
        MRT::HTTPResponse rep;
    }
}

void MasterHTTPSession::on_write( uptr<MRT::Buffer> data )
{

}

void MasterHTTPSession::on_close( )
{

}
