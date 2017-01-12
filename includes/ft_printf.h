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
	int         chars_printed;
	int			padding_num;
	char		padding_type;
	int			padding_justify;
	int         forcepositive;
	const char	*format;
	int         precision;
	int         isnumber;
	int			format_num;
	int			hashable;
	char		*outvalue;
	int			outval_num;
	int 		counter;
}				t_printret;

int		ft_printf(const char *frmt, ...);
void	ft_display(t_printret	*ret);
void	ft_handle_str(t_printret *ret, va_list argp);
char	*ft_itoa_base(unsigned int numb, int base);
char	*ft_itoa_bases(unsigned short numb, int base);
char	*ft_itoa_basel(unsigned long numb, int base);
char	*ft_ibase(long numb, int base);
char	*ft_ibases(short numb, int base);
void    ft_handle_numb(t_printret *ret, va_list argp);
void    ft_handle_numb_short(t_printret *ret, va_list argp);
void	ft_conversions(t_printret *ret, va_list argp);
void	ft_precision(t_printret *ret, va_list argp);
void	handle_length(va_list argp, t_printret *ret);
void	ft_assigner(t_printret	*ret, char *s);

#endif
