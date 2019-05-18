/*
** EPITECH PROJECT, 2018
** bsq
** File description:
** bsq
*/

#include "include/bsq.h"

int test_is_bt(char *str, int ptr)
{
    int width = 0;

    for (int i = ptr; str[i] == '.'; i++)
        width++;
    return (width);
}

int test_square_dim(char *str, int ptr, int width, int width_tot)
{
    int i = 0;
    int i_x = 0;
    int line = 0;
    int line_bp = count_linebp(str, ptr);

    while (str[i] != 0) {
        if (i_x >= ptr && i_x <= ptr + width - 1 && line < width &&
            str[i] != '.')
            return (0);
        i_x++;
        if (str[i] == '\n' && i >= ptr) {
            i_x = (width_tot + 1) * line_bp;
            line++;
        }
        i++;
    }
    return (1);
}

int test_sqr(char *str, int ptr, int *sz_tot, int width_test)
{
    int width_f = width_test;

    while (width_f < sz_tot[X] && width_f < sz_tot[Y]) {
        if (test_square_dim(str, ptr, width_f, sz_tot[X]))
            width_f++;
        else
            return (width_f - 1);
    }
}

void bsq(char *str)
{
    int ptr_g = 0;
    int ptr_i = 0;
    int sz_tot[2];
    sz_tot[0] = count_width(str);
    sz_tot[1] = count_height(str);
    int wi_act = 0;
    int wi_tmp;
    int line = 1;

    while (line <= sz_tot[Y] - wi_act) {
        wi_tmp = test_is_bt(str, ptr_i);
        if (wi_tmp > wi_act && ptr_i < (sz_tot[X] + 1) * line - wi_act &&
        (wi_tmp = test_sqr(str, ptr_i, sz_tot, wi_act + 1)) > wi_act) {
            wi_act = wi_tmp;
            ptr_g = ptr_i;
        }
        if (str[ptr_i] == '\n')
            line++;
        ptr_i++;
    }
    display_map(str, ptr_g, wi_act, sz_tot[X]);
}

int main(int ac, char **av)
{
    char *buff = malloc(sizeof(char) * BUFF_SIZE + 1);
    int len;
    int offset = 0;
    int file = open(av[1], O_RDONLY);
    int i = 0;

    if (ac != 2)
        display_error(134);
    display_error(errno);
    while ((len = read(file, buff + offset, BUFF_SIZE - offset)) > 0)
        offset = offset + len;
    test_errors(buff);
    display_error(errno);
    i = pass_fln(buff);
    test_char(buff, i + 1);
    bsq(buff + i + 1);
    free(buff);
    close(file);
    return (0);
}