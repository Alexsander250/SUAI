#include <stdio.h>

/*В символьной строке оставить только те  слова, в которых встречаются подряд идущие одинаковые буквы*/

void main()

{
	system("chcp 1251");
	char str[100];
	int sp = 0;
	do
	{
		printf("Введите строчку\n");
		gets(str);
	} while (str[0] == '\0');

	char *ptr;                                      //Объявление указателеля для первого проверяемого символа
	char *ptr2;                                     //Объявление указателеля для второго проверяемого символа
	char *space;                                   //Объявление указателеля для пробела
	ptr = &str[0];
	ptr2 = &str[1];
	space = ptr;                                  //адрес пробела в начале программы взят с -1 т.к. в цикле удаления слова в начале происходит имплекация


	do                                              //цикл проверки строки
	{

		if ((*ptr == *ptr2) && (((*ptr >= 'A') && (*ptr <= 'z')) || ((*ptr >= 'А') && (*ptr <= 'я'))) && (*ptr!='[') && (*ptr != ']') && (*ptr != '^') && (*ptr != '_'))                          //Проверка на равные символы
		{
			sp = 1;                             //установка флага на нахождение подряд идущих символов в слове (именно символ не буквы, проверку на знаки препинания не получилось реализовать)
		}

		if ((*ptr2 == ' ') || (*ptr2 == '\0'))       //проверка на окончание слова

		{

			if (sp == 0)                            //проверка есть ли в слове подряд идущие символы
			{
				ptr = space;                        //установка первого указателя на предидущий пробел

				while (*space != '\0')
				{
					*space = *ptr2;
					space++;
					ptr2++;
				}; //цикл удаления слова
				ptr2 = ptr + 1;                     //установка второго указателя на первую букву слова
				space = ptr;
			}

			else
			{
				space = ptr2;
				sp = 0;
			}
		}
		ptr2++;
		ptr++;

	} while (*ptr != '\0');
	printf("Обработанная строка\n");
	printf("%s", str);                                      //вывод результата
	printf("\n");
	system("pause");

}
