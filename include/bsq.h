/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** bsq
*/

#ifndef BSQ_H_
# define BSQ_H_

# include "my.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

# define BUFF_SIZE 4294967296
# define ERROR_EXIT 84
# define X 0
# define Y 1

void bsq(char *);
int test_sqr(char *, int, int *, int);
int test_square_dim(char *, int, int, int);
int test_is_bt(char *, int);

int count_width(char *);
int count_height(char *);
int count_linebp(char *, int);

void display_error(int);
void display_map(char *, int, int, int);
void test_char(char *, int);
void test_errors(char *);
int pass_fln(char *);
void test_char_valid(char *, int, int, int);

#endif /* !BSQ_H_ */
