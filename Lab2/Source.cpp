#include <iostream>
#include <ctime>


using namespace std;


class Sorts {

public:

	void SetArr(int size) {

		arr = new int[size];
		this->SIZE = size;

		int guess;
		cout << " В каком порядке желаете заполнить массив ?\n 0 - В хаотичном\n 1 - В обычном\n 2 - В обратном\n : ";
		cin >> guess;

		cout << endl << "   Исходный массив :  ";

		switch (guess) {

		case 0: {

			for (int i = 0; i < size; ++i) {

				arr[i] = rand() % size + 1;
				if (SIZE <= 2000)  cout << arr[i] << " ";

			}

			cout << endl << endl << " \n \tМассив заполнен в хаотичном порядке\n \n" << endl;
			break;

		}

		case 1: {

			for (int i = 0; i < size; ++i) {

				arr[i] = i + 1;
				if (SIZE <= 2000)  cout << arr[i] << " ";

			}

			cout << endl << endl << "  \n \tМассив заполнен в обычном порядке\n\n " << endl;
			break;

		}

		case 2: {

			for (int i = 0; i < size; ++i) {

				arr[i] = size - i;
				if (SIZE <= 2000)  cout << arr[i] << " ";

			}

			cout << endl << endl << "   \n\tМассив заполнен в обратном порядке\n\n " << endl;
			break;

		}

		}

	}

	void bubbleSort() {

		cout << " \t\tСортировка пузырьком\t\t\n " << endl;

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

				cout << "   Отсортированный массив : ";

				for (int i = 0; i < SIZE; ++i) cout << arrBubble[i] << " ";

			}

			cout << endl << " Время работы сортировки : " << count;

			count = 0;

			cout << endl << endl;

			delete[]arrBubble;

		}

		else cout << endl << " Устанем ждать " << endl << endl;

	}

	void insertinSort() {

		cout << " \t\tСортировка вставками\t\t\n " << endl;

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

				cout << "   Отсортированный массив : ";

				for (int i = 0; i < SIZE; ++i) cout << arrInsertion[i] << " ";

			}

			cout << endl << " Время работы сортировки : " << count;

			count = 0;

			cout << endl << endl;

			delete[]arrInsertion;

		}
		else cout << endl << " Так же долговато " << endl << endl;

	}

	void selectionSort() {

		cout << " \t\tСортировка выбором\t\t\n " << endl;

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

				cout << "   Отсортированный массив : ";

				for (int i = 0; i < SIZE; ++i) cout << arrSelection[i] << " ";

			}

			cout << endl << " Время работы сортировки : " << count;

			count = 0;

			cout << endl << endl;

			delete[]arrSelection;

		}
		else cout << endl << " Так же долговато " << endl << endl;;

	}
	void shellSort() {

		cout << " \t\tСортировка Шелла\t\t\n " << endl;

		int* arrShell = new int[SIZE];

		for (int i = 0; i < SIZE; ++i) arrShell[i] = arr[i];

		int d = SIZE;
		d /= 2;


		while (d && ++count) {

			for (int i = 1; i < SIZE - d; ++i, ++count) {

				int j = i;

				while (j >= 0 && arrShell[j] > arrShell[j + d] && ++count) {

					swap(arrShell[j], arrShell[j + d]);
					++count;
					--j;

				}
			}

			d = d / 2;

		}


		arrTime[3] = count;

		if (SIZE <= 1000) {

			cout << "   Отсортированный массив : ";

			for (int i = 0; i < SIZE; ++i) cout << arrShell[i] << " ";

		}

		cout << endl << " Время работы сортировки : " << count;

		count = 0;

		cout << endl << endl;

		delete[]arrShell;

	}

	void quickSort() {

		cout << " \t\tБыстрая сортировка\t\t\n " << endl;

		int* arrQSort = new int[SIZE];

		for (int i = 0; i < SIZE; ++i) arrQSort[i] = arr[i];


		long	long i, j;
		long long lb, ub;

		long  long  lbstack[2048], ubstack[2048];
		long long  stackpos = 1;
		long long ppos;
		int pivot;
		int temp;

		lbstack[1] = 0;
		ubstack[1] = SIZE - 1;

		do {

			lb = lbstack[stackpos];
			ub = ubstack[stackpos];
			--stackpos;

			do {

				ppos = (lb + ub) >> 1;
				i = lb; j = ub; pivot = arrQSort[ppos];

				do {

					while (arrQSort[i] < pivot && ++count) ++i;
					while (pivot < arrQSort[j] && ++count) --j;

					if (i <= j && ++count) {

						swap(arrQSort[i], arrQSort[j]);
						++count;
						++i;
						--j;

					}

				} while (i <= j && ++count);


				if (i < ppos && ++count) {

					if (i < ub && ++count) {

						++stackpos;
						lbstack[stackpos] = i;
						ubstack[stackpos] = ub;
						++count;

					}

					ub = j;


				}
				else {

					if (j > lb && ++count) {

						++stackpos;
						lbstack[stackpos] = lb;
						ubstack[stackpos] = j;
						++count;

					}

					lb = i;

				}

			} while (lb < ub && ++count);

		} while (stackpos != 0 && ++count);


		arrTime[4] = count;

		if (SIZE <= 1000) {

			cout << "   Отсортированный массив : ";

			for (int i = 0; i < SIZE; ++i) cout << arrQSort[i] << " ";

		}

		cout << endl << " Время работы сортировки : " << count;

		count = 0;

		cout << endl << endl;


		delete[]arrQSort;

	}

	void heapify(int arrHeap[], int SIZE, int i) {

		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < SIZE && arrHeap[left] > arrHeap[largest] && ++count)
			largest = left;

		if (right < SIZE && arrHeap[right] > arrHeap[largest] && ++count)
			largest = right;

		if (largest != i && ++count) {

			swap(arrHeap[i], arrHeap[largest]);
			++count;

			heapify(arrHeap, SIZE, largest);

		}
	}

	void buildHeap(int arrHeap[], int SIZE) {

		for (int i = SIZE / 2 - 1; i >= 0; i--, ++count)
			heapify(arrHeap, SIZE, i);

		for (int i = SIZE - 1; i >= 0; i--, ++count) {

			swap(arrHeap[0], arrHeap[i]);
			++count;
			heapify(arrHeap, i, 0);

		}
	}

	void heapSort() {

		cout << " \t\tСортировка кучей\t\t\n " << endl;

		int* arrHeap = new int[SIZE];

		for (int i = 0; i < SIZE; ++i) arrHeap[i] = arr[i];

		buildHeap(arrHeap, SIZE);

		arrTime[5] = count;

		if (SIZE <= 1000) {

			cout << "   Отсортированный массив : ";

			for (int i = 0; i < SIZE; ++i) cout << arrHeap[i] << " ";

		}

		cout << endl << " Время работы сортировки : " << count;

		count = 0;

		cout << endl << endl;

		delete[]arrHeap;

	}

	~Sorts() {

		delete[]arr;
		delete[]arrTime;

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
	obj.selectionSort();
	obj.shellSort();
	obj.quickSort();
	obj.heapSort();
	system("pause");
}

