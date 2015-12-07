/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-07
* Description:
* * * * * * * * * * * * * * * */

#ifndef FILE_TABLE_H_
#define FILE_TABLE_H_

#include "MRT.h"
#include "meloton.h"

class FileTable
{
public:

    SINGLETON( FileTable );

    ~FileTable( );

    void load_from_disk( );


private:

    struct FileIndex
    {
        char    file_name[248]  = { 0 };
        size_t  part_size       = 0;
        size_t  part_id         = 0;
        size_t  offset          = 0;
        size_t  index           = 0;
        size_t  file_name_hash  = 0;
    };

    FileTable( );

    FileIndex* file_index_array_;

    void    parse_file_index( FILE* file );
    void    save_index( FileIndex & index );
    size_t  hash_name( const char file_name[248] );

    FILE*       file_idx_ = 0;
    MRT::Mutex  file_idx_mutex_;
    size_t      array_idx_ =0;
};

#endif // !FILE_TABLE_H_
