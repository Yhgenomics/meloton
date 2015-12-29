/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-25
* Description:
* * * * * * * * * * * * * * * */

#ifndef BLOCK_META_H_
#define BLOCK_META_H_

#include <vector>

#include "MRT.h"
#include "NodeMeta.h"

class BlockMeta
{
public:

    BlockMeta( int id );
    ~BlockMeta( );

    int id( )
    {
        return id_;
    };


    std::vector<sptr<NodeMeta>> nodes( )
    {
        return std::vector<sptr<NodeMeta>>( nodes_ );
    };

    sptr<NodeMeta> get_nodes( size_t node_id )
    {
        for ( auto & n : this->nodes_ )
        {
            if ( n->node_id( ) == node_id )
            {
                return n;
            }
        }

        return  nullptr;
    };

    void add_nodes( sptr<NodeMeta> node )
    {
        this->nodes_.push_back( move_ptr( node ) );
    };

    PP_DEF( int , size )

private:

    int                         id_ = 0;
    int                         size_ = 0;
    std::vector<sptr<NodeMeta>> nodes_;
};

#endif // !BLOCK_META_H_
