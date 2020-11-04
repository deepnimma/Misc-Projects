#include <iostream>
using namespace std;

int main()
{
  double cost, tax;
  cout << "Enter Cost: ";
  cin >> cost;

  cout << "Enter Tax Amount: ";
  cin >> tax;

  double result = (cost + (cost * (tax / 100)));

  cout << endl << "Tax Amount: $" << result - cost;
  cout << endl << "Cost With Tax: $" << result;
}
