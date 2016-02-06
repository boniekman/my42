#include "fdf.h"

void	liool(t_map map)
{
	map.rows = 9;
	map.columns = 8;
}

int		main(void)
{
	char	*lol;
	char	**tab;
	int		i;
	int		j;
	t_map	map;

	liool(map);
	printf("%d %d\n");
	lol = ft_strdup("1 2 3 4 5");
	tab = ft_strsplit(lol, ' ');
	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
