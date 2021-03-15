#include <iostream>

template <class T>
class Element
{
private:
	Element<T> * next;
	T field;
public:
	Element<T> *  getNext() { return next; }
	void setNext(Element<T> *  value) { next = value; }

	T getValue() { return field; }
	void setValue(T value) { field = value; }
};

template <class T>
class LinkedList
{
protected:
	Element<T> *  begin;
	int num;
public:
	int Number() { return num; }
	Element<T> * getBegin() { return begin; }

	LinkedList()
	{
		begin = nullptr;
		num = 0;
	}

	Element<T>* push(T a)
	{
		//положить элемент в конец
		Element<T>* cur = begin;
		if (begin == nullptr)
		{
			num = 1;
			begin = new Element<T>;
			begin->setValue(a);
			begin->setNext(nullptr);
			return begin;
		}
		while (cur->getNext() != nullptr)
		{
			cur = cur->getNext();
		}
		num++;
		//вставка элемента
		cur->setNext(new Element<T>);
		cur->getNext()->setValue(a);
		cur->getNext()->setNext(nullptr);
		return cur;
	}

	Element<T>* add_to_begin(T a)
	{
		if (begin == nullptr)
		{
			num = 1;
			begin = new Element<T>;
			begin->setValue(a);
			begin->setNext(nullptr);
			return begin;
		}
		num++;
		Element<T>* new_b = new Element<T>;
		new_b->setValue(a);
		new_b->setNext(begin);
		begin = new_b;
		return begin;
	}

	T pop()
	{
		//вытащить элемент с конца
		Element<T> * cur = begin;
		Element<T> * prev = nullptr;
		//отдельно рассмотрим случай 0/1 элементов
		if (begin == nullptr)
		{		
			T K;
			return K;
		}
		if (num == 1)
		{
			T res = begin->getValue();
			num--;
			return res;
		}
		//ищем последний и предпоследний элемент
		while (cur->getNext() != nullptr)
		{
			prev = cur;
			cur = cur->getNext();
		}
		//сохраняем результат
		T res = cur->getValue();
		//предпоследний стал последним
		prev->setNext(nullptr);
		//последнего стёрли
		delete cur;
		num--;
		return res;
	}

	~LinkedList<T>()
	{
		//деструктор - освобождение памяти
		num = 0;
		Element<T> * cur = begin;
		if (cur != nullptr)
		{
			while (cur != nullptr)
			{
				Element<T> * prev = cur;
				cur = cur->getNext();
				delete prev;
			}
			begin = nullptr;
		}
	}

	void print()
	{
		//итеративная версия вывода списка 
		Element<T> *cur = begin;
		while (cur != nullptr)
		{
			std::cout << cur->getValue() << " ";
			cur = cur->getNext();
		}
		std::cout << "\n";
	}
};

template <class T>
class Stack:public LinkedList<T>
{
public:
	Stack():LinkedList<T>() {}
	Element<T>* push(T a){return LinkedList<T>::push(a);}
	T pop(){return LinkedList<T>::pop();}
};

template <class T>
class Queue:public LinkedList<T>
{
public:
	Queue():LinkedList<T>() {}
	Element<T>* enqueue(T a){return LinkedList<T>::add_to_begin(a);}
	T dequeue(){return LinkedList<T>::pop();}
};


int main()
{
	Stack<int> L;
	L.push(1);
	L.push(2);
	L.push(3);
	L.push(4);
	L.print();
	L.pop();
	L.print();
	Queue<int> F;
	F.enqueue(1);
	F.enqueue(2);
	F.enqueue(3);
	F.print();
	F.dequeue();
	F.print();
	system("pause");
	return 0;
}

