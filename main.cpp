#include <iostream>

#include "myString.h"

int main()
{
	//std::cout << "hello world!" << std::endl;
	{
		xl_string::nonMemberfunctions xl1;

		xl1.test_operatorConcatenate();
		xl1.test_operatorExtract();
		xl1.test_operatorInsert();

		xl1.test_relationalOpt();
		xl1.test_swap();
		xl1.test_getline();

		xl_string::stringOperators xl2;

		xl2.test_c_str();
		xl2.test_data();
		xl2.test_copy();
	}

	return 0;
}


