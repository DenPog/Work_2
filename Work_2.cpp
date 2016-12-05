// Work_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

int a, b, c;

void ShowMenu(int iItem)
{
	system("cls");
	printf("%s1 - Сложение\n", iItem == 1 ? ">" : " ");
	printf("%s2 - Вычитание\n", iItem == 2 ? ">" : " ");
	printf("%s3 - Возведение в степень\n", iItem == 3 ? ">" : " ");
	printf("%s4 - Выход\n", iItem == 4 ? ">" : " ");
	
}

int sum() 
{

	cout << "Введите два числа для сложения, подтверждая ввод клавишей 'enter':  " << endl;
	cin >> a;
	cin >> b;
	
	c = a + b; 

	return c;
}

int m_1()
{
	cout << "Введите два числа для вычитания, подтверждая ввод клавишей 'enter':  " << endl;
	cin >> a;
	cin >> b;

	c = a - b;

	return c;
}

int sqrt()
{
	cout << "Введите число для возведения в степень:  " << endl;
	cin >> a;
	cout << "Введите степень в которую необходимо возвести число:  " << endl;
	cin >> b;

	int m=a;

	for (int i = 1; i < b; i++)
	{
		a = a*m;
	}

	return a;
}

int fin()
{
	cout << "//---------------------------------------------------------------//" << endl;
	cout << "//---------------------------------------------------------------//" << endl;
	cout << "Благодарим за использование нашего калькулятора!" << endl;
	system("pause");
	return 0;
}

int main()
{
	setlocale(0, "");

	int iItem = 1;//Отвечает какой пункт меню активен в данный момент
	int nLast = 4;//Отвечает какой индекс у последнего пункта меню
	
	ShowMenu(iItem);

	while (TRUE)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (0 < iItem - 1)
				iItem = iItem - 1;
			else
				iItem = nLast;
			ShowMenu(iItem);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (iItem < nLast)
				iItem = iItem + 1;
			else
				iItem = 1;
			ShowMenu(iItem);
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			ShowMenu(iItem);
			switch (iItem)
			{
			case 1:
				sum();		
				cout << "Сумма = " << c << endl;	
				fin();
				break;
			case 2:
				m_1();		
				cout << "Разность = " << c << endl;			
				fin();
				break;
			case 3:
				sqrt();
				cout << "Число в степени  = " << a << endl;	
				fin();
				break;
			case 4:
				exit(0);
				break;
			
			}
			exit(0);
		}
	}
	
	return 0;
	
}
