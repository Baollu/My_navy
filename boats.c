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
#include "my_macro.h"

void place_char(char **tab, int x, int y, char c)
{
    x = x * 2;
    y = y + 1;
    tab[y][x] = c;
}

void place_boat(char **tab, char *start, char *end)
{
    int start_x = start[0] - 64;
    int start_y = start[1] - 48;
    int end_x = end[0] - 64;
    int end_y = end[1] - 48;
    char letter = (end_x - start_x) + (end_y - start_y) + 49;

    for (int i = start_y; i != end_y + 1; i++){
        for (int j = start_x; j != end_x + 1; j++){
            place_char(tab, j, i, letter);
        }
    }
}

void place_boats(char **tab, char **file)
{
    for (int i = 0; file[i] != NULL; i += 3){
        place_boat(tab, file[i + 1], file[i + 2]);
    }
}

int is_hiting(char **map, int x, int y)
{
    char chr = get_tile(map, x, y);

    if ((chr >= '0' && chr <= '9') || chr == 'x')
        return 1;
    else
        return 0;
}
