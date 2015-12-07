#include "ClusterSession.h"
#include "MessageUtils.h"

ClusterSession::ClusterSession( )
{
    this->parse_state_ = kHead;
     static size_t ndoe_session_id = 0x1000;
    this->id_ = ndoe_session_id;
    ndoe_session_id = ( ndoe_session_id + 1 ) % 0xFFFFFFFFFFFF;
}

ClusterSession::~ClusterSession( )
{
}

void ClusterSession::send_message( uptr<::google::protobuf::Message> message )
{
    uptr<MRT::Buffer> head      = make_uptr( MRT::Buffer , "YH" );
    uptr<MRT::Buffer> length    = make_uptr( MRT::Buffer , 4 );
    uptr<MRT::Buffer> body      = MessageUtils::build( message.get( ) );

    *( ( int* ) length->data( ) ) = ( int ) body->size( );

    this->send( move_ptr( head ) );
    this->send( move_ptr( length ) );
    this->send( move_ptr( body ) );
}

void ClusterSession::on_read ( uptr<MRT::Buffer> data )
{
    this->circle_buffer_.push( move_ptr( data ) );
    this->try_dispatch_message( this->circle_buffer_ );
}

void ClusterSession::try_dispatch_message( MRT::CircleBuffer & buffer )
{
    while ( true )
    {
        switch ( this->parse_state_ )
        {
            case ParseState::kHead:
                {
                    auto buf = buffer.pop( 2 );

                    if ( buf == nullptr )return;

                    if ( buf->data( )[0] == 'Y' &&
                         buf->data( )[1] == 'H' )
                    {
                        this->parse_state_ = ParseState::kLength;
                    }
                }break;
            case ParseState::kLength:
                {
                    auto buf = buffer.pop( 4 );

                    if ( buf == nullptr )return;

                    int len = *( ( int * ) buf->data( ) );

                    if ( len > MAX_CIRCLE_BUFFER_SIZE )
                    {
                        this->parse_state_ = ParseState::kHead;
                        break;
                    }

                    body_length_        = len;
                    this->parse_state_  = ParseState::kBody;
                }break;
            case ParseState::kBody:
                {
                    auto buf = buffer.pop( body_length_ );

                    if ( buf == nullptr )return;

                    MessageUtils::handle( this , 
                                          buf->data( ) , 
                                          buf->size( ) );
                    body_length_        = 0;
                    this->parse_state_  = ParseState::kHead;
                }break;
            default:
                break;
        }
    }
}
