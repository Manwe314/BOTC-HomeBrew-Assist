#include "assist.h"

char	*ft_strdup(char const *s1)
{
	int		size;
	char	*copy;
	int		i;
	char	*s;

	s = (char *)s1;
	size = ft_strlen(s);
	copy = (char *)malloc((size + 1) * sizeof(char));
	if (!copy)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
