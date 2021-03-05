
#include <sstream>
#include <cstring>
#include <stdio.h>
#include "myString.h"


namespace xl_string {

	/* (constructor) std::string::string
		string(); //default
		string(const string& str); //copy
		string(const string& str, size_t pos, size_t len = npos); // substring.
		string(const char* s); // from c-string
		string(const char*s, size_t n); // from buffer
		string(size_t n, char c); // fill
		string(InputIterator first, InputIterator lase); // range
		string(initializer_list<char> il); // initializer list
		string(string&& str) noexcept; // move
	*/
	void stringConstructor::test_constructor()
	{
		std::cout << "\nTest string::string() constructor...." << std::endl;

		std::string str1;
		std::string str2 = "Praise for born a crime";
		std::cout << "str2=" << str2 << std::endl;

		std::string str3(str2);
		std::cout << "constructor: str3(str2) = " << str3 << std::endl;

		std::string str4(str2, 0, 5); 
		std::cout << "constuctor: str4(str2, 0, 5) = " << str4 << std::endl;

		std::string str5(str2, 20);
		std::cout << "constuctor: str5(str2, 20) = " << str5 << std::endl;

		const char buff[] = "Artemis Fowl Series";
		std::string str6(buff);
		std::cout << "buff[]=" << buff << std::endl;
		std::cout << "constuctor: str6(buff) = " << str6 << std::endl;

		std::string str7(buff, 7);
		std::cout << "constuctor: str7(buff, 7) = " << str7 << std::endl;

		std::string str8(6, 'f');
		std::cout << "constructor: str8(6,'f') = " << str8 << std::endl;

		std::string str9(str2.begin() + 6, str2.end());
		std::cout << "constructor: str9(str2.begin()+6,str2.end()) = " << str9 << std::endl;

		std::string str10("Hello");
		std::cout << "constructor: str10(string&& \"Hello\") = " << str10 << std::endl;

	}

	/* std::string::poerator=
		string& operator= (const string& str);  // string
		string& operator= (const char* s);    // c-string
		string& operator= (char c);  // character
		string& operator= (initializer_list<char> il); // initializer list
		string& operator= (string&& str) noexcept;  // move
	*/
	void stringConstructor::test_operatorEqual()
	{
		std::cout << "\nTest string::operator= () ...." << std::endl;

		std::string str1;

		std::string str2("Vicent and Thoe");

		std::cout << "str1=" << str1 << std::endl;
		std::cout << "str2=" << str2 << std::endl;

		// operator=(const string& str);
		str1 = str2;
		std::cout << "operator=(str1) =" << str1 << std::endl;

		std::string str3;
		str3 = 'B';
		std::cout << "operator=('B') =" << str3 << std::endl;

		std::string str4;
		str4 = {'H', 'E', 'L', 'L', 'O'};
		std::cout << "operator=('H', 'E', 'L', 'L', 'O') =" << str4 << std::endl;

	}

	/* iterator: begin(), end(), rbegin(), rend()
	   const iterator: cbegin(), cend(), crbegin(), crend()
	*/
	void stringIteratorAccess::test_iterator()
	{
		std::cout << "\nTest string::iterator ...." << std::endl;

		std::string str("The Absolutely True diary of a Part-Time Indian");

		std::string::iterator it;
		std::cout << "str: begin->end = ";
		for (it = str.begin(); it != str.end(); ++it) {
			std::cout << *it;
		}
		std::cout<<std::endl;

		std::string::const_iterator cit;
		std::cout << "str: cbegin->cend =";
		for (cit = str.cbegin(); cit != str.cend(); ++cit) {
			std::cout << *cit;
		}
		std::cout << std::endl;


		std::string::reverse_iterator rit;
		std::cout << "str: end->begin = ";
		for (rit = str.rbegin(); rit != str.rend(); ++rit) {
			std::cout << *rit;
		}
		std::cout << std::endl;

		std::string::const_reverse_iterator crit;
		std::cout << "str: crbegin->crend =";
		for (crit = str.crbegin(); crit != str.crend(); ++crit) {
			std::cout << *crit;
		}
		std::cout << std::endl;

	}

	/*
	*/
	void stringIteratorAccess::test_access()
	{

	}

	/*------------------         string operations        --------------*/
	/* string operations: 
		std::string::c_str   // copy string to char[].  
		const char* c_str() const noexcept;
		const char* data() const noexcept;    // c_str() == data()

	*/
	void stringOperators::test_c_str()
	{
		std::cout << "\nTest string::c_str()...." << std::endl;

		std::string str("math, art, english, chemical");

		std::cout << "str=" << str << std::endl;

		size_t len = str.length();
		char* cstr = new char[len + 1];
		//cstr[0] = '\0';
		std::cout << "str len = " << str.length() << std::endl;
		strcpy_s(cstr, len+1, str.c_str());

		std::cout << cstr << std::endl;

		std::cout << "str.c_str()=" << str.c_str() << std::endl;

		delete[] cstr;
	}

	/* std::string::data
		const char* data() const noexcept;
	*/
	void stringOperators::test_data()
	{
		std::cout << "\nTest string::data()...." << std::endl;

		std::string str = "Python";
		const char* cstr= "Python";

		if (!memcmp(cstr, str.data(), str.length())) {
			std::cout << " str and cstr have same content." << std::endl;
		}

		std::cout << "str=" << str << std::endl;
		std::cout << "str.data()="<<str.data() << std::endl;
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
		std::cout << "\nTest string::copy()...." << std::endl;

		std::string str("Test string copy");

		char buff[32];
		memset(buff, 0, 32);
		std::size_t len = str.copy(buff, 6, 5);  //len = 6, buff = "string"

		std::cout << "str = " << str << std::endl;
		std::cout << "str.copy(buff, 6, 5), result: buff=" << buff << std::endl;

		char buff2[32];
		std::size_t len2 = str.copy(buff2, 6);   //len2 = 6, buff2 = "Test s"
		buff2[len2] = '\0';

		std::cout << "str.copy(buff2, 6), result: buff2=" << buff2 << std::endl;
	}

