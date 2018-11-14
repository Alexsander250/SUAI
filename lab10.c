#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*В символьной строке оставить только те  слова, в которых встречаются подряд идущие одинаковые буквы*/

void main()

{
	system("chcp 1251");
	
	int cword = 0, let = 0, ex = 0;
	int max = 0, num = 0, k=0, i = 0, j=0, leigth = 0, beg = 0;
	
	FILE *fin; // входной файл
	FILE *fout; // выходной файл
	char *str;
	char *ptr;
	char **strs;
	char *space;
	char ch;

	fopen_s(&fin, "F1.txt", "rt"); // открыть файл для чтения
	if (fin == NULL)
		return; // ошибка при открытии файла
	fopen_s(&fout, "F2.txt", "wt"); // открыть файл для записи
	if (fout == NULL)
		return; // ошибка при открытии файла
	fseek(fin, 0, SEEK_END);
	j = ftell(fin);
	while (i<=j)
	{

		
		fseek(fin, i, SEEK_SET);
		ch = getc(fin);
		if ((ch == '\n') || (ch=='\0'))
		{
			k++;
			if (leigth < (i - beg))
			{
				
				leigth = (i - beg)+1;
			}
			beg = i;
		}
		i++;
		
	}
	k = (k / 2) + 1;
	fseek(fin, 0, SEEK_SET);
	
	strs = (char**)malloc(k*sizeof(char*));
	for (i=0; i<k; i++)
	{
		strs[i] = (char*)malloc(leigth+1 * sizeof(char));
	}
	str = (char*)malloc(leigth+1 * sizeof(char));
	i = 0;
	j = 0;
	while (i<=(k-1))
	{
		ptr = fgets(str, leigth+1, fin);
		
		while (str[j]!='\0')
		{
			j++;
		}
		if (i == k-1)
		{
			str[j-1] = '\n';
			str[j] = '\0';
		}
		memcpy(strs[i], str, (j+1));
		j = 0;
		i++;
	}
	
	for (j = 0; j < k; j++)
	{
		for (i = j; i < k; i++)
		{
			ptr = strs[i];
			while (*ptr != '\0')
			{

				if ((*ptr == ' ' || *ptr == '\0') && (*(ptr-1) > '!' || *(ptr-1) < 'я'))
				{
						cword++;			//счетчик слов
				}
				
				ptr++;
			}
			printf("\n Кол-во слов=%d", cword);
			printf(" строка = %s", strs[i]);
			//system("pause");
			if (cword > max)
			{
				max = cword;
				str = strs[j];
				strs[j] = strs[i];
				strs[i] = str;
				i = j;
				
			}
			
			cword = 0;
		}
		max = 0;
	}
	

	for (i = 0; i < k; i++)
	{
		fputs(strs[i], fout);
	}	
	free(str);
	free(strs);
	fclose(fin);
	fclose(fout);
}
