/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-25
* Description:
* * * * * * * * * * * * * * * */

#ifndef FS_H_
#define FS_H_

#include <vector>

#include "MRT.h"
#include "meloton.h"
#include "Path.h"
#include "DirectoryMeta.h"
#include "FileMeta.h"
#include "BlockMeta.h"

class FS
{
public:

    SINGLETON( FS );
    ~FS( );

    sptr<DirectoryMeta> create_dir( std::string path );
    sptr<DirectoryMeta> get_dir( std::string path );
    //void delete_dir( std::string path );
    std::vector<sptr<DirectoryMeta>> list_dir( std::string path );
    
    sptr<FileMeta> create_file( std::string path );
    bool exist_file( std::string path );
    sptr<FileMeta> get_file( std::string path );
    //void delete_file( std::string path );
    //std::vector<sptr<FileMeta>> list_file( std::string path );

private:

    FS( );

    sptr<DirectoryMeta> root_;
};

#endif // !FS_H_
