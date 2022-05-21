/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:08:53 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/21 18:31:30 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_action(int i)
{
	if (i == 1)
		ft_putstr("a\n");
	if (i == 2)
		ft_putstr("b\n");
}

void	ft_isdigit(char *str, long res, int sign)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putstr("error\n");
			exit(1);
		}
		i++;
	}
	if (sign == -1)
		res *= sign;
	if (res > 2147483647 || res < -2147483648)
	{
		ft_putstr("error\n");
		exit(1);
	}
	return ;
}

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
			ft_putstr("error\n");
			exit(1);
		}
		head = head->next;
		temp = head;
	}
	return ;
}
