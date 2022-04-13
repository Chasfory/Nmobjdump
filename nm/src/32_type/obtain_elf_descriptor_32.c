/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-laetitia.bousch
** File description:
** obtain_elf_descriptor_32
*/

#include "file.h"

void the_display_recup_elf_descriptor_32(file_t *file,
                            version_32_t *version, int tmp)
{
    if (version->shdr[tmp].sh_type == SHT_SYMTAB) {
        version->sym = version->shdr[tmp].sh_offset + file->data;
        for (long unsigned int i = 0; i < (version->shdr[tmp].sh_size /
            version->shdr[tmp].sh_entsize); i++) {
            version->value = version->sym[i].st_value;
            version->str = (unsigned char *)
            (version->shdr[version->shdr[tmp].sh_link].sh_offset + file->data);
            version->second_str = &version->str[version->sym[i].st_name];
            file->c = gettype_32(&version->sym[i], version->shdr);
            display_result_32(version, file->c, &version->sym[i]);
        }
    }
}

int obtain_the_elf_descriptor_32(file_t *file)
{
    version_32_t version;

    version.ehdr = (Elf32_Ehdr *)file->data;
    version.shdr = (Elf32_Shdr *)(file->data + version.ehdr->e_shoff);
    if (version.ehdr->e_shoff > (long unsigned int)(file->filesize)) {
        printf("File format not recognized\n");
        return 84;
    }
    for (int tmp = 0; tmp < version.ehdr->e_shnum; tmp++) {
        the_display_recup_elf_descriptor_32(file, &version, tmp);
    }
    return 0;
}