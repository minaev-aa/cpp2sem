#include <iostream>
using namespace std;

class Node
{
protected:
	int data;
	Node* left;
	Node* right;
	Node* parent;

	int height;
public:
	virtual void setData(int d) {data = d;}
	virtual int getData(){return data;}
	int getHeight(){return height;}

	virtual Node* getLeft(){return left;}
	virtual Node* getRight(){return right;}
	virtual Node* getParent(){return parent;}

	virtual void setLeft(Node* N){left = N;}
	virtual void setRight(Node* N){right = N;}
	virtual void setParent(Node* N){parent = N;}

	Node(int n)
	{
		data = n;
		left = right = parent = NULL;
		height = 1;
	}

	Node()
	{
		left = NULL;
		right = NULL;
		parent = NULL;
		data = 0;
		height = 1;
	}

	virtual void print()
	{
		cout<<"\n"<<data;
	}

    virtual void setHeight(int h)
    {
        height = h;
    }
};

void print(Node* N) {cout<<"\n"<<N ->getData();}

class Tree
{
protected:
	Node* root;
public:
	virtual Node *getRoot() {return root;}
	Tree() {root = NULL;}

	virtual Node* Add_R(Node* N, Node* Current = NULL)
    {
    	if(N==NULL) return NULL;
    	if(root==NULL)
    	{
    		root = N;
    		return N;
    	}
    	if(Current==NULL) Current = root;

    	if(Current->getData() > N->getData())
    	{
    		if(Current->getLeft()!=NULL)
			{
    			Current->setLeft(Add_R(N,Current->getLeft()));
				
			}
    		else
    		{
				Current->setLeft(N);
				N->setParent(Current);
			}
    	}
    	if(Current->getData() < N->getData())
    	{
    		if(Current->getRight()!=NULL)
    		{
				Current->setRight(Add_R(N,Current->getRight()));
				
			}
    		else
    		{
				Current->setRight(N);
				N->setParent(Current);
			}

    	}
    	return Current;
    }

	virtual void Add(int n)
	{
		Node* N = new Node;
		N->setData(n);
		Add_R(N);
	}

	virtual Node* Remove(Node* Current)
	{ 
		if(Current==NULL)
				return NULL;
		if(Current->getLeft()==NULL && Current->getLeft()==NULL)
			{
				Node* Parent = Current->getParent();
				if (Parent!=NULL && Parent->getLeft()==Current)
				{
					Parent->setLeft(NULL);
				}
				if (Parent!=NULL && Parent->getRight()==Current)
				{
					Parent->setRight(NULL);
				}
			}
		if(Current->getLeft()==NULL && Current->getRight()!=NULL)
		{
			Node * Child = Current ->getRight();
			Node * Parent = Current->getParent();
			Child->setParent(Parent);
			if(Parent!=NULL && Parent->getLeft()==Current)
			{
				Parent->setLeft(Child);
			}
			if(Parent!=NULL && Parent->getRight()==Current)
			{
				Parent->setRight(Child);
			}
		}
		if(Current->getLeft()!=NULL && Current->getRight()==NULL)
		{
			Node * Child = Current ->getLeft();
			Node * Parent = Current->getParent();
			Child->setParent(Parent);
			if(Parent!=NULL && Parent->getLeft()==Current)
			{
				Parent->setLeft(Child);
			}
			if(Parent!=NULL &&Parent->getRight()==Current)
			{
				Parent->setRight(Child);
			}
		}
		if(Current->getLeft()!=NULL && Current->getRight()!=NULL)
		{
			Node * Child= Min_R(root->getRight());
			Node * GrandChild = Child->getRight();
			Node * Parent = Child ->getParent();
			if(Parent != root)
				Parent->setLeft(GrandChild);
			else
				Parent->setRight(GrandChild);
			if(GrandChild!=NULL)
				GrandChild->setParent(Parent);
			Child ->setLeft(Current->getLeft());
			Child ->setRight(Current->getRight());
			Current->getLeft()->setParent(Child);
			Current->getRight()->setParent(Child);
			Child->setParent(Current->getParent());
			if(Current == root)
				root=Child;
			delete Current;
			return Child;
		}
		return Current;
	}

	virtual Node* Min_R(Node* Current)
	{
		if(root==NULL) return NULL;
		if(Current->getLeft()!=NULL)
			return Min_R(Current->getLeft());
		return Current;
	}

	virtual Node* Max_R(Node* Current)
	{
		if(root==NULL) return NULL;
		if(Current->getRight()!=NULL)
			return Min_R(Current->getRight());
		return Current;
	}

	virtual Node* Find(int data, Node* Current)
	{
		if(Current==NULL) return NULL;

		if(Current->getData() == data) return Current;

		if(Current->getData()>data) return Find(data, Current->getLeft());

		if(Current->getData()<data) return Find(data, Current->getRight());
	}


