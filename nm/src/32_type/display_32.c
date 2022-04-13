/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** display_32
*/

#include "file.h"

void display_result_32(version_32_t *version, char c, Elf32_Sym *sym)
{
    if (ELF32_ST_BIND(sym->st_info) == STB_LOCAL && c != '?') {
        c += 32;
    }
    if (version->second_str[0] == '\0') {
        return;
    }
    if (version->value != 0) {
        printf("%016x %c %s\n", version->value, c, version->second_str);
    } else if (c == 'U' || c == 'w') {
        printf("%16c %c %s\n", ' ', c, version->second_str);
    }
}