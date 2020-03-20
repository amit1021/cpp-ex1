#include <iostream>
#include "PhoneticFinder.hpp"
#include <string>
#include "doctest.h"

using namespace std;
using namespace phonetic;

TEST_CASE("this test ....")
{
    string text ="";
    CHECK(find(text,"")==string(""));

}