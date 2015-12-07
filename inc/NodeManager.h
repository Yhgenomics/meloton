/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-08
* Description:
* * * * * * * * * * * * * * * */

#ifndef NODE_MANAGER_H_
#define NODE_MANAGER_H_

#include <functional>

#include "meloton.h"
#include "NodeSession.h"
#include "Array.h"

class NodeManager
{
   

public:
    
    typedef std::function<bool( sptr<NodeSession> instance)> find_callback_t;
    typedef std::function<void( sptr<NodeSession> instance)> all_callback_t;
   
    SINGLETON( NodeManager );

    ~NodeManager( );

    void                push_node   ( sptr<NodeSession> session );
    void                remove_node ( sptr<NodeSession> session );
    sptr<NodeSession>   find_node   ( find_callback_t callback );
    void                all_node    ( all_callback_t callback );

private:

    NodeManager( );

    uptr<Array<NodeSession>> node_array_ = nullptr;
};

#endif // !NODE_MANAGER_H_
