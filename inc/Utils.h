/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-25
* Description:
* * * * * * * * * * * * * * * */

#ifndef UTILS_H_
#define UTILS_H_

#include <string>

inline static size_t hash_code( std::string & name)
{
    size_t ret = 0;
    for (int i = 0; i < name.length(); i++)
    {
        char b = (char)name[i];
        size_t v = (((size_t)b << ((i % (char)8) * (char)8)) | i);
        ret |= (size_t)(v);
    }
    return ret;
}

#endif // !UTILS_H_
