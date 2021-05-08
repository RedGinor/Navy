/*
** EPITECH PROJECT, 2020
** player1
** File description:
** player 1 part
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "../include/my.h"
#include "../include/grid.h"

void send_signal(char r, char c)
{
    struct timespec tim, tim2;

    tim.tv_sec = 0;
    tim.tv_nsec = 500;
    for (char t = 'A'; t <= r; t++) {
        kill(g.pid, SIGUSR1);
        nanosleep(&tim, &tim2);
    }
    for (char t = '1'; t <= c; t++) {
        kill(g.pid, SIGUSR2);
        nanosleep(&tim, &tim2);
    }
    kill(g.pid, SIGUSR1);
}

void ask_attack(char *buf, int player)
{
    while (1) {
        write(1, "\nattack: ", 9);
        read(0, buf, 100);
        if (buf[0] >= 'A' && buf[0] <= 'H' &&
            buf[1] >= '1' && buf[1] <= '8' && buf[2] == 10) {
            send_signal(buf[0], buf[1]);
            write(1, buf, 2);
            return;
        }
        write(1, "wrong position", 15);
    }
}

void ask_move(int player, int mode)
{
    char *buf = malloc(sizeof(char) * 100);
    char c;
    int tmp[2] = {0, 0};

    if (mode == 1 || mode == 3) {
        ask_attack(buf, player);
        pause();
        sink_him(buf);
    } else {
        write(1, "\nwaiting for enemy's attack...\n", 31);
        sink_me(tmp);
    }
}

void play_game(int player)
{
    for (int turn = 0; g.win == 0; turn++) {
        write(1, "\nmy positions:\n", 15);
        print_grid(1);
        write(1, "\nenemy's positions:\n", 20);
        print_grid(2);
        ask_move(player, player);
        if (check_game() != 0)
            return;
        ask_move(player, player + 1);
        check_game();
    }
}
