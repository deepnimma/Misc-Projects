#include <iostream>
using namespace std;

int main()
{
    int a[100][100], n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    int fdia = 0, sdia = 0;
    
    for(int i = 0; i < n; i++)
    {
        fdia += a[i][n-i-1];
        sdia += a[n-i-1][i];
    }
    cout << fdia << " " << sdia;
    cout << abs(fdia-sdia);
    return 0;
}