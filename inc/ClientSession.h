/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description:
* * * * * * * * * * * * * * * */

#ifndef CLIENT_SESSION_H_
#define CLIENT_SESSION_H_

#include <vector>

#include <MRT.h>
#include <ClusterSession.h>
#include <TokenMeta.h>

class ClientSession :
    public ClusterSession
{
public:

    PP_DEF( size_t , token_num )

    bool            add_token( sptr<TokenMeta> token_meta );
    sptr<TokenMeta> get_token( size_t index );

private:

    size_t token_num_ = 0;
    std::vector<sptr<TokenMeta>> token_list_;
};

#endif // !CLIENT_SESSION_H_
