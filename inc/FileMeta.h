/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-25
* Description:
* * * * * * * * * * * * * * * */

#ifndef FILE_META_H_
#define FILE_META_H_

#include <vector>

#include "MRT.h"
#include "Utils.h"
#include "BlockMeta.h"

class FileMeta
{
public:

    FileMeta( std::string name );

    std::string name( );
    size_t name_hash( );

    sptr<BlockMeta> get_block( size_t id );

    PP_DEF( int , size )
    PP_DEF( std::vector<sptr<BlockMeta>> , blocks );

    void add_block( sptr<BlockMeta> block );

private:

    std::string name_ = "";
    int         size_ = 0;
    size_t      name_hash_ = 0;

    std::vector<sptr<BlockMeta>> blocks_;
};

#endif // !FILE_META_H_
