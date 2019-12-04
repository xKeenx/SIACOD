#include<iostream>
#include<string>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	T pop_front();
	void push_back(T data);
	void insert(T data, int index);
	void removeAt(int index);
	T pop_back();
	void clear();
	int GetSize() { return Size; }
	T& operator[](const int index);
	void toNext();
	void toPrev();
	void push_front(T data);


private:
	template<typename T>
	class Node
	{
	public:
		Node *pPrev;
		Node *pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr, Node *pPrev = nullptr)
		{
			this->pPrev = pPrev;
			this->data = data;
			this->pNext = pNext;
		}

	};
	int Size;
	Node<T> *head;

};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;

}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
T List<T>::pop_front()
{
	Node<T>*temp = head;
	head = head->pNext;

	T data = temp->data;

	delete temp;

	Size--;

	return data;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else {

		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;

		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;

	}
}

template<typename T>
T List<T>::pop_back()
{
	Node<T> *current = this->head;
	while (current->pNext)
	{
		current = current->pNext;
	}
	T data = current->data;
	current = NULL;

	--Size;

	return data;
}


template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		if (counter == index)

		{
			return current->data;
		}

		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::toNext()
{
	head = head->pNext;

}

template<typename T>
void List<T>::toPrev()
{
	head = head->pPrev;
}


template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;

}
template<typename T>
class Queue {
private:
	List<T> container;

public:

	void push(T data)
	{
		container.push_front(data);
	}
	T pop()
	{
		return container.pop_front();
	}
	bool isEmpty()
	{
		return container.GetSize() == 0;
	}

};

template <typename T>
class Stack {

private:

	T arr[1000];
	int top;

public:

	void initstack()
	{

		top = 0;
	}

	void push(T value)
	{
		arr[top] = value;
		top += 1;


	}

	T pop()
	{

		top -= 1;
		T result = arr[top];
		arr[top] = T();

		return result;
	}

	bool empty()
	{
		return top == 0;
	}
	T readtop()
	{
		return arr[top - 1];

	}

};

class Request
{
private:

	string name;

	int time;

	int priority;

public:

	Request() {
		name = "";
		time = 0;
		priority = 4;
	}

	Request(string name, int time, int priority)
	{
		this->name = name;
		this->time = time;
		this->priority = priority;

	}
	string get_name()
	{
		return name;
	}
	int get_time()
	{
		return time;

	}

	int get_priority()
	{
		return priority;
	}

	void dec_time()
	{
		--time;
	}

	bool isFinished()
	{
		return time == 0;
	}

	void output_status()
	{
		cout << "Для задачи " << name << " осталось " << time << " тиков" << endl;
	}
};

class Processor
{
private:
	Request current_request;
	int number;
public:

	Processor(int number) {
		this->number = number;
	}

	void set_request(Request new_request)
	{
		current_request = new_request;
	}

	Request get_request()
	{
		return current_request;
	}

	void delete_request() {
		current_request = Request();
	}

	bool check_request() {
		return current_request.get_time() > 0;
	}

	void update_status() {
		if (this->check_request()) {
			current_request.dec_time();
			if (current_request.isFinished()) {
				cout << "Запрос " << current_request.get_name() << " выполнен " << endl;
			}
		}
	}

	int get_priority()
	{
		return current_request.get_priority();
	}

	void output_status() {
		if (!check_request()) {
			cout << "Процессор " << number << " свободен" << endl;
		}
		else {
			current_request.output_status();
		}
	}
};



