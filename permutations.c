/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:31:45 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/04/02 15:59:45 by aelaoufi         ###   ########.fr       */
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

void	rotate(t_list *stack)
{
	t_list  *head;
	int temp;
	
	if(!stack)
		return ;
	head = stack;
	while(stack != NULL)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
	
}