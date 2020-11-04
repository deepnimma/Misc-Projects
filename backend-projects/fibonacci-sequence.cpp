#include <iostream>
using namespace std;
// Testing
int main()
{
  long long n, a[1000], i = 1, last_number, z = 1, temp;
  cout << "Enter a Number: ";
  cin >> n;
  cout << endl;

  a[0] = 0;
  last_number = 0;

  while(i <= n)
  {
    temp = i;
    cout << last_number + i << " ";
    temp += last_number;
    last_number = i;
    i = temp;
  }

  for(int i = 0; i < z; i++) {
    cout << a[z] << " ";
  }
}
