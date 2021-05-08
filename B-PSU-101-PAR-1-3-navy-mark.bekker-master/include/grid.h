/*
** EPITECH PROJECT, 2020
** grid
** File description:
** grids
*/

typedef struct g_grid
{
    int grid[8][8];
    int print[8][8];
    int player[8][8];
    int win;
    int pid;
    int row;
    int col;
} grid;

extern grid g;
