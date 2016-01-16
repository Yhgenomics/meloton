/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-29
* Description:
* * * * * * * * * * * * * * * */

#ifndef BLOCK_TABLE_H_
#define BLOCK_TABLE_H_

#include <string>
#include <vector>

#include "MRT.h"
#include "meloton.h"
#include <BlockIndex.h>

class BlockTable
{
public:

    SINGLETON( BlockTable );

    void load_from_file( );

    sptr<BlockIndex>  find_block( size_t index );
    sptr<BlockIndex>  create_block( std::string file_name , 
                                    size_t size ,
                                    size_t block_id , 
                                    size_t file_offset);
                      
    sptr<BlockIndex>  delete_block( size_t index );

    uptr<MRT::Buffer> read_block( sptr<BlockIndex> block , 
                                  size_t offset , 
                                  size_t size );

    size_t            write_block( sptr<BlockIndex> block,
                                   const char * data ,
                                   size_t size ,
                                   size_t offset );
    void              flush_block( );

    ~BlockTable( );

    size_t block_num ( )
    {
        return this->block_num_;
    };

private:

    BlockTable( );
     
    std::vector<sptr<BlockIndex>> block_idle_list_;
    FILE*                         pfile_index_      = nullptr;
    FILE*                         pfile_data_       = nullptr;
    size_t                        block_num_        = 0;
    sptr<BlockIndex>*             block_index_list_;

    void load_index( FILE* pfile );
    void save_index( FILE * pfile , size_t index );

    size_t alloc_data_space( );
};

#endif // !BLOCK_TABLE_H_
