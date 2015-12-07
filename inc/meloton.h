/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2015-12-01
* Description:
* * * * * * * * * * * * * * * */

#ifndef MELOTON_H_
#define MELOTON_H_



#endif // !MELOTON_H_

#define VERSIONMAJOR 0
#define VERSJONMINOR 1

#define SINGLETON(__type__) \
    static __type__ * instance( ) \
    { \
        static __type__ instance_; \
        return &instance_;\
    }