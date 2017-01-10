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
	const char	*format;
	int			format_num;
	char		*outvalue;
	int			outval_num;
	int 		counter;
}				t_printret;

int		ft_printf(const char *frmt, ...);
void	ft_display(t_printret	*ret);
void	ft_handle_str(t_printret *ret, va_list argp);
char	*ft_itoa_base(unsigned long numb, int base);
void    ft_handle_numb(t_printret *ret, va_list argp);

#endif
