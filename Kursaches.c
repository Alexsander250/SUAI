#include <stdio.h>


typedef struct
{
	int Day, Month, Year;
}Date;

typedef struct
{
	char FIO[30];  //240
	char Pol;//8
	char Obr;//8
	int gr;//16
	char Stip; //8
	Date DateR; //48
	int Ocen[5]; //80
}Stud;

char name[200];



int open()
{
	system("cls");
	FILE *Fin, *Fout;
	do
	{
		printf("Введите путь к файлу и имя файла\n");
		gets(name);
	} while (name[0] == '\0');
	
	
	
	
	fopen_s(&Fin, name, "rt");
	if (Fin == NULL)
	{
		printf("ukazannogo puti net");
		system("pause");
		return 1;
	}
	/*fseek(Fin, 0, SEEK_END);
	int size = ftell(Fin);
	int kol = size / 51;*/
	Stud meat[50];
		
	
	int i = 1;
	while (!feof(Fin))
	{
		fscanf_s(Fin, "%s %c %c %d %c %d %d %d", &meat[i].FIO, &meat[i].Pol, &meat[i].Obr, &meat[i].gr, &meat[i].DateR.Day, &meat[i].DateR.Month, &meat[i].DateR.Year);
		for (int j = 0; j < 5; j++)
		{
			fscanf_s(Fin, "%d", &meat[i].Ocen[j]);
		}
		i++;
	}
	system("pause");
	
}


void create()
{
	char way[100];
	system("cls");
	printf("Создание файла БД\nВВедите путь и название файла\n");
	do
	{
		gets(way);
	} while (way[0] == '\0');
	FILE *F1;
	fopen_s(&F1, way, "wb");
	fclose(F1);
	printf("Файл был создан по пути %s", way);
	open();
}






void main()
{
	system("chcp 1251");
	int a;
	printf("                              ДеканатOS\n");
	printf("______________________________________________________________\n");

	printf("1. Открыть файл с БД\n2. Создать файл с БД\n");
	//printf("");
	scanf_s("%d", &a);
	
	switch(a)
	{
		case 1: 
			open();
			break;
		case 2: 
			create();
			system("pause");
			break;
	}



}
