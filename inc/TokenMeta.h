/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description:
* * * * * * * * * * * * * * * */

#ifndef TOKEN_META_H_
#define TOKEN_META_H_

#include <string>

struct TokenMeta
{ 
    std::string address;
    int port;
    std::string token;
    size_t expire;
    size_t index;
    std::string request_id;
    size_t block_id;
    size_t client_id;
    size_t block_size;
    size_t offset;
};

#endif // !TOKEN_META_H_
