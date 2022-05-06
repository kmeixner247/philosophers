/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:14:35 by kmeixner          #+#    #+#             */
/*   Updated: 2021/05/15 10:14:35 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	calc_nbr(char *str, int nbrlen, int sign)
{
	long	nbr;
	int		mag;

	nbr = 0;
	mag = 1;
	nbrlen--;
	while (nbrlen >= 0)
	{
		nbr += (str[nbrlen] - 48) * mag;
		mag *= 10;
		nbrlen--;
	}
	return (nbr * sign);
}

int	checkstr(char *str)
{
	if (*str == 48)
		return (-1);
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (-1);
		str++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbrlen;

	i = 0;
	sign = 1;
	nbrlen = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i + nbrlen] >= 48 && str[i + nbrlen] <= 57)
		nbrlen++;
	return (calc_nbr(str + i, nbrlen, sign));
}
