#include <stdio.h>
#include "libftprintf.h"
int main(void)
{
	printf("	---- Return = %d ----", ft_printf("||F%*u%*s=r%-.*u,F0$",-15, 1569, -6, " 62eHsj]", -14, 2940));
	printf("	---- Return = %d ----", printf("||F%*u%*s=r%-.*u,F0$",-15, 1569, -6, " 62eHsj]", -14, 2940));
	return (0);
}