#include "fractol.h"
#include <stdio.h>

int	print(int keycode, void *o)
{
	printf("-> %d\n", keycode);
	return (0);
}

int main(void)
{
	void	*l;
	void	*w;

	l = mlx_init();
	w = mlx_new_window(l, 10, 10, "lol");
	mlx_key_hook(w, print, 0);
	mlx_loop(l);
	return (0);
}
