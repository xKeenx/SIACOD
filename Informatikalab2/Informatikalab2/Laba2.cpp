/*12.	Составьте программу – формирование цены на молоко. 
Животновод в начале каждой зимы повышает цену а молоко на р%, а каждым летом снижает на столько же процентов. 
Измениться ли цена на молоко и если да, то в какую сторону и на сколько через n лет. (Все значения должны вводиться с клавиатуры.)
3. Количество максимальных элементов массива*/




#include <iostream>
#include <cmath>
#include<Windows.h>
using namespace std;

void function1(unsigned int *p,unsigned int *n,double *price,double *price1)
{
	cin >> *p;
	cin >> *n;
	cin >> *price;
	
	*price1 = *price;
}


void function2(double *price,  unsigned int*p, unsigned int *n)
{
	for (int i = 0; i < *n; ++i)
	{
		*price = *price + *price * (static_cast<double>(*p) / 100);
		cout << *price << endl;
		*price = *price - *price * (static_cast<double>(*p) / 100);
		cout << *price << endl;

	}


}

void function3(double *price1,double *price)
{

	if (*price1 != *price)
	{
		if (*price1 > *price)
		{

			cout << "Число изменилось в меньшую сторону на " << *price1 - *price << endl;

		}
		else {

			cout << " Число изменилось в большую сторону на " << *price - *price1 << endl;
		}

	}




}
int main()
{   
	system("chcp 1251>nul");
	unsigned int p = 0;
	unsigned int n = 0;
	double price = 0;
	double price1 = 0;
	function1(&p, &n, &price,&price1);
	function2(&price, &p, &n);
	function3(&price1, &price);

	
	
	system("Pause");
}