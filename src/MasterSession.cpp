#include "MasterSession.h"
#include "MessageRegister.pb.h"

MasterSession* MasterSession::instance_ = nullptr;

MasterSession * MasterSession::instance( )
{
    return instance_;
}

MasterSession::MasterSession( )
{

}

MasterSession::~MasterSession( )
{

}

void MasterSession::on_connect( )
{
    uptr<MessageRegister> msg = make_uptr( MessageRegister );
    msg->set_id( "idididid" );
    this->send_message( move_ptr( msg ) );
}
