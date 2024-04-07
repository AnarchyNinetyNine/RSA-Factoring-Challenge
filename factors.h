#ifndef _FACTORS_H_
#define _FACTORS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

char *read_textfile(const char *filename, size_t letters);
char **fill_array(char **arr, char *placeholder, size_t wc);
char **_strtok(char *str);
char *tokenizer(char **placeholder);
size_t wc(char *placeholder);

#endif /* _FACTORS_H_ */
