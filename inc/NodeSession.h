/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-03
* Description:
* * * * * * * * * * * * * * * */

#ifndef NODE_SESSION_H_
#define NODE_SESSION_H_

#include "ClusterSession.h"

class NodeSession :
    public ClusterSession
{
public:

    NodeSession( );
    ~NodeSession( );
    
    PP_DEF( size_t , block_num )
    PP_DEF( size_t , disk_space )
    PP_DEF( size_t , token_num )
    PP_DEF( std::string , data_ip )
    PP_DEF( int , data_port )

    void    update_alive( );
    size_t  alive_time( );
    size_t  delay( );

protected:

private: 

    size_t      alive_time_  = 0;
    size_t      delay_       = 0;
    size_t      block_num_   = 0;
    size_t      disk_space_  = 0;
    size_t      token_num_   = 0;
    std::string data_ip_     = "";
    int         data_port_   = 0;
};

#endif // !NODE_SESSION_H_
