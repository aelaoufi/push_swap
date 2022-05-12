/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:25 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/12 17:39:29 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest(t_list *lst)
{
	t_list	*head;
	t_list	*temp;
	int		i;

	head = lst;
	temp = head;
	i = 1;
	while (head != NULL)
	{
		while (temp->next != NULL && head->content > temp->next->content)
			temp = temp->next;
		if (temp->next == NULL)
			return (i);
		i++;
		head = head->next;
		temp = head;
	}
	return (0);
}

void	b_to_a(t_list **lst, t_list **lst2, t_vars *var, int *arr)
{
	while (*lst2)
	{
		var->i = biggest(*lst2);
		if (var->i >= (var->ac2 - 1) / 2)
		{
			while (var->i < ft_lstsize(*lst2) + 1)
			{
				reverse_rotate(lst2, 2);
				var->i++;
			}
			push(lst2, lst, 1);
		}
		else
		{
			while (var->i > 1)
			{
				rotate(lst2, 2);
				var->i--;
			}
			push(lst2, lst, 1);
		}
	}
}