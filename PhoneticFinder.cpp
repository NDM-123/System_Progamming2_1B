#include <iostream>
#include "PhoneticFinder.hpp"
#include <string>
#include <cstring>
#include <ctype.h>
#include<bits/stdc++.h> 
#include <stdexcept>
#include <exception>
using namespace std;

namespace phonetic {

	int same(char a, char b) {
		if ((a == 'v' && b == 'w') || (b == 'v' && a == 'w'))return 0;
		if ((a == 'g' && b == 'j') || (b == 'g' && a == 'j'))return 0;
		if ((a == 's' && b == 'z') || (b == 's' && a == 'z'))return 0;
		if ((a == 't' && b == 'd') || (b == 't' && a == 'd'))return 0;
		if ((a == 'o' && b == 'u') || (b == 'o' && a == 'u'))return 0;
		if ((a == 'y' && b == 'i') || (b == 'y' && a == 'i'))return 0;
		if ((a == 'b' && b == 'f') || (b == 'b' && a == 'f') || (a == 'b' && b == 'p') || (b == 'b' && a == 'p'))
			return 0;
		if ((a == 'f' && b == 'p') || (b == 'f' && a == 'p'))return 0;
		if ((a == 'c' && b == 'q') || (b == 'c' && a == 'q') || (a == 'q' && b == 'k') || (b == 'q' && a == 'k'))
			return 0;
		if ((a == 'c' && b == 'k') || (b == 'c' && a == 'k'))return 0;
		return 1;
	}

	string find(string a, string b) {

		int count = 0;

		string word;
		// making a string stream 
		stringstream iss(a);

		while (iss >> word) {
			if (word.length() != b.length()) continue;	//if the stream is per word
			
			int count = 0;//count the correct chars
			
			for (int i = 0; i < word.length(); i++) {//run on chars
				if (same((char)tolower(word[i]), (char)tolower(b[i])) == 0 || (char)tolower(word[i]) == (char)tolower(b[i]))
				{
					count++;
				}//else{throw std::runtime_error(std::string("Exception"));}
				if (word == "")	throw std::runtime_error(std::string("Exception - Word wasnt found"));
				//if the same length to the 2 words return the answer!!!
				if ((count == b.length() && count == word.length())) {// && b.length()==word.length())) {
					return word;
				}

			}
			count = 0;//reset counter for next word
		}
	//	if (word == "") {
				throw std::runtime_error(std::string("Exception - Word wasnt found"));
	//		}
		return word = "Exception";


	}
}
