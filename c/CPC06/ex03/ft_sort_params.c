/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:06:42 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/22 18:48:37 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	**ft_sort_char_tab_ascii(char	**argv, int size)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				swap = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
	return (argv);
}

int	main(int	argc, char	**argv)
{
	int		size;
	char	**sort;

	if (argc == 1)
		return (1);
	size = 0;
	argv++;
	while (argv[size] != NULL)
		size++;
	sort = ft_sort_char_tab_ascii(argv, size);
	while (*sort != NULL)
	{
		while (**sort != '\0')
		{
			ft_putchar(**sort);
			(*sort)++;
		}
		ft_putchar('\n');
		sort++;
	}
	return (0);
}
