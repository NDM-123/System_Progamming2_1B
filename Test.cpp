
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test longer word") {           //fails
string text = "compute xxx yyy";
    CHECK(find(text, "commmmmm") == string("Happi"));
    CHECK(find(text, "com") == string("Happi"));
    CHECK(find(text, "computt") == string("Happi"));
    CHECK(find(text, "cccccccc") == string("Happi"));
}
TEST_CASE("Test longer word with upper case add on") {		//fails
    string text = "Happy xxx yyy";
    CHECK(find(text, "hAPPIy") == string("Happi"));
    CHECK(find(text, "haPpiy") == string("Happi"));
    CHECK(find(text, "Happyi") == string("Happi"));
    CHECK(find(text, "happiE") == string("Happi"));
}
TEST_CASE("Test not equals") {					//fails
 string text = "very xxx yyy";
    CHECK(find(text, "cery") == string("very"));
    CHECK(find(text, "veryy") == string("very"));
    CHECK(find(text, "veery") == string("very"));
    CHECK(find(text, "ver") == string("very"));	//12		
    
 text = "Happy xxx yyy";
    CHECK(find(text, "eappi") == string("Happi"));
    CHECK(find(text, "heppi") == string("Happi"));
    CHECK(find(text, "hadpi") == string("Happi"));
    CHECK(find(text, "happe") == string("Happi"));
}
TEST_CASE("Test replacement of lower-case and upper-case") {		//works
  string text = "share xxx yyy";
    CHECK(find(text, "Share") == string("share"));
    CHECK(find(text, "shAre") == string("share"));
    CHECK(find(text, "shaRe") == string("share"));
    CHECK(find(text, "SHARE") == string("share"));	//20

    text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HaPBI") == string("Happi"));
    CHECK(find(text, "HaBPI") == string("Happi"));
    CHECK(find(text, "HABBPI") == string("Happi"));
    CHECK(find(text, "haBBi") == string("Happi"));
    CHECK(find(text, "haBBI") == string("Happi"));	
}	

TEST_CASE("Test replacement of v and w") {			//works
    string text = "xxx vow yyy";
    CHECK(find(text, "wov") == string("vow"));
    CHECK(find(text, "wow") == string("vow"));
    CHECK(find(text, "vov") == string("vow"));
    CHECK(find(text, "VOW") == string("vow"));	//33

}
TEST_CASE("Test replacement of g and j") {			//works	
    string text = "xxx joy yyy";
    CHECK(find(text, "gOY") == string("joy"));
    CHECK(find(text, "goy") == string("joy"));
    CHECK(find(text, "Goy") == string("joy"));
    CHECK(find(text, "joy") == string("joy"));

}
TEST_CASE("Test replacement of s and z") {			//works
    string text = "xxx size yyy";
    CHECK(find(text, "zize") == string("size"));
    CHECK(find(text, "sise") == string("size"));
    CHECK(find(text, "zise") == string("size"));
    CHECK(find(text, "ZISE") == string("size"));	//41

}
TEST_CASE("Test replacement of u and o") {			//works	
    string text = "xxx out yyy";
    CHECK(find(text, "uut") == string("out"));
    CHECK(find(text, "oot") == string("out"));
    CHECK(find(text, "Uut") == string("out"));
    CHECK(find(text, "OOt") == string("out"));

}
TEST_CASE("Test replacement of k and c and q") {		//works	
    string text = "xxx quick yyy";
    CHECK(find(text, "kuick") == string("quick"));
    CHECK(find(text, "Cuick") == string("quick"));
    CHECK(find(text, "kuiqk") == string("quick"));
    CHECK(find(text, "kuiKk") == string("quick"));
    CHECK(find(text, "quiqq") == string("quick"));
    CHECK(find(text, "quicc") == string("quick"));	//52
}
TEST_CASE("Test replacement of p and b and f") {		//works
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hafpy") == string("happy"));
}
TEST_CASE("Test replacement of p and b and f and y with i") {	//works
	string text = "xxx happy yyy";
//mine - replacment of more than two chars y and i
    CHECK(find(text, "habbi") == string("happy"));
    CHECK(find(text, "haBpi") == string("happy"));
    CHECK(find(text, "hapbi") == string("happy"));
    CHECK(find(text, "habFi") == string("happy"));	//62
}

