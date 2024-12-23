/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:59:51 by christophed       #+#    #+#             */
/*   Updated: 2024/12/18 22:28:56 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function to load the doubly circular linked list with the input values
t_stack	*dclst_load(char **args)
{
	t_stack	*head;
	t_stack	*new;
	long	data;
	int		i;

	head = NULL;
	i = 0;
	while (args[i])
	{
		data = ft_atoi_long(args[i]);
		if (is_int(data) == 0 || has_double(head, (int) data) != 0)
			return (dclst_clear(&head), NULL);
		new = dclst_insert_node_end(&head, (int) data);
		if (!new)
			return (dclst_clear(&head), NULL);
		i++;
	}
	return (head);
}

// Function to convert a string to a long integer
long	ft_atoi_long(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

// Function extract a substring from a string
size_t	ft_cpy_len(char const *s, unsigned int start, size_t len)
{
	size_t	cpy_len;

	if (start + len > (unsigned int) ft_strlen(s))
		cpy_len = ft_strlen(s) - start;
	else
		cpy_len = len;
	return (cpy_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	cpy_len;

	if (start >= (unsigned int) ft_strlen(s))
	{
		cpy = (char *) malloc(sizeof(char));
		if (cpy == NULL)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	cpy_len = ft_cpy_len(s, start, len);
	cpy = (char *) malloc((cpy_len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < cpy_len)
	{
		cpy[i] = s[i + start];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// Function to split a string into words
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_is_split(char c1, char c2)
{
	return (c1 == c2);
}

int	ft_word_count(char const *s, char c)
{
	size_t	i;
	int		count;
	int		in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (ft_is_split(s[i], c))
			in_word = 0;
		else
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		i++;
	}
	return (count);
}

void	ft_free_split(char **str_split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(str_split[i]);
		i++;
	}
}

char	**ft_allocate(char const *s, char c, int words, char **str_split)
{
	int		i;
	int		j;
	size_t	backup_i;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (ft_is_split(s[i], c))
			i++;
		backup_i = i;
		while (!ft_is_split(s[i], c) && s[i])
			i++;
		str_split[j] = ft_substr(s, (unsigned int) backup_i, i - backup_i);
		if (str_split[j] == NULL)
		{
			ft_free_split(str_split, j);
			return (NULL);
		}
		j++;
	}
	str_split[j] = NULL;
	return (str_split);
}

char	**ft_split(char const *s, char c)
{
	char	**str_split;
	int		words;

	if (s == NULL)
		return (NULL);
	words = ft_word_count(s, c);
	str_split = (char **) malloc((words + 1) * sizeof(char *));
	if (str_split == NULL)
		return (NULL);
	if (ft_allocate(s, c, words, str_split) == NULL)
	{
		free(str_split);
		return (NULL);
	}
	return (str_split);
}