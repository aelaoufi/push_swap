/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:43:59 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/04/08 22:15:17 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (res > 9223372036854775807 && sign == 1)
		return (-1);
	if (res > (unsigned long long)9223372036854775807 + 1 && sign == -1)
		return (0);
	return (res * sign);
}

int	 compare(t_list *lst)
{
	if (lst->content > lst->next->content
		&& lst->next->content > lst->next->next->content
		&& lst->content > lst->next->next->content)
		return (1);
	if (lst->content < lst->next->content
		&& lst->content < lst->next->next->content
		&& lst->next->content > lst->next->next->content)
		return (2);
	if (lst->content > lst->next->content
		&& lst->next->content < lst->next->next->content
		&&lst->content > lst->next->next->content)
		return (3);
	if (lst->content < lst->next->content
		&&lst->next->content > lst->next->next->content
		&& lst->content > lst->next->next->content)
		return (4);
	if (lst->content > lst->next->content
		&& lst->next->content < lst->next->next->content
		&& lst->content < lst->next->next->content)
		return (5);
	return (0);
}