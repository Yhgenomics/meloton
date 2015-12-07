/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-07
* Description:
* * * * * * * * * * * * * * * */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <functional>

#include "MRT.h"


template<class T>
class Array
{
public:

    typedef std::function<bool( sptr<T> instance )> find_callback_t;

    Array( size_t initialSize );
    ~Array( );

    void    push( sptr<T> element );
    void    remove( sptr<T> element );
    void    remove_at( size_t index );
    sptr<T> get( size_t index );
    sptr<T> operator[]( size_t index );
    sptr<T> find( find_callback_t callback );
    size_t  size( );

private:

    sptr<T>*      array_ = nullptr;
    size_t  size_  = 0;
    size_t  cur_   = 0;
};


template<class T>
inline Array<T>::Array( size_t initialSize )
{
    SAFE_DELETE( array_ );
    array_ = new sptr<T>[initialSize]
    {
        0
    };
    size_ = initialSize;
    cur_ = 0;
}

template<class T>
inline Array<T>::~Array( )
{
    SAFE_DELETE( array_ );
};

template<class T>
inline void Array<T>::push( sptr<T> element )
{
    for ( size_t i = 0; i <= cur_; i++ )
    {
        if ( array_[i] == nullptr )
        {
            array_[i] = element;

            if ( i == ( cur_ ) )
            {
                ++cur_;
            }
            break;
        }
    }
};

template<class T>
inline void Array<T>::remove( sptr<T> element )
{
    for ( size_t i = 0; i < cur_; i++ )
    {
        if ( array_[i] != nullptr &&
             array_[i].get() == element.get() )
        {
            array_[i] = nullptr;

            if ( i == ( cur_ - 1 ) )
            {
                --cur_;
            }
            break;
        }
    }
};

template<class T>
inline void Array<T>::remove_at( size_t index )
{
    if ( index >= size_ )return;
    array_[index] = nullptr;
    if ( index == cur_ )
    {
        --cur_;
    }
}
template<class T>
inline sptr<T> Array<T>::get( size_t index )
{
    if ( index > cur_ )return nullptr;
    return array_[index];
}
template<class T>
inline sptr<T> Array<T>::operator[]( size_t index )
{
    if ( index > cur_ )return nullptr;
    return array_[index];
}
template<class T>
inline sptr<T> Array<T>::find( find_callback_t callback )
{
    for ( size_t i = 0; i <= cur_; i++ )
    {
        if ( array_[i] != nullptr )
        {
            if ( callback( array_[i] ) )
            {
                return array_[i];
            }
        }
    }

    return nullptr;
}
template<class T>
inline size_t Array<T>::size( )
{
    return this->cur_;
};

#endif // !ARRAY_H_
