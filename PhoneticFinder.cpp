
// AUTHORS: <Ohad Cohen , Eden Dahari, Amit Elbaz>

#include <iostream>
#include <ctype.h>
#include "PhoneticFinder.hpp"

using namespace std;
namespace phonetic
{//"dai lyke thys lead tu"
string find(string text, string word)
{
    string wordCheck = "";
    int j = 0;
    int save = 0;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (i == text.length() - 1 || text[i] == ' ')
        {
            if(i == text.length() - 1 && text[i] != ' ')
            {
                j++;
            }
            wordCheck = text.substr(save,j);
            if (wordCheck.length() == word.length())
            {
               if(isSame((wordCheck), word) == 1) 
               {
                   return wordCheck;
               }
            }
            save = i + 1;
            j = 0;
        }
        else
        {
            j++;
        }

    }
    return NULL;
}
}
int isSame(string wordCheck, string word)
{
    char letter[][3] = {{'a'},{'b','f','p'},{'c','k','q'},{'d','t'},{'e'},{'f','b','p'},{'g','j'}, {'h'}, {'i','y'}, {'j','g'}, {'k', 'c', 'q'}, {'l'}, {'m'}, {'n'}
    , {'o','u'}, {'p','b','f'}, {'q','c','k'}, {'r'},{'s','z'}, {'t','d'}, {'u','o'}, {'v','w'}, {'w','v'},{'x'},{'y','i'}, {'z','s'}};
    int match = 0;
    for (size_t i = 0; i < wordCheck.length(); i++)
    {
        wordCheck[i] = tolower(wordCheck[i]);
        word[i] = tolower(word[i]);
     if(wordCheck[i] != word[i])
     {
        int j = wordCheck[i] - 'a';
         for (size_t x = 0; x < 3; x++)
         {
             if(letter[j][x] == word[i])
             {
                 match++;
             }
         }
         
     }
     else
     {
        match++;
     }   
    }
    if(match == word.length())
    {
        return 1;
    }
    return 0;
}