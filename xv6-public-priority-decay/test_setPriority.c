#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[]){
    // printPTable();

    // int ppid = getppid();
    // setPriority(getpid(), 10);
   
    // // Print parent process ID
    // printf(1, "Parent Process ID: %d\n", ppid);
   
    // // Create a child process
    // int pid = fork();
    // if (pid < 0) {
    //     printf(1, "Fork Failure");
    //     exit();
    // } else if (pid == 0) {
    //     printPTable();
    //     // Child process
    //     printf(1, "Child Process: My PID = %d, My PPID = %d\n", getpid(), getppid());
    //     // setPriority(getppid(), 7);
    //     wait();
    // } else {
    //     // Parent process
    //     setPriority(4, 7);
    //     printPTable();
    //     sleep(20);
    //     printf(1, "Parent Process: My PID = %d, My PPID = %d\n", getpid(), getppid());
    //     printPTable();
       
    //     // Wait for the child process to terminate
    //     exit();
    // }


    int pid = getpid();
    // valid pid and priority
    int valid = setPriority(pid, 7);
    if(valid != 0)
        printf(2, "error in setting priority");
    else    
        printf(1, "priority is set successfully.\n");
    printPTable();

    valid = setPriority(pid, 8);
    if(valid != 0)
        printf(2, "error in setting priority");
    else    
        printf(1, "priority is set successfully.\n");
    printPTable();

    // invalid pid and valid priority
    valid = setPriority(-1, 1);
    if(valid != 0)
        printf(2, "error in setting priority: Invalid PID\n");
    else    
        printf(1, "priority is set successfully.");
    // valid pid and invalid priority
    valid = setPriority(pid, -1);
    if(valid != 0)
        printf(2, "error in setting priority: Invalid Priority\n");
    else    
        printf(1, "priority is set successfully.");
    // invalid pid and invalid priority
    valid = setPriority(-1, 11);
    if(valid != 0)
        printf(2, "error in setting priority: Both priority and PID invalid\n");
    else    
        printf(1, "priority is set successfully.");
    exit();
}

