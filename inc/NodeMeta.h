/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-28
* Description:
* * * * * * * * * * * * * * * */

#ifndef NODE_META_H_
#define NODE_META_H_

#include "MRT.h"

class NodeMeta
{
public:

    NodeMeta( size_t node_id )
    {
        this->node_id_ = node_id;
    };

    ~NodeMeta( )
    {

    };

    PP_DEF( size_t , index )
    PP_DEF( size_t , node_id )

private:

    size_t index_;
    size_t node_id_;
};

#endif // !NODE_META_H_
