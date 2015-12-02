#include "MRT.h"
#include "NodeDetector.h"
#include "NodeBroadcaster.h"

#include "MessageAccept.pb.h"

int main( )
{
    MessageAccept msg;

    msg.set_session_id( 1234 );
    msg.set_parent_address( "asdfasdfasdfasdfasdf" );
    msg.set_parent_port( 80 );
    auto size = msg.ByteSize( );
    auto str = msg.SerializeAsString( );

    LOG_SYS( "system start..." );

    while ( true )
    {
        MRT::Maraton::instance( )->loop( );
    }

    return 0;
}
