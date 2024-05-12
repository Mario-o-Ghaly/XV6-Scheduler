#include "types.h"
#include "stat.h"
#include "user.h"

#define NUM_PROCESSES 5

// void do_work() {
//     int counter = 0;
//     for (int i = 0; i < 1000000; i++) {
//         for (int j = 0; j < 1000000; j++) 
//             counter++;
//     }
// }

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
    if (argc < 2 || argc > 2){
        printf(1, "Error! Only one argument is required.\n");
        exit();
    }
    int choice = atoi(argv[1]);
    if(choice != 0 && choice != 1){
        printf(1, "Error! Invalid Input \n");
        exit();
    }
    int pid = 0, valid = 0, pr = 5;
    for (int i = 0; i < NUM_PROCESSES; i++ ) {
    pid = fork ();
    if (pid < 0) {
        printf(1, "Fork Failed\n");
        exit();
    } 
    else if (pid==0) {
        printf(1,"Child %d with PID:%d CREATED\n", i, getpid());
        pr = 5;
        if(i >= 0 && i < 10){
            if(choice == 0)
                pr = 10 - i;
            else pr = i + 1;
        }
        if( (valid = setPriority(getpid(), pr)) == 0) {
            yield();	
            printPTable();
            do_work();
            printf(1,"Child %d with PID:%d EXITED\n", i, getpid());
            exit();
        }
        else {
            printf(1, "Error in setting the priority !\n");
        }
    }
    }

    for(int i=0; i<NUM_PROCESSES; i++)
    {
        wait();
    }

    exit();
}


// int main(int argc, char *argv[]) {

//     int pid = 0, valid = 0, pr = 5;
//     for (int i = 0; i < NUM_PROCESSES; i++ ) {
//     pid = fork ();
//     if (pid < 0) {
//         printf(1, "Fork Failed\n");
//         exit();
//     } 
//     else if (pid==0) {
//         printf(1,"Child %d with PID:%d CREATED\n", i, getpid());
//         pr = 5;
//         if(i >= 0 && i < 10)
//             pr = i + 1;
//         if( (valid = setPriority(getpid(), pr)) == 0) {
//             // sleep(0);	
//             printPTable();
//             do_work();
//             printf(1,"Child %d with PID:%d EXITED\n", i, getpid());
//             exit();
//         }
//         else {
//             printf(1, "Error in setting the priority !\n");
//         }
//     }
//     }

//     for(int i=0; i<NUM_PROCESSES; i++)
//     {
//         wait();
//     }

//     exit();
// }


