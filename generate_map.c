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

char *read_file(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    char *str;
    char temp = '0';
    int len;

    if (fd == -1)
        return NULL;
    for (len = 0; read(fd, &temp, 1); len++);
    close(fd);
    fd = open(file_name, O_RDONLY);
    str = malloc(sizeof(char) * (len + 1));
    read(fd, str, len);
    str[len] = '\0';
    return str;
}

char **array_2d(char *buffer)
{
    int i = 0;
    int z = 0;
    char **tab = malloc(sizeof(char *) * (10 + 1));

    for (i = 0; i != 10; i++){
        tab[i] = malloc(sizeof(char) * 18 + 1);
        for (int j = 0; j != 18; j++){
            tab[i][j] = buffer[z];
            z++;
        }
        tab[i][18] = '\0';
    }
    tab[i] = NULL;
    return tab;
}

char **create_map(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer;
    char **tab;

    buffer = malloc(sizeof(char) * (180 + 1));
    read(fd, buffer, 180);
    buffer[180] = '\0';
    tab = array_2d(buffer);
    return tab;
}

char **generate_map(char *pos)
{
    char **map = create_map("map");

    place_boats(map, my_str_to_word_array(read_file(pos)));
    return map;
}

void print_map(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++){
        my_printf("%s", tab[i]);
    }
}
