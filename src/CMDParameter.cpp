#include "CMDParameter.h"
#include "stdio.h"
#include "meloton.h"
#include "Variable.h"
CMDParameter::~CMDParameter( )
{

}

bool CMDParameter::parse( int argc , char * argv[] )
{
    if ( argc <= 2 )
    {
        print_help( );
        return false;
    }

    if ( argv[1][0] == 's' )
    {
        Variable::mode = 1;

        if ( argc > 2 )
        {
            Variable::port = atoi( argv[2] );
            return true;
        }
    }
    else if ( argv[1][0] == 'n' )
    {
        Variable::mode = 0;

        if ( argc > 3 )
        {
            Variable::server_ip = std::string( argv[2] );
        } 

        if ( argc >= 4 )
        {
            Variable::port = atoi( argv[3] );
            return true;
        }
    } 
     
    print_help( );
    return false;
}

void CMDParameter::print_help( )
{
    printf( "YHGenomics Inc.\r\n" );
    printf( "Meloton Distribute File Systrem\r\n" );
    printf( "Version:   %d.%d\r\n" , VERSIONMAJOR , VERSJONMINOR );
    printf( "Build Date:%s %s\r\n" , __DATE__ , __TIME__ );
    printf( "========================================\r\n" );
    printf( "Usage: meloton options ip port\r\n" );
    printf( "   options: \r\n" );
    printf( "            s : run meloton in master mode \r\n" );
    printf( "            n : run meloton in node mode \r\n" );
    printf( "   ip: master ip address or listener ip address \r\n" );
    printf( "   port: connecting port or listening port\r\n" );
}
