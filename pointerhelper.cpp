// pointerhelper algorithms I wrote to speed along this course
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "helper.h"
using namespace std;

int pointerhelper:: get_length(){
    int input;
    cout<<"How many numbers would you like?(enter integer)";
    cin>>input;
    return input;
};

int* pointerhelper :: get_rand_arr(int input){
    const int length = input;
    int arr[length];
    for(int i = 0; i < length; i++){
        // adds a random number 1 through 6
        // to the arr at index i
        //srand(time(0));
        arr[i] = 1 + (rand() % 5); 
    }
    for(int i = 0; i < length; i++){
        cout<<arr[i]<<" ";
    }
    return arr;
};

int**pointerhelper :: sort_ptr_adr(){
    const int length = get_length();
    
    int arr[length];
    int* arr_ptr = get_rand_arr(length);
    // const int length = sizeof(arr)/sizeof(int); //test to see if works
    
    // check arr for values
    cout<<"print arr: ";
    for(int i = 0; i < length; i++){
        arr[i] = arr_ptr[i];
    }
    cout<<endl;
    
    int * ptrs[length];
    /*
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
    }*/
    return ptrs;
};