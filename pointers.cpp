#include <iostream>
#include "pointerhelper.h"
using namespace std;

int main(){
    pointerhelper a;
    int*ptrs = *(a.sort_ptr_adr()); // bulid with makefile to make this work
    int length = sizeof(ptrs) / sizeof(int);
    for (int i = 0; i < length; i++){
        cout<<*ptrs[i]<<" ";
    }
}