	virtual void PreOrder(Node* N, void (*f)(Node*))
	{
		if(N!=NULL)
			f(N);
		if(N!=NULL && N->getLeft()!=NULL)
			PreOrder(N->getLeft(), f);
		if(N!=NULL && N->getRight()!=NULL)
			PreOrder(N->getRight(), f);
	}

	virtual void InOrder(Node* N, void (*f)(Node*))
	{
		if(N!=NULL && N->getLeft()!=NULL)
			InOrder(N->getLeft(), f);
		if(N!=NULL)
			f(N);
		if(N!=NULL && N->getRight()!=NULL)
			InOrder(N->getRight(), f);
	}

	virtual void PostOrder(Node* N, void (*f)(Node*))
	{
		if(N!=NULL && N->getLeft()!=NULL)
			PostOrder(N->getLeft(), f);
		if(N!=NULL && N->getRight()!=NULL)
			PostOrder(N->getRight(), f);
		if(N!=NULL)
			f(N);
	}
};

class AVL_Tree: public Tree
{
protected:
	int bfactor(Node* p)
    {
        int hl = 0;
        int hr = 0;
        if(p->getLeft()!=NULL)
            hl = p->getLeft()->getHeight();
        if(p->getRight()!=NULL)
            hr = p->getRight()->getHeight();
        return (hr - hl);
    }

	//при добавлении узлов в них нет информации о балансе, т.к. не ясно, куда в дереве они попадут
	//после добавления узла рассчитываем его высоту (расстояние до корня) и редактируем высоты в узлах, где это
	//значение могло поменяться
    void fixHeight(Node* p)
    {
        int hl = 0;
        int hr = 0;
        if(p->getLeft()!=NULL)
            hl = p->getLeft()->getHeight();
        if(p->getRight()!=NULL)
            hr = p->getRight()->getHeight();
        p->setHeight((hl>hr?hl:hr)+1);
    }

    Node* RotateRight(Node* p) // правый поворот вокруг p
    {
		Node* Parent = p->getParent();
        Node* q = p->getLeft();
		Node* B = q->getRight();
        p->setLeft(B);
		if (B!=NULL)
			B->setParent(p);
        q->setRight(p);
		if (q!=NULL)
			p->setParent(q);
        if(p==root)
		{
			q->setParent(NULL);
			root = q;
		}
		else
			q->setParent(Parent);
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    Node* RotateLeft(Node* q) // левый поворот вокруг q
    {
		Node* Parent = q->getParent();
        Node* p = q->getRight();
		Node* B = p->getLeft();
        q->setRight(B);
		if (B!=NULL)
			B->setParent(q);
        p->setLeft(q);
		if (p!=NULL)
			q->setParent(p);
        if(q==root)
		{
			p->setParent(NULL);
			root = p;
		}
		else
			p->setParent(Parent);
        fixHeight(q);
        fixHeight(p);
        return p;
    }

	//балансировка поддерева узла p - вызов нужных поворотов в зависимости от показателя баланса
    Node* Balance(Node* p) // балансировка узла p
    {
        fixHeight(p);
		if( bfactor(p)==2 )
		{
			if( bfactor(p->getRight()) < 0 )
				p->setRight(RotateRight(p->getRight()));
			return RotateLeft(p);
		}
		if( bfactor(p)==-2 )
		{
			if( bfactor(p->getLeft()) > 0  )
				p->setLeft(RotateLeft(p->getLeft()));
			return RotateRight(p);
		}
			return p; // балансировка не нужна
	}

public:
	//конструктор AVL_Tree вызывает конструктор базового класса Tree
	AVL_Tree(): Tree() {}
	Node* Remove(Node* N)
	{
		Node* remNode =Tree::Remove(N);
		return Balance(remNode);
	}
	//переопределение функции Add_R
	Node* Add_R(Node* N, Node* Current = NULL)
	{
		Node* AddedNode = Tree::Add_R(N, Current);
		//применяем к добавленному узлу балансировку
		return Balance(AddedNode);
	}
 
	void Add(int n)
	{
		Node* N = new Node;
		N->setData(n);
		Add_R(N);
	}
};

int main()
{
	void (*f_ptr)(Node*); f_ptr = print;
	AVL_Tree T;
	int arr[15];
	int i=0;
	for(i=0;i<15;i++) arr[i] = (int)(100*cos(15*double(i)));
	for(i=0;i<15;i++) 
		T.Add(arr[i]);
	
	Node *M = T.Min_R(T.getRoot());

	cout<<"\nMin = "<<M->getData()<<"\tFind "<<arr[3]<<": "<<T.Find(arr[3], T.getRoot());
	T.Remove(T.Find(arr[2], T.getRoot()));
	
	cout<<"\n-----\nPreorder:";
	T.PreOrder(T.getRoot(), f_ptr);
	cout<<"\n-----\nInorder:";
	T.InOrder(T.getRoot(), f_ptr);
	cout<<"\n-----\nPostorder:";
	T.PostOrder(T.getRoot(), f_ptr);
	cout<<"\n";
	char c; cin>>c;
	return 0;
}