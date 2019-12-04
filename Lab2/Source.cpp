#include <iostream>
#include <ctime>


using namespace std;


class Sorts {

public:

	void SetArr(int size) {

		arr = new int[size];
		this->SIZE = size;

		int guess;
		cout << " � ����� ������� ������� ��������� ������ ?\n 0 - � ���������\n 1 - � �������\n 2 - � ��������\n : ";
		cin >> guess;

		cout << endl << "   �������� ������ :  ";

		switch (guess) {

		case 0: {

			for (int i = 0; i < size; ++i) {

				arr[i] = rand() % size + 1;
				if (SIZE <= 2000)  cout << arr[i] << " ";

			}

			cout << endl << endl << " \n \t������ �������� � ��������� �������\n \n" << endl;
			break;

		}

		case 1: {

			for (int i = 0; i < size; ++i) {

				arr[i] = i + 1;
				if (SIZE <= 2000)  cout << arr[i] << " ";

			}

			cout << endl << endl << "  \n \t������ �������� � ������� �������\n\n " << endl;
			break;

		}

		case 2: {

			for (int i = 0; i < size; ++i) {

				arr[i] = size - i;
				if (SIZE <= 2000)  cout << arr[i] << " ";

			}

			cout << endl << endl << "   \n\t������ �������� � �������� �������\n\n " << endl;
			break;

		}

		}

	}

	void bubbleSort() {

		cout << " \t\t���������� ���������\t\t\n " << endl;

		if (SIZE <= 49999) {

			int* arrBubble = new int[SIZE];


			for (int i = 0; i < SIZE; ++i)	arrBubble[i] = arr[i];


			for (int i = SIZE - 1; i > 0; --i, ++count) {

				for (int j = 0; j < i; ++j, ++count) {

					if (arrBubble[j] > arrBubble[j + 1] && ++count) {

						swap(arrBubble[j], arrBubble[j + 1]);
						++count;

					}

				}

			}


			arrTime[0] = count;

			if (SIZE <= 1000) {

				cout << "   ��������������� ������ : ";

				for (int i = 0; i < SIZE; ++i) cout << arrBubble[i] << " ";

			}

			cout << endl << " ����� ������ ���������� : " << count;

			count = 0;

			cout << endl << endl;

			delete[]arrBubble;

		}

		else cout << endl << " ������� ����� " << endl << endl;

	}

	void insertinSort() {

		cout << " \t\t���������� ���������\t\t\n " << endl;

		if (SIZE <= 49999) {

			int* arrInsertion = new int[SIZE];

			for (int i = 0; i < SIZE; ++i) arrInsertion[i] = arr[i];


			for (int i = 1; i < SIZE; ++i, ++count)
				for (int j = i; j > 0 && arrInsertion[j - 1] > arrInsertion[j] && ++count; --j, ++count) {

					swap(arrInsertion[j - 1], arrInsertion[j]);
					++count;

				}


			arrTime[1] = count;

			if (SIZE <= 1000) {

				cout << "   ��������������� ������ : ";

				for (int i = 0; i < SIZE; ++i) cout << arrInsertion[i] << " ";

			}

			cout << endl << " ����� ������ ���������� : " << count;

			count = 0;

			cout << endl << endl;

			delete[]arrInsertion;

		}
		else cout << endl << " ��� �� ��������� " << endl << endl;

	}

	void selectionSort() {

		cout << " \t\t���������� �������\t\t\n " << endl;

		if (SIZE <= 49999) {

			int* arrSelection = new int[SIZE];
			int min;


			for (int i = 0; i < SIZE; ++i) arrSelection[i] = arr[i];



			for (int i = 0; i < SIZE - 1; ++i, ++count) {

				min = i;

				for (int j = i + 1; j < SIZE; ++j, ++count) {

					if (arrSelection[j] < arrSelection[min] && ++count) {

						min = j;

					}
				}

				swap(arrSelection[i], arrSelection[min]);
				++count;

			}


			arrTime[2] = count;

			if (SIZE <= 1000) {

				cout << "   ��������������� ������ : ";

				for (int i = 0; i < SIZE; ++i) cout << arrSelection[i] << " ";

			}

			cout << endl << " ����� ������ ���������� : " << count;

			count = 0;

			cout << endl << endl;

			delete[]arrSelection;

		}
		else cout << endl << " ��� �� ��������� " << endl << endl;;

	}

	private:

		static unsigned long long count;
		int SIZE;
		int* arr;
		unsigned long long* arrTime = new unsigned long long[6];

};

unsigned long long Sorts::count = 0;


int main()
{
	system("chcp 1251 > null");
	srand(time(0));


	Sorts obj;

	obj.SetArr(50000);
	obj.bubbleSort();
	obj.insertinSort();
	system("pause");
}

