/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-07
* Description:
* * * * * * * * * * * * * * * */

#ifndef FILE_TABLE_H_
#define FILE_TABLE_H_
 
#include <string>

#include "MRT.h"
#include "meloton.h"

const size_t FT_ERROR_FILE_EXIST = 0x100;
const size_t FT_ERROR_FILE_NOTFOUND = 0x101;
const size_t FT_ERROR_READ_OUTOFBOUND = 0x102;
const size_t FT_ERROR_WRITE_OUTOFBOUND = 0x103;
const size_t FT_ERROR_FILE_CLOSED = 0x104;


class FileHandler
{
public :

    FileHandler( );
    ~FileHandler( );

private:

    size_t file_name_hash  = 0;
    size_t position        = 0;
    size_t h_idx           = 0;

    friend class FileTable;
};

class FileTable
{
public:

    SINGLETON( FileTable );

    ~FileTable( );

    void initial( );
    
    sptr<FileHandler> create_file( const std::string & file_name , 
                              const size_t & part_id  ,
                              const size_t & file_size );

    sptr<FileHandler> open_file( const std::string & file_name , 
                                 const size_t & part_id );

    size_t write_file( sptr<FileHandler> handler , 
                       const char * data , 
                       const size_t len );

    size_t read_file( sptr<FileHandler> handler , 
                      char * buffer , 
                      const size_t buffer_size );

    size_t seek_file( sptr<FileHandler> handler ,
                      const size_t & position );
    
    size_t file_size( sptr<FileHandler> handler );

    void close_file( sptr<FileHandler> handler );

    size_t error( );

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

    
    void            read_file_index  ( FILE * file );
    void            save_index       ( FileIndex * index );
    size_t          add_index        ( FileIndex * index );
    size_t          hash_name        ( const char file_name[248] );
    size_t          hash_name        ( const char * file_name , 
                                       size_t len );
    FileIndex *     find_index       ( const std::string & file_name , 
                                       const size_t & part_id );
    FileIndex *     find_hash        ( size_t hash);

    FILE*           open_table_read  ( );
    FILE*           open_table_append( );
    FILE*           open_idx_write   ( );
    FILE*           open_idx_read    ( );
    void            close_file       ( FILE* );

    FileIndex** idx_array_           = nullptr;
    size_t      idx_size_            = 0;
    size_t      idx_index_           = 0;
                                     
    FILE*       file_idx_            = 0;
    MRT::Mutex  file_idx_mutex_;     
                                     
    FILE*       file_table_          = 0;
    MRT::Mutex  mutex_handle_file ;  
                                     
                                     
    size_t      error_               = 0;
                                     
    const std::string FILE_IDX_NAME  = "file.idx";
    const std::string FILE_DATA_NAME = "file.data";
};

#endif // !FILE_TABLE_H_
