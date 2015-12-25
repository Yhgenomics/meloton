/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-25
* Description:
* * * * * * * * * * * * * * * */

#ifndef DIRECTORY_META_H_
#define DIRECTORY_META_H_

#include <vector>

#include "MRT.h"
#include "FileMeta.h"
#include "Path.h"

class DirectoryMeta
{
public:

    DirectoryMeta( std::string name );
    ~DirectoryMeta( );

    sptr<FileMeta> append_file( sptr<FileMeta> meta );
    sptr<FileMeta> get_file( std::string name );
    sptr<FileMeta> get_file( sptr<Path> path );
    bool file_exist( std::string name );

    sptr<DirectoryMeta> append_dir( sptr<DirectoryMeta> meta );
    sptr<DirectoryMeta> get_dir( std::string name );
    sptr<DirectoryMeta> get_dir( sptr<Path> path );
    bool dir_exist( std::string name );

    PP_DEF( std::string , name )

private:

    std::string                      name_ = "";
    size_t                           name_hash_ = 0;
    sptr<DirectoryMeta>              parent_ = nullptr;
    std::vector<sptr<DirectoryMeta>> children_;
    std::vector<sptr<FileMeta>>      files_;

};

#endif // !DIRECTORY_META_H_
