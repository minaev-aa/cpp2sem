#include <iostream>
#include <vector>
#include <string>

int m;

std::vector < std::vector <std::string>> check(std::vector < std::vector <std::string>> vect, int n)
{
    if(vect[n][1] == "0" && m == 0)
    {    vect[n][1] = "1";
	m=1;}

    else if(vect[n][1] == "1" && m == 0)
    {
        std::vector<std::vector <std::string>>::iterator pos = vect.begin() + n;
        vect.erase(pos);
    }
    else if(vect[n][1] == "0")
    {
        if (m == 1)
            m = 0;
        else if (m == 0)
            m = 1;
    }
    return vect;
}

int main()
{
    int n, k,p;
	p=0;
    std::string name, status;
    std::vector < std::vector <std::string>> vec;
	std::vector <std::string> nima;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin >> name >> status;
		nima.push_back(name);
		nima.push_back(status);
        vec.push_back(nima);
		nima.clear();
    }
    std::cin >> k;
	int l = vec.size();
    for(int i = 0; i < k; i++)
    {
        if(vec.size() != 1 && p < k)
        {
			if(vec.size() < l)
				i -= 1;
			l = vec.size();
			vec = check(vec, i);
			p +=1;
		}
        else
            break;
    }
    for(int i = 0; i < vec.size(); i++)
    {
      std::cout << vec[i][0] << " " << vec[i][1] << std::endl;
    }  
    return 0;
}