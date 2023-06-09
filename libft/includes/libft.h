/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:48:48 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/11/03 19:13:23 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define BUFFER_SIZE 8
# define MAX_FD 8192

typedef struct s_conversion
{
	int					length;
	int					minus;
	int					plus;
	int					space;
	int					hash;
	int					precision;
	char				width_char;
	int					width;
	char				type_size;
	char				type;
	char				*prefix;
	int					neg;
	int					precision_over_20;
	unsigned long long	float_whole_nb;
	long double			rounding_val;
	int					inf;
	int					nan;
	int					sign_written;
}						t_conversion;

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void		*ft_memccpy(void *restrict dst, const void *restrict src, int c, \
			size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcat(char *restrict s1, const char *restrict s2);
char		*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
size_t		ft_strlcat(char *restrict dst, const char *restrict src, \
			size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_iswhitespace(int c);
int			ft_numlen(long long nb);
size_t		ft_array_size(const void **array);
void		ft_putnbrendl(int n);
int			ft_count_words(const char *str, char c);
char		**ft_free_array2(char ***result, int size);
double		ft_atod(const char *str);
long int	ft_atol(const char *str);

int			get_next_line(const int fd, char **line);

int			ft_check_conversion_validity(const char *format, int format_i);
int			ft_valid_conv_flag(char c);
int			ft_valid_conv_type(char c);
void		ft_init_conv(t_conversion *conv);
void		ft_error_exit(int error_nbr);
void		ft_parse_conv(const char *format, int format_i, t_conversion *conv);
void		ft_write_string(t_conversion *conv, va_list args);
void		ft_write_conv(va_list args, t_conversion *conv);
void		ft_write_unsigned(t_conversion *conv, va_list args);
void		ft_write_int(t_conversion *conv, va_list args);
void		ft_write_float(t_conversion *conv, va_list args);
void		ft_float_output(t_conversion *conv, char *str);
void		ft_int_output(t_conversion *conv, char *str);
void		ft_unsigned_output(t_conversion *conv, char *str);
void		ft_write_width_float(t_conversion *conv, char *str);
void		ft_write_width_int(t_conversion *conv, char *str);
void		ft_write_width_unsigned(t_conversion *conv, char *str);
int			ft_printf(const char *format, ...);
void		ft_without_decimals(t_conversion *conv, char *str);
void		ft_write_possible_mark(t_conversion *conv);
void		ft_write_possible_mark_space(t_conversion *conv);
char		*ft_insert_inf_nan(t_conversion *conv, char *str);
long double	ft_double_rounding(t_conversion *conv, long double fl);
long double	ft_long_rounding(t_conversion *conv, long double fl);

#endif
