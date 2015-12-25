/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-25
* Description:
* * * * * * * * * * * * * * * */

#ifndef FILE_META_H_
#define FILE_META_H_

#include "MRT.h"
#include "Utils.h"

class FileMeta
{
public:

    FileMeta( std::string name );

    std::string name( )
    {
        return this->name_;
    }

    size_t name_hash( )
    {
        return this->name_hash_;
    }

private:

    std::string name_ = "";
    int         size_ = 0;
    size_t      name_hash_ = 0;
    size_t      block_count_ = 0;

};

#endif // !FILE_META_H_
