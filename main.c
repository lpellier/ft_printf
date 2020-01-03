#include <stdio.h>
#include "libftprintf.h"
int main(void)
{
	printf("	---- Return = %d ----", ft_printf("||%*.10uUAfqt$S5Kt{r(g%11.48u%*.18u%9X%16s+-ejK(hu$",7, 2468, -7377, -18, -1264, 2756, "f}!*"));
	printf("	---- Return = %d ----", printf("||%*.10uUAfqt$S5Kt{r(g%11.48u%*.18u%9X%16s+-ejK(hu$",7, 2468, -7377, -18, -1264, 2756, "f}!*"));
	return (0);
}