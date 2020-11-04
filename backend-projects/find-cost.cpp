#include <iostream>
using namespace std;

int main()
{
  int w, l, c;
  cout << "Enter Length: ";
  cin >> l;

  cout << "Enter Width: ";
  cin >> w;

  cout << "Enter Cost: ";
  cin >> c;

  cout << "Total Cost is: $" << l * w * c;
}
