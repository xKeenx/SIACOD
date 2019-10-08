/*1. Описать структуру с именем NOTE, содержащую следующие поля:
- фамилия, имя;
- номер телефона;
- день рождения (массив из трех чисел).
2. Написать программу, выполняющую следующие действия:
- ввод с клавиатуры данных в массив, состоящий из восьми элементов типа NOTE; записи должны быть упорядочены по датам дней рождения;
- вывод на экран информации о человеке, номер телефона которого введен с клавиатуры;
- если такого нет, выдать на дисплей соответствующее сообщение.

*/
#include <iostream>
#include<Windows.h>

using namespace std;
struct Note {

	char name[255];
	unsigned long long int phone;
	int date[3];
	

};
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Note arr[3];
	char tempname[255];
	int temp;
	unsigned long long int tempphone;
	int requestNum;
    
	
	for (int i = 0; i < 3; ++i)
	{
		
		cout << "Введите имя студента №" << i + 1 << endl;
		scanf_s("\n");
		cin.getline(arr[i].name, 255);
		
		cout << "Введите номер телефона студента №" << i + 1 << endl;
		
		cin >> arr[i].phone;
		
		cout << "Введите дату рождения студента №" << i + 1 << endl;
		
		cout << "Введите число:";
		
		cin >> arr[i].date[0];
		
		cout << "Введите месяц:";
				
		cin >> arr[i].date[1];
				
		cout << "Введите год:";
			
		cin >> arr[i].date[2];

	}
	for ( int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; j++)
		{
			
						if (arr[j].date[0] > arr[j + 1].date[0])
						{
							for (int i = 0; i < 3; ++i)
							{
								temp = arr[j].date[i];
								arr[j].date[i] = arr[j + 1].date[i];
								arr[j + 1].date[i] = temp;
							}
							strcpy_s(tempname, arr[j].name);

							strcpy_s(arr[j].name, arr[j + 1].name);

							strcpy_s(arr[j + 1].name, tempname);

							tempphone = arr[j].phone;
							arr[j].phone = arr[j + 1].phone;
							arr[j + 1].phone = tempphone;
							break;
						}
					
		}

	}
	cout << endl;
	
	for (int i = 0; i < 3; ++i)
	{

		cout << "Имя студента №" << i + 1 << endl;
		cout << arr[i].name << endl;
	
		cout << "Номер телефона студента №" << i + 1 << endl;
		cout << arr[i].phone << endl;
		
		cout << "Дату рождения студента №" << i + 1 << endl;
		cout << arr[i].date[0] << " " << arr[i].date[1] << " " << arr[i].date[2] << endl;
		
	}


	cout << "Введите номер телефона: ";
	cin >> requestNum;

	bool flag = true;

	for (int i = 0; i < 3; ++i)
	{
		if (arr[i].phone == requestNum)
		{
			flag = false;
			cout << "Имя: " << arr[i].name << endl << "Номер телефона: " << arr[i].phone << endl << "Дата рождения: "<< arr[i].date[0] << " " << arr[i].date[1] << " " << arr[i].date[2] << endl;
			break;

		}

	}
	if (flag)
		cout << "Ошибка!!!";
	cout << endl;

	system("pause");
}