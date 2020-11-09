// Written By Deepesh Nimma
#include <iostream>
using namespace std;

int main()
{
  long long n;
  cout << "Enter a Number: ";
  cin >> n;

  for(long long i = 1; i <= n; i++)
  {
    if(i % 3 == 0 && i % 5 == 0)
    {
      cout << "FizzBuzz" << endl;
    }
    else if(i % 3 == 0)
    {
      cout << "Fizz" << endl;
    }
    else if(i % 5 == 0)
    {
      cout << "Buzz" << endl;
    }
    else
    {
      cout << i << endl;
    }
  }

  cout << endl << "Program Complete";
  return 0;
}
