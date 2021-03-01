
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include "myString.h"




namespace xl_string {

	/*------------------         string operations        --------------*/
	/* string operations: 
		std::string::c_str   // copy string to char[].  
		const char* c_str() const noexcept;
		const char* data() const noexcept;    // c_str() == data()

	*/
	void stringOperators::test_c_str()
	{
		std::string str("math, art, english, chemical");
		size_t len = str.length();
		char* cstr = new char[len + 1];
		//cstr[0] = '\0';
		std::cout << "str len = " << str.length() << std::endl;
		strcpy_s(cstr, len+1, str.c_str());

		std::cout << cstr << std::endl;

		delete[] cstr;
	}

	/* std::string::data
		const char* data() const noexcept;
	*/
	void stringOperators::test_data()
	{
		std::string str = "Python";
		const char* cstr= "Python";

		if (!memcmp(cstr, str.data(), str.length())) {
			std::cout << " str and cstr have same content." << std::endl;
		}
	}

	/* std::string::get_alocator
		alocator_type get_allocator() const noexcept;
	*/

	/* std::string::copy
		// copy a subsrting to char[], return length.
		size_t copy(char* s, size_t len, size_t pos = 0) const;
	*/
	void stringOperators::test_copy()
	{
		std::string str("Test string copy");

		char buff[32];
		memset(buff, 0, 32);
		std::size_t len = str.copy(buff, 6, 5);

		char buff2[32];
		std::size_t len2 = str.copy(buff2, 5);
		buff2[len2] = '\0';

		std::cout << "buff = " << buff << ", buff2 = " << buff2 << std::endl;
	}

	void stringOperators::test_find()
	{}

	void stringOperators::test_substr()
	{}

	void stringOperators::test_compare()
	{}

	/*------------------         Non-member function overloads--------------                   */
	/* std::operator+ (string)
		string operator+ (const string& lhs, const string& rhs);
		string operator+ (string&& lhs, string&& rhs);
		string operator+ (string&& lhs, const string& rhs);
		string operator+ (const string& lhs, string&& rhs);

		string operator+ (const string& lhs, const char* rhs);
		string operator+ (string&& lhs, const char* rhs);
		string operator+ (const char* lhs, const string& rhs);
		string operator+ (const char* lhs, string&& rhs);

		string operator+ (const string& lhs, char rhs);
		string operator+ (string&& lhs, char rhs);
		string operator+ (char lhs, const string& rhs);
		string operator+ (chat lhs, string&& rhs);
	*/
	void nonMemberfunctions::test_operatorConcatenate()
	{
		std::string firstlevel("com");
		std::string secondlevel("cplusplus");
		std::string scheme("http://");
		std::string hostname;
		std::string url;

		// "www." ->string&&
		// secondlevel -> string&
		// '.' -> char 
		// firstlevel -> string&
		hostname = "www." + secondlevel + '.' + firstlevel;
		url = scheme + hostname;

		std::cout << url << std::endl;
	}

	/* std::operator>> (string)
		istream& operator>> (istream& is, string& str);		
	*/
	void nonMemberfunctions::test_operatorExtract()
	{
		std::string name;
		std::cout << "Please entry your name:";
		std::cin >> name;
		std::cout << "Welcome, " << name << std::endl;
	}

	/* std::operator<< (string)
		ostream& operator<< (ostream& os, const string& str);
	*/
	void nonMemberfunctions::test_operatorInsert()
	{
		std::string str = "cplusplus";
		std::cout << "This is " << str << std::endl;
	}


	/* relational operators (string)
		bool operator== (const string& lhs, const string& rhs);
		bool operator== (const char* lhs, const string& rhs);
		bool operator== (const string& lhs, const char* rhs);

		bool operator!= (const string& lhs, const string& rhs);
		bool operator!= (const char* lhs, const string& rhs);
		bool operator!= (const string& lhs, const char* rhs);
		
		bool operator< (const string& lhs, const string& rhs);
		bool operator< (const char* lhs, const string& rhs);
		bool operator< (const string& lhs, const char* rhs);

		bool operator<= (const string& lhs, const string& rhs);
		bool operator<= (const char* lhs, const string& rhs);
		bool operator<= (const string& lhs, const char* rhs);

		bool operator> (const string& lhs, const string& rhs);
		bool operator> (const char* lhs, const string& rhs);
		bool operator> (const string& lhs, const char* rhs);

		bool operator>= (const string& lhs, const string& rhs);
		bool opreator>= (const char* lhs, const string& rhs);
		bool operator>= (const string& lhs, const char* rhs);
	*/
	void nonMemberfunctions::test_relationalOpt()
	{
		std::string str1 = "alpha";
		std::string str2 = "beta";

		char buff[32] = "alpha";

		if (str1 == str1) {
			std::cout << "str1 equal buff" << std::endl;
		}

		if (str1 != str2) {
			std::cout << "str1 not equal str2" << std::endl;
		}

		if (str1 < str2) {
			std::cout << "str1 less than str1" << std::endl;
		}

		if (str1 <= str2) {
			std::cout << "str1 less than or equal str2" << std::endl;
		}

		if (str1 > str2) {
			std::cout << "str1 greater than str2" << std::endl;
		}

		if (str1 >= str2) {
			std::cout << "str1 greater than or equal str2" << std::endl;
		}

	}

	/* std::swap (string)
		void swap(string& x, string& y); // Note: No const!!!
	*/
	void nonMemberfunctions::test_swap()
	{
		std::string str1("hello");
		std::string str2 = "welcome";

		std::cout << "Before swap, str1 = " << str1 << ", str2 = " << str2 << std::endl;
		std::swap(str1, str2);
		std::cout << " After swap, str1 = " << str1 << ", str2 = " << str2 << std::endl;

	}

	/* std::getline(string)
		istream& getline(istream&  is, string& str, char delim);
		istream& getline(istream&& is, string& str, char delim);
		istream& getline(istream&  is, string& str);  // '\n'
		istream& getline(istream&& is, string& str);
	*/
	void nonMemberfunctions::test_getline()
	{
		std::string msg;
		std::cout << "Type your msg : ";
		std::cin.ignore();
		std::getline(std::cin, msg);
		std::cout << "Your message is : " << msg << std::endl;

		std::istringstream input;
		input.str("1 2 3 4 5 6 7");
		int sum = 0;
		for (std::string line; std::getline(input, line, ' ');) {
			sum += std::stoi(line);
		}
		std::cout << "The sum is " << sum << std::endl;
	}
}