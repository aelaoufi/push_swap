/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:25 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/20 15:14:56 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest(t_list *lst, t_vars *var, int *arr)
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

int	biggest_content(t_list *lst, t_vars *var, int *arr)
{
	t_list	*head;
	t_list	*temp;
	int		i;

	head = lst;
	temp = head;
	while (head != NULL)
	{
		while (temp->next != NULL && head->content > temp->next->content)
			temp = temp->next;
		if (temp->next == NULL)
			return (head->content);
		head = head->next;
		temp = head;
	}
	return (0);
}

void	down(t_list **lst, t_list **lst2, t_vars *var, int *arr)
{
	if (var->temp == 0 || (*lst2)->content > ft_lstlast(*lst)->content)
	{
		push(lst2, lst, 1);
		rotate(lst, 1);
		var->i--;
		var->temp++;
	}
	else
	{
		rotate(lst2, 2);
		var->i--;
	}
}

void	b_to_a(t_list **lst, t_list **lst2, t_vars *var, int *arr)
{
	while (*lst2)
	{
		var->i = biggest(*lst2, var, arr);
		var->content = biggest_content((*lst2), var, arr);
		if (arr[var->ac2 - 2] != var->content)
		{
			reverse_rotate(lst, 1);
			var->temp--;
			var->ac2--;
		}
		else if (var->i >= (ft_lstsize(*lst2) / 2) && var->ac2 - 2 >= 0)
		{
			while ((*lst2)->content != arr[var->ac2 - 2])
				reverse_rotate(lst2, 2);
			push(lst2, lst, 1);
			var->ac2--;
		}
		else
		{
			while ((*lst2)->content != arr[var->ac2 - 2] && var->ac2 - 2 >= 0)
				down(lst, lst2, var, arr);
			push(lst2, lst, 1);
			var->ac2--;
		}
	}
}
