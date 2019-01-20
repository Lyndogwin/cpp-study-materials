// pointerhelper algorithms I wrote to speed along this course
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "pointerhelper.h"
using namespace std;

int* pointerhelper :: get_rand_arr(){
    int input;
    cout<<"How many numbers would you like?(enter integer)";
    cin>>input;
    const int length = input;
    int arr[length];
    for(int i = 0; i < length; i++){
        // adds a random number 1 through 6
        // to the arr at index i
        srand(time(0));
        arr[i] = 1 + (rand() % 5); 
    }
    return arr;
}

int**pointerhelper :: sort_ptr_adr(){
    int *arr; 
    arr = get_rand_arr();
    const int length = sizeof(arr)/sizeof(int); //test to see if works
    static int * ptrs[length];
    
    for(int i = 0; i < length; i++){
        ptrs[i] = &arr[i];
    }
    // insertion sort
    for (int i = 0; i < length; i++){
        if(i != (length - 1)){
            for(int j = i + 1; j < length; j++){
                if (j == 1){
                    ptrs[0] = &arr[0];
                }
                else if(arr[j] < *ptrs[i]){
                    ptrs[i + 1] = ptrs[i];
                    ptrs[i] = &arr[j];
                }
            }  
        }
    }
    return ptrs;
}