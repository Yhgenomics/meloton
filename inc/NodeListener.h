/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-01
* Description:
* * * * * * * * * * * * * * * */

#ifndef NODE_LISTENER_H_
#define NODE_LISTENER_H_

#include "MRT.h"

using namespace MRT;

class NodeListener :
    MRT::Listener
{
public:

protected:

private:

    // Í¨¹ý Listener ¼Ì³Ð
    virtual Session * create_session( ) override;
    virtual void on_session_open( Session * session ) override;
    virtual void on_session_close( Session * session ) override;
};

#endif // !NODE_LISTENER_H_
