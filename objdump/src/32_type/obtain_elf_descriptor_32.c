/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** obtain_elf_descriptor_32
*/

#include "file.h"

#include <ctype.h>
#include <stdbool.h>

void recup_elf_flags_32(file_t *file,
                            version_32_t *version, int i)
{
    char *tmp;

    tmp = ((char *)(file->data +
    version->shdr[version->ehdr->e_shstrndx].sh_offset) +
    version->shdr[i].sh_name);
    if (version->shdr[i].sh_type == SHT_SYMTAB) {
        version->flags |= HAS_SYMS;
    }
    if (black_list_32(version, i, tmp) == true) {
        return;
    }
    gettype_32(version, tmp, i);
    version->flags |= D_PAGED;
}

void print_section_32(file_t *file,
                version_32_t *version, int i)
{
    char *tmp;

    tmp = ((char *)(file->data +
    version->shdr[version->ehdr->e_shstrndx].sh_offset) +
    version->shdr[i].sh_name);
    if (black_list_32(version, i, tmp) == true) {
        return;
    }
    display_section_32(tmp);
    for (long unsigned int j = 0; j < (version->shdr[i].sh_size); j += 16) {
        display_1_32(version, i, j);
        display_2_32(version, i, file, j);
        display_3_32(version, i, file, j);
    }
}

int obtain_the_elf_descriptor_32(file_t *file, char *f)
{
    version_32_t version;

    version.flags = 0;
    version.ehdr = (Elf32_Ehdr *)file->data;
    version.shdr = (Elf32_Shdr *)(file->data + version.ehdr->e_shoff);
    if (version.ehdr->e_shoff > (long unsigned int)(file->filesize)) {
        printf("File format not recognized\n");
        return 84;
    }
    if (version.ehdr->e_type == ET_EXEC) {
        version.flags |= EXEC_P;
    }
    for (int tmp = 0; tmp < version.ehdr->e_shnum; tmp++) {
        recup_elf_flags_32(file, &version, tmp);
    }
    display_32(&version, file, f);
    for (int i = 0; i < version.ehdr->e_shnum; i++) {
        print_section_32(file, &version, i);
    }
    return 0;
}
