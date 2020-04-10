#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>
void (*hello_message)(const char *);
bool initLibary(){
    void *hdl = dlopen("/liblib.so",RTLD_LAZY);
    if (NULL == hdl)
    return false;
        hello_message = (void(*)(const char *))dlsym(hdl,"hello_message");
        if(NULL == hello_message)
        return false;
        return true;
}
        int main(){
        if (initLibary)
        hello_message("Ariel");
        else    
            printf("Libary was not loaded\n");
            return 0;
        }
    
    
