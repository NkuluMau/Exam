/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:07:05 by nnqisha           #+#    #+#             */
/*   Updated: 2017/09/18 14:48:25 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	oppbrac(char c)
{
	if (c =='{')
		return ('}');
	else if (c == '(')
		return(')');
	else if (c == '[')
		return (']');
	return (0);
}

int		openbrac(char c)
{
	if (c == '{' || c == '(' || c == '[')
		return (1);
	return (0);
}

int		closebrac(char c)
{
	if (c == '}' || c == ')' || c == ']')
		return (1);
	return (0);
}

int		numbrac(char *s)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (s[i])
	{
		if (openbrac(s[i]) == 1 || closebrac(s[i]) == 1)
			num++;
		i++;
	}
	return (num);
}

int		brackets(char *s)
{
	int		count;
	int		i;
	int		j;
	char	closing;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (openbrac(s[i]) == 1)
		{
			count++;
			closing = oppbrac(s[i]);
			j = i;
			j++;
			while (s[j])
			{
				if (openbrac(s[j]) == 1)
					count++;
				else if (closebrac(s[j]) == 1)
					count--;
				if (count == 0 && s[j] != closing)
					return (-1);
				else if (count == 0 && s[j] == closing)
					break ;
				j++;
			}
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 1)
	{
		while (av[++i])
		{
			if (numbrac(av[i]) % 2 == 0)
			{
				if (brackets(av[i]) == 0)
					write(1, "OK\n", 3);
				else
					write(1, "Error\n", 6);
			}
			else
				write(1, "Error\n", 6);
		}
	}
	else
		write(1, "\n", 1);
}
