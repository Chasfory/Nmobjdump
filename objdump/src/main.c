/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** nm
*/

#include "file.h"

int files(char **av, int ac)
{
    for (int i = 1; av[i]; i++) {
        open_file(av[i], ac);
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2) {
        return open_file("a.out", 1);
    }
    return files(av, ac);
}
