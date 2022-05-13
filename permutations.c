/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:31:45 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/13 16:57:02 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, int i)
{
	int	temp;

	if (!stack || ft_lstsize(stack) == 1)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	ft_putstr("s");
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
	ft_putstr("r");
	print_action(i);
}

void	reverse_rotate(t_list **stack, int i)
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
	ft_putstr("rr");
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
		ft_putstr("p");
		print_action(i);
		return ;
	}
	else
		ft_lstadd_front(stack_2, head);
	ft_putstr("p");
	print_action(i);
}

// lst2 :4894
// lst2 :999
// lst2 :84
// lst2 :615
// lst2 :58
// lst2 :65
// lst2 :25
// lst2 :22
// lst2 :55
// lst2 :13
// lst2 :16
// lst2 :8
// lst2 :12
// lst2 :5
// lst2 :6
// lst2 :4
// lst2 :3
// lst2 :2