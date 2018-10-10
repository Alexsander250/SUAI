#include <stdio.h>

/*В символьной строке оставить только те  слова, в которых встречаются подряд идущие одинаковые буквы*/

void main()

{
	system("chcp 1251");
	char str[1488];
	int ch = 0, cword = 0,  let = 0, ex=0;
	int Num = 0;

	printf("Введите номер удаляемого слова\n");
	if (scanf_s("%d", &Num) != 1) { printf("Не правильный ввод данных, перезапуск программы...\n"); system("pause"); return; }
	FILE *fin; // входной файл
	FILE *fout; // выходной файл
	char *ptr;
	char *space;

	
	fopen_s(&fin, "text.txt", "rt"); // открыть файл для чтения
	if (fin == NULL)
		return; // ошибка при открытии файла
	fopen_s(&fout, "result.txt", "wt"); // открыть файл для записи
	if (fout == NULL)
		return; // ошибка при открытии файла
	while (!feof(fin))
	{
		ptr = fgets(str, 1024, fin);

		space = &str[0];
		if (ptr == NULL)
			break;
		int dl = strlen(str);
			for (int i = 0; i!=dl+1; i++)
		{
			
			if ((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'А' && *ptr <= 'я') && (*ptr != '[') && (*ptr != ']') && (*ptr != '^') && (*ptr != '_'))	//проверка на нахождение букв между разделителями слов
			{
				ch++;
			}

			if (*ptr == ' ' || *ptr == '\0')
			{
				if (ch > 0)
				cword++;			//счетчик слов
				ch = 0;
			}

			if ((cword == Num) && (*ptr == ' ' || *ptr == '\0'))			
			{
				while ((*space++ = *ptr++) != '\0');		//удаление N ого слова 
				break;
			}
			if (*ptr == '\0')
			{
				*(ptr+1) = '\n';
				break;
			}
			if (*ptr == ' ')
			{
				space = ptr;	//постановка указателя на разделитель слов
			}
			*ptr++;
		}


		cword = 0;
		if (str[0]!='\0')
		{
			str[strlen(str) - 1] = '\n';
		}
		
		fputs(str, fout);
	}
	fclose(fin);
	fclose(fout);
}
