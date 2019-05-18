/*
** EPITECH PROJECT, 2018
** test_errors
** File description:
** test_errors
*/

#include "include/bsq.h"

int pass_fln(char *buff)
{
    int j = 0;

    while (buff[j] != '\n')
        j++;
    return (j);
}

void test_char(char *buff, int i)
{
    if (buff[i] == 0)
        exit(ERROR_EXIT);
}

void test_char_valid(char *buff, int i, int nb_char_tmp, int nb_char)
{
    if (buff[i] != '.' && buff[i] != 'o' && buff[i] != '\n' &&
        (buff[i] < '0' || buff[i] > '9'))
        exit(ERROR_EXIT);
    if (buff[i] == '\n' && nb_char_tmp != nb_char)
        exit(ERROR_EXIT);
}

void test_errors(char *buff)
{
    int nb_line = my_getnbr(buff);
    int nb_line_tmp = 0;
    int nb_char = 0;
    int nb_char_tmp = 0;
    int j = 0;

    test_char(buff, 0);
    j = pass_fln(buff);
    for (int i = j + 1; buff[i] != '\n'; i++)
        nb_char++;
    for (int i = j + 1; buff[i] != 0; i++) {
        test_char_valid(buff, i, nb_char_tmp, nb_char);
        if (buff[i] == '\n') {
            nb_line_tmp++;
            nb_char_tmp = -1;
        }
        nb_char_tmp++;
    }
    if (nb_line_tmp != nb_line)
        exit(ERROR_EXIT);
}