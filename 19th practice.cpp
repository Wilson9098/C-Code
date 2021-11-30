#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <errno.h>


int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (!pf)
	{
		perror("Error opeaning test.txt");
		return 0;
	}

	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		putchar(ch);
	}
	puts("");

	if (ferror(pf))
	{
		perror("Error reading test.txt");
	}
	else if (feof(pf))
	{
		puts("end of file");
	}

	fclose(pf);
	pf = NULL;

	return 0;
}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fseek(pf, -4, SEEK_END);
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	rewind(pf);
//	int ps = ftell(pf);
//	printf("%d\n", ps);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}