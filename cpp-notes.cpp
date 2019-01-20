#include<iostream>
using namespace std;
////////////////////////////////////////////
// function declarations needed           //
// if function definition is not          // 
// in synchronous order of the program    //
// execution. For Example: if function    //
// definition is in another file          //
////////////////////////////////////////////

void some_function(); // function declaration

int main(){
    # main execution here
}

// this function definition is only legal
// because I declared the function with a
// prototype above
void some_function(){
    
}