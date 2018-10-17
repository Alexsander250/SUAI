#include <stdio.h>

/*В символьной строке оставить только те  слова, в которых встречаются подряд идущие одинаковые буквы*/

void main()

{
	system("chcp 1251");
	char str[1488];
	int ch = 0, cword = 0, let = 0, ex = 0;
	int Num = 0;

	printf("Введите номер удаляемого слова\n");
	if (scanf_s("%d", &Num) != 1) { printf("Не правильный ввод данных, перезапуск программы...\n"); system("pause"); return; }
	if (Num < 0) { printf("Не правильный ввод данных, перезапуск программы...\n"); system("pause"); return; }
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
	
	fseek(fin, 0, SEEK_SET);
	int a = ftell(fin);
	fseek(fin, 0, SEEK_END);
	int n = ftell(fin);
	int c = n - a;
	c = c*(-1);
	n = -1;
	//int n;
	//char t;
	system("pause");
	while (n != c-1)
	{
		fseek(fin, n, SEEK_END);
		str[0] = getc(fin);
		str[1] = '\0';
		n--;
		printf("%s", str);
		system("pause");
		fputs(str, fout);
	}
	fclose(fin);
	fclose(fout);
}
