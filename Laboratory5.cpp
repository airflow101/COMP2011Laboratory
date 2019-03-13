/*
 * File: lab5_skeleton.cpp
 *
 * Lab 5: Recursion - Alien Word Parsing
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LEN = 256;

/* ADD THE RETURN TYPE HERE */ correct_word(/* ADD FORMAL PARAMETER LIST HERE */)
{

   /* ADD YOUR CODE HERE */
   /* THIS MUST BE A RECURSIVE FUNCTION */

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
