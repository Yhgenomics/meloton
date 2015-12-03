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

    size_t id( );

protected:

private:

    size_t id_;

};

#endif // !NODE_SESSION_H_
