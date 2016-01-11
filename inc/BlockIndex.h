/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-29
* Description:
* * * * * * * * * * * * * * * */

#ifndef BLOCK_INDEX_H_
#define BLOCK_INDEX_H_

#include <string>
#include "meloton.h"

struct BlockIndex
{
    size_t      index = 0;
    char        path[MAX_PATH_SIZE] = { 0 };
    size_t      path_hash;
    size_t      size = 0;
    size_t      offset = 0;
    size_t      block_id = 0;
    size_t      file_offset = 0;
    bool        is_used = false;
};

#endif // !BLOCK_INDEX_H_
