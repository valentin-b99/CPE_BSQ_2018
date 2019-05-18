/*
** EPITECH PROJECT, 2018
** displays
** File description:
** displays
*/

#include "include/bsq.h"
#include "include/errors.h"

void display_error(int error)
{
    int i = 1;

    while (i != error && i < 136)
        i++;
    if (i < 135) {
        my_putstr(errors[i - 1].msg);
        my_putchar('\n');
        exit(ERROR_EXIT);
    }
}

void display_map(char *str, int ptr, int width, int width_tot)
{
    int i = 0;
    int i_x = 0;
    int line = 0;
    int line_bp = count_linebp(str, ptr);

    while (str[i] != 0) {
        if (i_x >= ptr && i_x <= ptr + width - 1 && line < width &&
        str[i] != '\n') {
            write(1, "x", 1);
        } else {
            write(1, &str[i], 1);
        }
        i_x++;
        if (str[i] == '\n' && i >= ptr) {
            i_x = (width_tot + 1) * line_bp;
            line++;
        }
        i++;
    }
}