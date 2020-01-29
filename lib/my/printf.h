/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** printf.h
*/

#ifndef PSU_MY_PRINTF_2019_PRINTF_H
#define PSU_MY_PRINTF_2019_PRINTF_H

typedef struct tag
{
    char tag;
    void (*func)();
} tag;

typedef struct flag
{
    char flag;
    int exist;
    int width;
} flag;

int get_mult(long long int i);
int my_put_octal(int i);

void print_percent(va_list args, flag **flags, int precision, int width);
void print_dec(va_list args, flag **flags, int precision, int width);
void print_double(va_list args, flag **flags, int precision, int width);
void print_char(va_list args, flag **flags, int precision, int width);
void print_str(va_list args, flag **flags, int precision, int width);
void print_unprint_str(va_list args, flag **flags, int precision, int width);
void print_pointer(va_list args, flag **flags, int precision, int width);
void print_hex(va_list args, flag **flags, int precision, int width);
void print_unsigned(va_list args, flag **flags, int precision, int width);
void print_all(va_list args, flag **flags, int precision, int width);
void (*get_print_func(char const c))();
void print_binary(va_list args, flag **flags, int precision, int width);
void print_octal(va_list args, flag **flags, int precision, int width);

int is_flag(char const c);
void active_minus_flag(flag **flags, char c);
void active_plus_flag(flag **flags, char c);
void active_space_flag(flag **flags, char c);
void active_zero_flag(flag **flags, char c);

flag** create_flags_table(int size);
int get_width_or_precision(char *str, char **endptr);
int detect_flags(char **str, flag **flags, int length);
int manage_precision(char **endptr);

static const tag TAGS[] =
{
    {'d', &print_dec},
    {'i', &print_dec},
    {'%', &print_percent},
    {'f', &print_double},
    {'c', &print_char},
    {'s', &print_str},
    {'S', &print_unprint_str},
    {'p', &print_pointer},
    {'x', &print_hex},
    {'u', &print_unsigned},
    {'b', &print_binary},
    {'o', &print_octal},
    {-1, 0}
};

#endif