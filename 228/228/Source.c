#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

void one()
{
	int sign = -1, N = 3;
	float x = 1, ch, a, s;
	printf("�� ��������� �������� �.�. �1\n");
	printf("enter N = ");
	scanf_s("%i", &N);
	printf("enter x = ");
	scanf_s("%f", &x);
	s = x;
	ch = x;
	for (int i = 2; i <= N; i++)
	{
		ch = ch*x;
		a = (ch / i)*sign;
		s = s + a;
		sign = -sign;
	}
	printf("s=%5.3f\n", s);
	system("pause");
	
}

void four()
{
	printf("�� ��������� �������� �.�. �4 \n");
	int i, mass[10], summ = 0, sr;
	for (i = 0; i <= 9; i++)
	{
		printf("������� %i", i + 1);
		printf(" ���� ������� = ");
		scanf_s("%i", &mass[i]);
		summ = summ + mass[i];
	}
	sr = summ / 10;
	printf("������� �������������� (����� �����)=  %i\n", sr);
	for (i = 0; i <= 9; i++)
	{
		if (mass[i] <= sr) { mass[i] = 0; }

		printf("���� ������� mass[ %i", i + 1);
		printf("]= %i\n", mass[i]);
		system(" ");

	}
	system("pause");
	
}

void five()
{
	printf("�� ��������� �������� �.�. �5\n");
	int summ = 0, s = 0, min = INT_MAX;
	int mass[3][2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("������� %i", i + 1);
			printf(", %i", j + 1);
			printf(" ���� ������� = ");
			scanf_s("%i", &mass[i][j]);
			summ = summ + mass[i][j];
		}
		if (summ < min) { min = summ; summ = 0; s = i; }
	}

	for (int j = 0; j < 2; j++)
	{
		mass[s][j] = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("���� ������� mass[ %i", i + 1);
			printf("] [ %i", j + 1);
			printf("]= %i\n", mass[i][j]);
		}

	}
	system("pause");
	
}


void six()
{
	printf("�� ��������� �������� �.�. �6\n");
	int n, raz = 1, o = 0;
	printf("������� ����� N\n");
	scanf_s("%i", &n);
	int n1 = n;
	while ((n1 /= 10) != 0)
	{
		raz++;
	}
	o = n % 10;
	while (o != 1)
	{
		o = n % 10;
		
		n /= 10;
			
		if (o == 1) {break; }
		raz--;
	}
	printf("������� ������� ���������� � ���������: %i\n", raz);
	system("pause");
	
}


void main()
{
	system("chcp 1251");
	int num;
	printf("������� ����� ������������ ������ (��� ������ �� ��������� ������� 0) = \n");
	scanf_s("%i", &num);
	switch (num)
	{
	case 0: break;
	case 1: one();
		break;
	case 4: four();
		break;
	case 5: five();
		break;
	case 6: six();
		break;
	default:
		break;
	}


}