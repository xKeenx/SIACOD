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