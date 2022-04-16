/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:53:50 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/04/16 21:13:17 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	int	var;

	var = comp_three(*lst);
	if (var == 1)
	{
		rotate(lst);
		swap(*lst);
	}
	if (var == 2)
	{
		swap(*lst);
		rotate(lst);
	}
	if (var == 3)
		rotate(lst);
	if (var == 4)
		reverse_rotate(lst);
	if (var == 5)
		swap(*lst);
}

void	sort_four(t_list **lst, t_list **lst2, char **av, int ac)
{
	int	i;

	i = comp_four(av, ac);
	if (i == 1)
		push(lst, lst2);
	if (i == 2)
	{
		swap(*lst);
		push(lst, lst2);
	}
	if (i == 3)
	{
		reverse_rotate(lst);
		reverse_rotate(lst);
		push(lst, lst2);
	}
	if (i == 4)
	{
		reverse_rotate(lst);
		push(lst, lst2);
	}
	sort_three(lst);
	push(lst2, lst);
}
