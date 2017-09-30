#include "stdafx.h" // include-файл
#include <stdlib.h> //подключение стандартной библиотеки
#include <stdio.h> //  для ввода-вывода
#include <conio.h> // для работы с консолью
#include <iostream> // заголовочный файл с классами, функциями и переменными для организации ввода-вывода 
using namespace std;
void error();


struct node {
	int item;// элемент
	node *next; // указатель на предыдущий элемент
    node *top; // указатель на топ
};

void initialise (node *s) {     // инициализация стека
	s->top = NULL; // вершина стека указывает на нуль
}

int push(node *s, int value) {  // Добавляет элементы в стек
	int temp;
	node* p = new node;  // динамически распределяем память для вводимых элементов
	if (p == NULL) error();   // Ошибка, если память не была распределена
	p->item = value; // распределяем значение
	p->next = s->top; // копируем адрес элемента 
	s->top = p; // топ указывает на последний введённый элемент
	temp = s->top->item; // локальная переменная несёт значение последнего введённого элемента - топа
	return temp;// выводит по-порядку записанные в стек элементы
}

int pop(node *s) {   // Удаляет элементы из стека
	int temp;
	node *p;
	if (s->top == NULL) error(); // Если нет элементов, выдаёт ошибку
	p = s->top; // p указывает на вершину стека
	temp = s->top->item; // переменная несёт значение удаляемого топа
	s->top = p->next; // передвигает указатель топа на следующий элемент
	delete(p); // удаляет адрес, на который указывает p (адрес предыдущей вершины) 
	return temp; // возвращает значение элемента, удалённого из стека
}

void error()
{
	cout << "Stack's empty" << endl;
	_gettch();
}

void process()
{
	int n; // переменная со значением количества вводимых элементов 
	node S;
	cout << "How many elements should it be in the Stack?" << endl; //вводим n
	cin >> n;
	cout << endl;
	if (n <= 0) error(); //если введено отрицицательное число или нуль, выдаёт ошибку
	else
	{
		cout << "Inputed elements:" << endl;
		for (int i = 0; i < n; i++)
			cout << push(&S, rand() % 9 + 1) << endl; // вводит рандомные значения элементов
		cout << endl;
		cout << "Deleted data:" << endl;// выводит удалённые значения
		for (int i = 0; i < n; i++)
			cout << pop(&S) << endl;
	}
}

int main() {
	node S; // стек
	initialise(&S); // инициализация элементов стека
	process();
	_gettch();
	return 0;
}
