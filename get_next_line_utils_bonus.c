/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:13:33 by mkucukku          #+#    #+#             */
/*   Updated: 2022/12/01 16:12:16 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length])
		length++;
	return (length);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
	i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*cstm_str;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	cstm_str = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (cstm_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i] != '\0')
			cstm_str[i] = str[i];
	while (buff[j] != '\0')
		cstm_str[i++] = buff[j++];
	cstm_str[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (cstm_str);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*custom_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	custom_str = (char *)malloc(sizeof(char) * (i + 2));
	if (!custom_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		custom_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		custom_str[i] = str[i];
		i++;
	}
	custom_str[i] = '\0';
	return (custom_str);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*custom_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	custom_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!custom_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		custom_str[j++] = str[i++];
	custom_str[j] = '\0';
	free (str);
	return (custom_str);
}
