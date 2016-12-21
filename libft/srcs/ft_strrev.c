/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktshikot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:11:48 by ktshikot          #+#    #+#             */
/*   Updated: 2016/05/30 15:11:51 by ktshikot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
		int i;
		int j;
	    char c;

		j = ft_strlen(str);
		i = -1;
		while (i++ < j--)
		{
	         c = str[i];
	         str[i] = str[j];
	         str[j] = c;
	     }
		 return (str);
}
