// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "List.cpp"
#include "map.cpp"

using namespace std;
string decode(string code, List <char> &sort);
string encode(string &str, List <char> &sort);

void main()
{
	List <char> sort;
	string str = "the criterion of truth is experience";
	str=encode(str,sort);
	str=decode(str,sort);
	cout << "Simbols, code and frequency:" << endl;
	sort.print();
	getchar();
}


string encode(string &str, List <char> &sort)
{
	string code = "";
	if (str == "") {
		cout << "empty";
		return str;
	}
		
	map < char> Map;
	
	for (size_t i = 0; i != str.length();i++) //adding simbols and frequency to map
		Map.insert(str[i]);
	
	sort = Map.get_keys();
	sort.sorting(sort.get_front(), sort.get_back()); //sorting simbols by frequency
	sort.make_group(sort.get_front(),sort.get_back()); //create a code
	
	for (int j = 0; j < sort.get_size(); j++) //adding code to map
		Map.set_code(sort.get_code_list(j), sort.get_data_list(j));
	
	for (size_t i = 0; i != str.length();i++)
		code = code + Map.get_code(str[i]);
	
	cout <<"Encode string: "<< code << '\n';
	
	return code;
}

string decode(string code, List <char> &sort)
{
	string decode_str = "";
	cout << "Decode string: ";
	while (code.length() != 0)
	{
		for (int j = 0; j < sort.get_size(); j++)
		{
			
			int size = 0;
			if (sort.compare_str(code, sort.get_code_list(j), size)) 
			{
				cout << sort.get_data_list(j);
				decode_str += sort.get_data_list(j);
				code.erase(0, size);
			}
		}
	}
	cout << '\n';
	return decode_str;
}
