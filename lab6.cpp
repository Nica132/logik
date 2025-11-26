#define _CRT_SECURE_NO_WARNINGS
#include "locale"
#include "stdio.h"
#include "conio.h"
#include <locale.h> 
#include <stdlib.h>
#include <malloc.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int v1, v2;
	int** M1;
	int** M2;
	int** N3;
	int** N2;
	int** N;
	int** E;

	printf("Введите размерность матрицы М1\n");
	scanf("%d", &v1);
	printf("Введите размерность матрицы М2\n");
	scanf("%d", &v2);
	int l = 0, k = 0;
	int vr = 0;
	int q1, q2;
	int w = v2 + 1;
	M1 = (int**)malloc(v1 * sizeof(int*));
	M2 = (int**)malloc(v2 * sizeof(int*));
	N = (int**)malloc(v2 * sizeof(int*));
	N2 = (int**)malloc(v2 * sizeof(int*));
	N3 = (int**)malloc(w * sizeof(int*));
	E = (int**)malloc(50 * sizeof(int*));
	for (int i = 0; i < 50; i++)
	{
		E[i] = (int*)malloc(50 * sizeof(int));
	}
	for (int i = 0; i < w; i++)
	{
		N3[i] = (int*)malloc(w * sizeof(int));
	}
	for (int i = 0; i < v2; i++)
	{
		N[i] = (int*)malloc(v2 * sizeof(int));
	}
	for (int i = 0; i < v2; i++)
	{
		N2[i] = (int*)malloc(v2 * sizeof(int));
	}
	if ((v2 == 1) || (v2 == 0)) {
		printf("Матрица не может быть размерностью 0 или 1, там дальше по заданиям \n нужно вводить 2 веришины, а откуда мы их возьмём, если массив 1 или 0\n\n");
	};
	printf("задание 1\n");
	for (int i = 0; i < v1; i++) {
		M1[i] = (int*)malloc(v1 * sizeof(int));
		for (int j = 0; j < v1; j++) {
			M1[i][j] = rand() % 2;
			printf("%5d ", M1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < v2; i++) {
		M2[i] = (int*)malloc(v2 * sizeof(int));
		for (int j = 0; j < v2; j++) {
			M2[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < v2; i++)
	{
		for (int j = 0; j < v2; j++)
		{
			printf("%5d ", M2[i][j]);
		}
		printf("\n");
	}
	printf("Задание 2\n");
	printf("Отождествление вершин\n");
	printf("\nВведите две вершины\n");
	scanf("%d%d", &q1, &q2);
	for (int j = 0; j < v2; j++) {
		for (int i = 0; i < v2; i++)
		{
			N[i][j] = M2[i][j];
			vr = M2[i][q1];
			if ((N[i][q2] || vr) == 1) {
				N[i][q2] = 1;
			}
			else
			{
				N[i][q2] = 0;
			};
			N[i][q1] = 0;
		}
	}
	for (int i = 0; i < v2; i++) {
		for (int j = 0; j < v2; j++)
		{
			vr = M2[q1][j];
			if ((N[q2][j] || vr) == 1) {
				N[q2][j] = 1;
			}
			else
			{
				N[q2][j] = 0;
			};
			N[q1][j] = 0;
		}
	}
	for (int i = 0; i < v2; i++) {
		k = 0;
		if (i == q1) {
			continue;
		};
		for (int j = 0; j < v2; j++)
		{
			if (j != q1) {
				N2[l][k] = N[i][j];
				k++;
			};
		}
		l++;
	}
	for (int i = 0; i < v2 - 1; i++) {
		for (int j = 0; j < v2 - 1; j++)
		{
			printf("%5d", N2[i][j]);
		}
		printf("\n");
	}
	printf("\nСтягивание ребра");
	printf("\nВведите 2 вершины\n");
	scanf("%d%d", &q1, &q2);
	vr = 0;
	for (int j = 0; j < v2; j++) {
		for (int i = 0; i < v2; i++)
		{
			N[i][j] = M2[i][j];
			vr = M2[i][q1];
			if ((N[i][q2] || vr) == 1) {
				N[i][q2] = 1;
			}
			else
			{
				N[i][q2] = 0;
			};
			N[i][q1] = 0;
		}
	}
	for (int i = 0; i < v2; i++) {
		for (int j = 0; j < v2; j++)
		{
			vr = M2[q1][j];
			if ((N[q2][j] || vr) == 1) {
				N[q2][j] = 1;
			}
			else
			{
				N[q2][j] = 0;
			};
			N[q1][j] = 0;
		}
	}
	for (int i = 0; i < v2; i++) {
		for (int j = 0; j < v2; j++)
		{
			if (N[q2][q2] == 1) {
				N[q2][q2] = 0;
			};
		}
	}
	l = 0;
	for (int i = 0; i < v2; i++) {
		k = 0;
		if (i == q1) {
			continue;
		};
		for (int j = 0; j < v2; j++)
		{
			if (j != q1) {
				N2[l][k] = N[i][j];
				k++;
			};
		}
		l++;
	}
	for (int i = 0; i < v2 - 1; i++) {
		for (int j = 0; j < v2 - 1; j++)
		{
			printf("%5d", N2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int vver;
	int nov = 0;
	printf("\nРасщепление вершины");
	printf("\nВведите вершину\n");
	scanf("%d", &vver);
	for (int j = 0; j < v2; j++) {
		for (int i = 0; i < v2; i++)
		{
			N3[i][j] = M2[i][j];
			if (i == v2) {
				N3[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++)
		{
			if (j == v2) {
				N3[i][j] = 0;
			}
		}
	}
	for (int j = 0; j < w; j++) {
		for (int i = 0; i < w; i++)
		{
			if (i == v2) {
				N3[i][j] = 0;
			}
		}
	}
	for (int j = 0; j < v2; j++) {
		for (int i = 0; i < w; i++) {
			if (j % 2 == 0 && N3[vver][j] == 1)
			{
				N3[vver][j] = 0;
				N3[v2][j] = 1;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < v2; i++) {
		for (int j = 0; j < w; j++) {
			if (i % 2 == 0 && N3[i][vver] == 1)
			{
				N3[i][vver] = 0;
				N3[i][v2] = 1;
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++)
		{
			if (i == vver)
			{
				N3[i][v2] = 1;
			}
			if (i == v2)
			{
				N3[i][vver] = 1;
			}
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			printf("%5d,", N3[i][j]);
		}
		printf("\n");
	}
	printf("\n\nЗадание 3. Объединение графов \n");
	printf("\nОбъединение графов\n");
	int r;
	if (v1 >= v2)
	{
		w = v2;
		r = v1;
	}
	else {
		w = v1;
		r = v2;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++)
		{
			if (v2 >= v1)
			{
				E[i][j] = M2[i][j];
			}
			else {
				E[i][j] = M1[i][j];
			}
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			if ((M1[i][j] || M2[i][j]) == 1) {
				E[i][j] = 1;
			}
			else
			{
				E[i][j] = 0;
			}
		}
	}
	printf("\n\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			printf("%5d,", E[i][j]);
		}
		printf("\n");
	}
	printf("\nПересечение графов \n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++)
		{
			E[i][j] = 0;
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			if ((M1[i][j] && M2[i][j]) == 1) {
				E[i][j] = 1;
			}
			else
			{
				E[i][j] = 0;
			}
			//printf("%5d", N[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			printf("%5d,", E[i][j]);
		}
		printf("\n");
	}
	printf("\nКольцевая сумма графов\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++)
		{
			if (v2 <= v1)
			{
				E[i][j] = M1[i][j];
			}
			else {
				E[i][j] = M2[i][j];
			}
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			if ((M1[i][j] ^ M2[i][j]) == 1) {
				E[i][j] = 1;
			}
			else
			{
				E[i][j] = 0;
			}
		}
		printf("\n");
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			printf("%5d,", E[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < v2; i++)
		free(M2[i]);
	free(M2);
	getchar();
	for (int i = 0; i < v2; i++)
		free(N2[i]);
	free(N2);
	getchar();
	for (int i = 0; i < v2; i++)
		free(N[i]);
	free(N);
	getchar();   getchar();
	for (int i = 0; i < w; i++)
		free(N3[i]);
	free(N3);
	getchar();   getchar();
	for (int i = 0; i < r; i++)
		free(E[i]);
	free(E);
	getchar();
}
