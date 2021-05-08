/*
** EPITECH PROJECT, 2020
** brain_game_2
** File description:
** game mechanics
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "../include/grid.h"

int check_game(void)
{
    int p_ship = 0;
    int e_ship = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (g.player[i][j] >= 2 && g.player[i][j] <= 5)
                p_ship++;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (g.grid[i][j] == 1)
                e_ship++;
    if (p_ship == 0)
        g.win = 2;
    if (e_ship == 14)
        g.win = 1;
    return (g.win);
}

void put_result(int *tmp, int hit, int mode)
{
    char c1 = tmp[0] + 'A';
    char c2 = tmp[1] + '1';

    if (mode == 0) {
        write(1, &c1, 1);
        write(1, &c2, 1);
        g.player[tmp[1]][tmp[0]] = hit;
    } else
        g.grid[tmp[1]][tmp[0]] = hit;
}

void sink_me(int *tmp)
{
    while (g.col == 0);
    tmp[0] = g.row - 1;
    g.row = 0;
    while (g.row == 0);
    tmp[1] = g.col - 1;
    g.col = 0;
    g.row = 0;
    if (g.player[tmp[1]][tmp[0]] == 0 || g.player[tmp[1]][tmp[0]] == 6) {
        put_result(tmp, 6, 0);
        write(1, ": missed\n", 9);
        kill(g.pid, SIGUSR2);
    } else {
        put_result(tmp, 1, 0);
        write(1, ": hit\n", 6);
        kill(g.pid, SIGUSR1);
    }
}

void sink_him(char *pos)
{
    int tmp[2] = {pos[0] - 'A', pos[1] - '1'};

    if (g.row == 0) {
        g.col = 0;
        put_result(tmp, 6, 1);
        write(1, ": missed\n", 9);
    } else {
        g.row = 0;
        put_result(tmp, 1, 1);
        write(1, ": hit\n", 6);
    }
}
