/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** open_file
*/

#include "file.h"

int open_file(char *file, int ac)
{
    file_t f;

    f.fd = open(file, O_RDONLY);
    if (f.fd == -1) {
        printf("objdump: '%s': No such file\n", file);
        return 84;
    }
    f.filesize = lseek(f.fd, 0, SEEK_END);
    f.data = mmap(NULL, f.filesize, PROT_READ, MAP_PRIVATE, f.fd, 0);
    get_elf_descriptor(&f, file);
    return 0;
}
