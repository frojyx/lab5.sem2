#include "functions.h"

void menu()
{
	int n = 0;
	printf("Выберите номер задания.(1 или 2)\n");
	while (n < '1' || n > '2') n = _getch();
	if (n == '1') Task1();
	else Task2();
}

int integerVerification(int* value, int min, int max)
{
    setlocale(0, "ru");
    int indexChar;

    while (1)
    {
        char* temp = NULL;
        char* new_temp;
        temp = (char*)malloc(1 * sizeof(char));
        indexChar = 0;

        while (1)
        {
            new_temp = (char*)realloc(temp, (1 + indexChar) * sizeof(char));
            if (new_temp == NULL)
            {
                printf("Ошибка распределения памяти");
                free(temp);
                return;
            }
            temp = new_temp;
            temp[indexChar] = _getch();

            if (temp[indexChar] == ENTER && indexChar != 0)
                break;
            if (temp[indexChar] == '\b')
            {
                indexChar--;
                if (indexChar < 0)
                {
                    indexChar = 0;
                    continue;
                }
                temp[indexChar] = ' ';
                printf("\b \b");
                continue;
            }
            if (temp[indexChar] == '-' && indexChar == 0)
            {
                printf("%c", temp[indexChar]);
                indexChar++;
                continue;
            }
            if ((indexChar > INT_LIMIT && *temp == '-') || (indexChar > INT_LIMIT - 1 && *temp != '-'))
            {
                puts("\n"RED"\tОшибка, достигнуто максимальное количество символов типа данных Int, повторите ввод"END"\n");
                indexChar = 0;
                continue;
            }
            if (*temp == '0' && (*(temp + 1) >= '0' && *(temp + 1) <= '9'))
            {
                printf("\n"RED"\tОшибка, число не может начинаться с нуля, повторите ввод"END"\n");
                indexChar = 0;
                continue;
            }
            if (*temp == '-' && (*(temp + 1) == '0'))
            {
                printf("\n"RED"\tОшибка, ноль не может быть отрицательным, повторите ввод"END"\n");
                indexChar = 0;
                continue;
            }
            if (atoi(temp) == INT_MAX || atoi(temp) == INT_MIN)
            {
                puts("\n"RED"\tОшибка, вы ввели число не из промежутка числа типа данных Int, повторите ввод!"END"");
                indexChar = 0;
                continue;
            }

            if (temp[indexChar] >= '0' && temp[indexChar] <= '9')
            {
                printf("%c", temp[indexChar]);
                indexChar++;
            }
        }
        temp[indexChar] = '\0';
        *value = atoi(temp);
        free(new_temp);
        printf("\n");
        if (*value >= min && *value <= max)
        {
            temp[indexChar] = '\0';
            return 0;
        }
        else
        {
            printf("\n"RED"\tОшибка ввода. Пожалуйста, введите целое число в диапазоне от %d до %d"END"\n", min, max);
            indexChar = 0;
        }
    }
}
