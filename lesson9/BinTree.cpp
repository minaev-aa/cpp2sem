#include <iostream>

using namespace std;

class Node
{
private:
	int data;

	Node* left;
	Node* right;
	Node* parent;
public:
	void setData(int d) {data = d;}
	int getData(){return data;}

	Node* getLeft(){return left;}
	Node* getRight(){return right;}
	Node* getParent(){return parent;}

	void setLeft(Node* N){left = N;}
	void setRight(Node* N){right = N;}
	void setParent(Node* N){parent = N;}

	
	Node(int n)
	{
		data = n;
		left = right = parent = NULL;
	}

	Node()
	{
		left = NULL;
		right = NULL;
		parent = NULL;
		data = 0;
	}

	void print()
	{
		cout<<data<<"\n";
	}
};

void print(Node* N) {cout<<"\n"<<N ->getData();}

class Tree
{
private:
	Node* root;
public:
	Node *getRoot() {return root;}
	Tree() {root = NULL;}

	void Add_R(Node* N, Node* Current = NULL)
    {
    	if(N==NULL) 
		{return;}
    	if(root==NULL)
    	{
    		root = N;
    		return;
    	}
    	if(Current==NULL) 
		{Current = root;}
		if (Current->getData() >= N->getData())
		{
			if (Current->getLeft()!=NULL)
			{
				Add_R(N,Current->getLeft());
			}
			else
			{
				Current->setLeft(N);
				N->setParent(Current);
			}
		}
		if (Current->getData()< N->getData())
		{
			if (Current->getRight()!=NULL)
			{
				Add_R(N,Current->getRight());
			}
			else
			{
				Current->setRight(N);
				N->setParent(Current);
			}
		}
    }

	void Add(int n)
	{
		Node* N = new Node;
		N->setData(n);
		Add_R(N);
	}

	void Remove(Node* Current)
	{
		if(Current==NULL)
			return;
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
			Parent->setRight(GrandChild);
			GrandChild->setParent(Parent);
			Child ->setLeft(Current->getLeft());
			Child ->setRight(Current->getRight());
			Current->getLeft()->setParent(Child);
			Current->getRight()->setParent(Child);
			Child->setParent(Current->getParent());
			if(Current == root)
				root=Child;
			delete Current;
		}
	}

	Node* Min_R(Node* Current)
	{
		if(root==NULL) return NULL;
		if(Current->getLeft()!=NULL)
			return Min_R(Current->getLeft());
		return Current;
	}

	Node* Max_R(Node* Current)
	{
		if(root==NULL) return NULL;
		if(Current->getRight()!=NULL)
			return Min_R(Current->getRight());
		return Current;
	}

	Node* Find(int data, Node* Current = NULL)
	{
		if(Current==NULL) 
			throw 0;
		if (data == NULL || data == Current->getData())
				return Current;
		if (data<Current->getData())
			return Find(data,Current->getLeft());
		if (data>Current->getData())
			return Find(data,Current->getRight());
		
	}


	void PreOrder(Node* N, void (*f)(Node*))
	{
		if(N!=NULL)
			f(N);
		if(N!=NULL && N->getLeft()!=NULL)
			PreOrder(N->getLeft(), f);
		if(N!=NULL && N->getRight()!=NULL)
			PreOrder(N->getRight(), f);
	}

	
	void InOrder(Node* N, void (*f)(Node*))
	{
		if(N!=NULL && N->getLeft()!=NULL)
			InOrder(N->getLeft(), f);
		if(N!=NULL)
			f(N);
		if(N!=NULL && N->getRight()!=NULL)
			InOrder(N->getRight(), f);
	}

	void PostOrder(Node* N, void (*f)(Node*))
	{
		if(N!=NULL && N->getLeft()!=NULL)
			PostOrder(N->getLeft(), f);
		if(N!=NULL && N->getRight()!=NULL)
			PostOrder(N->getRight(), f);
		if(N!=NULL)
			f(N);
	}


};

int _tmain(int argc, _TCHAR* argv[])
{
	Tree T;
	T.Add(5);
	T.Add(3);
	T.Add(6);
	T.Add(4);
	T.Add(2);

	Node *M = T.Min_R(T.getRoot());
	cout<<"\nMin = "<<M->getData()<<'\n';
	T.Add(10);
	Node* n;
	try
	{
		n = T.Find(5, T.getRoot());
	}
	catch(...)
	{
		n=NULL;
	}
	T.Remove(n);
	void (*f_ptr)(Node*); f_ptr = print;
	cout<<"\n-----\nPreorder:"<<'\n';
	T.PreOrder(T.getRoot(), f_ptr);
	cout<<"\n-----\nInorder:"<<'\n';
	T.InOrder(T.getRoot(), f_ptr);
	cout<<"\n-----\nPostorder:"<<'\n';
	T.PostOrder(T.getRoot(), f_ptr);
	Node *R = T.Min_R(T.getRoot());
	cout<<R->getData()<<'\n';

	return 0;
}