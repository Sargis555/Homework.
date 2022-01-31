#include "string.h"

int main()
{
	new_string str((char*)("Hello world"));
	new_string str1((char*)("world"));
	new_string str3;
	cout<<str.find_first_of(str1)<<endl;
	str1 += ('d');
	str.swap(str1);
	cout<<(str1 < str)<<endl;
	str3 = str + str1;
	str.append('s');
	str.Print();
	str1.Print();
	str3.Print();
	cout<<str.get_length()<<'\n';
	cout<<str1.get_length()<<'\n';
	cout<<str3.get_length()<<'\n';
	cout<<str[0]<<'\n';

	
	return 0;
}
