/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-25
* Description:
* * * * * * * * * * * * * * * */

#ifndef PATH_H_
#define PATH_H_

#include <string>
#include <vector>

#include "Error.h"

class Path
{
public:

    Path( std::string );
    ~Path( );

    Error parse( std::string path );
    std::vector<std::string> list( );
    std::string filename( );

private:

    std::string path_;
    std::string filename_;
    std::vector<std::string> path_list_;
};

#endif // !PATH_H_
