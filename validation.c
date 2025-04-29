#include "push_swap.h"

static char	*strglue(char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;	

	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	res[i + j] = ' ';
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	**join_argv(int argc, char **argv)
{
	int	i;
	char	*res;
	char	**mat;

	res = (char *)malloc(1);
	if (!res)
		return (NULL);
	res[0] = 0;
	i = 0;
	while (i < argc - 1)
	{
		res = strglue(res, argv[++i]);
		if (!res)
			return (NULL);
	}
	mat = ft_split(res, ' ');
	if (!mat)
		return (free(res), NULL);
	free(res);
	return(mat);
}