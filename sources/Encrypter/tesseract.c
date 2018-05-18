#include <stdio.h>

int main(int args, char *argv[])
{
	FILE *arq1, *arq2;
	char *chave;
	int c;
	
	chave = argv[1];
	if (*chave != '\0')	
	{
		arq1 = fopen(argv[2], "rb");
	}
	if (arq1 != NULL)
	{
		arq2 = fopen(argv[3], "wb");
		if (arq2 != NULL)
		{
			while ((c = getc(arq1)) != EOF)
			{
				if (!*chave) chave = argv[1];
				c ^= *(chave++);
				putc(c, arq2);
			}
			fclose(arq2);
		}
		fclose(arq1);
	}
	return 1;
}
