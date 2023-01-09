 #include <pthread.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #include <unistd.h>
 #define NUM_THREADS 1000

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

 void *PrintHello(void *processid)
 {
    long tid;
    tid = (long)processid;
    printf("Hello World! It's me, process #%ld!\n", tid);
 }

 void ChildProcess(void)
 {
    int i;

    for ( i = 0; i < NUM_THREADS; i++)
    {
        printf("Hello World! It's me, child process #%d!\n", i);
    }
    printf("   *** Child process is done ***\n");   
}

 void  ParentProcess(void)
{
    int   i;

    for (i = 1; i <= NUM_THREADS; i++)
    {
        printf("Hello World! It's me, parent process #%d!\n", i);
    }
    printf("*** Parent is done ***\n");
}

 int main(int argc, char argv[])
 {
    pthread_t threads[NUM_THREADS];
    int rc;
    
    rc = fork();
    if (rc == -1)
    {
        printf("");
        {
            printf("ERROR; return code from fork() is %d\n", rc);
            exit(-1);
        }
    }
    else if (rc == 0)
    {
        ChildProcess();
    }
    else
    {
        ParentProcess();
    }
    
    // Last thing that main() should do:
    exit(1);
 }