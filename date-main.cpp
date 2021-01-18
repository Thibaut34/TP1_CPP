#include <iostream>
#include "date.h"
#include <cassert>



int main() {
	Date valid(2019,4,30);
	std :: cout << valid.year() << std::endl;
	std ::cout << valid.toString() << std::endl;
	return 0;
};
