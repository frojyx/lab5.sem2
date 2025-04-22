#include "functions.h"

stack* push(stack* top,int data)
{
	stack * ptr = malloc(sizeof(stack));
	ptr->data = data;
	ptr->next = top;
	return ptr;
}

stack* pop(stack* top)
{
	if (top == NULL)
		return top;
	stack* ptr_next = top->next;
	free(top);
	return ptr_next;
}

void InterStack(int max_size, stack** top, int* size)
{
	int num;
	if (*size == max_size)
	{
		printf("Вы не можете добавить элемент\n");
		return;
	}
	printf("Введите элемент:\n");
	integerVerification(&num, INT_MIN, INT_MAX);
	*top = push(*top, num);
	(*size)++;	
}

void FreeStack(stack *top)
{
	while (top != NULL)
		top = pop(top);
}

int FindElements(stack* top,int value)
{
	stack* pos = top;
	while (pos != NULL)
	{
		if (pos->data == value)
			return 1;
		pos = pos->next;
	}
	return 0;
}

void SubstractFromStackAndShow(stack* top,stack * top1)
{
	stack* pos = top;
	while (pos != NULL)
	{
		if(FindElements(top1,pos->data)==0)
			printf("%d\n", pos->data);
		pos = pos->next;
	}
}

void Task1()
{
	stack* top = NULL,*top1=NULL; 	
	Task1Menu(top,top1);
	FreeStack(top);
	FreeStack(top1);
}

void Task1Menu(stack* top,stack * top1) {

	int answer;
	int first_size=0, second_size=0;
	int size1 = 0, size2 = 0;
	printf("Выберите действие.");
	printf("\n+================================+\n1.Ввод первого стека.\n2.Ввод второго стека.\n3.Добавить элемент в первый стек.\n4.Добавить элемент во второй стек.\n5.Вывод элементов из первого стека,которых нет во втором стеке.\n6.Конец программы.\n+================================+\n\n");
	do {
		answer = 0;
		printf("\nВыберите пункт из меню.\n\n");
		while (answer < '1' || answer > '7') answer = _getch();
		if (answer == '1') {
			printf("Введите максимальный размер первого стека:\n");
			integerVerification(&first_size, 1, INT_MAX);
			InterStack(first_size, &top, &size1);
		}
		else if (answer == '2') {
			printf("Введите максимальный размер второго стека:\n");
			integerVerification(&second_size, 1, INT_MAX);
			InterStack(second_size, &top1, &size2);
		}
		else if (answer == '3') {
			if (first_size == 0)
			{
				printf("Задайте размер стека.\n");
				continue;
			}
			InterStack(first_size, &top, &size1);
		}
		else if (answer == '4') {
			if (second_size == 0)
			{
				printf("Задайте размер стека.\n");
				continue;
			}
			InterStack(second_size, &top1, &size2);
		}
		else if (answer == '5') {
			SubstractFromStackAndShow(top, top1);
		}
	} while (answer != '6');
}
