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

void get_bin(int *binary, int nbr)
{
    for (int i = 7; i > -1; i--){
        binary[i] = nbr % 2;
        nbr = nbr >> 1;
    }
}

void send_bin(int *binary, int pid)
{
    for (int i = 0; i < 8; i++){
        kill(pid, binary[i] == 1 ? 12 : 10);
        usleep(3000);
    }
}

void send_nbr(int nbr, int pid)
{
    int binary[8];

    get_bin(binary, nbr);
    send_bin(binary, pid);
}

void send(char *code, int pid)
{
    send_nbr(my_strlen(code), pid);
    for (int i = 0; code[i]; i++)
        send_nbr(code[i], pid);
}
