#include <iostream>
#include "complex.h"


int main(){

	int r = 1,i = 1;
	complex com_1(r,i);
	i = -1;
	complex com_2(r,i);

	com_1 += com_2;
	std::cout << com_1 << '\n' << com_2 << '\n';

	std::cout << com_1 + com_2 << '\n';
	return 0;
}
