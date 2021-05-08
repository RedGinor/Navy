/*
** EPITECH PROJECT, 2020
** get_info
** File description:
** gets signals from users
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/grid.h"
#include "../include/my.h"

void put_pid(int PID)
{
    int r = PID % 10;
    char c = '0';

    PID /= 10;
    if (PID > 0)
        put_pid(PID);
    c += r;
    write(1, &c, 1);
}

void connect_player_2(int tmp)
{
    pid_t pid = tmp;
    struct sigaction *sig;

    g.pid = tmp;
    sig = malloc(sizeof(struct sigaction));
    sig->sa_flags = SA_SIGINFO;
    sig->sa_sigaction = &listener;
    sigaction(SIGUSR2, sig, NULL);
    kill(pid, SIGUSR1);
    pause();
    sig->sa_sigaction = &reciever;
    sigaction(SIGUSR1, sig, NULL);
    sigaction(SIGUSR2, sig, NULL);
    play_game(2);
}

void connect_player_1(void)
{
    pid_t pid = getpid();
    struct sigaction *sig;

    sig = malloc(sizeof(struct sigaction));
    sig->sa_flags = SA_SIGINFO;
    sig->sa_sigaction = &listener;
    write(1, "my_pid: ", 8);
    put_pid(pid);
    write(1, "\nwaiting for enemy connection...\n", 33);
    sigaction(SIGUSR1, sig, NULL);
    pause();
    sig->sa_sigaction = &reciever;
    sigaction(SIGUSR1, sig, NULL);
    sigaction(SIGUSR2, sig, NULL);
    play_game(1);
}
