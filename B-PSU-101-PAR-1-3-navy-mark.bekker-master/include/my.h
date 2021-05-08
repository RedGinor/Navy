/*
** EPITECH PROJECT, 2020
** header
** File description:
** includes
*/

#include <signal.h>

int check_args(char *buf);

int check_grid(char *buf);

int check_pos(char *buf);

void print_grid(int player);

void copy_grid(int mode);

void connect_player_1(void);

void connect_player_2(int tmp);

void play_game(int player);

void listener(int sig, siginfo_t *info, void *context);

void reciever(int sig, siginfo_t *info, void *context);

void put_pid(int PID);

int check_game(void);

void put_result(int *tmp, int hit, int mode);

void sink_me(int *tmp);

void sink_him(char *pos);
