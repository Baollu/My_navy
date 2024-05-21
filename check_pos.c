/*
** EPITECH PROJECT, 2024
** check
** File description:
** pos
*/

#include <stddef.h>
#include "my.h"
#include "my_macro.h"

int same_boats(int *nbr, int boat)
{
    for (int i = 0; i < 4; i++){
        if (nbr[i] == boat)
            return 0;
    }
    return 1;
}

int nbr_boats(char **file)
{
    int nbr[4] = {0};

    for (int i = 0; i < 12; i += 3){
        nbr[i / 3] = file[i][0] - 48;
    }
    for (int i = 0; i < 4; i++){
        if (same_boats(nbr, i + 2) == 1){
            return 1;
        }
    }
    return 0;
}

int check_pos(char **file)
{
    int array_len;

    for (array_len = 0; file[array_len] != NULL; array_len++);
    if (array_len != 12)
        return 84;
    for (int i = 0; file[i] != NULL; i += 3){
        if (file[i][0] < '2' || file[i][0] > '5')
            return 84;
    }
    if (nbr_boats(file) == 1)
        return 84;
    return 0;
}
