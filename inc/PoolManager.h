/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-31
* Description:
* * * * * * * * * * * * * * * */

#ifndef MANAGER_H_
#define MANAGER_H_

#include <functional>
#include <string>

#include <Array.h>

template<class T>
class PoolManager
{
public:
    
    typedef std::function<bool( sptr<T> instance)> find_callback_t;

    // Check if n1 is greater than n2
    typedef std::function<bool( sptr<T> n1 , 
                                sptr<T> n2)> compare_callback_t;
    typedef std::function<void( sptr<T> instance)> all_callback_t;
   
    virtual ~PoolManager( );
    sptr<T>             create_node ( );
    sptr<T>             get_node    ( size_t index );
    size_t              count       ( );
    void                push_node   ( sptr<T> session );
    void                push_node   ( T* session );
    void                remove_node ( sptr<T> session );
    void                remove_node ( T* session );
    sptr<T>             find_node   ( find_callback_t callback );
    void                all_node    ( all_callback_t callback );
    void                sort        ( compare_callback_t callback );

protected:

    PoolManager( size_t element_size );

    uptr<Array<T>> node_array_ = nullptr;
    
    void quick_sort( size_t i , size_t j , compare_callback_t compare );
}; 

template<class T>
inline PoolManager<T>::~PoolManager( )
{
}

template<class T>
inline sptr<T> PoolManager<T>::create_node( )
{
    auto session = make_sptr( T );
    this->push_node( session );
    return session;
}

template<class T>
inline sptr<T> PoolManager<T>::get_node( size_t index )
{
    return this->node_array_->get( index );
}

template<class T>
inline size_t PoolManager<T>::count( )
{
     return this->node_array_->size( );
}

template<class T>
inline void PoolManager<T>::push_node( sptr<T> session )
{
     this->node_array_->push( sptr<T>(session) );
}

template<class T>
inline void PoolManager<T>::push_node( T* session )
{
    this->node_array_->push( sptr<T>( session ) );
}

template<class T>
inline void PoolManager<T>::remove_node( sptr<T> session )
{
    this->node_array_->remove( sptr<T>( session ) );
}

template<class T>
inline void PoolManager<T>::remove_node( T* session )
{
    this->node_array_->remove( session );
}

template<class T>
inline sptr<T> PoolManager<T>::find_node( find_callback_t callback )
{
    return this->node_array_->find( callback );
}

template<class T>
inline void PoolManager<T>::all_node( all_callback_t callback )
{
    for ( size_t i = 0; i < this->node_array_->size( ); i++ )
    {
        auto t = this->node_array_->get( i );
        if ( t != nullptr )
        {
            callback( t );
        }
    }
}

template<class T>
inline void PoolManager<T>::sort( compare_callback_t callback )
{
    quick_sort( 0 , this->node_array_->size( ) - 1, callback );
}

template<class T>
inline PoolManager<T>::PoolManager( size_t element_size )
{
    this->node_array_ = make_uptr( Array<T> , element_size );
}

template<class T>
inline void PoolManager<T>::quick_sort( size_t i , size_t j , compare_callback_t compare )
{
    size_t l , r;
    l = r =  0;

    if (l < r)  
    {        
        size_t i = l , j = r;
        auto x = this->node_array_->get(l);  
        while (i < j)  
        {  
            auto nj = this->node_array_->get(j);  
            while ( i < j && compare(nj,x) ) // s[j]>= x
            {
                j--;   
            } 

            if ( i < j )
            { 
                //s[i++] = s[j];  
                this->node_array_->swap( i , j );
                i++;
            }

            auto ni = this->node_array_->get(i);  
            while ( i < j && compare(x , ni) ) //s[i] < x
            {
                i++;
            }

            if ( i < j )
            {
                //s[j--] = s[i];
                this->node_array_->swap( j , i );
                j--;
            }
        } 
        
        this->node_array_->set( i , x );
        //s[i] = x;  
        
        quick_sort(l, i - 1 , compare);
        quick_sort(i + 1, r , compare);  
    }  
}

#endif // !MANAGER_H_

