/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** display_64
*/

#include "file.h"

void display_section_64(char *tmp)
{
    printf("Contents of section %s:\n", tmp);
}

void display_1_64(version_64_t *version, int i, long unsigned int j)
{
    printf(" %04lx ", version->shdr[i].sh_addr + j);
}

void display_2_64(version_64_t *version, int i, file_t *file,
                long unsigned int j)
{
    unsigned char *values = (unsigned char *)
    (version->shdr[i].sh_offset + file->data);

    for (int tmp = 0; tmp < 16; tmp++) {
        if ((tmp + j) >= version->shdr[i].sh_size) {
            printf("  ");
        } else {
            printf("%02x", values[tmp + j]);
        }
        if ((tmp + 1) % 4 == 0) {
            printf(" ");
        }
    }
    printf(" ");
}

void display_3_64(version_64_t *version, int i, file_t *file,
                long unsigned int j)
{
    char *values = (char *)(version->shdr[i].sh_offset + file->data);

    for (int tmp = 0; tmp < 16; tmp++) {
        if ((tmp + j) >= version->shdr[i].sh_size) {
            printf(" ");
        } else {
            printf("%c", isprint(values[tmp + j]) ? values[tmp + j] : '.');
        }
    }
    printf("\n");
}

void display_64(version_64_t *version, file_t *file, char *f)
{
    int p = 0;

    printf("\n%s:     file format elf64-x86-64\n", f);
    printf("architecture: i386:x86-64, flags 0x%08x:\n", version->flags);
    for (int i = 0; i < flags; i++) {
        if (version->flags & flags_tab[i]) {
            p = space_display_64(p, i);
        }
    }
    printf("\nstart address 0x%016lx\n\n", version->ehdr->e_entry);
}
