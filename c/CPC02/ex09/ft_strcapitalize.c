/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfukuzaw </var/mail/hfukuzaw>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:00:00 by hfukuzaw          #+#    #+#             */
/*   Updated: 2021/09/17 15:00:03 by hfukuzaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	is_lower_alphabet(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_upper_alphabet(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_mark(char c)
{
	if (!is_lower_alphabet(c))
	{
		if (!is_upper_alphabet(c))
		{
			if (!is_numeric(c))
				return (1);
		}
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && is_lower_alphabet(str[i]))
			str[i] -= 32;
		else if (i >= 1 && is_lower_alphabet(str[i]) && is_mark(str[i - 1]))
			str[i] -= 32;
		else if (!is_mark(str[i - 1]) && is_upper_alphabet(str[i]))
			str[i] += 32;
		i++;
	}
	return (str);
}

/*
int main(void)
{
	char	test[] = "salut, comment tu vas ? ";
	char	test2[] = "42mots quarante-deux; cinquante+et+un";
	char	test3[] = "sALUT, COMMENT TU V:aS ? 42MOtS qua";
	char	test4[] = "r$ante-dEUX;z cin#qua/nTee+eT+eN";
	ft_strcapitalize(test);
	ft_strcapitalize(test2);
	ft_strcapitalize(test3);
	ft_strcapitalize(test4);
	printf("test: %s\n", test);
	printf("test: %s\n", test2);
	printf("test: %s\n", test3);
	printf("test: %s\n", test4);
	return (0);
}
*/
