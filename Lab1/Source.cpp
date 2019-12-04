#include<iostream>
#include <conio.h>      
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
	cout << "Это его значение: " << x << endl;
	_getch();
	//Представление вещественных чисел одинарной точности ( тип float) 

	float arr[2][2];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			cout << "Это двоичное представление заданного числа:" << endl;
			BinOut((unsigned char*)&arr[i][j], sizeof(arr[i][j]));
			cout << "Введите двоичное представление числа типа float:" << endl;
			BinIn((unsigned char*)&arr[i][j], sizeof(arr[i][j]));
			cout << "Это его значение: " << arr[i][j] << endl;
			_getch();
		}
	system("Pause");
}