/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-01
* Description:
* * * * * * * * * * * * * * * */

#ifndef MELOTON_H_
#define MELOTON_H_



#endif // !MELOTON_H_

#define VERSIONMAJOR 0
#define VERSJONMINOR 1

#define MAX_SIZE_T 0xFFFFFFFFFFFFul

#define BLOCK_SIZE          64 * 1024 * 1024
#define REPLICATE_NUM       3
#define FILE_INDEX_NAME     "file.idx"
#define FILE_DATA_NAME      "file.data"
#define MAX_BLOCK_NUM       1024 * 1024 * 10
#define MAX_PATH_SIZE       255
#define SIZE_PER_MESSAGE    1024*5

#define SINGLETON(__type__) \
    static __type__ * instance( ) \
    { \
        static __type__ instance_; \
        return &instance_;\
    }