TEST_CASE("Test not equals with upper and lower cases") {	//fails
    string text = "Happy xxx yyy";
    CHECK(find(text, "EAPPI") == string("Happi"));
    CHECK(find(text, "hePpi") == string("Happi"));
    CHECK(find(text, "Hadpi") == string("Happi"));
    CHECK(find(text, "happE") == string("Happi"));
}
TEST_CASE("Test replacement of d and t") {	//works
    string text = "xxx dont yyy";
    CHECK(find(text, "tont") == string("dont"));
    CHECK(find(text, "tond") == string("dont"));
    CHECK(find(text, "dond") == string("dont"));
    CHECK(find(text, "dont") == string("dont"));	//70
//mine - replacment of more than two chars d and t and o and u
    CHECK(find(text, "tunt") == string("dont"));
    CHECK(find(text, "dunt") == string("dont"));
    CHECK(find(text, "tund") == string("dont"));
    CHECK(find(text, "dund") == string("dont"));
}
TEST_CASE("Test replacement of lower-case and upper-case in dont") {		//works	
    string text = "xxx dont yyy";
    CHECK(find(text, "Tont") == string("dont"));
    CHECK(find(text, "TOnd") == string("dont"));
    CHECK(find(text, "DONd") == string("dont"));
    CHECK(find(text, "DONT") == string("dont"));
//mine - replacment of more than two chars d and t and o and u with upper case
    CHECK(find(text, "tunT") == string("dont"));
    CHECK(find(text, "duNt") == string("dont"));
    CHECK(find(text, "tUnd") == string("dont"));
    CHECK(find(text, "Dund") == string("dont"));	//82
}
TEST_CASE("Test shorter word") {           //fails
string text = "compute xxx yyy";
    CHECK(find(text, "comput") == string("compute"));
    CHECK(find(text, "compu") == string("compute"));
    CHECK(find(text, "comp") == string("compute"));
    CHECK(find(text, "com") == string("compute"));
    CHECK(find(text, "co") == string("compute"));
    CHECK(find(text, "c") == string("compute"));
    CHECK(find(text, "") == string("compute"));
}
TEST_CASE("Test shorter word with upper case") {	//fails
    string text = "Happy xxx yyy";
    CHECK(find(text, "HAPP") == string("Happi"));
    CHECK(find(text, "HAP") == string("Happi"));
    CHECK(find(text, "HA") == string("Happi"));
    CHECK(find(text, "H") == string("Happi"));		//93	
}

TEST_CASE("Test multiply switches") {			//works
    string text = "xxx yyy acknowledge";
    CHECK(find(text, "akknowledge") == string("acknowledge"));
    CHECK(find(text, "aqqnowledge") == string("acknowledge"));
    CHECK(find(text, "aqqnuwledge") == string("acknowledge"));
    CHECK(find(text, "aqqnuwletge") == string("acknowledge"));
    CHECK(find(text, "aqqnuwletje") == string("acknowledge"));
//test upper case with multiply switches
    CHECK(find(text, "aQcnuwletje") == string("acknowledge"));
    CHECK(find(text, "aQqnuwletJe") == string("acknowledge"));
    CHECK(find(text, "aQqnuwLetJe") == string("acknowledge"));	//101
    CHECK(find(text, "aQqNuwletJe") == string("acknowledge"));
    CHECK(find(text, "aQqNUwletJe") == string("acknowledge"));
    CHECK(find(text, "aQqNUWletJe") == string("acknowledge"));
    CHECK(find(text, "aQQNUWletJe") == string("acknowledge"));
    CHECK(find(text, "aQQNUWLedJe") == string("acknowledge"));
    CHECK(find(text, "AQQNUMLetJe") == string("acknowledge"));
    CHECK(find(text, "aQQNUMLeTJe") == string("acknowledge"));
    CHECK(find(text, "aQQNUMLeTJe") == string("acknowledge"));	//109
     
}
