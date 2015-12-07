#include "FileTable.h"

#include <string>

FileTable::FileTable( )
{
    this->file_index_array_ = new FileIndex[1024 * 1024 * 10];
}

FileTable::~FileTable( )
{

}

void FileTable::load_from_disk( )
{
    const static std::string FILE_NAME = "file_index.idx";

}

void FileTable::parse_file_index( FILE * file )
{
    size_t total_file_num   = 0;
    file_idx_               = file;

    fread( &total_file_num , sizeof( size_t ) , 1 , file );

    for ( size_t i = 0; i < total_file_num; i++ )
    {
        fread( &this->file_index_array_[i] , sizeof( FileIndex ) , 1 , file );
        this->file_index_array_[i].index = i;
    }

    array_idx_ = total_file_num;
}

void FileTable::save_index( FileIndex & index )
{
    file_idx_mutex_.wait( );

    int num_size    = sizeof( size_t );
    int offset      = fseek( this->file_idx_ ,
                             num_size + index.index * sizeof( FileIndex ) ,
                             SEEK_CUR );
    fwrite( &index ,
            sizeof( FileIndex ) ,
            1 ,
            this->file_idx_ );

    file_idx_mutex_.release( );
}

size_t FileTable::hash_name( const char file_name[248] )
{
    size_t result = 0;

    for ( size_t i = 0; i < 248 && file_name[i]; i++ )
    {
        result ^=  ( size_t ) ( ( file_name[i] ) << ( ( i % sizeof( size_t ) ) * 8 ) );
    }

    return result;
}
