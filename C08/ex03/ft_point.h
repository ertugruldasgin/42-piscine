/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udasgin@student.42istanbul.com.tr          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 18:52:46 by udasgin           #+#    #+#             */
/*   Updated: 2026/09/02 20:24:49 by udasgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct
{
	int	x;
	int	y;
}		t_point;

void	set_point(t_point *point);

#endif /* ifndef FT_POINT_H */
