// Written By Deepesh Nimma
#include <iostream>
using namespace std;

int main()
{
  double cost, money_given;
  int dollar_count = 0, quarters_count = 0, dimes_count = 0, nickels_count = 0, pennies_count = 0;


  cout << "Enter Cost of Item: ";
  cin >> cost;

  cout << "Enter Money Given: ";
  cin >> money_given;

  cost *= 100;
  money_given *= 100;
  cost -= money_given;

  while(cost >= 100)
  {
    cost -= 100;
    dollar_count++;
  }

  while(cost >= 25)
  {
    cost -= 25;
    quarters_count++;
  }

  while(cost >= 10)
  {
    cost -= 10;
    dimes_count++;
  }

  while(cost >= 5)
  {
    cost -= 5;
    nickels_count++;
  }

  pennies_count = cost;

  cout << "Change is " << dollar_count << " dollars " << quarters_count << " quarters ";
  cout << dimes_count << " dimes " << nickels_count << " nickels and " << pennies_count << " pennies.";
}
