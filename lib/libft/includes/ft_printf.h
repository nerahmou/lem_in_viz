/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 20:24:23 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 15:23:25 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define FLAGS " #0+-"
# define WIDTH "123456789*"
# define PREC "."
# define SIZE "hljz"
# define TYPE "sSdDibBoOuUxXcCpn%"

# define XUPP "0123456789ABCDEF"
# define XLOW "0123456789abcdef"
# define DEC "0123456789"
# define OCT "01234567"
# define BI "01"

# define NUL "(null)"

# define BLUE "{blue}"
# define RED "{red}"
# define GREEN "{green}"

# define BBLUE "{Bblue}"
# define BRED "{Bred}"
# define BGREEN "{Bgreen}"

# define RES_COLOR "{eoc}"

# define SET_BLUE "\e[34m"
# define SET_RED "\e[31m"
# define SET_GREEN "\e[32m"

# define SET_BBLUE "\e[44m"
# define SET_BRED "\e[41m"
# define SET_BGREEN "\e[42m"

# define ITALIC "{italic}"
# define BOLD "{bold}"
# define UNDERLINE "{underline}"

# define SET_BOLD "\e[1m"
# define SET_ITALIC "\e[3m"
# define SET_UNDERLINE "\e[4m"

# define SET_RES "\e[0m"

typedef	struct	s_suitcase
{
	int		is_sharp;
	int		is_zero;
	int		is_minus;
	int		is_plus;
	int		is_space;

	int		width;

	int		is_precision;
	int		prec;

	char	size;

	char	type;

	int		length;
	int		position;

	int		ret;
	int		ret_nul;
}				t_suitcase;

int				ft_printf(const char *str, ...);

intmax_t		ft_abs(long nbr);
int				ft_atoi(const char *str);
int				ft_putchar(char c);
void			ft_putnbr(long nbr);
void			ft_putnbr_base(uintmax_t nbr, char *base, size_t baselen);
int				ft_putwchar(wchar_t c);
int				ft_putstr(const char *str);
int				ft_putwstr(const wchar_t *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
int				ft_wstrlen(const wchar_t *str);
int				ft_uintlen(uintmax_t n, int base);
int				ft_wcharlen(wchar_t c);

intmax_t		d_size(va_list *ap, t_suitcase *s_c);
uintmax_t		u_size(va_list *ap, t_suitcase *s_c);

int				check_color_style(const char *str, int *ret);

int				get_attributs(va_list *ap, t_suitcase *s_c, const char *str);
void			get_flag(t_suitcase *s_c, char c);
void			get_width(va_list *ap, t_suitcase *s_c, const char *str);
void			get_size(t_suitcase *s_c, const char *str);
void			get_prec(va_list *ap, t_suitcase *s_c, const char *str);
void			get_type(t_suitcase *s_c, char c);
void			get_ret_value(va_list *ap, t_suitcase *s_c, int *ret);

int				print(va_list *ap, t_suitcase *s_c);
int				print_s(va_list *ap, t_suitcase *s_c);
void			print_s_minus(char *str, t_suitcase *s_c);
void			print_s_nominus(char *str, t_suitcase *s_c);
int				print_ws_minus(wchar_t *wstr, t_suitcase *s_c);
int				print_ws_nominus(wchar_t *wstr, t_suitcase *s_c);
void			print_d(va_list *ap, t_suitcase *s_c);
void			print_b(va_list *ap, t_suitcase *s_c);
void			print_o(va_list *ap, t_suitcase *s_c);
void			print_u(va_list *ap, t_suitcase *s_c);
void			print_x(va_list *ap, t_suitcase *s_c);
int				print_c(va_list *ap, t_suitcase *s_c);
void			print_p(va_list *ap, t_suitcase *s_c);
void			print_m(t_suitcase *s_c);
#endif
