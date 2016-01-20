#include "MasterHTTPListener.h"
#include "MasterHTTPSession.h"

MasterHTTPListener::MasterHTTPListener( std::string ip , int port )
    : Listener( ip , port )
{

}

MasterHTTPListener::~MasterHTTPListener( )
{

}

MRT::Session * MasterHTTPListener::create_session( )
{
    return new MasterHTTPSession( );
}

void MasterHTTPListener::on_session_open( MRT::Session * session )
{

}

void MasterHTTPListener::on_session_close( MRT::Session * session )
{

}
