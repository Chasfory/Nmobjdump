/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** display_64
*/

#include "file.h"

void display_result_64(version_64_t *version, char c, Elf64_Sym *sym)
{
    if (ELF64_ST_BIND(sym->st_info) == STB_LOCAL && c != '?') {
        c += 32;
    }
    if (version->second_str[0] == '\0') {
        return;
    }
    if (version->value != 0) {
        printf("%016lx %c %s\n", version->value, c, version->second_str);
    } else if (c == 'U' || c == 'w') {
        printf("%16c %c %s\n", ' ', c, version->second_str);
    }
}