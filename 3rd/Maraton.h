/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-11-19
* Description:
* * * * * * * * * * * * * * * */

#ifndef MARATON_H_
#define MARATON_H_

#include <functional>
#include <vector>

#include "Macro.h"
#include "Operator.h"
#include "Listener.h"
#include "Connector.h"

NS_MARATON_BEGIN

class Maraton
{
public:

    static Maraton* instance( )
    {
        static Maraton* inst = nullptr;

        if ( inst == nullptr )
        {
            static Maraton maraton;
            inst = &maraton;
        }

        return inst;
    }

    void regist     ( sptr<Operator> listener );
    void unregist   ( sptr<Operator> opt );
    void unregist   ( const Operator * opt );
    void run        ( );

private:

    Maraton( )
    {
    };

    ~Maraton( )
    {
    };

    uv_loop_t*          uv_loop( );
    sptr<Operator>      elements_[MAX_CONNECTION_SIZE];
    int                 elements_index_                 = 0;
     
    static void uv_process_resolved( uv_getaddrinfo_t * req , int status , addrinfo * res );
};

NS_MARATON_END

#endif // !MARATON_H_
