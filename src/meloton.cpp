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

int main( int argc , char * argv[] )
{ 

   
    FileTable::instance( )->initial( );

    auto tim = time( 0 );

    for ( size_t i = 0; i < 100; i++ )
    {
        auto data_size = ( 1 + i ) * 10;
        char* tmp_data = new char[data_size] { (char)('A' + i % 20) };
        char buf[512] = { 0 };
        itoa( (i+1) , buf , 10 );
        std::string id ( buf );
        std::string name = "File_Name_" + id;
        auto f = FileTable::instance( )->create_file( name , 1 , data_size );
        FileTable::instance( )->write_file( f , tmp_data , data_size );
        delete tmp_data;
    }

     auto deltaTime = time( 0 ) - tim;


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
