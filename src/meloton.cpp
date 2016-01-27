#include "MRT.h"
#include "CMDParameter.h"
#include "Variable.h"
#include "MasterConnector.h"
#include "NodeListener.h"
#include "Array.h"
#include "NodeSession.h"
#include "NodeManager.h"
#include <time.h>
#include <ClientListener.h>
#include <BlockTable.h>
#include <Path.h>
#include <DirectoryMeta.h>
#include <FS.h>
#include <NodeHTTPListener.h>
#include <MasterHTTPListener.h>

int main( int argc , char * argv[] )
{     
    printf( "Enter any thing to start...\r\n" );
    scanf("");
    if ( !CMDParameter::parse( argc , argv ) )
    {
        return 0;
    }

    // Server mode
    if ( Variable::mode == 1 )
    {
        LOG_SYS( "system start in master mode" );

        MRT::Maraton::instance( )->regist( make_uptr( NodeListener , 
                                           "0.0.0.0" , 
                                           100)); 

        MRT::Maraton::instance( )->regist( make_uptr( ClientListener , 
                                           "0.0.0.0"  , 
                                           101));

        MRT::Maraton::instance( )->regist( make_uptr( MasterHTTPListener ,
                                           "0.0.0.0"  ,
                                           80 ) );

        MRT::Maraton::instance( )->loop( );

        LOG_SYS( "system shutdown" );
    }
    // Node mode
    else if ( Variable::mode == 0 )
    {
        LOG_SYS( "system start in node mode" );
        LOG_SYS( "load index file" );
        
        BlockTable::instance( )->load_from_file( );
        
        LOG_SYS( "connecting %s:%d" , Variable::server_ip.c_str( ) , Variable::port );

        MRT::Maraton::instance( )->regist( make_uptr( ClientListener ,
                                           "0.0.0.0"  ,
                                           101 ) );

        MRT::Maraton::instance( )->regist( make_uptr( NodeHTTPListener ,
                                           "0.0.0.0"  ,
                                           80 ) );

        while ( true )
        {
            MRT::Maraton::instance( )->regist( make_uptr( MasterConnector , 
                                           Variable::server_ip , 
                                           100));
            
            MRT::Maraton::instance( )->loop( );

            LOG_SYS( "disconnected to server , reconnecting" );
        }
    }
    
    return 0;
}
