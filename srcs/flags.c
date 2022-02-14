/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <slyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 04:06:16 by slyu              #+#    #+#             */
/*   Updated: 2022/02/06 04:06:20 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_set(int *i, t_partial *part, const char *fstr, int wid_pre)
{
	int		j;
	char	*num;

	if (wid_pre == 1)
		(*i)++;
	j = 0;
	while (ft_isdigit(fstr[*i + j]))
		j++;
	num = malloc(j + 1);
	ft_memcpy(num, fstr + *i, j);
	num[j] = '\0';
	part->width[wid_pre] = ft_atoi(num);
	*i += j - 1;
	free(num);
}

int	istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'u'
		|| c == 'i' || c == 'x' || c == 'X' || c == 's' || c == '%')
		return (1);
	return (0);
}

int	check_flag(int *i, t_partial *part, const char *fstr)
{
	enum e_flag;
	if (fstr[*i] == '-')
		part->flag[minus] = 1;
	else if (fstr[*i] == '0')
		part->flag[zero] = 1;
	else if (fstr[*i] == '.')
		flag_set(i, part, fstr, 1);
	else if (fstr[*i] == '#')
		part->flag[sharp] = 1;
	else if (fstr[*i] == ' ')
		part->flag[space] = 1;
	else if (fstr[*i] == '+')
		part->flag[plus] = 1;
	else if (ft_isdigit(fstr[*i]))
		flag_set(i, part, fstr, 0);
	else
		return (0);
	return (1);
}

void	fill_precision(int precision, char **num_str, int s_len)
{
	char	*new_str;

	new_str = malloc(precision + 1);
	ft_memset(new_str, '0', precision);
	new_str[precision] = '\0';
	ft_memcpy(new_str + precision - s_len, *num_str, s_len);
	free(*num_str);
	*num_str = new_str;
}