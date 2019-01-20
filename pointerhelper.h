
#ifdef __cplusplus
extern "C" {
#endif

// Include guard
#ifndef __pointerhelper_h_INCLUDED__      // <- if pointerstruct.h hasn't been included yet...
#define __pointerhelper_h_INCLUDED__     // <- #define this so that it can be included

class pointerhelper
{
    public:
        int get_length();
        int*get_rand_arr(int);
        int**sort_ptr_adr();
};

#endif

#ifdef __cplusplus
}
#endif
