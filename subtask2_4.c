#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>
#include <sched.h>

char stack[10000];

void TimeToSHOOTaPic()
{
    for (int i = 0; i < 3; ++i) {
        usleep(30000000);
    }
}


int task3(void* c)
{
    int prosses3 = fork();
    if(prosses3 == 0)
    {

        char* argv[2] = {"./subtask2.3",NULL};
        execvp(argv[0],argv);

    }
    return 0;
}

int main()
{
    int process1 = fork();
    if( process1 == 0)
    {
        int waits = clone(task3,stack+1 , CLONE_PARENT , 0 );
       char* argv[2] = {"./subtask2.1",NULL};
       execvp(argv[0],argv);

    }

    else{
        int prosses2 = fork();
        if(prosses2 == 0)
        {
            char* argv[2] = {"./subtask2.2",NULL};
            execvp(argv[0],argv);

        }
    }

    TimeToSHOOTaPic();
    return 0;
}