/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-03
* Description:
* * * * * * * * * * * * * * * */

#ifndef CLUSTER_SESSION_H_
#define CLUSTER_SESSION_H_

#include "MRT.h"
#include <google/protobuf/message.h>

class ClusterSession :
    public MRT::Session
{
public:

    ClusterSession( );
    ~ClusterSession( );

    void    send_message( uptr<::google::protobuf::Message> message );
    size_t  id          ( ) { return this->id_; };

protected:

    void on_read ( uptr<MRT::Buffer> data ) override;

private:

    enum ParseState
    {
        kHead = 1,
        kLength,
        kBody
    };

    void try_dispatch_message( MRT::CircleBuffer & buffer );
    
    ParseState          parse_state_;
    int                 body_length_;
    MRT::CircleBuffer   circle_buffer_;

    size_t              id_;
};

#endif // !CLUSTER_SESSION_H_
