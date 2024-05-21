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

int bits_to_int(int *bits)
{
    int nbr = 0;

    for (int i = 0; i < 8; i++)
        nbr = nbr * 2 + bits[i];
    return nbr;
}

void decode(int nbr, int len)
{
    static char message[257];
    static int nbr_letter_received = 0;

    message[nbr_letter_received] = nbr;
    nbr_letter_received++;
    if (nbr_letter_received == len){
        message[len] = '\0';
        message_received(message, NULL);
        nbr_letter_received = 0;
    }
}

void bit_received(int bit)
{
    static int bits[8];
    static int nbr_bit_received = 0;
    static int len = 0;

    bits[nbr_bit_received % 8] = bit;
    nbr_bit_received++;
    if (nbr_bit_received < 8){
        return;
    }
    if (nbr_bit_received == 8){
        bits[nbr_bit_received - 1] = bit;
        len = bits_to_int(bits);
        return;
    }
    if (nbr_bit_received % 8 == 0){
        decode(bits_to_int(bits), len);
        if (nbr_bit_received == (1 + len) * 8)
            nbr_bit_received = 0;
    }
}

void sa_usr1(int)
{
    bit_received(0);
}

void sa_usr2(int)
{
    bit_received(1);
}
