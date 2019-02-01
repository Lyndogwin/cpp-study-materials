#include <iostream>
#include "helper.h"
using namespace std;

int main(){
    pointerhelper a;
    int o = 1;
    int*ptrs = *(a.sort_ptr_adr()); 
    cout<<ptrs<<endl;
    int length = sizeof(*ptrs) / sizeof(int);
    for (int i = 0; i < length; i++){
        cout<<ptrs[i]<<" ";
    }
}