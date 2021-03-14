#include <iostream>
#include <string>

class Stack {
    double *data;
    int len;
    int end;
public:
    Stack(int size = 1) {
        len = size;
        data = new double[size];
        end = 0;
    };
    ~Stack() {
        delete[] data;
    };
    double pop(void) {
        if(end)
		{
			double it = data[--end];
			if (end < len / 2)
			{
				resize(len / 2);
				len = len / 2;
			}
			return it;
		}
    };
    void push(double a) {
        if(end >= len - 1) {
            len = 2 * len;
			resize(len);
        }

        data[end++] = a;
    };
	void resize(int size)
	{
		double* temp = new double[len];
		for(int i = 0; i < len / 2; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
	}
};

void calc()
{
	Stack s;
	std::string str;
	while ( std::cin >> str )
	{
		if ( str == "+")
			s.push(s.pop() + s.pop());
		else if (str == "*") 
			s.push(s.pop() * s.pop());
		else if (str == "/") 
			s.push((1 / s.pop()) * s.pop());
		else if (str == "-") 
			s.push(-s.pop() + s.pop());
		else if (str == "#") 
			break;
		else
			s.push(atof(str.c_str()));
	}
	std::cout << s.pop() << std::endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	Stack k;
	k.push(1);
	k.push(2);
	k.push(3);
	k.push(4);
	std::cout << k.pop()<< "\n";
	std::cout << k.pop()<< "\n";
	std::cout << k.pop()<< "\n";
	std::cout << k.pop()<< "\n";
	calc();
	system("pause");
	return 0;
}

