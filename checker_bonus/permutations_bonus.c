/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:16:02 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/21 16:16:47 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_action(int i)
{
	if (i == 1)
		ft_putstr("a\n");
	if (i == 2)
		ft_putstr("b\n");
}

void	swap(t_list *stack, int i)
{
	int	temp;

	if (!stack || ft_lstsize(stack) == 1)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	print_action(i);
}

void	rotate(t_list **stack, int i)
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
	print_action(i);
}

void	reverse_rotate(t_list **stack, int i)
{
	t_list	*head;

	if (!*stack || ft_lstsize(*stack) == 1)
		return ;
	head = (*stack);
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	ft_lstadd_front(stack, head->next);
	head->next = 0;
	print_action(i);
}

void	push(t_list	**stack_1, t_list **stack_2, int i)
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
		print_action(i);
		return ;
	}
	else
		ft_lstadd_front(stack_2, head);
	print_action(i);
}
