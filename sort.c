/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:53:50 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/04/08 22:14:33 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list *lst)
{
	int	var;

	var = compare(lst);
	if (var == 1)
	{
		rotate(&lst);
		swap(lst);
	}
	if (var == 2)
	{
		swap(lst);
		rotate(&lst);
	}
	if (var == 3)
		rotate(&lst);
	if (var == 4)
		reverse_rotate(&lst);
	if (var == 5)
		swap(lst);
}
