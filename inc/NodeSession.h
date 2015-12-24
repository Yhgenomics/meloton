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
    

    void    update_alive( );
    size_t  alive_time( );
    size_t  delay( );


protected:

private: 

    size_t alive_time_  = 0;
    size_t delay_       = 0;
    size_t block_num_   = 0;
    size_t disk_space_  = 0;
};

#endif // !NODE_SESSION_H_
