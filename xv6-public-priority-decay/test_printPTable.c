#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

// this program is to test the printPTable system call
int main(int argc, char* argv[]){
    printPTable();
    exit();
}

// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fcntl.h"

// #define NUM_PROCESSES 5

// void do_work() {
//     volatile int counter = 0;
//     for (int i = 0; i < 1000000; i++) {
//         counter++;
//     }
// }

// int main(int argc, char* argv[]) {
//     // Create multiple child processes with different priorities
//     for (int i = 0; i < NUM_PROCESSES; i++) {
//         int pid = fork();
//         if (pid < 0) {
//             printf(1, "fork failed\n");
//             exit();
//         } else if (pid == 0) {
//             // Child process
//             setPriority(getpid(), i); // Set priority of child process
//             do_work(); // Simulate some work
//             exit();
//         }
//     }

//     // Wait for all child processes to finish
//     for (int i = 0; i < NUM_PROCESSES; i++) {
//         wait();
//     }

//     // Print the process table to observe the effect of priority decay
//     printf(1, "Process Table After Running:\n");
//     printPTable();

//     exit();
// }
