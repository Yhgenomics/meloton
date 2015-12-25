#include "FileMeta.h"

FileMeta::FileMeta( std::string name )
{
    this->name_ = name;
    this->name_hash_ = hash_code( name );
}
