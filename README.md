1-3
#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    printf("Залание 1-3\n");
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    printf("\n");

    int *a = (int *)malloc(size * sizeof(int)); 
    srand(time(0));
    
    for (int i = 0; i < size; i++) {
        a[i] = rand();
        printf("Элемент %d: %d\n", i + 1, a[i]);
    }

	int min=a[0], max=a[0];
	for (int i = 1; i < size; i++){
		if (max < a[i])
		max = a[i];
		if (min > a[i])
		min = a[i];
		}

    printf("\nМаксимальное: %d\nМинимальное: %d\n", max, min);
    
    free(a);
    getch();
    return 0;
}




4
#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    
    setlocale(LC_ALL, "Russian");
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);
    
	int** mtr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mtr[i] = (int*)malloc(cols * sizeof(int));
    }
    
    int* rS = (int*)malloc(rows * sizeof(int));
    int* cS = (int*)malloc(cols * sizeof(int));
    
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < rows; i++) {
        rS[i] = 0;
        for (int j = 0; j < cols; j++) {
            mtr[i][j] = rand() % 100; // числа от 0 до 99
        }
    }
    
    for (int j = 0; j < cols; j++) {
        cS[j] = 0;
    }
    // Вычисление сумм 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rS[i] += mtr[i][j];
            cS[j] += mtr[i][j];
        }
    }
    // Вывод матрицы 
    printf("Матрица %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", mtr[i][j]);
        }
        printf(" | Сумма строки: %d\n", rS[i]);
    }
    
    for (int j = 0; j < cols; j++) {
        printf("----");
    }
    printf("\n");
    
    for (int j = 0; j < cols; j++) {
        printf("%4d", cS[j]);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        free(mtr[i]);
    }
    free(mtr);
    free(rS);
    free(cS);
   
	getch ();
	return 0;
}




5
#include "stdafx.h"
#include <conio.h>
#include <Windows.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    struct Student {
        char lastName[50];
        char firstName[50];
        int age;
        char group[20];
    };
	SetConsoleOutputCP(1251); //подключение русс яз
	SetConsoleCP(1251);

    struct Student students[5] = {
        {"Иванов", "Иван", 20, "24ВВВ1"},
        {"Петров", "Петр", 21, "24ВВВ2"},
        {"Сидорова", "Мария", 19, "24ВВВ1"},
        {"Кузнецов", "Алексей", 20, "24ВВВ2"},
        {"Смирнова", "Елена", 22, "24ВВВ3"}
    };
    
    int choice = 1;
    int count = 4;
    
    while (choice != 0) {
        printf("\n=== Система поиска студентов ===\n");
        printf("1. Поиск по фамилии\n");
        printf("2. Поиск по имени\n");
        printf("3. Поиск по возрасту\n");
        printf("4. Поиск по группе\n");
        printf("5. Показать всех студентов\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        
        
        char sName[50];
        char sFName[50];
        int sAge;
        char sGroup[20];
        int found;
        int i;
        
        if (choice == 1) { // По фамилии
            printf("Введите фамилию для поиска: ");
            scanf("%s", sName);
            
            printf("\nРезультаты поиска по фамилии '%s':\n", sName);
            found = 0;
            for (i = 0; i < count; i++) {
                if (strcmp(students[i].lastName, sName) == 0) {
                    printf("Студент %d: %s %s, возраст: %d, группа: %s, средний балл: %.2f\n",
                           i + 1, students[i].lastName, students[i].firstName,
                           students[i].age, students[i].group);
                    found = 1;
                }
            }
        }
        else if (choice == 2) { // По имени
            printf("Введите имя для поиска: ");
            scanf("%s", sFName);
            
            printf("\nРезультаты поиска по имени '%s':\n", sFName);
            found = 0;
            for (i = 0; i < count; i++) {
                if (strcmp(students[i].firstName, sFName) == 0) {
                    printf("Студент %d: %s %s, возраст: %d, группа: %s, средний балл: %.2f\n",
                           i + 1, students[i].lastName, students[i].firstName,
                           students[i].age, students[i].group);
                    found = 1;
                }
            }
            if (!found) {
                printf("Студенты не найдены!\n");
            }
        }
        else if (choice == 3) { // По возрасту
            printf("Введите возраст для поиска: ");
            scanf("%d", &sAge);
            
            printf("\nРезультаты поиска по возрасту '%d':\n", sAge);
            found = 0;
            for (i = 0; i < count; i++) {
                if (students[i].age == sAge) {
                    printf("Студент %d: %s %s, возраст: %d, группа: %s, средний балл: %.2f\n",
                           i + 1, students[i].lastName, students[i].firstName,
                           students[i].age, students[i].group);
                    found = 1;
                }
            }
        }
        else if (choice == 4) { // По группе
            printf("Введите группу для поиска: ");
            scanf("%s", sGroup);
            
            printf("\nРезультаты поиска по группе '%s':\n", sGroup);
            found = 0;
            for (i = 0; i < count; i++) {
                if (strcmp(students[i].group, sGroup) == 0) {
                    printf("Студент %d: %s %s, возраст: %d, группа: %s, средний балл: %.2f\n",
                           i + 1, students[i].lastName, students[i].firstName,
                           students[i].age, students[i].group);
                    found = 1;
                }
            }
        }
        else if (choice == 5) { // Показать всех студентов
            printf("\nСписок всех студентов:\n");
            for (i = 0; i < count; i++) {
                printf("Студент %d: %s %s, возраст: %d, группа: %s, средний балл: %.2f\n",
                       i + 1, students[i].lastName, students[i].firstName,
                       students[i].age, students[i].group);
            }
        }
        else if (choice == 0) { // Выход
            printf("Выход из программы...\n");
        }
	}
    
	getch ();
    return 0;
}
