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

    // Check if n1 is greater than n2
    typedef std::function<bool( sptr<NodeSession> n1 , 
                                sptr<NodeSession> n2)> compare_callback_t;
    typedef std::function<void( sptr<NodeSession> instance)> all_callback_t;
   
    SINGLETON( NodeManager );

    ~NodeManager( );
    NodeSession*        create_node ( );
    sptr<NodeSession>   get_node    ( size_t index );
    size_t              count       ( );
    void                push_node   ( sptr<NodeSession> session );
    void                remove_node ( sptr<NodeSession> session );
    sptr<NodeSession>   find_node   ( find_callback_t callback );
    void                all_node    ( all_callback_t callback );
    void                sort        ( compare_callback_t callback );

private:

    NodeManager( );

    uptr<Array<NodeSession>> node_array_ = nullptr;
    void quick_sort( size_t i , size_t j , compare_callback_t compare );
};

#endif // !NODE_MANAGER_H_
