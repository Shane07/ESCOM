#include <stdio.h>

int main()
{
	int c, d = 0x0E;
	printf("%d\n\n\n", sizeof(unsigned long int));

	for(c = 0x80; c > 0; c >>= 1) // 0x80 = 128 <- 2^(8-1) where 8 = cant bits CHAR
		(c&d)? printf("1") : printf("0");
	printf("\t%d\n", d);
	return 0;
}