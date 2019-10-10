#include<iostream>
#include <conio.h>      
#include <iomanip>
using namespace std;
void BinOut(unsigned char* Buf, int len) {
	int i, j;
	unsigned char byte;
	for (i = len - 1; i >= 0; i--)
		for (j = 1, byte = Buf[i]; j <= 8; byte <<= 1, j++)
			_putch(byte & 0x80 ? '1' : '0');
	printf("\n");
}

void BinIn(unsigned char* Buf, int len) {
	int i, j;
	char ch;
	for (i = len - 1; i >= 0; i--)
		for (j = 1, Buf[i] = 0; j <= 8; Buf[i] = (Buf[i] << 1) + (ch - '0'), j++) {
			while ((ch = _getch()) != '0' && ch != '1');
			_putch(ch);
		}
	printf("\n");
}



int main() {
<<<<<<< HEAD
	setlocale(LC_ALL, "Russian");
	// Представление целых чисел без знака(тип unsigned int)
	unsigned int n;
	cout << "Введите число типа unsigned int: ";
	cin >> n;
	cout << "Это его двоичное представление:" << endl;
	BinOut((unsigned char*)&n, sizeof(n));
	cout << "Введите двоичное представление числа типа unsigned int :" << endl;
	BinIn((unsigned char*)&n, sizeof(n));
	cout << "Это его значение: " << n << endl;
	// Представление вещественных чисел
	//двойной точности (тип double)
	double x;
	cout << "Введите число типа double: ";
	cin >> x;
	cout << "Это его двоичное представление:" << endl;
	BinOut((unsigned char*)&x, sizeof(x));
	cout << "Введите двоичное представление числа типа double:" << endl;
	BinIn((unsigned char*)&x, sizeof(x));
	cout << "Это его значение: " <<setprecision(15)<< x << endl;
	_getch();
	//Представление вещественных чисел одинарной точности ( тип float) 
=======
	system("chcp 1251 > nul")
	// Ïðåäñòàâëåíèå öåëûõ ÷èñåë áåç çíàêà(òèï unsigned int)
	unsigned int n;
	cout << "Ââåäèòå ÷èñëî òèïà unsigned int: ";
	cin >> n;
	cout << "Ýòî åãî äâîè÷íîå ïðåäñòàâëåíèå:" << endl;
	BinOut((unsigned char*)&n, sizeof(n));
	cout << "Ââåäèòå äâîè÷íîå ïðåäñòàâëåíèå ÷èñëà òèïà unsigned int :" << endl;
	BinIn((unsigned char*)&n, sizeof(n));
	cout << "Ýòî åãî çíà÷åíèå: " << n << endl;
	// Ïðåäñòàâëåíèå âåùåñòâåííûõ ÷èñåë
	//äâîéíîé òî÷íîñòè (òèï double)
	double x;
	cout << "Ââåäèòå ÷èñëî òèïà double: ";
	cin >> x;
	cout << "Ýòî åãî äâîè÷íîå ïðåäñòàâëåíèå:" << endl;
	BinOut((unsigned char*)&x, sizeof(x));
	cout << "Ââåäèòå äâîè÷íîå ïðåäñòàâëåíèå ÷èñëà òèïà double:" << endl;
	BinIn((unsigned char*)&x, sizeof(x));
	cout << "Ýòî åãî çíà÷åíèå: " <<setprecision(15)<< x << endl;
	_getch();
	//Ïðåäñòàâëåíèå âåùåñòâåííûõ ÷èñåë îäèíàðíîé òî÷íîñòè ( òèï float) 
>>>>>>> 6cb2191b40cba571d33e0b035ea7f4569edb2b02

	float arr[2][2];
	
	for (int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			cin >> arr[i][j];
		
		}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
<<<<<<< HEAD
			cout << "Это двоичное представление заданного числа:" << endl;
			BinOut((unsigned char*)&arr[i][j], sizeof(arr[i][j]));
			cout << "Введите двоичное представление числа типа float:" << endl;
			BinIn((unsigned char*)&arr[i][j], sizeof(arr[i][j]));
			cout << "Это его значение: " << arr[i][j] << endl;
=======
			cout << "Ýòî äâîè÷íîå ïðåäñòàâëåíèå çàäàííîãî ÷èñëà:" << endl;
			BinOut((unsigned char*)&arr[i][j], sizeof(arr[i][j]));
			cout << "Ââåäèòå äâîè÷íîå ïðåäñòàâëåíèå ÷èñëà òèïà float:" << endl;
			BinIn((unsigned char*)&arr[i][j], sizeof(arr[i][j]));
			cout << "Ýòî åãî çíà÷åíèå: " << arr[i][j] << endl;
>>>>>>> 6cb2191b40cba571d33e0b035ea7f4569edb2b02
			_getch();

		} //Кодировка UTF-8
	system("Pause");
}
