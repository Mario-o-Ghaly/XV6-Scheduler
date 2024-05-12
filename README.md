# XV6-Scheduler

This project implements a priority-based scheduler for the xv6 operating system. xv6, a simple Unix-like operating system, does not include a scheduler by default. The implemented scheduler assigns priorities to processes in the range of 1 to 10, with 1 being the highest priority. The default priority setting for processes is 5.

## Features
- Priority-based scheduling: Priorities are assigned to processes, allowing higher-priority processes to execute before lower-priority ones.
- Priority-with-decay scheduling: Same as the priority-based, but with a modification that whenever a priority holds the CPU, its priority decays by one degree(increases in value).
- System calls added:
 - printPTable(): Prints the name, PID, status, and priority of all processes except for the "unused".
 - setPriority(int pid, int priority): Sets the priority of the process with the given process ID to the specified priority.
 - yield(): Yields the CPU, allowing other processes to execute.

## Usage
Building xv6:
Download the whole folder, and inside it open the terminal and run the following commands:
 -  make clean
 -  make
 -  make qemu

## Testing
- Compile and run the provided test program test.c to verify the functionality of the priority-based scheduler.
- test_setPriority.c verifies the functionality of the setPriority system call together with printPTable.

Enjoy Learning :))))
