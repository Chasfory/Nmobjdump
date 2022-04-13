/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** file
*/

#ifndef FILE_H_
    #define FILE_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/mman.h>
    #include <unistd.h>
    #include <elf.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdbool.h>

    #include "flags.h"

static const int flags = 10;

typedef struct file_s {
    int fd;
    off_t filesize;
    void *data;
    Elf64_Ehdr *ehdr;
    char c;
} file_t;

typedef struct version_32_s {
    Elf32_Shdr *shdr;
    Elf32_Ehdr *ehdr;
    int flags;
} version_32_t;

typedef struct version_64_s {
    Elf64_Shdr *shdr;
    Elf64_Ehdr *ehdr;
    int flags;
} version_64_t;

static const int flags_tab [] = {
    BFD_NO_FLAGS,
    HAS_RELOC,
    EXEC_P,
    HAS_LINENO,
    HAS_DEBUG,
    HAS_SYMS,
    HAS_LOCALS,
    DYNAMIC,
    WP_TEXT,
    D_PAGED
};

static const char *flags_string [] = {
    "BFD_NO_FLAGS",
    "HAS_RELOC",
    "EXEC_P",
    "HAS_LINENO",
    "HAS_DEBUG",
    "HAS_SYMS",
    "HAS_LOCALS",
    "DYNAMIC",
    "WP_TEXT",
    "D_PAGED"
};

int open_file(char *file, int ac);
int get_elf_descriptor(file_t *file, char *f);
int obtain_the_elf_descriptor_64(file_t *file, char *f);
int obtain_the_elf_descriptor_32(file_t *file, char *f);
void display_64(version_64_t *version, file_t *file, char *f);
void display_section_64(char *tmp);
void display_1_64(version_64_t *version, int i, long unsigned int j);
void display_2_64(version_64_t *version, int i, file_t *file,
                long unsigned int j);
void display_3_64(version_64_t *version, int i, file_t *file,
                long unsigned int j);
void gettype_64(version_64_t *version, const char *tmp, int i);
void display_32(version_32_t *version, file_t *file, char *f);
void display_section_32(char *tmp);
void display_1_32(version_32_t *version, int i, long unsigned int j);
void display_2_32(version_32_t *version, int i, file_t *file,
                long unsigned int j);
void display_3_32(version_32_t *version, int i, file_t *file,
                long unsigned int j);
void gettype_32(version_32_t *version, const char *tmp, int i);
bool black_list(version_64_t *version, int i, char *tmp);
bool black_list_32(version_32_t *version, int i, char *tmp);
int space_display_32(int p, int i);
int space_display_64(int p, int i);

#endif /* !FILE_H_ */