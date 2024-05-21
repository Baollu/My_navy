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

void get_other_pid(char *message, self_t *self)
{
    self->other_pid = my_getnbr(message + 2);
    my_printf("enemy connected\n\n");
    usleep(1000);
    send("co", self->other_pid);
    print_turn(self);
}

void print_turn(self_t *self)
{
    my_printf("my navy:\n");
    print_map(self->map);
    my_printf("\n");
    my_printf("enemy navy:\n");
    print_map(self->other_map);
    my_printf("\n");
    if (self->player == 1)
        play(self);
    else
        wait_enemy();
}

void wait_enemy(void)
{
    my_printf("waiting for enemy's attack...\n\n");
}

void connected(self_t *self)
{
    my_printf("successfully connected to enemy\n\n");
    print_turn(self);
}

void play(self_t *self)
{
    char *input;

    my_printf("attack: ");
    input = my_get_line();
    while (my_strlen(input) != 2 || is_legal(input[0], input[1]) == 0){
        my_printf("\nwrong position\n\nattack: ");
        input = my_get_line();
    }
    my_printf("\n");
    send(input, self->other_pid);
}
