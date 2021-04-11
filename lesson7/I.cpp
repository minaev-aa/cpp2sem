#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main()
{
	std::string x;
	getline(std::cin,x);
	int num, n;
    std::vector <int> vec;
	std::vector <int> chet;
	std::vector <int> nechet;
    
	std::string buffer = "";
	for(int i=0; i < x.size(); i++){
    if(x[i] != ' '){     
          buffer += x[i];     
    }
    else{
          vec.push_back(atoi(buffer.c_str()));
          buffer = "";
    }
	
	}
	vec.push_back(atoi(buffer.c_str()));
    buffer = "";
	n =vec.size();
	for(int i = 0; i < n; i++)
    {
		int in = vec[i];
		if (in % 2 == 0)
			chet.push_back(in);
		else
			nechet.push_back(in);
	
	}
	std::sort(chet.rbegin(), chet.rend());
	std::reverse(chet.begin(), chet.end());
	std::sort(nechet.rbegin(), nechet.rend());
	std::reverse(nechet.begin(), nechet.end());
	chet.insert(chet.end(), nechet.begin(), nechet.end());
	for(int i = 0; i < n; i++)
    {
        std::cout << chet[i] << " ";
	}
    return 0;
}