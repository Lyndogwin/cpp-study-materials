#include "helper.h" // header with necessary inclusions

// best practice is test after each edit

////////////////////////////////////////////
// function declarations needed           //
// if function definition is not          // 
// in synchronous order of the program    //
// execution. For Example: if function    //
// definition is in another file          //
////////////////////////////////////////////

//-----------Function Declaration-----------
void some_function(void); 

// this is the type of function that CAN be passed to pthread_create()
void * thread_func(void *);
// create a new process
void create_process(void);

// -----------------Main--------------------
int main(void){
    /////////////////////////
    // main execution here //
    /////////////////////////
    pthread_t id; 
    int some_int = 5;
    int arr[4] = {0,1,2,3};
    int length = sizeof(arr)/ sizeof(int);
    // standard call to pthread_create with helper function
    int rc = pthread_create(&id, NULL,thread_func,(void *) &some_int); // pass address of int as " void * "
    
    create_process();
    
    for(int i = 0; i < length; i++){
        // in this thread creation loop, you cannot simply 
        // pass the address of i dispite what immediate logic 
        // would dictate. this is because of the fact that the code
        // in the thread's function would excute with some sort of delay
        // given thier random scheduling and when the execution is eventually 
        // perfomed, the address of i would point to its final value
        // of 4, which would result in a printing of four '4's
        rc = pthread_create(&id, NULL, thread_func,(void *) &arr[i]);
    }
    
    
    // use the folloeing insead of standard exit to 
    // avoid terminating the program before the thread
    // code is executed
    pthread_exit(0);  
}

//------------Function Definition--------------

// this function definition is only legal
// because I declared the function with a
// prototype above
void some_function(){
    cout << "I'm some function." << endl;
}

void * thread_func(void * args){
    cout<< "-------------------------------------"<< endl;
    cout << "Thread Created"<< endl;
    
    // convert to int * then dereference that pointer
    int real_arg = *((int *) args);
    cout << "argument passed was: "<< real_arg << endl;
}

void create_process(){
    pid_t id = fork();
    
    if(id == -1){
        cout<< "ERROR: Process fork failed"<< endl;
    }
    else if(id == 0){
        cout<< "I am the child process"<< endl;
        char * args[3] = {(char * )"./notetest",(char *)" ", NULL};
        // the line bellow would create fork bomb because each
        // newly forked process would run this program from the begining
        // which creates more processes.
        // this process creation would continue until the
        // memory limit was reached
        
        // execvp(args[0],args);
    }
    else{
        cout<< "I am a Parent now"<< endl;
    }
}

