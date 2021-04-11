#include <iostream>
#include <iomanip>
#include <vector>


int main() {
    std::vector<double> v;
	double m = 0., d=0., x;

	double f =1;
    while(f == 1)
    {
        std::cin >> x;
		if(x == 0)
		    f = 0; 
		if (f == 1){
		v.push_back(x);}
		
	}
	for(int i = 0; i < v.size();i++)
	{
		m += v[i];
		d += v[i] * v[i];
	}
	m = m / v.size();
	d = d / v.size();
	//std::round(1000*m)/1000;
	d -= m*m;
	int mm = 3;
	int dd =3;
	if (int(m) == m)
	    mm= 1;
	else if (int(m * 10) == m * 10)
	    mm =1;
	else if (int(m * 100) == m * 100)
	    mm =2;
	else
	{
	    mm =3;
	}

	if (int(d) == d)   
	    dd = 1;
	else if (int(d * 10) == d *10)   
	    dd =1; 
	else if (int(d * 100) == d *100)   
	    dd =2;
	else
		dd =3;
	std::cout<<std::fixed<<std::setprecision(mm)<<m<<" ";
	std::cout<<std::fixed<<std::setprecision(dd)<<d;
	return 0;
}