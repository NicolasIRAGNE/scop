/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:41:22 by iburel            #+#    #+#             */
/*   Updated: 2018/02/18 18:17:34 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <inttypes.h>
# include <wchar.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define PF_BUFF_SIZE 1000000

typedef struct s_pftags		t_pftags;
typedef struct s_pfflags	t_pfflags;
typedef enum e_pftype		t_pftype;

extern void		(*g_pf_buff)(char *, int);
extern t_uint64	(*g_pf_utype[7])(va_list);
extern t_int64	(*g_pf_type[7])(va_list);

struct		s_pftags
{
	t_uint8 hashtag : 1;
	t_uint8 zero : 1;
	t_uint8 minus : 1;
	t_uint8 space : 1;
	t_uint8 plus : 1;
	t_uint8 maj : 1;
	t_uint8 prec : 1;
};

enum		e_pftype
{
	H,
	HH,
	L,
	LL,
	J,
	Z,
	ND
};

struct		s_pfflags
{
	t_pftags	tags;
	t_pftype	type;
	t_uint32	prec;
	t_uint32	blank;
};

int			ft_printf(char *format, ...);
int			ft_dprintf(int fd, char *format, ...);
int			ft_sprintf(char *str, char *format, ...);
int			ft_snprintf(char *str, int size, char *format, ...);

int			ft_vprintf(char *format, va_list arg);
int			ft_vdprintf(int fd, char *format, va_list arg);
int			ft_vsprintf(char *str, char *format, va_list arg);
int			ft_vsnprintf(char *str, int size, char *format, va_list arg);

int			pf_conv(char **format, va_list arg);
char		*pf_tags(char *format, va_list arg, t_pfflags *flags);
int			pf_arg(char c, va_list arg, t_pfflags *flags);

void		pf_buff(char *str, int len);
void		pf_putbuff(void);
void		spf_init_buff(char *str);
void		spf_buff(char *str, int len);
void		dpf_init_buff(int fd);
void		dpf_buff(char *str, int len);
void		dpf_putbuff(void);

int			pf_putchar(wchar_t c);

int			pf_itoa(char *str, t_int64 n);
int			pf_uitoa_base(char *str, t_uint64 n, t_uint32 base, int maj);
void		pf_fill(int size, char octet);

t_int64		pf_short(va_list arg);
t_int64		pf_2short(va_list arg);
t_int64		pf_long(va_list arg);
t_int64		pf_2long(va_list arg);
t_int64		pf_intmax(va_list arg);
t_int64		pf_ssize(va_list arg);
t_int64		pf_int(va_list arg);
t_uint64	pf_ushort(va_list arg);
t_uint64	pf_u2short(va_list arg);
t_uint64	pf_ulong(va_list arg);
t_uint64	pf_u2long(va_list arg);
t_uint64	pf_uintmax(va_list arg);
t_uint64	pf_size(va_list arg);
t_uint64	pf_uint(va_list arg);

char		*pf_hashtag(char *format, va_list arg, t_pfflags *flags);
char		*pf_zero(char *format, va_list arg, t_pfflags *flags);
char		*pf_minus(char *format, va_list arg, t_pfflags *flags);
char		*pf_space(char *format, va_list arg, t_pfflags *flags);
char		*pf_plus(char *format, va_list arg, t_pfflags *flags);
char		*pf_h(char *format, va_list arg, t_pfflags *flags);
char		*pf_l(char *format, va_list arg, t_pfflags *flags);
char		*pf_lmaj(char *format, va_list arg, t_pfflags *flags);
char		*pf_j(char *format, va_list arg, t_pfflags *flags);
char		*pf_z(char *format, va_list arg, t_pfflags *flags);
char		*pf_blank(char *format, va_list arg, t_pfflags *flags);
char		*pf_prec(char *format, va_list arg, t_pfflags *flags);
char		*pf_star(char *format, va_list arg, t_pfflags *flags);

int			pf_a(va_list arg, t_pfflags *flags);
int			pf_maj_a(va_list arg, t_pfflags *flags);
int			pf_b(va_list arg, t_pfflags *flags);
int			pf_maj_b(va_list arg, t_pfflags *flags);
int			pf_c(va_list arg, t_pfflags *flags);
int			pf_maj_c(va_list arg, t_pfflags *flags);
int			pf_d(va_list arg, t_pfflags *flags);
int			pf_maj_d(va_list arg, t_pfflags *flags);
int			pf_e(va_list arg, t_pfflags *flags);
int			pf_maj_e(va_list arg, t_pfflags *flags);
int			pf_f(va_list arg, t_pfflags *flags);
int			pf_maj_f(va_list arg, t_pfflags *flags);
int			pf_g(va_list arg, t_pfflags *flags);
int			pf_maj_g(va_list arg, t_pfflags *flags);
int			pf_i(va_list arg, t_pfflags *flags);
int			pf_maj_i(va_list arg, t_pfflags *flags);
int			pf_k(va_list arg, t_pfflags *flags);
int			pf_o(va_list arg, t_pfflags *flags);
int			pf_maj_o(va_list arg, t_pfflags *flags);
int			pf_p(va_list arg, t_pfflags *flags);
int			pf_s(va_list arg, t_pfflags *flags);
int			pf_maj_s(va_list arg, t_pfflags *flags);
int			pf_u(va_list arg, t_pfflags *flags);
int			pf_maj_u(va_list arg, t_pfflags *flags);
int			pf_x(va_list arg, t_pfflags *flags);
int			pf_maj_x(va_list arg, t_pfflags *flags);
int			pf_per(va_list arg, t_pfflags *flags);

#endif
