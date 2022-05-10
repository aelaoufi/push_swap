/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:25 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/10 16:51:51 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_b(t_list **lst2, t_vars *var, int *arr)
{
	t_list  *head;

	head = *lst2;
	var->i = 1;
	while (head)
	{
		if (head->content == arr[var->ac2 - 1])
			return ;
		var->i++;
		head = head->next;
	}
}

void	b_to_a(t_list **lst, t_list **lst2, t_vars *var, int *arr)
{
	big_b(lst2, var, arr);
	if (var->i > (var->ac2 - 1) / 2)
	{
		while (var->i <= var->ac2 - 1)
		{
			reverse_rotate(lst2, 2);
			var->i++;
		}
		push(lst2, lst, 1);
		return ;
	}
	if (var->i < (var->ac2 - 1) / 2)
	{
		while (var->i > 0)
		{
			rotate(lst2, 2);
			var->i--;
		}
		push(lst2, lst, 1);
	}
}