#include "MRT.h"
#include "CMDParameter.h"
#include "Variable.h"
#include "MasterConnector.h"
#include "NodeListener.h"

int main( int argc , char * argv[] )
{ 
    if ( !CMDParameter::parse( argc , argv ) )
    {
        return 0;
    }

    if ( Variable::mode == 0 )
    {
        LOG_SYS( "system start in master mode" );
        LOG_SYS( "listen on: %s:%d" , Variable::server_ip , Variable::port );

        MRT::Maraton::instance( )->regist( make_uptr( NodeListener , 
                                           Variable::server_ip , 
                                           Variable::port));
    }
    else if ( Variable::mode == 1 )
    {
        LOG_SYS( "system start in node mode" );
        LOG_SYS( "connecting %s:%d" , Variable::server_ip , Variable::port );

        MRT::Maraton::instance( )->regist( make_uptr( MasterConnector , 
                                           Variable::server_ip , 
                                           Variable::port));
    }

    MRT::Maraton::instance( )->loop( );

    return 0;
}
