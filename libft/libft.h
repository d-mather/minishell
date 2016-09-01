/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 12:00:22 by dmather           #+#    #+#             */
/*   Updated: 2016/08/27 20:43:42 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <termcap.h>
# include <term.h>
# include <curses.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# define BUFF_SIZE 9999

# ifndef COLOURS
#  define COLOURS
#  define C_RESET			"\033[0m"
#  define C_PURPLE			"\033[38;5;128m"
#  define C_RED				"\033[31m"
#  define C_GREEN			"\033[32m"
#  define C_YELLOW			"\033[33m"
#  define C_BLUE			"\033[34m"
#  define C_MAGENTA			"\033[35m"
#  define C_CYAN			"\033[36m"
#  define C_GRAY			"\033[90m"
#  define C_L_RED			"\033[91m"
#  define C_L_GREEN			"\033[92m"
#  define C_L_YELLOW		"\033[93m"
#  define C_L_BLUE			"\033[94m"
#  define C_L_MAGENTA		"\033[95m"
#  define C_L_CYAN			"\033[96m"
#  define C_L_GRAY			"\033[37m"
#  define C_BLACK			"\033[30m"
#  define C_WHITE			"\033[97m"

/*
** Background Colours
*/

#  define BG_RESET			"\033[49m"
#  define BG_LRED			"\033[41m"
#  define BG_LGREEN			"\033[42m"
#  define BG_LYELLOW		"\033[43m"
#  define BG_LBLUE			"\033[44m"
#  define BG_LMAGENTA		"\033[45m"
#  define BG_LCYAN			"\033[46m"
#  define BG_LGRAY			"\033[47m"
#  define BG_BLACK			"\033[40m"
#  define BG_WHITE			"\033[107m"
#  define BG_RED			"\033[101m"
#  define BG_GREEN			"\033[102m"
#  define BG_YELLOW			"\033[103m"
#  define BG_BLUE			"\033[104m"
#  define BG_MAGENTA		"\033[105m"
#  define BG_CYAN			"\033[106m"
#  define BG_GRAY			"\033[100m"
# endif

typedef	struct		s_printf_data
{
	va_list			ap;
	char			*ptr;
	char			*buff;
	char			*spec_arr;
	char			*flag_arr;
	char			flag;
	char			*flags;
	int				left_align;
	int				width;
	int				prec;
}					t_data;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_split_string
{
	size_t			words;
	char			**strings;
}					t_split_string;

int					ft_atoi(const char *str);
void				ft_float_swap(float *a, float *b);
void				ft_free_tab(char ***table, int len);
void				ft_bzero(void *s, size_t n);
char				*ft_ctostr(char c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isint(char *str);
char				ft_islower(char c);
int					ft_isprint(int c);
char				ft_isupper(char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstclear(t_list **begin_list);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlen(t_list *blist);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnclear(t_list **begin_list, int nb);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstpushback(t_list **blst, void const *content,
						size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				ft_memswap(void *a, void *b);
t_split_string		ft_nstrsplit(char const *s, char c);
char				*ft_nstrjoin(char *s1, char *s2, char *s3);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_realloc(void *ptr, size_t size);
int					ft_sprintf(char **str, const char *format, ...);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnew(size_t size);
char				*ft_strnjoin(const char *s1, const char *s2,
						size_t n_chars);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtoupper(char *str);
char				*ft_strtrim(const char *s);
char				**ft_tabdup(char **table, int len);
char				*ft_tabstrstr(char **haystack, const char *needle);
char				ft_tolower(char c);
char				ft_toupper(char c);
char				*ft_trim_qu(const char *s);
char				*ft_uitoa(unsigned int n);
char				*ft_uitoa_base(size_t n, unsigned int base);
int					ft_gnl(const int fd, char **line);

/*
** FT_PRINTF
*/
int					ft_printf(const char *format, ...);
int					analyze(t_data *data, const char *format);
void				init_data(t_data *data, const char *format);
int					find_char(char **ptr, char *chars);
int					get_width(va_list ap, char **ptr, int *nbr);
int					get_number(char **ptr, int *nbr);
int					get_prec(va_list ap, char **ptr, int *nbr);
void				add_padding(t_data *d, char **str);
void				add_int_flags(t_data *d, char **str, int arg);
void				process_hex(t_data *data, char **val_str, size_t arg);
void				process_args(t_data *data);
void				process_addr(t_data *data);
void				process_chars(t_data *data);
void				process_uint(t_data *data);
void				process_int(t_data *data);

#endif
