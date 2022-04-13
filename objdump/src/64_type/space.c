/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** space
*/

#include "file.h"

int space_display_64(int p, int i)
{
    if (p == 1) {
        printf(", ");
        p = 0;
    }
    printf("%s", flags_string[i]);
    p = 1;
    return p;
}
