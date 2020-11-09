// Written By Deepesh Nimma
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int n;
  cout << "Enter Number: ";
  cin >> n;
  cout << endl;

  if (n > 16)
  {
    cout << "Too Large!" << endl;
    return 0;
  }

  double pi = 2 * acos(0.0);
  printf("%.*f\n", n, pi);
}
