#include "string.h"
#include <cassert>

new_string::new_string()
{
    str = nullptr;
	length = 0;
}

new_string::new_string(char *str)
{
    length = strlen(str);
	assert(length >=0);
    this->str = new char[length+1];
    for (int i = 0; i < length; ++i)
    {
        this->str[i] = str[i];
    }
    this->str[length] = '\0';
}

new_string::new_string(const new_string& str1)
{
    if (this->str != nullptr)
    {
        delete[] str;
    }
	assert(this->str == nullptr);
    length = strlen(str1.str);
    this->str = new char[length +1];
    for (int i = 0; i < length; ++i)
    {
        this->str[i] = str1.str[i];
    }
    this->str[length] = '\0';
	assert(strlen(this->str) == strlen(str1.str));
}

new_string::~new_string()
{
    delete[] this->str;
}

int new_string::get_length()
{
    return length;
}

void new_string::append(char value)
{
	new_string new_str;
	length = strlen(this->str);
	new_str.str = new char[length + 2];
	for (int i = 0; i < length; ++i)
	{
    	new_str.str[i] = this->str[i];
	}
	new_str.str[length] = value;
	new_str.str[length + 1] = '\0';
	*this = new_str;
}

char new_string::operator+=(char value)
{
	append(value);
	return *this->str;
}

bool new_string::operator<(const new_string& str1)
{
	for (int i = 0; i < this->length; ++i)
	{
    	if (this->str[i] < str1.str[i]){
        	return true;
        }
    }
      	return false;
}


char& new_string::operator[](int index)
{
    return this->str[index];
}

const new_string& new_string::operator=(const new_string& str1)
{
	if (this == &str1){
        return *this;
    }
    if(this->str != nullptr){
        delete[] str;
		str = nullptr;
    }
	assert(str == nullptr);
    length = strlen(str1.str);
    this->str = new char[length+1];
    for (int i = 0; i < length; ++i)
    {
        this->str[i] = str1.str[i];
    }
    this->str[length] = '\0';
	assert(strlen(this->str) == strlen(str1.str));
    return *this;
}

new_string new_string::operator+(const new_string& str1)
{
    new_string new_str;
    int length1 = strlen(this->str);
    int length2 = strlen(str1.str);
    new_str.length = length1 + length2;
    new_str.str = new char[length1 + length2 + 1];
    int i = 0;
    for (i = 0; i < length1; ++i)
    {
        new_str.str[i] = this->str[i];
    }
    for (int j = 0; j < length2; ++j, ++i)
    {
        new_str.str[i] = str1.str[j];
    }
    new_str.str[length1 + length2] = '\0';
	assert(strlen(new_str.str) == strlen(this->str) + strlen(str1.str));
    return new_str;
}

void new_string::swap(new_string& str1)
{
    new_string tmp;
    tmp = *this;
    *this =  str1;
    str1 = tmp;
}

void new_string::Print()
{
    cout<< str<<'\n';
}

