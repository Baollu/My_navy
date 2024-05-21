/*
** EPITECH PROJECT, 2024
** map
** File description:
** map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int have_letter(char *tab)
{
    int j = 0;

    for (j = 2; tab[j] != '\0'; j++){
        if (is_in_str(tab[j], "ox. \n") == 0){
            return 1;
        }
    }
    return 0;
}

char get_tile(char **map, int x, int y)
{
    return map[1 + y][2 * x];
}

int check_win(char **tab)
{
    int i = 0;

    for (i = 2; tab[i] != NULL; i++){
        if (have_letter(tab[i]) == 1){
            return 0;
        }
    }
    return 1;
}

int is_legal(char x, char y)
{
    if (y < '1' || y > '8')
        return 0;
    if (x < 'A' || x > 'H')
        return 0;
    return 1;
}
