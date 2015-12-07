#include "MRT.h"
#include "CMDParameter.h"
#include "Variable.h"
#include "MasterConnector.h"
#include "NodeListener.h"
#include "Array.h"
#include "NodeSession.h"
#include "NodeManager.h"
#include "FileTable.h"

int main( int argc , char * argv[] )
{ 

    FileTable::instance( )->load_from_disk( );
    if ( !CMDParameter::parse( argc , argv ) )
    {
        return 0;
    }

    // Server mode
    if ( Variable::mode == 0 )
    {
        LOG_SYS( "system start in master mode" );
        LOG_SYS( "listen on: %s:%d" , Variable::server_ip , Variable::port );

        MRT::Maraton::instance( )->regist( make_uptr( NodeListener , 
                                           Variable::server_ip , 
                                           Variable::port));
    }
    // Node mode
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
