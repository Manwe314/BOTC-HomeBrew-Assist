#include "assist.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	unsigned int	cmp;

	if (!s)
		return (0);
	if (len < 0)
		return (ft_strdup(s));
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == 0)
		return (0);
	substr[0] = '\0';
	i = 0;
	cmp = 0;
	while (s[cmp] != '\0')
		cmp++;
	if (cmp <= start)
		return (substr);
	while (i < len && (s[i] != '\0'))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
