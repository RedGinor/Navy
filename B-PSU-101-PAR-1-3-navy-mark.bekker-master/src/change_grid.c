/*
** EPITECH PROJECT, 2020
** change_grid
** File description:
** grid manipulation
*/

#include <unistd.h>
#include "../include/grid.h"

void copy_grid(int mode)
{
    if (mode == 0) {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                g.player[i][j] = g.grid[i][j];
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                g.grid[i][j] = 0;
    }
    if (mode == 1)
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                g.print[i][j] = g.player[i][j];
    if (mode == 2)
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                g.print[i][j] = g.grid[i][j];
}

void print_grid(int player)
{
    char c = '1';

    copy_grid(player);
    write(1, " |A B C D E F G H\n-+---------------\n", 36);
    for (int i = 0; i < 8; i++, c = i + '1') {
        write(1, &c, 1);
        write(1, "|", 1);
        for (int j = 0; j < 8; j++) {
            c = g.print[i][j] + '0';
            for (; c != '.' && g.print[i][j] == 0; c = '.');
            for (; c != 'x' && g.print[i][j] == 1; c = 'x');
            for (; c != 'o' && g.print[i][j] == 6; c = 'o');
            write(1, &c, 1);
            if (j != 7)
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
}
