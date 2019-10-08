
#include <iostream>
using namespace std;

template <typename T>
void function(T a[], int size)
{
	T max = a[0];
	for (int i = 1; i < size; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		if (a[i] == max)
		{
			++count;
		}



	}
	cout << "Максимальный элемент " << max << endl<< "Встречается " << count << " раз(a)" << endl;
	
}

int main()
{
	system("chcp 1251>nul");
	

	int a[10]{ 8,1,1,2,8,4,5,6,7,8 };
	int size = 10;
	function(a, size);

	system("Pause");
}