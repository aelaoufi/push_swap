/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:16:02 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/15 16:19:38 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_list *stack)
{
	int	temp;

	if (!stack || ft_lstsize(stack) == 1)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	rotate(t_list **stack)
{
	t_list	*head;
	int		temp;

	if (!(*stack) || ft_lstsize(*stack) == 1)
		return ;
	head = (*stack);
	temp = head->content;
	while (head->next != NULL)
	{
		head->content = head->next->content;
		head = head->next;
	}
	head->content = temp;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*head;

	if (!stack || ft_lstsize(*stack) == 1)
		return ;
	head = (*stack);
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	ft_lstadd_front(stack, head->next);
	head->next = 0;
}

void	push(t_list	**stack_1, t_list **stack_2)
{
	t_list	*head;

	if (!stack_1)
		return ;
	head = *stack_1;
	*stack_1 = (*stack_1)->next;
	if (!stack_2)
	{
		*stack_2 = head;
		(*stack_2)->next = 0;
		return ;
	}
	else
		ft_lstadd_front(stack_2, head);
}