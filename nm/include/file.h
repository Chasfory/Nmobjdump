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
    Elf32_Sym *sym;
    unsigned char *str;
    unsigned char *second_str;
    Elf32_Addr value;
} version_32_t;

typedef struct version_64_s {
    Elf64_Shdr *shdr;
    Elf64_Ehdr *ehdr;
    Elf64_Sym *sym;
    unsigned char *str;
    unsigned char *second_str;
    Elf64_Addr value;
} version_64_t;

int open_file(char *file, int ac);
int get_elf_descriptor(file_t *file);
int obtain_the_elf_descriptor_64(file_t *file);
int obtain_the_elf_descriptor_32(file_t *file);
void display_result_64(version_64_t *version, char c, Elf64_Sym *sym);
char gettype_64(Elf64_Sym *sym, Elf64_Shdr *shdr);
void display_result_32(version_32_t *version, char c, Elf32_Sym *sym);
char gettype_32(Elf32_Sym *sym, Elf32_Shdr *shdr);

#endif /* !FILE_H_ */