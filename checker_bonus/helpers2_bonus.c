/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:33:23 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/21 23:15:11 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_dupl(t_list *lst)
{
	t_list	*head;
	t_list	*temp;

	head = lst;
	temp = head;
	while (head != NULL)
	{
		while (temp->next != NULL && head->content != temp->next->content)
			temp = temp->next;
		if (temp->next != NULL && head->content == temp->next->content)
		{
			ft_putstr("Error\n");
			exit(1);
		}
		head = head->next;
		temp = head;
	}
	return ;
}

void	ft_isdigit(char *str, long res, int sign)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		ft_putstr("Error\n");
		exit(1);
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i++;
	}
	if (sign == -1)
		res *= sign;
	if (res > 2147483647 || res < -2147483648)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	return ;
}