#include "MasterConnector.h"
#include "MasterSession.h"

MasterConnector::MasterConnector( std::string ip , int port )
    : MRT::Connector( ip , port )
{
}

MasterConnector::~MasterConnector( )
{
}

MRT::Session * MasterConnector::create_session( )
{
    SAFE_DELETE( MasterSession::instance_ );
    MasterSession::instance_ = new MasterSession( );
    return MasterSession::instance_;
}

void MasterConnector::on_session_open( MRT::Session * session )
{

}

void MasterConnector::on_session_close( MRT::Session * session )
{

}