int main()
{

	setlocale(LC_ALL, "Russian");

	Queue <Request> F0;
	Queue <Request> F1;
	Queue <Request> F2;

	Processor P1(1);
	Processor P2(2);

	Stack <Request> S1;
	S1.initstack();

	Stack <Request> S2;
	S2.initstack();

	int input;

	cout << "Введите 1, если хотите добавить запрос:";
	cin >> input;

	while (input == 1 ||
		P1.check_request() || P2.check_request() ||
		!F0.isEmpty() || !F1.isEmpty() || !F2.isEmpty() ||
		!S1.empty() || !S2.empty())
	{
		Request req1 = Request();

		string name;
		int time;
		int priority;

		if (input == 1) {
			cout << "Введите название запроса: ";
			cin >> name;

			time = rand() % 5 + 1;
			priority = rand() % 3;

			req1 = Request(name, time, priority);

			switch (req1.get_priority())
			{
			case 0:
				F0.push(req1);
				break;
			case 1:
				F1.push(req1);
				break;
			case 2:
				F2.push(req1);
				break;

			default:

				break;
			}

		}

		Request new_request;

		if (!F0.isEmpty()) {
			new_request = F0.pop();
		}
		else if (!F1.isEmpty())
		{
			new_request = F1.pop();
		}
		else if (!F2.isEmpty())
		{
			new_request = F2.pop();
		}

		priority = new_request.get_priority();

		if (!P1.check_request()) {
			P1.set_request(new_request);
		}
		else if (!P2.check_request()) {
			P2.set_request(new_request);
		}
		else {
			if (P1.get_priority() > new_request.get_priority()) {
				S1.push(P1.get_request());
				P1.set_request(new_request);
			}
			else {

				switch (priority)
				{
				case 0:
					F0.push(new_request);
					break;
				case 1:
					F1.push(new_request);
					break;
				case 2:
					F2.push(new_request);
					break;

				default:

					break;
				}

				if (!F0.isEmpty()) {
					new_request = F0.pop();
				}
				else if (!F1.isEmpty())
				{
					new_request = F1.pop();
				}
				else if (!F2.isEmpty())
				{
					new_request = F2.pop();
				}


				if (P2.get_priority() > new_request.get_priority()) {
					S2.push(P2.get_request());
					P2.set_request(new_request);
				}
				else {
					priority = new_request.get_priority();
					switch (priority)
					{
					case 0:
						F0.push(new_request);
						break;
					case 1:
						F1.push(new_request);
						break;
					case 2:
						F2.push(new_request);
						break;

					default:

						break;
					}
				}
			}
		}

		if (P1.check_request()) {
			P1.update_status();
		}
		if (P2.check_request()) {
			P2.update_status();
		}

		new_request = Request();

		if (!P1.check_request()) {
			if (!S1.empty()) {
				priority = S1.readtop().get_priority();
			}

			if (!F0.isEmpty()) {
				if (priority == 0 && !S1.empty()) {
					new_request = S1.pop();
				}
				else {
					new_request = F0.pop();
				}
			}
			else if (!F1.isEmpty()) {
				if (priority <= 1 && !S1.empty()) {
					new_request = S1.pop();
				}
				else {
					new_request = F1.pop();
				}
			}
			else {
				if (!S1.empty()) {
					new_request = S1.pop();
				}
				else {
					if (!F2.isEmpty()) {
						new_request = F2.pop();
					}
				}
			}

			P1.set_request(new_request);

			new_request = Request();
		}

		if (!P2.check_request()) {
			if (!S2.empty())
			{
				priority = S2.readtop().get_priority();
			}

			if (!F0.isEmpty()) {
				if (priority == 0 && !S2.empty()) {
					new_request = S2.pop();
				}
				else {
					new_request = F0.pop();
				}
			}
			else if (!F1.isEmpty()) {
				if (priority <= 1 && !S2.empty()) {
					new_request = S2.pop();
				}
				else {
					new_request = F1.pop();
				}
			}
			else {
				if (!S2.empty()) {
					new_request = S2.pop();
				}
				else {
					if (!F2.isEmpty()) {
						new_request = F2.pop();
					}
				}
			}

			P2.set_request(new_request);

			new_request = Request();
		}

		P1.output_status();
		P2.output_status();

		cout << "Введите 1, если хотите добавить запрос:";
		cin >> input;
	}


	system("pause");
}