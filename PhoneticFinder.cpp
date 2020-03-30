#include <iostream>
#include "PhoneticFinder.hpp"
#include <string>
#include <cstring>
#include <ctype.h>
#include<bits/stdc++.h> 
using namespace std;

namespace phonetic {

	int same(char a, char b) {
		if ((a == 'v' && b == 'w') || (b == 'v' && a == 'w'))return 0;
		if ((a == 'g' && b == 'j') || (b == 'j' && a == 'g'))return 0;
		if ((a == 's' && b == 'z') || (b == 'z' && a == 's'))return 0;
		if ((a == 't' && b == 'd') || (b == 't' && a == 'd'))return 0;
		if ((a == 'o' && b == 'u') || (b == 'o' && a == 'u'))return 0;
		if ((a == 'y' && b == 'i') || (b == 'y' && a == 'i'))return 0;
		if ((a == 'b' && b == 'f') || (b == 'b' && a == 'f') || (a == 'b' && b == 'p') || (b == 'b' && a == 'p'))
			return 0;
		if ((a == 'f' && b == 'p') || (b == 'r' && a == 'p'))return 0;
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

		try {
			while (iss >> word) {
				int count = 0;//count the correct chars
				for (int i = 0; i < word.length(); i++) {//run on chars
					if (same((char)tolower(word[i]), (char)tolower(b[i])) == 0 || (char)tolower(word[i]) == (char)tolower(b[i]))
					{
						count++;
					}


				}
				count = 0;//reset counter for next word
			}
			//if the same length to the 2 words return the answer!!!
			if ((count == b.length() && count == word.length())) {
				return word;
			}
		}
		catch (int e) {
			cout << "Exception 10: Not the same word";
		}

		word = "Exception";

		return word;


	}
}
