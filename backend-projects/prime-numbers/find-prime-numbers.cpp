#include <iostream>
#include <fstream>
using namespace std;

void FindPrimeNumbers()
{
  fstream myfile;
  int n;

  myfile.open("prime-numbers.txt");

  for(n = 2; n < 10000; n++)
  {
    bool checkPrime = false;
    for(int i = 2; i < n; i++)
    {
      if (n % i == 0)
        checkPrime = true;
    }

    if(checkPrime == false)
    {
      myfile << n << endl;
    }

  }

  myfile.close();
}

int main()
{
  FindPrimeNumbers();
}
