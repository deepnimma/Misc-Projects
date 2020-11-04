#include <iostream>
using namespace std;

long long findFactorial(long long n)
{
  long long result = 1;
  for(long long i = n; i > 0; i--)
  {
    result *= i;
  }

  return result;
}

int main()
{
  long long n;
  cout << "Enter Number: ";
  cin >> n;

  n = findFactorial(n);

  cout << "Factorial Is: " << n;
}
