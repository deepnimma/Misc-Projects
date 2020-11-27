// Written By Deepesh Nimma
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  string s;
  int n;
  cout << "Enter Word To Be Translated: ";
  cin >> s;
  cout << endl;

  n = s.size();
  transform(s.begin(), s.end(), s.begin(), ::tolower);

  // if(s[0] != 'a' && s[0] != 'e' && s[0] != 'o' && s[0] != 'u' && s[0] != 'i')
  // {
  //   char temp = s[0];
  //   s.erase(0, 1);
  //   s[n - 1] = '-';
  //   s[n] = temp;
  //   s[n + 1] = 'a';
  //   s[n + 2] = 'y';
  //   cout << s;
  // }
  // else
  // {
  //   cout << s;
  // }

  vector<char> vs;

  for(int i = 0; i < n; i++)
  {
    vs.push_back(s[i]);
  }

  if(vs[0] != 'a' && vs[0] != 'e' && vs[0] != 'o' && vs[0] != 'u' && vs[0] != 'i')
  {
    char temp = vs[0];
    vs.erase(vs.begin());
    // vs.push_back('-');
    vs.push_back(temp);
    vs.push_back('a');
    vs.push_back('y');
  }
  else
  {
    vs.push_back('y');
    vs.push_back('a');
    vs.push_back('y');
  }

  for(int i = 0; i < vs.size(); i++)
  {
    cout << vs.at(i);
  }
}
