/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** get_elf_descriptor
*/

#include "file.h"

int get_error_elf_bis(file_t *file)
{
    if (file->ehdr->e_ident[EI_MAG2] != ELFMAG2) {
        return 84;
    }
    if (file->ehdr->e_ident[EI_MAG3] != ELFMAG3) {
        return 84;
    }
    return 0;
}

int get_error_elf(file_t *file)
{
    if (file->ehdr->e_ident[EI_MAG0] != ELFMAG0) {
        return 84;
    }
    if (file->ehdr->e_ident[EI_MAG1] != ELFMAG1) {
        return 84;
    }
    return get_error_elf_bis(file);
}

int get_elf_descriptor(file_t *file, char *f)
{
    file->ehdr = (Elf64_Ehdr *)(file->data);

    if (get_error_elf(file) == 1) {
        return 84;
    }
    if (file->ehdr->e_ident[EI_CLASS] == ELFCLASS32) {
        return obtain_the_elf_descriptor_32(file, f);
    } else if (file->ehdr->e_ident[EI_CLASS] == ELFCLASS64) {
        return obtain_the_elf_descriptor_64(file, f);
    }
    return 84;
}
