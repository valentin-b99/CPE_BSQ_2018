/*
** EPITECH PROJECT, 2018
** counters
** File description:
** counters
*/

int count_width(char *str)
{
    int width = 0;

    for (int i = 0; str[i] != '\n'; i++)
        width++;
    return (width);
}

int count_height(char *str)
{
    int height = 0;

    for (int i = 0; str[i] != 0; i++)
        if (str[i] == '\n')
            height++;
    return (height);
}

int count_linebp(char *str, int ptr)
{
    int line_bp = 0;

    for (int j = 0; j < ptr; j++)
        if (str[j] == '\n')
            line_bp++;
    return (line_bp);
}