#include <iostream>
#include "PhoneticFinder.hpp"
#include <string>
#include "doctest.h"

using namespace std;
using namespace phonetic;

int countCheck = 0;

TEST_CASE("Test replacement of y and i && of o and u" )
{
    string text ="dai lyke thys lead tu"; //day like this lead to
    CHECK(find(text,"dai")==string("day")); 
    CHECK(find(text,"lyke")==string("like"));
    CHECK(find(text,"thys")==string("this"));
    CHECK(find(text,"tu")==string("to"));
    countCheck+=4;
}
TEST_CASE("Test replacement of y and i && of f and p" )
{
    string text ="Feofole lyke uz"; //people like this
    CHECK(find(text,"Feofole")==string("people"));
    CHECK(find(text,"lyke")==string("like"));
    countCheck+=2;
}
TEST_CASE("Test replacement of d and t && of b and p")
{
    string text ="you lighd dhe sbark in my ponfire heard"; //you light the spark in my bonfire heart
    CHECK(find(text,"lighd")==string("light"));
    CHECK(find(text,"dhe")==string("the"));
    CHECK(find(text,"sbark")==string("spark"));
    CHECK(find(text,"ponfire")==string("bonfire"));
    CHECK(find(text,"heard")==string("heart"));
    countCheck+=5;
    cout << "the number of test: " << countCheck << endl;
}
