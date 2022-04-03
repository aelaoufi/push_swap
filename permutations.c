/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:31:45 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/04/03 23:29:04 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_list *stack)
{
	int temp;
	
	if(!stack)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	rotate(t_list **stack)
{
	t_list  *head;
	int		temp;
	
	if(!stack)
		return ;
	head = (*stack);
	temp = head->content;
	while(head->next != NULL)
	{
		head->content = head->next->content;
		head = head->next;
	}
	head->content = temp;
}

void	shift(t_list **stack)
{
	t_list	*head;
	int		temp;
	
	if(!stack)
		return ;
	head = (*stack);
	temp = head->content;
	while(head->next->next != NULL)
	{
		head->content = head->next->content;
		head = head->next;
	}
	head->content = temp;
	temp = head->next->content;
	head->next = NULL;
	ft_lstadd_front(stack, ft_lstnew(temp));
}