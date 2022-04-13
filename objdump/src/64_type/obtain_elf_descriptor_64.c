/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** obtain_elf_descriptor_64
*/

#include <ctype.h>
#include <stdbool.h>

#include "file.h"

void recup_elf_flags_64(file_t *file,
                        version_64_t *version, long unsigned int i)
{
    char *tmp;

    tmp = ((char *)(file->data +
    version->shdr[version->ehdr->e_shstrndx].sh_offset) +
    version->shdr[i].sh_name);
    if (version->shdr[i].sh_type == SHT_SYMTAB) {
        version->flags |= HAS_SYMS;
    }
    if (black_list(version, i, tmp) == true) {
        return;
    }
    gettype_64(version, tmp, i);
    version->flags |= D_PAGED;
}

void print_section_64(file_t *file,
                version_64_t *version, int i)
{
    char *tmp;

    tmp = ((char *)(file->data +
    version->shdr[version->ehdr->e_shstrndx].sh_offset) +
    version->shdr[i].sh_name);
    if (black_list(version, i, tmp) == true) {
        return;
    }
    display_section_64(tmp);
    for (long unsigned int j = 0; j < (version->shdr[i].sh_size); j += 16) {
        display_1_64(version, i, j);
        display_2_64(version, i, file, j);
        display_3_64(version, i, file, j);
    }
}

int obtain_the_elf_descriptor_64(file_t *file, char *f)
{
    version_64_t version;

    version.flags = 0;
    version.ehdr = (Elf64_Ehdr *)file->data;
    version.shdr = (Elf64_Shdr *)(file->data + version.ehdr->e_shoff);
    if (version.ehdr->e_shoff > (long unsigned int)(file->filesize)) {
        printf("File format not recognized\n");
        return 84;
    }
    if (version.ehdr->e_type == ET_EXEC) {
        version.flags |= EXEC_P;
    }
    for (int tmp = 0; tmp < version.ehdr->e_shnum; tmp++) {
        recup_elf_flags_64(file, &version, tmp);
    }
    display_64(&version, file, f);
    for (int i = 0; i < version.ehdr->e_shnum; i++) {
        print_section_64(file, &version, i);
    }
    return 0;
}
