/*
 * File: lab5_skeleton.cpp
 *
 * Lab 5: Recursion - Alien Word Parsing
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LEN = 256;

bool correct_word( char word[], int start, int length )
{
  if(word[length] >= 'a' && word[length] <= 'z'){
    if(start == length){
      return true;
    }
    else{
      return false;
    }
  }
  else if(word[length] == '@' || word[length] == '#'){
    if(start == length){
      return false;
    }
    else{
      return correct_word(word, start, length - 1);
    }
  }
  else if(word[length] == '|'){
    /*for(int i = 0; i < length; i++){
      if(word[i] == '|'){
        for(int j = 0; j < i; j++){
          if(word[i] >= 'a' && word[i] <= 'z'){
            return correct_word(word, j, i - 1) && correct_word(word, i, length);
          }
        }
      }
      if(word[i] >= 'a' && word[i] <= 'z'){
        return correct_word(word, start, i - 1) && correct_word(word, i, length-1);
      }
    }*/
    bool counter = false;
    for(int i = 0; i < length; i++){
      counter = counter || (correct_word(word, start, i) && correct_word(word, i + 1, length-1));
      /*for(int j = start; j < i; j++){
        cout<< word[j];
      }
      cout<<endl;*/
    }
    return counter;
  }
  else{
    return false;
  }
    return 0;
  }


int main()
{
   char word[MAX_LEN];
   char c;

   do{
      cout << "Enter a word: ";
      cin >> word;
      if (correct_word(word, 0, strlen(word) - 1))
         cout << "The word is CORRECT!\n";
      else
         cout << "The word is INCORRECT!\n";
      cout << "Do you want to enter a new word ('Y'/'y' for Yes, 'N'/'n' for No)? ";
      cin >> c;
   } while (c == 'Y' || c=='y');

   return 0;
}
