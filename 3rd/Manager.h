/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-10-22
* Description:
* * * * * * * * * * * * * * * */

#ifndef MANAGER_HPP_
#define MANAGER_HPP_ 

#include <vector>
#include <mutex>
#include "Macro.h"

NS_MARATON_BEGIN

template<class T>
class Manager
{
public:

    virtual void push( sptr<T> instance )
    {
        this->instance_.push_back( move_ptr( instance ) );
    }

    virtual bool pop( sptr<T> instance )
    {
        typename std::vector<sptr<T>>::iterator itr = this->instance_.begin( );

        while ( itr != this->instance_.end( ) )
        {
            if ( ( *itr ).get( ) == instance.get( ) )
            {
                itr = this->instance_.erase( itr );
                return true;
            }
            else
            {
                itr++;
            }
        }

        return false;
    }

protected:

    std::vector<sptr<T>> instances() 
    {
        std::vector<sptr<T>> vret( this->instance_.begin(), this->instance_.end() );

        return vret;
    }

    std::vector<sptr<T>> instance_;

private:

    std::mutex mtx;
};
 
NS_MARATON_END

#endif //!MANAGER_HPP_ 