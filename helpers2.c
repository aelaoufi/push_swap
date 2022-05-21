/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:08:53 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/20 15:16:14 by aelaoufi         ###   ########.fr       */
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

void	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putstr("error");
			exit(1);
		}
		i++;
	}
	return ;
}
