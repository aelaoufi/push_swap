/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:53:50 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/20 15:34:39 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	int	var;

	var = comp_three(*lst);
	if (var == 1)
	{
		rotate(lst, 1);
		swap(*lst, 1);
	}
	if (var == 2)
	{
		swap(*lst, 1);
		rotate(lst, 1);
	}
	if (var == 3)
		rotate(lst, 1);
	if (var == 4)
		reverse_rotate(lst, 1);
	if (var == 5)
		swap(*lst, 1);
}

void	sort_four(t_list **lst, t_list **lst2)
{
	int	i;

	i = smallest(*lst);
	if (i == 1)
		push(lst, lst2, 2);
	if (i == 2)
	{
		swap(*lst, 1);
		push(lst, lst2, 2);
	}
	if (i == 3)
	{
		reverse_rotate(lst, 1);
		reverse_rotate(lst, 1);
		push(lst, lst2, 2);
	}
	if (i == 4)
	{
		reverse_rotate(lst, 1);
		push(lst, lst2, 2);
	}
	sort_three(lst);
	push(lst2, lst, 1);
}

void	sort_f(int i, t_list **lst, t_list **lst2)
{
	if (i == 1)
		push(lst, lst2, 2);
	if (i == 2)
	{
		swap(*lst, 1);
		push(lst, lst2, 2);
	}
	if (i == 3)
	{
		reverse_rotate(lst, 1);
		reverse_rotate(lst, 1);
		reverse_rotate(lst, 1);
		push(lst, lst2, 2);
	}
}

void	sort_five(t_list **lst, t_list **lst2)
{
	int	i;

	i = smallest(*lst);
	sort_f(i, lst, lst2);
	if (i == 4)
	{
		reverse_rotate(lst, 1);
		reverse_rotate(lst, 1);
		push(lst, lst2, 2);
	}
	if (i == 5)
	{
		reverse_rotate(lst, 1);
		push(lst, lst2, 2);
	}
	sort_four(lst, lst2);
	push(lst2, lst, 1);
}
