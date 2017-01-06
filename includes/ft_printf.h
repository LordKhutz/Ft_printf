/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:09:53 by ktshikot          #+#    #+#             */
/*   Updated: 2016/06/02 15:09:57 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_printret
{
	int         returnvalue;
}				t_printret;

void	handle_ll(char format, va_list argp);
void	handle_hh(char format, va_list argp);
void	handle_h(char format, va_list argp);
void	handle_j(char format, va_list argp);
void	handle_z(char format, va_list argp);
int		handle_length(const char *format, va_list argp);
void	base(unsigned int number_to_convert, char case_, int base, t_printret *ret);
void	base_l(long number_to_convert, char case_, int base, t_printret *ret);
void	base_change(va_list argp, char format, t_printret *ret);
void	print_string(va_list argp, char format, t_printret *ret);
int	    handle_num(va_list argp, char format, int pos_num, t_printret *ret);
void	pointer_s(va_list argp, char format, t_printret *ret);
int		double_percent(char format);
void	handle_hashtag(char format);
int		handle_0_padding(const char *format);
int		handle_space_padding(const char *format);
int		handle_padding(const char *format, va_list argp, t_printret *ret);
int		ft_printf(const char *format, ...);

#endif
