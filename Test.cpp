
// AUTHORS: <Ohad Cohen , Eden Dahari, Amit Elbaz>

#include <iostream>
#include "PhoneticFinder.hpp"
#include <string>
#include "doctest.h"

using namespace std;
using namespace phonetic;

TEST_CASE("Test replacement of y and i && of o and u" )
{
    string text = "dai lyke thys lead tu"; //day like this lead to
    CHECK(find(text,"day") == string("dai")); 
    CHECK(find(text,"like") == string("lyke"));
    CHECK(find(text,"this") == string("thys"));
    CHECK(find(text,"to") == string("tu"));

}

TEST_CASE("Test replacement of y and i && f and p" )
{
    string text = "Feofle lyke uz"; //people like us
    CHECK(find(text,"people") == string("Feofle"));
    CHECK(find(text,"like") == string("lyke"));
    CHECK(find(text,"us") == string("uz"));
}

TEST_CASE("Test replacement of d and t && b and p")
{
    string text = "you lighd dhe sbark in my ponfire heard"; //you light the spark in my bonfire heart
    CHECK(find(text,"light") == string("lighd"));
    CHECK(find(text,"the") == string("dhe"));
    CHECK(find(text,"spark") == string("sbark"));
    CHECK(find(text,"bonfire") == string("ponfire"));
    CHECK(find(text,"heart") == string("heard"));
   
}

TEST_CASE("Test replacement of f and p and b && d and t && s and z" )
{
    string text = "Uffrond zdyle reaty do addack now"; // upfront style, ready to attack now
    CHECK(find(text,"upfront") == string("Uffrond")); 
    CHECK(find(text,"style") == string("zdyle"));
    CHECK(find(text,"ready") == string("reaty"));
    CHECK(find(text,"to") == string("do"));
    CHECK(find(text,"attack") == string("addack"));
    CHECK(find(text,"now") == string("now"));
}

TEST_CASE("Test replacement of o and u && of c and q && of y and i" )
{                  
    string text = "And thyngs that have not uqqorred iet"; //And things that have not occurred yet
    CHECK(find(text,"And") == string("And"));
    CHECK(find(text,"things") == string("thyngs"));
    CHECK(find(text,"that") == string("that"));
    CHECK(find(text,"have") == string("have"));
    CHECK(find(text,"not") == string("not"));
    CHECK(find(text,"occurred") == string("uqqorred"));
    CHECK(find(text,"yet") == string("iet"));

}

TEST_CASE("Test replacement lower case to uper case")
{
    string text = "Let ME dO tHOsE ThInGS foR YoU"; //Let me do those things for you
    CHECK(find(text,"Let") == string("Let"));
    CHECK(find(text,"Led") == string("Let"));
    CHECK(find(text,"me") == string("ME"));
    CHECK(find(text,"do") == string("dO"));
    CHECK(find(text,"those") == string("tHOsE"));
    CHECK(find(text,"things") == string("ThInGS"));
    CHECK(find(text,"for") == string("foR"));
    CHECK(find(text,"YoU") == string("YoU"));
}

TEST_CASE("Test replacement of t and d && of g and j" )
{                  
    string text = "jodda prodecd"; //And things that have not occurred yet
    CHECK(find(text,"Gotta") == string("jodda"));
    CHECK(find(text,"protect") == string("prodecd"));
  
}

TEST_CASE("Test replacement of p and b && of o and u" )
{                  
    string text = "blace yuur head un my beating heart"; //Place your head on my beating heart
    CHECK(find(text,"Place") == string("blace"));
    CHECK(find(text,"your") == string("yuur"));
    CHECK(find(text,"head") == string("head"));
    CHECK(find(text,"on") == string("un"));
    CHECK(find(text,"my") == string("my"));
    CHECK(find(text,"beating") == string("beating"));
    CHECK(find(text,"heart") == string("heart"));
    
}

TEST_CASE("Test replacement all possible mistakes")
{
    string text = "MAipE ve duuq dHyz du pAR "; //maybe we took this to far
    CHECK(find(text,"maybe") == string("MAipE"));
    CHECK(find(text,"we") == string("ve"));
    CHECK(find(text,"took") == string("duuq"));
    CHECK(find(text,"this") == string("dHyz"));
    CHECK(find(text,"to") == string("du"));
    CHECK(find(text,"far") == string("pAR"));
    
}

