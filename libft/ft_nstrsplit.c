/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmather <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 15:28:58 by dmather           #+#    #+#             */
/*   Updated: 2016/07/02 15:29:00 by dmather          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		words++;
	}
	return (words);
}

static char		*next_word(const char *s, char c, size_t *len)
{
	*len = 0;
	while (*s && *s == c)
		s++;
	while (s[*len] && s[*len] != c)
		(*len)++;
	return ((char *)s);
}

t_split_string	ft_nstrsplit(char const *s, char c)
{
	t_split_string	split;
	size_t			wordl;
	size_t			i;

	i = 0;
	split.words = count_words(s, c);
	split.strings = (char **)malloc(sizeof(char *) * split.words);
	if (split.strings == NULL)
	{
		split.words = -1;
		return (split);
	}
	while (i < split.words)
	{
		s = next_word(s, c, &wordl);
		split.strings[i] = (char *)ft_strsub(s, 0, wordl);
		if (split.strings[i] == NULL)
		{
			split.words = -1;
			return (split);
		}
		s += wordl;
		i++;
	}
	return (split);
}
