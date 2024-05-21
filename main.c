/*
** EPITECH PROJECT, 2023
** main
** File description:
** main template
*/

#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_macro.h"

void end_game(int winner, self_t *self)
{
    my_printf("my navy:\n");
    print_map(self->map);
    my_printf("\n");
    my_printf("enemy navy:\n");
    print_map(self->other_map);
    my_printf("\n");
    if (winner == 0){
        send("end", self->other_pid);
        my_printf("Enemy won");
    } else {
        my_printf("I won");
    }
    kill(getpid(), 2);
}

void result(char *m, int end_game, self_t *self)
{
    int x = m[1] - 64;
    int y = m[2] - 48;

    my_printf("result: %c%c:%s\n\n",
        m[1], m[2], m[0] == 'M' ? "missed" : "hit");
    place_char(self->other_map, x, y, m[0] == 'T' ? 'x' : 'o');
    if (self->player == 1 && end_game == 0)
        wait_enemy();
}

void attack(char *m, self_t *self)
{
    int x = m[0] - 64;
    int y = m[1] - 48;

    place_char(self->map, x, y, is_hiting(self->map, x, y) ? 'x' : 'o');
    my_printf("result: %c%c:%s\n\n",
        m[0], m[1], is_hiting(self->map, x, y) ? "hit" : "missed");
    usleep(10000);
    send_result(m, check_win(self->map), self->other_pid, self->map);
    usleep(10000);
    if (check_win(self->map)){
        end_game(0, self);
        return;
    }
    if (self->player == 1){
        send("turn", self->other_pid);
        print_turn(self);
        usleep(5000);
    } else {
        play(self);
    }
}

void message_received(char *message, self_t *self_address)
{
    static self_t *self;

    if (my_strcmp(message, "setup") == 0)
        self = self_address;
    if (message[0] == 'P')
        get_other_pid(message, self);
    if (my_strcmp(message, "co") == 0)
        connected(self);
    if (my_strcmp(message, "play") == 0)
        play(self);
    if (my_strcmp(message, "turn") == 0)
        print_turn(self);
    if (my_strcmp(message, "end") == 0)
        end_game(1, self);
    if (message[1] >= '0' && message[1] <= '9')
        attack(message, self);
    if (message[1] == 'T' || message[1] == 'M')
        result(message + 1, message[0] - 48, self);
}

int main(int argc, char **argv)
{
    self_t self;

    if (check_arg(argc, argv) == 84)
        return 84;
    signal(SIGUSR1, &sa_usr1);
    signal(SIGUSR2, &sa_usr2);
    my_printf("my_pid: %d\n\n", getpid());
    self.player = (argc == 2 ? 1 : 2);
    if (self.player == 2){
        self.other_pid = my_getnbr(argv[1]);
        send_pid(self.other_pid);
    } else {
        my_printf("waiting for ennemy connection...\n\n");
    }
    self.map = generate_map(argc == 3 ? argv[2] : argv[1]);
    self.other_map = create_map("map");
    message_received("setup", &self);
    while (1)
        usleep(100);
    return 0;
}