TEST_CASE("Test replacement of t and d")
{
    string text = "Dime will deach you all you neet do learn "; //Time will teach you all you need to learn
    CHECK(find(text,"Time") == string("Dime"));
    CHECK(find(text,"will") == string("will"));
    CHECK(find(text,"teach") == string("deach"));
    CHECK(find(text,"you") == string("you"));
    CHECK(find(text,"all") == string("all"));
    CHECK(find(text,"you") == string("you"));
    CHECK(find(text,"need") == string("neet"));
    CHECK(find(text,"to") == string("do"));
    CHECK(find(text,"learn") == string("learn"));

    //check that some exception is thrown
    CHECK_THROWS(find(text,"Tim"));//the word is too short
    //check that a specific exception type is thrown
    CHECK_THROWS_AS(find(text,"leern"), exception); //the word not exist

}

TEST_CASE("Test replacement of o and u && v and w")
{
    string text = "Nuv I knuv that luwe ain’t meant tu be a play thing"; //Now I know that love ain’t meant to be a play thing
    CHECK(find(text,"Now") == string("Nuv"));
    CHECK(find(text,"I") == string("I"));
    CHECK(find(text,"know") == string("knuv"));
    CHECK(find(text,"that") == string("that"));
    CHECK(find(text,"love") == string("luwe"));
    CHECK(find(text,"ain’t") == string("ain’t"));
    CHECK(find(text,"meant") == string("meant"));
    CHECK(find(text,"to") == string("tu"));
    CHECK(find(text,"be") == string("be"));
    CHECK(find(text,"a") == string("a"));
    CHECK(find(text,"play") == string("play"));
    CHECK(find(text,"thing") == string("thing"));

    //check that some exception is thrown
    CHECK_THROWS(find(text,"No"));//the word is too short
    //check that a specific exception type is thrown
    CHECK_THROWS_AS(find(text,"been"), exception); //the word not exist

}

TEST_CASE("Test replacement all possible ")
{
    string text = "I tund fELYEwE dhad ANifuti pEEl dHe Vai I tu"; //i dont believe that anybody feels the way i do
    CHECK(find(text,"i") == string("I"));
    CHECK(find(text,"dont") == string("tund"));
    CHECK(find(text,"believe") == string("fELYEwE"));
    CHECK(find(text,"that") == string("dhad"));
    CHECK(find(text,"anybody") == string("ANifuti"));
    CHECK(find(text,"feel") == string("pEEl"));
    CHECK(find(text,"the") == string("dHe"));
    CHECK(find(text,"way") == string("Vai"));
    CHECK(find(text,"i") == string("I"));
    CHECK(find(text,"do") == string("tu"));

    //check that some exception is thrown
    CHECK_THROWS(find(text,""));//the word is too short (empty word)
    //check that a specific exception type is thrown
    CHECK_THROWS_AS(find(text,"believed"), exception); //the word not exist

}

TEST_CASE("Test replacement i any y ")
{
    string text = "Now y know yt’s not an ordynari everidai thyng"; // Now I know it’s not an ordinary everyday thing
    CHECK(find(text,"Now") == string("Now"));
    CHECK(find(text,"I") == string("y"));
    CHECK(find(text,"know") == string("know"));
    CHECK(find(text,"it’s") == string("yt’s"));
    CHECK(find(text,"not") == string("not"));
    CHECK(find(text,"an") == string("an"));
    CHECK(find(text,"ordinary") == string("ordynari"));
    CHECK(find(text,"everyday") == string("everidai"));
    CHECK(find(text,"thing") == string("thyng"));

    //check that some exception is thrown
    CHECK_THROWS(find(text,"thin"));//the word is too short
    //check that a specific exception type is thrown
    CHECK_THROWS_AS(find(text,"any"), exception); //the word not exist

}

TEST_CASE("Test replacement all possible mistakes")
{
    string text = "LAdeli i HaWe peeN Hart du REAkh"; //lately i have been hard to reach
    CHECK(find(text,"lately") == string("LAdeli"));
    CHECK(find(text,"have") == string("HaWe"));
    CHECK(find(text,"been") == string("peeN"));
    CHECK(find(text,"hard") == string("Hart"));
    CHECK(find(text,"to") == string("du"));
    CHECK(find(text,"reach") == string("REAkh"));

    //check that some exception is thrown
    CHECK_THROWS(find(text,"hav"));//the word is too short
    //check that a specific exception type is thrown
    CHECK_THROWS_AS(find(text,"anything"), exception); //the word not exist

}
