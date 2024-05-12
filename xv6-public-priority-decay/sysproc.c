#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_printPTable(void)
{
  return printPTable();
}

int
sys_setPriority(void)
{
  int pid, pr;
  if(argint(0, &pid) < 0) // get the pid from the user space and store it in pid variableو  Retrieves the first argument (index 0) passed from the user space and stores it in the variable pid. If the argument is not passed, it returns -1. 
    return -1;
  if(argint(1, &pr) < 0) // get the priority from the user space and store it in pr variable
    return -1;

  return setPriority(pid, pr); // call the setPriority function with the pid and priority as arguments
  // Note: user space is the memory space that is allocated to the user process. It is different from the kernel space, which is allocated to the kernel.
}

void
sys_yield(void)
{
  return yield();
}

