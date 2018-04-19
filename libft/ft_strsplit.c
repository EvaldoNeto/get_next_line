/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:35:44 by eneto             #+#    #+#             */
/*   Updated: 2018/04/09 19:49:39 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_of_words(char const *s, char c)
{
	int i;
	int n;

	n = 0;
	i = 0;
	if (s[0] && s[0] != c)
		n++;
	while (s[i] && s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			n++;
		i++;
	}
	return (n);
}

static int		**malloc_matrix(int i, int j)
{
	int **pos;

	if (!(pos = (int **)malloc(sizeof(int *) * j)))
		return (NULL);
	if (!(*pos = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	if (!(*(pos + 1) = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	return (pos);
}

static int		**words_pos(char const *s, char c, int n_words)
{
	int **pos;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(pos = malloc_matrix(n_words, 2)))
		return (NULL);
	if (s[0] && s[0] != c)
		pos[0][0] = 0;
	while (s[j] && s[j + 1])
	{
		if (s[j] == c && s[j + 1] != c)
			pos[0][i] = j + 1;
		if (s[j] != c && s[j + 1] == c)
		{
			pos[1][i] = j;
			i++;
		}
		j++;
	}
	if (s[j] && s[j] != c)
		pos[1][i] = j;
	return (pos);
}

char			**ft_strsplit(char const *s, char c)
{
	int		n_words;
	int		**pos;
	int		i;
	char	**str;

	if (!s)
		return (NULL);
	n_words = num_of_words(s, c);
	pos = words_pos(s, c, n_words);
	i = 0;
	if (!(str = (char **)malloc(sizeof(char *) * (n_words + 1))))
		return (str);
	while (i < n_words)
	{
		if (!(*(str + i) = ft_strsub(s, pos[0][i], pos[1][i] - pos[0][i] + 1)))
		{
			while (i-- >= 0)
				ft_memdel((void **)(str + i));
			return (str);
		}
		i++;
	}
	ft_memdel((void **)pos);
	*(str + i) = NULL;
	return (str);
}
