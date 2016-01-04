/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-29
* Description:
* * * * * * * * * * * * * * * */

#ifndef BLOCK_DISTRIBUTER
#define BLOCK_DISTRIBUTER

#include "MRT.h"
#include "ClusterSession.h"
#include <google/protobuf/message.h>
#include <MessageRequestGet.pb.h>
#include <MessageRequestPut.pb.h>

#include "FS.h"
#include <ClientSession.h>

class BlockDistributer
{
public:

    BlockDistributer( );
    ~BlockDistributer( );

    void get_file( sptr<FileMeta> file , 
                   sptr<ClientSession> session , 
                   uptr<MessageRequestGet> msg );

    void put_file( size_t file_size , 
                   sptr<ClientSession> session , 
                   uptr<MessageRequestPut> msg );

private:


};

#endif // !BLOCK_DISTRIBUTER
