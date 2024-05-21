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

int check_arg(int argc, char **argv)
{
    char **file;
    char *pre_file;

    if (argc != 2 && argc != 3)
        return 84;
    pre_file = read_file(argc == 2 ? argv[1] : argv[2]);
    if (pre_file == NULL)
        return 84;
    file = my_str_to_word_array(pre_file);
    if (check_pos(file) == 84)
        return 84;
    if (check_contact(file) == 84)
        return 84;
    if (check_collision(argc == 2 ? argv[1] : argv[2]) == 84)
        return 84;
    return 0;
}
