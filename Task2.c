#include "functions.h"

void InterStackInOrder(int max_size, stack** top, int* size)
{
	int num;
	if (*size == max_size)
	{
		printf("Вы не можете добавить элемент\n");
		return;
	}
	printf("Введите элемент:\n");
	integerVerification(&num, INT_MIN, INT_MAX);
	if(*top!=NULL && num<=(*top)->data){
		printf("Ошибка. Элемент должен быть больше предыдущего.\n");
		return;
	}
	*top = push(*top, num);
	(*size)++;
}

stack* CreateThirdIncreasingStack(stack * top, stack* top1)
{
	stack* pos1 = top;
	stack* pos2 = top1;
	stack* pos3 = NULL;
	while (pos1 != NULL && pos2 != NULL)
	{
		if (pos1->data >= pos2->data)
		{
			pos3=push(pos3, pos1->data);
			pos1=pop(pos1);
		}
		else
		{
			pos3=push(pos3, pos2->data);
			pos2=pop(pos2);
		}
	}
	if (pos1 == NULL)
	{
		while (pos2 != NULL)
		{
			pos3=push(pos3, pos2->data);
			pos2=pop(pos2);
		}
	}
	else
		while (pos1 != NULL)
		{
			pos3=push(pos3, pos1->data);
			pos1=pop(pos1);
		}
	return pos3;
}

stack* show(stack* top)
{
	stack* pos = top;
	while (pos != NULL)
	{
		printf("%d\n", pos->data);
		pos = pos->next;
	}
}

void Task2()
{
	stack* top = NULL, * top1 = NULL,*top2=NULL;
	Task2Menu(top,top1,top2);
	FreeStack(top);
	FreeStack(top1);
	FreeStack(top2);
}

void Task2Menu(stack * top,stack * top1, stack* top2) {
	int max_size=0;
	int size1 = 0, size2 = 0;
	printf("Выберите действие.");
	printf("\n+================================+\n1.Задать максимальное количество элементов.\n2.Добавить элемент в первый стек.\n3.Добавить элемент во второй стек.\n4.Вывести новый стек по возрастанию.\n5.Конец программы.\n+================================+\n\n");
	int answer;
	do {
		answer = 0;
		printf("\nВыберите пункт из меню.\n\n");
		while (answer < '1' || answer > '7') answer = _getch();
		if (answer == '1') {
			printf("Введите максимальный размер стеков:\n");
			integerVerification(&max_size, 1, INT_MAX);
		}
		else if (answer == '2') {
			if (max_size == 0)
			{
				printf("Задайте размер стека.\n");
				continue;
			}
			InterStackInOrder(max_size, &top, &size1);
		}
		else if (answer == '3') {
			if (max_size == 0)
			{
				printf("Задайте размер стека.\n");
				continue;
			}
			InterStackInOrder(max_size, &top1, &size2);
		}
		else if (answer == '4') {
			top2 = CreateThirdIncreasingStack(top, top1);
			show(top2);
		}
	} while (answer != '5');
}
