// Written By Deepesh Nimma
#include <iostream>
using namespace std;

int main()
{
  int n, m = 0;
  cout << "Enter Number: ";
  cin >> n;
  cout << endl;

  while(n != 1)
  {
    if (n % 2 == 0)
    {
      n /= 2;
    }
    else
    {
      n = 3 * n + 1;
    }

    cout << n << " ";
    m++;
  }

  cout << endl << "Count is: " << m;
}
