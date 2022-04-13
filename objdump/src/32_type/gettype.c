/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** gettype
*/

#include "file.h"

#include <string.h>
#include <stdbool.h>

bool black_list_32(version_32_t *version, int i, char *tmp)
{
    return ((!version->shdr[i].sh_size
        || ((((version->shdr[i].sh_type == SHT_NOBITS)
        || (version->shdr[i].sh_type == SHT_SYMTAB)
        || (version->shdr[i].sh_type == SHT_STRTAB)
        || (version->shdr[i].sh_type == SHT_RELA)))
        && (version->shdr[i].sh_flags == 64)))
        && strcmp(&tmp[version->shdr[i].sh_name], ".dynstr") != 0);
}

void gettype_32_bis(version_32_t *version, int i)
{
    if (version->shdr[i].sh_type == SHT_REL) {
      	version->flags |= HAS_RELOC;
    }
    if (version->shdr[i].sh_type == SHT_HASH) {
      	version->flags |= D_PAGED;
    }
}

void gettype_32(version_32_t *version, const char *tmp, int i)
{
    if (version->ehdr->e_type == ET_DYN) {
    	version->flags |= DYNAMIC;
    }
    if (strcmp(".symtab", tmp) == 0) {
      	version->flags |= HAS_SYMS;
    }
    gettype_32_bis(version, i);
}
