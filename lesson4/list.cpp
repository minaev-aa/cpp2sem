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

	LinkedList(LinkedList& L)
	{
		//конструктор копий
		begin = nullptr;
		num = L.Number();
		Element<T>* temp = L.begin;
		while(temp != nullptr){
			push(temp->getValue());
			temp = temp->getNext();
		}
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
			cur = cur->getNext();
			while (cur != nullptr)
			{
				Element<T> * prev = cur;
				cur = cur->getNext();
				prev = nullptr;
				delete prev;
			}
			if (begin != nullptr)
				begin = nullptr;
				delete begin;
		}
	}

	Element<T>* operator[](int i)
	{
		//индексация
		if (i<0 || i>num) 
			return nullptr;
		int k = 0;
		Element<T> * cur = begin;
		for (k = 0; k<i; k++)
		{
			cur = cur->getNext();
		}
		return cur;
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

	void insert_i(int n, T value)
	{
		Element<T> * e = (*this)[n];
		insert(e, value);
	}

	Element<T>* insert(Element<T> * current, T value)
	{
		//вставка элемента со значением value в список сразу за элементом current
		Element<T> * newElem = new Element<T>;
		newElem->setNext(nullptr);
		newElem->setValue(value);

		return insert(current, newElem);
	}

	Element<T>* insert(Element<T> * current,Element<T> * newElem)
	{
		//вставка элемента newElem в список сразу за элементом current
		if (current == nullptr)
		{
			if (begin == nullptr)
				return nullptr;
			current = begin;
			while (current->getNext() != nullptr)
			{
				current = current->getNext();
			}
			newElem->setNext(current->getNext());
			current->setNext(newElem);
			num++;
			return newElem;
		}
		newElem->setNext(current->getNext());
		current->setNext(newElem);
		num++;
		return newElem;
	}
	
	void remove_i(int n)
	{
		Element<T> * e = (*this)[n];
		remove(e);
	}

	void remove(Element<T> * current)
	{
		//удаление элемента
		if (current != nullptr)
		{
			Element<T> * cur = begin;
			if(cur!=current)
			{
				while (cur->getNext() != current)
				{
					cur = cur->getNext();
				}
			}
			cur->setNext(current->getNext());
			num--;
			//освобождение памяти
			delete current;
		}
	}
	
	Element<T> *  find(T a)
	{
		Element<T> * e = begin;
		if(begin==nullptr)
			return nullptr;
		else
		{
			for(e;e!=nullptr;e=e->getNext())
			{
				if (e->getValue()==a)
					return e;
			}
		}
		return nullptr;
	}

	void del_all()
	{
		this->~LinkedList<T>();
	}

	void remove(T a)
	{
		//удаление элемента
		Element<T>*e = find(a);
		if(e!=nullptr)
		{
			Element<T>*next=e->getNext();
			if (e != begin)
				remove(e);
			if (e == begin)
			{
				remove(e);
				begin = next;
			}
		}
	}
	LinkedList<T> reverse();
	LinkedList<T>& operator = (const LinkedList<T>&);
	LinkedList<T> operator + (const LinkedList<T>&);
};

template <class T>
LinkedList<T> LinkedList<T>::reverse()
{
	LinkedList<T> cur;
	Element<T>* temp = begin;
	while(temp != nullptr)
	{
		cur.add_to_begin(temp->getValue());
		temp = temp->getNext();
	}
	return cur;
}

template <class T>
LinkedList<T> & LinkedList<T>::operator = (const LinkedList<T> & L)
{
    if(this == &L)
       return *this;
   this->~LinkedList<T>();
   Element<T> * temp = L.begin;
   while(temp != nullptr)
   {
      push(temp->getValue());
      temp = temp->getNext();
   }
   return *this;
}

template <class T>
LinkedList<T> LinkedList<T>::operator + (const LinkedList<T>& L)
{
   LinkedList<T> cur(*this);
   Element<T> * temp = L.begin;
   while(temp != nullptr)
   {
      cur.push(temp->getValue());
      temp = temp->getNext();
   }
   return cur;
}
 
int _tmain(int argc, _TCHAR* argv[])
{
	LinkedList<int> L;
	L.push(1);
	L.push(2);
	L.push(3);
	L.push(4);
	L.print();
	LinkedList<int> F;
	F.add_to_begin(1);
	F.add_to_begin(2);
	F.add_to_begin(3);
	F.print();
	F.remove_i(2);
	F.print();
	F.insert_i(2, 1);
	F.print();
	LinkedList<int> G(L.reverse());
	G.print();
	G = F + L;
	G.del_all();
	G.print();
	system("pause");
	return 0;
}

