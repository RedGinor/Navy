/*
** EPITECH PROJECT, 2020
** error_handler
** File description:
** handles errors
*/

#include "../include/grid.h"

grid g;

int check_args(char *buf)
{
    int num[4] = {1, 1, 1, 1};

    for (int i = 0; i < 32; i += 8) {
        if (buf[i] < '2' || buf[i] > '5')
            return (84);
        if (buf[i + 1] != ':' || buf[i + 4] != ':')
            return (84);
        if (buf[i + 2] < 'A' || buf[i + 2] > 'H' ||
            buf[i + 5] < 'A' || buf[i + 5] > 'H')
            return (84);
        if (buf[i + 3] < '1' || buf[i + 3] > '8' ||
            buf[i + 6] < '1' || buf[i + 6] > '8')
            return (84);
        num[buf[i] - '2']--;
        for (int j = 0; j < 4; j++)
            if (num[j] < 0)
                return (84);
    }
    return (0);
}

void fill_grid(char *buf, int t, int size)
{
    int chr = buf[t + 2] - buf[t + 5];
    int pos_c = buf[t + 5] - 'A';
    int num = buf[t + 3] - buf[t + 6];
    int pos_n = buf[t + 6] - '1';

    if (chr < 0) {
        chr *= -1;
        pos_c = buf[t + 2] - 'A';
    }
    if (num < 0) {
        num *= -1;
        pos_n = buf[t + 3] - '1';
    }
    for (int i = 0; i <= chr; i++)
        for (int j = 0; j <= num; j++)
            g.grid[pos_n + j][pos_c + i] = size;
}

int check_grid(char *buf)
{
    int ship = 0;
    int size = 0;

    for (int i = 0; i < 4; i++) {
        size = buf[i * 8] - '0';
        fill_grid(buf, i * 8, size);
    }
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (g.grid[i][j] != 0)
                ship++;
    if (ship != 14)
        return (84);
    return (0);
}

int check_pos(char *buf)
{
    int size = 0;
    int num = 0;
    int chr = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            g.grid[i][j] = 0;
    for (int i = 0; i < 4; i++) {
        size = buf[i * 8] - '0';
        num = buf[i * 8 + 3] - buf[i * 8 + 6];
        chr = buf[i * 8 + 2] - buf[i * 8 + 5];
        if (num != size - 1 && num != 0 && -num != size - 1)
            return (84);
        if (chr != size - 1 && chr != 0 && -chr != size - 1)
            return (84);
        if (num == chr || -num == chr)
            return (84);
    }
    return (check_grid(buf));
}
