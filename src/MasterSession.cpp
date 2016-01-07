#include "MasterSession.h"
#include "MessageRegister.pb.h"
#include <BlockTable.h>
#include <Variable.h>
#include <MRT.h>
#include <MessageAlive.pb.h>
#include <TokenPool.h>
#include <BlockTable.h>
#include <MessageUpdateBlock.pb.h>

MasterSession* MasterSession::instance_ = nullptr;

MasterSession * MasterSession::instance( )
{
    return instance_;
}

MasterSession::MasterSession( )
{
    instance_ = this;
}

MasterSession::~MasterSession( )
{

}

void MasterSession::sync_all_block( )
{ 
    auto block_num = BlockTable::instance( )->block_num( );

    for ( size_t i = 0; i < block_num; i++ )
    {
        auto block = BlockTable::instance( )->find_block( i );

        if ( false == block->is_used ) continue;

        uptr<MessageUpdateBlock> msg = make_uptr( MessageUpdateBlock );
        msg->set_id( block->block_id );
        msg->set_index( block->index );
        msg->set_path( block->path );
        msg->set_size( block->size );
        msg->set_status( 0 );
        
        LOG_DEBUG( "Sync File[%lld] : %s" , block->block_id , block->path );

        this->send_message( move_ptr( msg ) );
    }
}

void MasterSession::alive( )
{
    worker_ = MRT::SyncWorker::create( 1000 , [this] ( MRT::SyncWorker* worker )
    {
        uptr<MessageAlive> alive = make_uptr( MessageAlive );
        alive->set_block_num( BlockTable::instance( )->block_num( ) );
        alive->set_disk_space( 1000 );
        alive->set_session_id( this->session_id( ) );
        alive->set_token_num( TokenPool::instance( )->token_num( ) );
        alive->set_local_time( Timer::tick( ) );
        this->send_message( move_ptr( alive ) );
        return false;
    } , nullptr , nullptr );
}

void MasterSession::on_connect( )
{
    uptr<MessageRegister> msg = make_uptr( MessageRegister );
    msg->set_id( MRT::UUID::create( ) );
    msg->set_block_num( BlockTable::instance( )->block_num( ) );
    msg->set_data_addr ( "" );
    msg->set_data_port ( 0 );
    msg->set_disk_space( 1000 );
    this->send_message( move_ptr( msg ) );
}

void MasterSession::on_close( )
{
    if ( worker_ != nullptr )
    {
        MRT::SyncWorker::stop( worker_ );
    }
}
