/*1. ������� ��������� � ������ NOTE, ���������� ��������� ����:
- �������, ���;
- ����� ��������;
- ���� �������� (������ �� ���� �����).
2. �������� ���������, ����������� ��������� ��������:
- ���� � ���������� ������ � ������, ��������� �� ������ ��������� ���� NOTE; ������ ������ ���� ����������� �� ����� ���� ��������;
- ����� �� ����� ���������� � ��������, ����� �������� �������� ������ � ����������;
- ���� ������ ���, ������ �� ������� ��������������� ���������.

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
		
		cout << "������� ��� �������� �" << i + 1 << endl;
		scanf_s("\n");
		cin.getline(arr[i].name, 255);
		
		cout << "������� ����� �������� �������� �" << i + 1 << endl;
		
		cin >> arr[i].phone;
		
		cout << "������� ���� �������� �������� �" << i + 1 << endl;
		
		cout << "������� �����:";
		
		cin >> arr[i].date[0];
		
		cout << "������� �����:";
				
		cin >> arr[i].date[1];
				
		cout << "������� ���:";
			
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

		cout << "��� �������� �" << i + 1 << endl;
		cout << arr[i].name << endl;
	
		cout << "����� �������� �������� �" << i + 1 << endl;
		cout << arr[i].phone << endl;
		
		cout << "���� �������� �������� �" << i + 1 << endl;
		cout << arr[i].date[0] << " " << arr[i].date[1] << " " << arr[i].date[2] << endl;
		
	}


	cout << "������� ����� ��������: ";
	cin >> requestNum;

	bool flag = true;

	for (int i = 0; i < 3; ++i)
	{
		if (arr[i].phone == requestNum)
		{
			flag = false;
			cout << "���: " << arr[i].name << endl << "����� ��������: " << arr[i].phone << endl << "���� ��������: "<< arr[i].date[0] << " " << arr[i].date[1] << " " << arr[i].date[2] << endl;
			break;

		}

	}
	if (flag)
		cout << "������!!!";
	cout << endl;

	system("pause");
}