#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10000
#define CYCLES 1000
char child_stack[STACK_SIZE+1];

void print(const char *text){
    for (size_t i = 0; i <CYCLES; i++)
    {
        printf("Hello from %s\n",text);
        usleep(1000000);
    }   
}
int child(void *params){
print("child_thread1");
return 0;

}
int child2( void *params){
    print("child thread 2");
    return 0;
}
int main(){
    int result1 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
   // int res2 = clone(child2,child_stack+STACK_SIZE,CLONE_PARENT,0);
    printf("clone result %d\n",result1);
    print("parent");
    return 0;

}