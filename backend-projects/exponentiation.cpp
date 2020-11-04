#include <iostream>
using namespace std;

long long power(long long a, long long b)
{
  long long result = 1;

  if(b == 0)
  {
    return 1;
  }

  while(b != 0)
  {
    result *= a;
    b--;
  }

  return result;
}

int main()
{
  long long base, exponent, result;
  cout << "Enter Base: ";
  cin >> base;

  cout << "Enter Exponent: ";
  cin >> exponent;

  result = power(base, exponent);
  cout << base << " raised to " << exponent << " (" << base << " ^ " << exponent << ") = " << result;
  return 0;
}
