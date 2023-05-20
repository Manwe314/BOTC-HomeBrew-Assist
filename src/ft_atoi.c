#include "assist.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	nbr;

	i = 0;
	s = 1;
	nbr = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	nbr = nbr * s;
	return (nbr);
}
