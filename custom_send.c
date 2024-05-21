/*
** EPITECH PROJECT, 2023
** main
** File description:
** main template
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_macro.h"

extern self_t self;

void send_pid(int pid)
{
    int my_pid = getpid();
    int len;

    for (len = 1; pid / my_compute_power_rec(10, len - 1) >= 10; len++);
    send_nbr(len + 2, pid);
    send_nbr('P', pid);
    send_nbr(' ', pid);
    for (; len > 0; len--)
        send_nbr((my_pid / my_compute_power_rec(10, len - 1)) % 10 + 48, pid);
}

void send_result(char *m, int end_game, int pid, char **map)
{
    int x = m[0] - 64;
    int y = m[1] - 48;

    send_nbr(4, pid);
    send_nbr(end_game + 48, pid);
    send_nbr(is_hiting(map, x, y) ? 'T' : 'M', pid);
    send_nbr(m[0], pid);
    send_nbr(m[1], pid);
}
