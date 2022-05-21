/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:28:18 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/20 15:14:00 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	creat_array(int *arr, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < ac - 1)
	{
		arr[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
}

void	array_sort(int *arr, int ac)
{
	int	i;
	int	temp;
	int	j;

	j = 0;
	temp = 0;
	while (j < ac - 1)
	{
		i = 0;
		while (i < ac - 2)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
}

void	range(t_vars *var, int ac)
{
	var->ac2 = ac;
	var->mid = (ac - 1) / 2;
	if (ac >= 150)
		var->range = (ac - 1) / 18;
	if (ac < 150 && ac >= 10)
		var->range = (ac - 1) / 8;
	if (ac < 10)
		var->range = (ac - 1) / 5;
	var->start = var->mid - var->range;
	var->end = var->mid + var->range;
	var->temp = 0;
}

void	a_to_b(t_list **lst, t_list **lst2, t_vars *var, int *arr)
{
	var->i = 0;
	if ((*lst) && (*lst)->content >= arr[var->start]
		&& (*lst)->content <= arr[var->end])
	{
		push(lst, lst2, 2);
		var->i++;
	}
	if ((*lst2) && (*lst2)->content < arr[var->mid])
		rotate(lst2, 2);
}

void	big_chunkus(t_list **lst, t_list **lst2, t_vars *var, int *arr)
{
	while ((*lst))
	{
		while ((*lst) && var->end - var->start >= ft_lstsize(*lst2))
		{
			a_to_b(lst, lst2, var, arr);
			if (var->i == 0)
				rotate(lst, 1);
		}
		var->start -= var->range;
		var->end += var->range;
		if (var->start < 0)
			var->start = 0;
		if (var->end >= var->ac2 - 2)
			var->end = var->ac2 - 2;
	}
	b_to_a(lst, lst2, var, arr);
}
