#include <iostream>
using namespace std;

int main() {
  long long n;
  cout << "Enter a Number: ";
  cin >> n;
  cout << endl;

  for(long long i = 1; i <= n; i++) {
    if(i == n) {
      cout << i << '.';
      break;
    }
    if(n % i == 0) {
      cout << i << ',' << " ";
    }
  }

  return 0;
}
