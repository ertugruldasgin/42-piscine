/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:39:16 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/02 17:07:26 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_charset(char *c, char *charset)
{
	char	*temp;

	temp = charset;
	while (*temp)
	{
		if (*c == *temp)
			return (1);
		temp++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_is_in_charset(&str[i], charset) && (ft_is_in_charset(&str[i
					+ 1], charset) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	ft_put_words(char *str)
{
}

char	**ft_split(char *str, char *charset)
{
	int	word_count;

	word_count = ft_count_words(str, charset);
	strs = malloc(sizeof(char) * (word_count + 1));
	if (strs == NULL)
		return (NULL);
	strs[word_count] = NULL;
	return (strs);
}
