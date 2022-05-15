/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:14:55 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/15 16:20:18 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int					i;
	int					sign;
	unsigned long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (res > 9223372036854775807 && sign == 1)
		return (-1);
	if (res > (unsigned long long)9223372036854775807 + 1 && sign == -1)
		return (0);
	return (res * sign);
}

void	creat_list(t_list *lst, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac - 1)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_atoi(av[i + 1])));
		i++;
	}
}

void	creat_array(int *arr, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < ac - 1)
	{
		arr[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
}

void	array_sort(int *arr, int ac)
{
	int	i;
	int	temp;
	int	j;

	j = 1;
	while (j <= ac - 1)
	{
		i = 0;
		while (i < ac - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
}