#include "types.h"
#include "stat.h"
#include "user.h"

#define NUM_PROCESSES 5

void do_work() {
    double result = 0.0;
    for (int i = 1; i <= 10000; ++i) {
        double factor = 1.0 / i;
        for (int j = 1; j <= i; ++j) {
            double term = 1.0 / (i * j);
            for (int k = 1; k <= j; ++k) {
                result += term * factor * k;
            }
        }
    }
}


int main(int argc, char *argv[]) {

    int pid = 0, valid = 0;
    if( (valid = setPriority(getpid(), 1)) != 0 ) printf(1, "Error in setting the priority! \n");
    for (int i = 0; i < NUM_PROCESSES; i++ ) {
    pid = fork ();
    if (pid < 0) {
        printf(1, "Fork Failed\n");
        exit();
    } 
    else if (pid==0) {
        printf(1,"Child %d with PID:%d CREATED\n", i, getpid());
        yield();	
        printPTable();
        do_work();
        yield();
        printf(1,"work2\n");
        printPTable();
        do_work();
        printf(1,"Child %d with PID:%d EXITED\n", i, getpid());
        exit();

    }
    }

    for(int i=0; i<NUM_PROCESSES; i++)
    {
        wait();
    }

    exit();
}
