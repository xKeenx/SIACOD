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

		cout << "Введите размер массива : ";
		cin >> SIZE;
		cout << endl << endl;

		arr = new int[SIZE];

		switch (guess) {

		case true: {

			cout << "\t\t Массив заполнен упорядоченно \n" << endl;
			cout << "Исходный массив : ";

			for (int i = 0; i < SIZE; ++i) {

				arr[i] = i + 1;
				cout << arr[i] << " ";

			}
			break;

		}
		case false: {


			cout << "\t\t Массив заполнен хаотично \n" << endl;
			cout << "Исходный массив : ";

			for (int i = 0; i < SIZE; ++i) {

				arr[i] = rand() % SIZE + 1;
				cout << arr[i] << " ";

			}
			break;

		}
		default: {

			cout << " Ошибка исполнения " << endl;
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

		cout << endl << " Индекс данного элемента : " << rezult << endl;
		cout << " Время работы линейного поиска : " << count << endl << endl;

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

		cout << endl << " Индекс данного элемента : " << rezult << endl;
		cout << " Время работы быстрого линейного поиска : " << count << endl << endl;

		count = 0;

	}

	void binary_search(int key) {

		int low = 0;
		int high = SIZE - 1;
		int rezult = -1;

		while (low <= high && ++count) {

			int mid = (low + high) / 2;

			if (key == arr[mid] && ++count) {

				rezult = mid + 1;
				break;

			}
			else if (key > arr[mid] && ++count) {

				low = mid + 1;

			}
			else {

				high = mid - 1;
				++count;

			}

		}

		cout << " Индекс данного элемента : " << rezult << endl;
		cout << " Время работы бинарного поиска : " << count << endl << endl;

		count = 0;

	}

	int blok__search(int key) {

		int rezult = -1;
		int num = (1) / 10.0 * SIZE;

		for (int i = num; i <= SIZE && ++count; i += num) {

			while (++count && key <= arr[i - 1]) {

				for (int j = i - num; j <= i && ++count; ++j)

					if (++count && arr[j] == key) {

						cout << " Индекс данного элемента : " << j + 1 << endl;

						cout << " Время работы блочного поиска : " << count << endl << endl;

						count = 0;

						return j + 1;

					}

			}

		}

		cout << " Индекс данного элемента : " << rezult << endl;
		cout << " Время работы блочного поиска : " << count << endl << endl;

		count = 0;

		return -1;

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


int main()
{
	system("chcp 1251 > null");
	srand(time(0));

	Searchs obj;

	int Size = 200;

	obj.set_array(false);
	obj.linear_search(Size);
	obj.fast_linear_search(Size);
	obj.binary_search(Size);
	obj.blok__search(Size);




}