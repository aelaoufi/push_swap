/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:08:53 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/13 17:02:30 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_action(int i)
{
	if (i == 1)
		ft_putstr("a\n");
	if (i == 2)
		ft_putstr("b\n");
}

void	print_rotate(t_vars *var, t_list **lst, t_list **lst2)
{
	if (var->rb == 1 && var->ra == 1)
	{
		ft_putstr("rr\n");
		rotate(lst, 0);
		rotate(lst2, 0);
	}
	if (var->rb == 1 && var->ra == 0)
	{
		ft_putstr("rb\n");
		rotate(lst2, 0);
	}
	if (var->rb == 0 && var->ra == 1)
	{
		ft_putstr("ra\n");
		rotate(lst, 0);
	}
}
