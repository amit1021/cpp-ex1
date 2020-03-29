
// AUTHORS: <Ohad Cohen , Eden Dahari, Amit Elbaz>


// AUTHORS: <Ohad Cohen , Eden Dahari, Amit Elbaz>

#include <iostream>
#include "PhoneticFinder.hpp"

using namespace std;

namespace phonetic
{//"dai lyke thys lead tu"
string find(string text, string word)
{
    string wordCheck = "";
    for (size_t i = 0; i < text.length; i++)
    {
        if (text[i] == ' ')
        {
            wordCheck = substring(text,i);
            if (wordCheck == word)
            {
               if(isSame(wordCheck, word) == 1) 
               {
                   //good 
                   return wordCheck;
               }
            }
        }
        
    }
    
    cout << "after fix" << endl;
    return "ABC";
}
}

string substring(string text, int i)
{
    string word_cut ="";
    for (size_t j = i+1; text[j] != ' '; j++)
    {
        word_cut += text[j];
    }
    return word_cut;
}

int isSame(string wordCheck, string word)
{
    for (size_t i = 0; i < wordCheck.length;)
    {
        if(wordCheck[i] == word[i])
        {
            i++;
        }
        else if (wordCheck[i] == 'v')
        {
            if (word[i] == 'w' || word[i] == 'W' )
            {
                i++;
            }
            
        }
        

    }
    
}

int main()
{
    for (size_t i = 0; i < 3; i++)
    {
        cout<< "amit"<<endl;
    }
    
    cout << substring("amit elbaz aaa" , 4) << endl;
}
