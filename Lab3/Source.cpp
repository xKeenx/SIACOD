#include <iostream>
#include <ctime>

using namespace std;


struct ARRAY {

	int num;
	bool flagAr;

};

class Searchs {

public:

	void set_array(bool guess) {

		cout << "������� ������ ������� : ";
		cin >> SIZE;
		cout << endl << endl;

		arr = new int[SIZE];

		switch (guess) {

		case true: {

			cout << "\t\t ������ �������� ������������ \n" << endl;
			cout << "�������� ������ : ";

			for (int i = 0; i < SIZE; ++i) {

				arr[i] = i + 1;
				cout << arr[i] << " ";

			}
			break;

		}
		case false: {


			cout << "\t\t ������ �������� �������� \n" << endl;
			cout << "�������� ������ : ";

			for (int i = 0; i < SIZE; ++i) {

				arr[i] = rand() % SIZE + 1;
				cout << arr[i] << " ";

			}
			break;

		}
		default: {

			cout << " ������ ���������� " << endl;
			break;

		}

		}

		cout << endl << endl;


	}


	void linear_search(int key) {

		int i = 0;
		int rezult = -1;

		ARRAY *arrLinear = new ARRAY[SIZE];

		arrLinear[SIZE - 1].flagAr = false;

		bool flag = arrLinear[0].flagAr;

		for (int i = 0; i < SIZE; ++i) {

			arrLinear[i].num = arr[i];

		}

		while (flag && ++count) {

			flag = arrLinear[i].flagAr;

			if (++count && arrLinear[i].num == key) {

				rezult = i + 1;
				delete[]arrLinear;
				arrLinear = nullptr;
				break;

			}

			++i;

		}

		if (arrLinear != nullptr) delete[]arrLinear;

		cout << endl << " ������ ������� �������� : " << rezult << endl;
		cout << " ����� ������ ��������� ������ : " << count << endl << endl;

		count = 0;


	}

	void fast_linear_search(int key) {

		int i = 0;
		bool flag;
		int rezult = -1;

		ARRAY* arrLinear = new ARRAY[SIZE + 1];

		arrLinear[SIZE].num = key;
		arrLinear[SIZE].flagAr = false;


		for (int i = 0; i < SIZE; ++i) {

			arrLinear[i].num = arr[i];

		}

		while (true) {

			flag = arrLinear[i].flagAr;

			if (++count && arrLinear[i].num == key) {

				rezult = i + 1;
				delete[]arrLinear;
				arrLinear = nullptr;
				if (!flag) rezult = -1;
				break;

			}

			++i;

		}

		if (arrLinear != nullptr) delete[]arrLinear;

		cout << endl << " ������ ������� �������� : " << rezult << endl;
		cout << " ����� ������ �������� ��������� ������ : " << count << endl << endl;

		count = 0;

	}




	~Searchs()
	{
		delete[]arr;
	}

private:

	static int count;
	int* arr = nullptr;
	int SIZE = 0;


};


int Searchs::count = 0;