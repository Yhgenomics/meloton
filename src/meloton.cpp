#include "MRT.h"
#include "CMDParameter.h"
#include "Variable.h"
#include "MasterConnector.h"
#include "NodeListener.h"
#include "Array.h"
#include "NodeSession.h"
#include "NodeManager.h"
#include "FileTable.h"
#include <time.h>

void test_file_table( )
{
    size_t data_size = 1024;
    FileTable::instance( )->initial( );
    char read_tmp_data[512] = { 0 };
    auto tim = time( 0 );

    char* write_data = new char[data_size];

    for ( size_t i = 0; i < data_size; i++ )
    {
        write_data[i] = 'A';
    }

    //auto f = FileTable::instance( )->open_file( "FILE_1" , 1 );
    //if( f != nullptr) FileTable::instance( )->read_file( f , read_tmp_data , 512 );

    for ( size_t i = 0; i < 100000; i++ )
    {
        char buf[10] = { 0 };
        itoa( (i+1) , buf , 10 );
        std::string id ( buf );
        std::string name = "FILE_" + id;
        auto f = FileTable::instance( )->create_file( name , 1 , data_size );
        FileTable::instance( )->write_file( f , write_data , data_size );
    }

    auto deltaTime = time( 0 ) - tim;
}

int main( int argc , char * argv[] )
{  

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

        LOG_ERROR( "system shutdown" );
    }
    // Node mode
    else if ( Variable::mode == 1 )
    {
        LOG_SYS( "system start in node mode" );
        LOG_SYS( "connecting %s:%d" , Variable::server_ip , Variable::port );

        while ( true )
        {
            MRT::Maraton::instance( )->regist( make_uptr( MasterConnector , 
                                           Variable::server_ip , 
                                           Variable::port));

            MRT::Maraton::instance( )->loop( );

            LOG_ERROR( "disconnected to server , reconnecting" );
        }
        
    }

  

    return 0;
}
