/*
** EPITECH PROJECT, 2019
** MY.H
** File description:
** prototypes of all libmy functions
*/

void my_putchar(char c);
int is_num(char const c);
int is_alpha(char c);
int my_isneg(int nb);
int my_put_nbr(long long int nb, int precision);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
long long int mpow(long n, long p);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem (char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
int get_nb_spe_chars(char const *str);
int is_special_char(char c);
int my_putnbr_base(int nbr, char const *base);
void show_line(char const *str, int size);
int add_spaces_and_zero(char const *str, int j);
int my_putnbr_base_without_zero(int nbr, char const *base);
int get_int_with_default_conditions(int result);
void set_alignment(int spaces);
int my_put_double(double d, int precision);
char *my_strdup(char const *src);
int print_error(char const *error);
int my_strtol(char *str, char **endptr);
void *my_memset(char *pointer, int value, int size);
int my_printf(char const *str, ...);
char *my_itos(int i);
char **my_str_split(char *str, char to_find);
char **my_str_split2char(char *str, char to_find, char to_find2);
void arr2d_destroy(void **data);