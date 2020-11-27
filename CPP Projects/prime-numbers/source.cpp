#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
  fstream myfile;
  int a[1230], n;
  bool continueOP = true;
  string s;

  myfile.open("prime-numbers.txt");

  for(int i = 1; i <= 1229; i++)
  {
    myfile >> a[i];
  }


  while(continueOP == true)
  {
    cout << "Enter Number of Prime Numbers To Be Displayed: ";
    cin >> n;
    cout << endl;

    for(int i = 0; i <= n; i++)
    {
      cout << a[i] << " ";
    }

    cout << endl << "Continue? (Yes/No): ";
    cin >> s;
    cout << endl;

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    if(s == "no")
    {
      continueOP = false;
    }
  }

  myfile.close();
  return 0;
}
