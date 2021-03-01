
#include <iostream>
#include <string>

// stoi() convert string to integer
// stol() convert string to long int
// stoul() convert string to unsigned integer
// stoll() convert string to long long
// stof() convert string to float
// stod() convert string to double
// stold() convert string to longdouble
// to_string() convert numerical value to string
// to_wstring() convert numerical value to wide string

// constructor
// destructor
// operator=

// iterator: begin/end, rbegin/rend, cbegin/cend, crbegin/crend

/* Capacity:
    size()
    length()
	max_size()
	resize()
	capacity()
	reverse()
	clear()
	empty()
	shrink_to _fit()
*/

/* Element access
	operator[]
	at
	back()
	front()
*/

/* Modifiers:
	operator+=
	append()
	push_back()
	assign()
	insert()
	erase()
	replace()
	swap()
	pop_back()
*/

/* String operations:
	c_str()
	data()
	get_allocator
	copy()
	find()
	rfind()
	find_first_of()
	find_last_of()
	find_fisrt_not_of()
	find_last_not_of()
	substr()
	compare()
*/

/* Member constants
	npos
*/

/* Non-member functions overloads
	operator+
	relational operators
	swap
	operator>> 
		istream& operator>> (istream* input, string& str);
	operator<<
		
	getline
*/

/* https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/basic_string.h
	template<typename _CharT, typename _Traits, typename _Alloc>
	basic_istream<_CharT, _Traits>&
	operator>>(basic_istream<_charT, _Traits>& _is, basic_istream<_CharT, _Traits, _Alloc>& _str);

	template<>
	basic_istream<char>& operator>>basic_istream<char>& _is, basic_string<char>& _str);

	template<typename _CharT, typename _Traits, typename _Alloc>
	inline basic_ostream<_CharT, _Traits>& _os, const basic_string<_Chart, _Traits, _Alloc>& _str)
	{
		return _ostream_insert(_os, _str.data(), _str.size());
	}

*/


namespace xl_string {

	/* String operations:
		c_str
		data
		get_allocator
		copy
		find
		rfind
		find_first_of
		find_last_of
		find_first_not_of
		find_first_not_of
		substr
		compare
	*/
	class stringOperators {
	public:
		void test_c_str();
		void test_data();
		void test_get_allocator();
		void test_copy();
		void test_find();
		void test_substr();
		void test_compare();
	};

	/* Member constants
		npos: Maximum value for size_t
	*/

	/* Non-member functions overloads
	operator+
	relational operators
	swap
	operator>>
		istream& operator>> (istream* input, string& str);
	operator<<

	getline
	*/
	class nonMemberfunctions {
	public:
		void test_operatorConcatenate(); // operator+
		void test_operatorExtract(); // operator>>
		void test_operatorInsert(); //operator<<
		void test_relationalOpt();
		void test_swap();
		void test_getline();
	};



}