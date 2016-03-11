#include "MasterConnector.h"
#include "MasterSession.h"
#include "Variable.h"

MasterConnector::MasterConnector( std::string ip , int port )
    : MRT::Connector( ip , port )
{
}

MasterConnector::~MasterConnector( )
{

    MRT::Maraton::instance( )->regist( make_uptr( MasterConnector ,
                                       Variable::server_ip ,
                                       100 ) );
}

MRT::Session * MasterConnector::create_session( )
{
    MasterSession::instance_ = new MasterSession( );
    return MasterSession::instance_;
}

void MasterConnector::on_session_open( MRT::Session * session )
{

}

void MasterConnector::on_session_close( MRT::Session * session )
{
    MasterSession::instance_ = nullptr;
}
