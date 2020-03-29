#include <iostream>
#include "PhoneticFinder.hpp"
#include <string>
#include <cstring>
#include <ctype.h>

using namespace std;

namespace phonetic {

    int same(char a, char b) {
        if ((a == 'v' && b == 'w') || (b == 'v' && a == 'w'))return 0;
        if ((a == 'g' && b == 'j') || (b == 'j' && a == 'g'))return 0;
        if ((a == 's' && b == 'z') || (b == 'z' && a == 's'))return 0;
        if ((a == 't' && b == 'd') || (b == 'd' && a == 't'))return 0;
        if ((a == 'o' && b == 'u') || (b == 'u' && a == 'o'))return 0;
        if ((a == 'y' && b == 'i') || (b == 'i' && a == 'y'))return 0;
        if ((a == 'b' && b == 'f') || (b == 'f' && a == 'b') || (a == 'b' && b == 'p') || (b == 'p' && a == 'b'))
            return 0;
        if ((a == 'f' && b == 'p') || (b == 'p' && a == 'f'))return 0;
        if ((a == 'c' && b == 'q') || (b == 'q' && a == 'c') || (a == 'q' && b == 'k') || (b == 'k' && a == 'q'))
            return 0;
        if ((a == 'c' && b == 'k') || (b == 'k' && a == 'c'))return 0;
        return 1;
    }


    string find(string a, string b) {
//  if std::strlen(a)!=std::strlen(b)return null;   irrelevant because obviously lengths are diffrent
        try {
            int count = 0;
            for (int i = 0; i < std::strlen(a.c_str()); i++) {
                if (same(tolower(a[i]), tolower(b[i])) == 0)count++;
                if ( (count == std::strlen(b.c_str()) && (i + 1) >= std::strlen(a.c_str())) || (count == std::strlen(b.c_str()) && a[i + 1] == ' ')) {
                    return b;
                } else { throw 10; }
                if (same(tolower(a[i]), tolower(b[i])) != 0)count = 0;
            }
        } catch (int e) {
            cout << "Exception 10: Not the same word\t";
        }
        return b;
    }
}


