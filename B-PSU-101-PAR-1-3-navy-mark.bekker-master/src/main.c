/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/my.h"
#include "../include/grid.h"

int error_handler(int ac, char **av)
{
    char *path;
    char *buf;
    int fd;
    struct stat stats;

    if (ac != 2 && ac != 3)
        return (84);
    path = av[ac - 1];
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (84);
    stat(path, &stats);
    buf = malloc(sizeof(char) * stats.st_size);
    read(fd, buf, stats.st_size);
    if (stats.st_size != 32 || check_args(buf) == 84)
        return (84);
    close(fd);
    return (check_pos(buf));
}

int my_atoi(char *s)
{
    int num = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        num *= 10;
        num += s[i] - '0';
    }
    return (num);
}

int main(int ac, char **av)
{
    int player = ac - 1;
    int sig = 0;

    if (error_handler(ac, av) == 84)
        return (84);
    copy_grid(0);
    g.win = 0;
    if (ac - 1 == 2)
        connect_player_2(sig = my_atoi(av[1]));
    else
        connect_player_1();
    write(1, "\nmy positions:\n", 15);
    print_grid(1);
    write(1, "\nenemy's positions:\n", 20);
    print_grid(2);
    if (g.win == 1)
        write(1, "\nI won\n", 7);
    else
        write(1, "\nEnemy won\n", 11);
    return (0);
}
