/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:43:59 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/13 17:01:33 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

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

int	comp_three(t_list *lst)
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

// int	small(char **av, int ac)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	j = 2;
// 	while (i <= ac - 1)
// 	{
// 		if (i == ac - 1)
// 			return (i);
// 		while (j <= ac - 1 && ft_atoi(av[i]) < ft_atoi(av[j]))
// 			j++;
// 		if (j > ac - 1)
// 			return (i);
// 		i++;
// 		j = i + 1;
// 	}
// 	return (0);
// }

int	smallest(t_list *lst)
{
	t_list	*head;
	t_list	*temp;
	int		i;

	head = lst;
	temp = head;
	i = 1;
	while (head != NULL)
	{
		while (temp->next != NULL && head->content < temp->next->content)
			temp = temp->next;
		if (temp->next == NULL)
			return (i);
		i++;
		head = head->next;
		temp = head;
	}
	return (0);
}

void	creat_list(t_list *lst, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac - 1)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(av[i + 1])));
		i++;
	}
}
