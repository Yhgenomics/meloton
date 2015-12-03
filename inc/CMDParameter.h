/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-03
* Description:
* * * * * * * * * * * * * * * */

#ifndef CMD_PARAMTER_H_
#define CMD_PARAMTER_H_

class CMDParameter
{
public:

    ~CMDParameter( );

    static bool parse( int argc , char * argv[] );
    static void print_help();
    
private:

    CMDParameter( );

};

#endif // !CMD_PARAMTER_H_