	/* std::string::find
		size_t find(const string*str, size_t pos = 0) const noexcept; //string
		size_t find(const char* s, size_t pos = 0) const;  // c-string
		size_t find(const char* s, size_t pos, size_type n) const;  // buffer
		size_t find(char c, size_t pos = 0) const noexcept;  // character

	*/
	void stringOperators::test_find()
	{
		std::cout << "\nTest string::find()...." << std::endl;

		std::string str = "welcome to the cplusplus!";
		std::string str1("to");
		size_t pos = 0;

		std::cout << "str = " << str << std::endl;

		pos = str.find(str1);
		if (pos != std::string::npos) {
			std::cout << "str.find(\"to\")=" << pos << std::endl;
		}
		pos = str.find(str1, 10);
		if (pos == std::string::npos) {
			std::cout << "str.find(\"to\", 10)= string::npos"<<std::endl;
		}

		char buff[] = "the";
		pos = str.find(buff);
		if (pos != std::string::npos) {
			std::cout << "str.find(\"the\")=" << pos << std::endl;
		}
		char buff1[] = "welcomm";
		pos = str.find(buff1, 0, 6);
		if (pos != std::string::npos) {
			std::cout << "str.find(\"welcomm\", 0, 6)=" << pos << std::endl;
		}
		pos = str.find(buff1, 0, 7);
		if (pos == std::string::npos) {
			std::cout << "str.find(\"welcomm\", 0, 7)==string::npos" << std::endl;
		}

		pos = str.find('c');
		if (pos != std::string::npos) {
			std::cout << "str.find('c')=" << pos << std::endl;
		}
	}

	/* std::string::rfind
		size_t rfind(const string& str, size_t pos = npos) const noexcept; // string
		size_t rfind(const char* s, size_t pos = npos) const; //c-string
		size_t rfind(const char* s, size_t pos, size_t n) const; //buffer
		size_t rfind(char c, size_t pos = npos) const noexcept; //character
	*/
	void stringOperators::test_rfind()
	{
		std::cout << "\nTest string::rfind()...." << std::endl;

		std::string str = "welcome to the cplusplus!";
		std::string subStr("plus");
		size_t pos = 0;

		std::cout << "str = " << str << std::endl;

		pos = str.rfind(subStr);
		std::cout << "str.rfind(\"plus\")=" << pos << std::endl;

		pos = str.rfind(subStr, 2);
		std::cout << "str.rfind(\"plus\", 2)=" << pos << std::endl; // pos = 4294967295
		if (pos == std::string::npos) {
			std::cout << "str.rfind(\"plus\", 2)=string::npos: not found!"<< std::endl; // pos = 4294967295
		}

		pos = str.rfind('o');
		std::cout << "str.rfind('o')=" << pos << std::endl;

		pos = str.rfind('o', 50);
		std::cout << "str.rfind('o', 50)=" << pos << std::endl;  // if pos >npos, pos = npos.

		std::cout << "str.rfind('o', 7)=" << str.rfind('o', 7) << std::endl;

	}

	/* std::string::find_first_of
		size_t find_first_of(const string& str, size_t pos = 0) const noexcept; //string
		size_t find_first_of(const char* s, size_t pos = 0) const;  // c-string
		size_t find_first_of(const char* s, size_t pos, size_t n) const; // buffer
		size_t find_first_of(char c, size_t pos = 0) const noexcept; // character
	*/
	void stringOperators::test_find_first_of()
	{
		std::cout << "\nTest string::find_first_of()...." << std::endl;

		std::string str = "";
	}

	void stringOperators::test_find_last_of()
	{}

	void stringOperators::test_find_first_not_of()
	{}

	void stringOperators::test_find_last_not_of()
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
		std::cout << "\nTest string::operator+()...." << std::endl;

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
		std::cout << "\nTest string::relation operation:==, !=, <,<=, > >=" << std::endl;
		std::string str1 = "alpha";
		std::string str2 = "beta";

		char buff[32] = "alpha";

		std::cout << "str1=" << str1 << std::endl;
		std::cout << "str2=" << str2 << std::endl;

		bool b=false;
		b = (str1 == str2);
		std::cout << "str1 == str2 ? result = " << b << std::endl;

		b = (str1 != str2);
		std::cout << "str1 != str2 ? result = " << b << std::endl;

		b = (str1 < str2);
		std::cout << "str1 < str2 ? result = " << b << std::endl;

		b = (str1 <= str2);
		std::cout << "str1 <= str2 ? result = " << b << std::endl;

		b = (str1 > str2);
		std::cout << "str1 > str2 ? result = " << b << std::endl;

		b = (str1 >= str2);
		std::cout << "str1 >= str2 ? result = " << b << std::endl;

	}

	/* std::swap (string)
		void swap(string& x, string& y); // Note: No const!!!
	*/
	void nonMemberfunctions::test_swap()
	{
		std::cout << "\nTest string::swap()...." << std::endl;

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
		std::cout << "\nTest string::getline()...." << std::endl;

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
		std::cout << "The sum(1 2 3 4 5 6 7) is " << sum << std::endl;
	}
}