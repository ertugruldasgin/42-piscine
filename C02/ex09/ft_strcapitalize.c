/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 07:35:41 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/12 16:45:25 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

int	ft_is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*res;

	res = str;
	while (*str)
	{
		if (str == res || !ft_is_alphanumeric(*(str - 1)))
		{
			if (ft_is_lower(*str))
				*str -= 32;
		}
		else
		{
			if (ft_is_upper(*str))
				*str += 32;
		}
		str++;
	}
	return (res);
}
