/*
** EPITECH PROJECT, 2024
** test
** File description:
** test
*/

#include <unistd.h>
#include <string.h>
#include "my.h"

char *my_get_line(void)
{
    char str[257];
    char temp;
    int i;

    read(0, &temp, 1);
    for (i = 0; temp != '\n'; i++){
        str[i] = temp;
        read(0, &temp, 1);
    }
    str[i] = '\0';
    return my_strdup(str);
}
