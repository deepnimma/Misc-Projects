#include <iostream>
using namespace std;

#define ll long long

int main()
{
  ll a = 1, b = 2, c[1001], temp, i = 0, sum = 0;

  cout << a << " " << b << " ";

  // c[0] = a;
  // c[1] = b;
  // i = 2;

  while(i < 1000)// && c[i] < 4000000)
  {
    c[i] = a + b;
    a = b;
    b = c[i];
    // if(c[i] % 2 == 0)
    // {
    //   c[i] = 0;
    // }

    i++;
  }

  for(int i = 0; i < 1000; i++)
  {
    cout << c[i] << " ";
    // if(c[i] % 2 == 0)
    // {
    //   sum += c[i];
    // }
  }

  cout << sum;
}
