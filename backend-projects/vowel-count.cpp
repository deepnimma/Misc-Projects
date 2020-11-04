#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int acount = 0, ecount = 0, icount = 0, ocount = 0, ucount = 0, vowelcount = 0, consonantcount = 0, n;
  string s;

  cout << "Enter Word: ";
  cin >> s;

  transform(s.begin(), s.end(), s.begin(), ::tolower);

  n = s.size();

  for(int i = 0; i < n; i++)
  {
    if(s[i] == 'a')
    {
      acount++;
      vowelcount++;
    }
    else if(s[i] == 'e')
    {
      ecount++;
      vowelcount++;
    }
    else if(s[i] == 'i')
    {
      icount++;
      vowelcount++;
    }
    else if(s[i] == 'o')
    {
      ocount++;
      vowelcount++;
    }
    else if(s[i] == 'u')
    {
      ucount++;
      vowelcount++;
    }
    else
    {
      consonantcount++;
    }
  }

  cout << acount << " 'a's " << endl;
  cout << ecount << " 'e's " << endl;
  cout << ocount << " 'o's " << endl;
  cout << icount << " 'i's " << endl;
  cout << ucount << " 'u's " << endl;

  cout << endl << vowelcount << " vowels";
  cout << endl << consonantcount << " consonants";
  cout << endl << "Total Length of Word: " << vowelcount + consonantcount;
}
