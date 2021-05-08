/*
** EPITECH PROJECT, 2020
** sigaction_extra
** File description:
** extras
*/

#include <unistd.h>
#include "../include/my.h"
#include "../include/grid.h"

void listener(int sig, siginfo_t *info, void *context)
{
    pid_t pid = getpid();

    if (sig == SIGUSR1) {
        write(1, "\nenemy connected\n", 17);
        g.pid = info->si_pid;
        pid = g.pid;
        kill(pid, SIGUSR2);
    }
    if (sig == SIGUSR2) {
        write(1, "my_pid: ", 8);
        put_pid(pid);
        write(1, "\nsuccessfully connected\n", 24);
    }
}

void reciever(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1)
        g.row++;
    if (sig == SIGUSR2)
        g.col++;
}

