#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <limits.h>	

#define RED "\033[31m"   
#define END "\033[0m"    
#define ENTER 13        
#define INT_LIMIT 10     

typedef struct stack{
	int data;
	struct stack* next;
}stack;


void menu();
stack* push(stack* top, int data);
stack* pop(stack* top);
void InterStack(int max_size, stack** top, int* size);
void FreeStack(stack* top);
int FindElements(stack* top, int value);
void SubstractFromStackAndShow(stack* top, stack* top1);
void Task1();
void Task1Menu(stack* top, stack* top1);
stack* show(stack* top);
void InterStackInOrder(int max_size, stack** top, int* size);
stack* CreateThirdIncreasingStack(stack* top, stack* top1);
stack* show(stack* top);
void Task2();
void Task2Menu(stack* top, stack* top1, stack* top2);
int integerVerification(int* value, int min, int max);
