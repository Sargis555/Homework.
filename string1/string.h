#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>



using namespace std;

class new_string
{

private:
	char *str;
	int length;	

public:
	new_string();
	new_string(char *str);
	new_string(const new_string& str1);
	~new_string();

public:
	int get_length();
	void append(char value);
	char operator+=(char value);
	bool operator<(const new_string& str1);
	char& operator[](int index);
	const new_string& operator=(const new_string& str1);
	new_string operator+(const new_string& str1);
	void swap(new_string& str1);
	void Print();
};

#endif
