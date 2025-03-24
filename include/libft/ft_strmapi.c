/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:39:44 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/06 10:30:29 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *) malloc((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = ((*f)(i, s[i]));
		i++;
	}
	str[i] = '\0';
	return (str);
}
