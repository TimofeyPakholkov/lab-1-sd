#include <iostream>
#include <cstring>

int main (int argc, char *argv[])
{
	if (!strcmp(argv[2],"float")) {
		union {
			float d;
			char c[sizeof(float)];
		}qu;
		qu.d=atof(argv[1]);
		for (int i=sizeof(float)-1; i>=0; i--) {
			int k=128;
			while (k>0) {
				printf("%d", bool(qu.c[i] & k));
				k=k>>1;
			};
			std::cout << '\t';
		}
	}
	else
		if (!strcmp(argv[2],"double")) {
			union {
				double d;
				char c[sizeof(double)];
			}q;
			q.d=atof(argv[1]);
			for (int i=sizeof(double)-1; i>=0; i--) {
                        	int k=128;
                        	while (k>0) {
                                	printf("%d", bool(q.c[i] & k));
                                	k=k>>1;
                        	};
                        	std::cout << '\t';
                	}
		}
		else {
			std::cout << "Ошибка вввода" << std::endl;
			exit(1);
		}
	std::cout << std::endl;
	return 0;
}
