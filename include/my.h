/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#ifndef MY_PROTOTYPE
    #define MY_PROTOTYPE
    #define NBR_FUNCTION 11
    #include <stdarg.h>

struct option_s {
    char letter;
    int plus;
    int space;
    int minus;
    int width;
    int pre;
    int zero;
    int hash;
    int h;
    int L;
    int l;
};


typedef struct self_s {
    int other_pid;
    char **map;
    char **other_map;
    int player;
} self_t;


void sa_usr1(int signo);
void sa_usr2(int signo);
void send(char *code, int pid);
void send_nbr(int nbr, int pid);
void send_pid(int pid);
void send_result(char *m, int end_game, int pid, char **map);
void message_received(char *message, self_t *self_address);
int check_win(char **tab);
char get_tile(char **map, int x, int y);
char **create_map(char *file);
char **generate_map(char *pos);
void print_map(char **tab);
void wait_enemy(void);
void connected(self_t *self);
void place_char(char **tab, int x, int y, char c);
void place_boats(char **tab, char **file);
int is_legal(char x, char y);
int is_hiting(char **map, int x, int y);
char *my_get_line(void);
int check_arg(int argc, char **argv);
void get_other_pid(char *message, self_t *self);
void play(self_t *self);
void print_turn(self_t *self);
char *read_file(char *file_name);
int check_pos(char **file);
int check_contact(char **file);
int check_collision(char *file_name);

char **my_str_to_word_array(char const *str);
int my_base_len(int *Nbr);
void my_put_base(int *Nbr, int base, int uppercase);
void print_hash(char letter);
int h_diff(struct option_s *op, char c);
int h_diff(struct option_s *op, char c);
void convert_base(long long int nbr, int base, int act, int *Nbr);
int *convert_base_start(long long int nbr, int base);
int my_nbrlen(int nbr);
int is_in_str(char letter, char *str);
int get_nbr_letter(int add);
int format_n(va_list list, struct option_s *option);
int format_s(va_list list, struct option_s *option);
int format_u(va_list list, struct option_s *option);
int format_x(va_list list, struct option_s *option);
int format_i(va_list list, struct option_s *option);
int format_d(va_list list, struct option_s *option);
int format_c(va_list list, struct option_s *option);
int format_p(va_list list, struct option_s *option);
int format_x2(va_list list, struct option_s *option);
int format_o(va_list list, struct option_s *option);
int format_percent(va_list list, struct option_s *option);
int my_printf(const char *format, ...);
long long int convert_nbr(struct option_s *op, va_list list);
void check_option(struct option_s *op, int is_neg);
int print_space(int nbr_space, struct option_s *op, int no_space, int is_neg);
struct option_s *option_init(void);
void convert_str(char *str, struct option_s *option, va_list list);
int my_nbrlen(int nbr);
int is_in_str(char letter, char *str);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr_u(unsigned nb);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int check(char c);
int transform_into_nbr(char const *str, int start, int length, int neg);
int my_findnbr(char const *str, int i, int neg);
void insert(int *array2, int nbr, int size, int size_max);
int search(char *str, char const *to_find, int n);
int my_char_isalpha(char c);
int my_show_word_array(char const **tab);
int count_space_in_str(char const *str);

#endif
