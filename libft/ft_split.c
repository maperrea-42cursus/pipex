/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:38:13 by maperrea          #+#    #+#             */
/*   Updated: 2021/06/13 11:57:59 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	array_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free_one(array[i]);
		array[i] = NULL;
		i++;
	}
	free_one(array);
	array = NULL;
}

static int	rec_split(char ***output, const char **str, char c, int count)
{
	int		i;
	int		flag;
	int		len;

	i = 0;
	flag = 0;
	len = 0;
	if (count <= 0)
		return (0);
	while (**str && **str == c)
		(*str)++;
	while ((*str)[len] && (*str)[len] != c)
		len++;
	**output = malloc_list(sizeof(char) * (len + 1));
	if (!**output)
		return (1);
	while (**str && **str != c)
		(**output)[i++] = *((*str)++);
	(**output)[i] = 0;
	(*output)++;
	if (rec_split(output, str, c, count - 1))
		flag = 1;
	(*output)--;
	return (flag);
}

char	**ft_split(const char *s, char c)
{
	char	**output;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	output = ft_calloc(1, sizeof(char *) * (count + 1));
	if (!output)
		return (NULL);
	if (rec_split(&output, &s, c, count))
		array_free(output);
	return (output);
}
