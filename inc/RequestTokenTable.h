/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-29
* Description:
* * * * * * * * * * * * * * * */

#ifndef REQEUST_TOKEN_TABLE
#define REQEUST_TOKEN_TABLE

#include <string>
#include <vector>
#include <tuple>

#include "MRT.h"
#include "meloton.h"
#include "ClusterSession.h"
#include <NodeSession.h>
#include <Array.h>

class RequestTokenCollection
{
public:

    typedef std::tuple < sptr<NodeSession> ,
                         std::string ,
                         size_t,
                         size_t> TokenResponse;

    RequestTokenCollection( sptr<ClusterSession> client , 
                            std::string request_id , 
                            size_t token_num );
    ~RequestTokenCollection( );

    void add_token( sptr<NodeSession> client , 
                    std::string token ,
                    size_t index ,
                    size_t block_id);

    void reply_token( );

    bool is_full( );
    std::string request_id( );

    PP_DEF( size_t , token_max_size )
private:

    
    size_t                           token_max_size_ = 0;
    std::string                      request_id_     = "";
    sptr<ClusterSession>             client_         = nullptr;
                             
    std::vector<sptr<TokenResponse>> token_list_;
  
    friend class RequestTokenTable;
};

class RequestTokenTable
{
public:

    SINGLETON( RequestTokenTable );

    ~RequestTokenTable( );

    sptr<RequestTokenCollection> create   ( sptr<ClusterSession> client , 
                                            std::string request_id , 
                                            size_t token_num  );

    sptr<RequestTokenCollection> find     ( std::string request_id );
    sptr<RequestTokenCollection> remove   ( std::string request_id );

private:

    RequestTokenTable( );

    std::vector<sptr<RequestTokenCollection>> token_list_;

};

#endif // !REQEUST_TOKEN_TABLE
