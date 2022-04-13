/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** gettype
*/

#include "file.h"

char gettype_64_four(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
        && shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR)) {
        return 'T';
    } else if ((shdr[sym->st_shndx].sh_type == SHT_DYNAMIC) ||
        (shdr[sym->st_shndx].sh_type == SHT_INIT_ARRAY) ||
        (shdr[sym->st_shndx].sh_type == SHT_FINI_ARRAY)) {
        return 'D';
    }
    return '?';
}

char gettype_64_tree(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    if (shdr[sym->st_shndx].sh_type == SHT_NOBITS
        && shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) {
        return 'B';
    } else if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
            && shdr[sym->st_shndx].sh_flags == SHF_ALLOC) {
        return 'R';
    } else {
        if (shdr[sym->st_shndx].sh_type == SHT_PROGBITS
            && shdr[sym->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) {
            return 'D';
        }
    }
    return gettype_64_four(sym, shdr);
}

char gettype_64_bis(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    if (sym->st_shndx == SHN_UNDEF) {
        return 'U';
    } else if (sym->st_shndx == SHN_ABS) {
        return 'A';
    } else {
        if (sym->st_shndx == SHN_COMMON) {
            return 'C';
        }
    }
    return gettype_64_tree(sym, shdr);
}

char gettype_64(Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    if (ELF64_ST_BIND(sym->st_info) == STB_GNU_UNIQUE) {
        return 'u';
    } else if (ELF64_ST_BIND(sym->st_info) == STB_WEAK &&
        ELF64_ST_TYPE(sym->st_info) == STT_OBJECT) {
        return (sym->st_shndx == SHN_UNDEF) ? 'v' : 'V';
    } else {
        if (ELF64_ST_BIND(sym->st_info) == STB_WEAK) {
            return (sym->st_shndx == SHN_UNDEF) ? 'w' : 'W';
        }
    }
    return gettype_64_bis(sym, shdr);
}