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
	printf("%s1 - plus\n", iItem == 1 ? ">" : " ");
	printf("%s2 - minus\n", iItem == 2 ? ">" : " ");
	printf("%s3 - stepen\n", iItem == 3 ? ">" : " ");
	printf("%s4 - exid\n", iItem == 4 ? ">" : " ");
	
}

int sum() 
{

	cout << "vvedite 2 chisla dlya slojeniya, i najmite 'enter':  " << endl;
	cin >> a;
	cin >> b;
	
	c = a + b; 

	return c;
}

int m_1()
{
	cout << "vvedite 2 chisla dlya minusa, i najmite 'enter':  " << endl;
	cin >> a;
	cin >> b;

	c = a - b;

	return c;
}

int sqrt()
{
	cout << "vvedite chislo dlya vozvedeniya v stepen:  " << endl;
	cin >> a;
	cout << "vvedite stepen:  " << endl;
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
	cout << "Thank you for using our calculator!" << endl;
	system("pause");
	return 0;
}

int main()
{
	setlocale(0, "");

	int iItem = 1;//Îòâå÷àåò êàêîé ïóíêò ìåíþ àêòèâåí â äàííûé ìîìåíò
	int nLast = 4;//Îòâå÷àåò êàêîé èíäåêñ ó ïîñëåäíåãî ïóíêòà ìåíþ
	
	ShowMenu(iItem);

	while (TRUE)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
			if (0 < iItem - 1)
				iItem = iItem - 1;
			else
				iItem = nLast;
			ShowMenu(iItem);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
			if (iItem < nLast)
				iItem = iItem + 1;
			else
				iItem = 1;
			ShowMenu(iItem);
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Îòæèìàåì êíîïêó
			ShowMenu(iItem);
			switch (iItem)
			{
			case 1:
				sum();		
				cout << "summ = " << c << endl;	
				fin();
				break;
			case 2:
				m_1();		
				cout << "minus = " << c << endl;			
				fin();
				break;
			case 3:
				sqrt();
				cout << "chislo v stepen  = " << a << endl;	
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
