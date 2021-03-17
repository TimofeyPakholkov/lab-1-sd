#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>

void conv(int a)
{
	std::string s;
	std::ofstream f;
	f.open("fff.txt");
	while (a>1) {
		if (a%2==0)
			s+="0";
		else
			s+="1";
		a=a/2;
	}
	std::reverse(s.begin(),s.end());
	f << s;
	f.close();
}

int main(int argc,char *argv[])
{
	bool z=0;
	if (atoi(argv[1])<0)
		z=1;
	int i=0,l,e,h=23;
	double a,d;
	std::string s, ss;
	conv(abs(atoi(argv[1])));
	std::ifstream f;
	f.open("fff.txt");
	f >> s;
	f.close();
	l=s.length();
	d=modf(atof(argv[1]),&a);
	if (!strcmp(argv[2],"double"))
		h=52;
	while (i!=(h-l)) {
		d=modf(2*d,&a);
		s+=std::to_string(abs((int)a));
		i++;
	}
	ss=s;
	if (!strcmp(argv[2],"double"))
		e=1023;
	if (!strcmp(argv[2],"float"))
                e=127;
	else
		if (e!=1023) {
			std::cout << "Ошибка ввода" << '\n';
			exit(1);
		}
	e+=l;
	conv(e);
	f.open("fff.txt");
	f >> s;
	f.close();
	std::cout << z << '\t' << "1" << s << '\t' << ss << '\n';
	return 0;
}
