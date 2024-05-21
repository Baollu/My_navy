/*
** EPITECH PROJECT, 2024
** contact
** File description:
** contact
*/

#include <stddef.h>
#include "my.h"
#include "my_macro.h"

int check_contact(char **file)
{
    int pos[2] = {0};
    int result = 0;

    for (int i = 0; i < 12; i += 3){
        pos[0] = ((file[i + 2][0]) - (file[i + 1][0]));
        pos[1] = (file[i + 2][1] - file[i + 1][1]);
        result = pos[1] + pos[0];
        if ((result + 1) != (file[i][0] - 48)){
            return 84;
        }
    }
    return 0;
}

int check_collision(char *file_name)
{
    char **tab = generate_map(file_name);
    int boats = 0;

    for (int y = 2; tab[y] != NULL; y++){
        for (int x = 2; tab[y][x] != '\0'; x++){
            boats += is_in_str(tab[y][x], "2345");
        }
    }
    if (boats != 14)
        return 84;
    return 0;
}
