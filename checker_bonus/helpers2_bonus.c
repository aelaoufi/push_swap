/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaoufi <aelaoufi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 18:33:23 by aelaoufi          #+#    #+#             */
/*   Updated: 2022/05/22 10:43:05 by aelaoufi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{	
	if (s1 == NULL)
		return (0);
	while ((*s1 != '\0') || (*s2 != '\0'))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	check_dupl(t_list *lst)
{
	t_list	*head;
	t_list	*temp;

	head = lst;
	temp = head;
	while (head != NULL)
	{
		while (temp->next != NULL && head->content != temp->next->content)
			temp = temp->next;
		if (temp->next != NULL && head->content == temp->next->content)
		{
			ft_putstr("Error\n");
			exit(1);
		}
		head = head->next;
		temp = head;
	}
	return ;
}

void	ft_isdigit(char *str, long res, int sign)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		print_error("Error\n");
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			print_error("Error\n");
		i++;
	}
	if (sign == -1)
		res *= sign;
	if (res > 2147483647 || res < -2147483648)
		print_error("Error\n");
	return ;
}
