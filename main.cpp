#include <iostream>

#include "myString.h"

int main()
{
	//std::cout << "hello world!" << std::endl;
	{

		xl_string::stringConstructor xl1;
		xl1.test_constructor();
		xl1.test_operatorEqual();

		xl_string::stringIteratorAccess xl2;
		xl2.test_iterator();
		xl2.test_access();

		xl_string::stringOperators xl5;
		xl5.test_c_str();
		xl5.test_data();
		xl5.test_copy();
		xl5.test_find();
		xl5.test_rfind();

		xl_string::nonMemberfunctions xl6;
		xl6.test_operatorConcatenate();
		//xl6.test_operatorExtract();
		xl6.test_operatorInsert();
		xl6.test_relationalOpt();
		xl6.test_swap();
		//xl6.test_getline();

	}

	return 0;
}


