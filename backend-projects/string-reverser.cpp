// Written By Deepesh Nimma
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int n;

  cout << "Enter String: ";
  cin >> s;
  n = s.size();

  string d;

  for(int i = 0; i <= n - 1; i++)
  {
    d[n - i] = s[i];
  }

  for(int i = 0; i < n; i++)
  {
    cout << d[i];
  }
}
