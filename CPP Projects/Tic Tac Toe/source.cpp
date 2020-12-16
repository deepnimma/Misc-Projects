#include <iostream>
using namespace std;

string a[9][9];

bool checkHorizontal();
bool checkVertical();
bool checkDiagonal();
void displayGrid(string, string, string, string, string, string, string, string, string);


int main()
{
    int count = 0;

    // while(!checkDiagonal() && !checkVertical() && !checkHorizontal())
    while(true)
    {
        system("CLS");
        string b = "1", c = "2", d = "3", e = "4", f = "5", g = "6", h = "7", i = "8", j = "9";
        int x;
        // displayGrid();
        displayGrid(b, c, d, e, f, g, h, i, j);

        if(count % 2 == 0)
        {
            cout << "Player 1 (X): Enter Grid Number (1-9)";
            cin >> x;

            switch(x)
            {
                case 1:
                    a[0][0] = "X";
                    b = "X";
                    break;
                case 2:
                    a[0][1] = "X";
                    c = "X";
                    break;
                case 3:
                    a[0][2] = "X";
                    d = "X";
                    break;
                case 4:
                    a[1][0] = "X";
                    e = "X";
                    break;
                case 5:
                    a[1][1] = "X";
                    f = "X";
                    break;
                case 6:
                    a[1][2] = "X";
                    g = "X";
                    break;
                case 7:
                    a[2][0] = "X";
                    h = "X";
                    break;
                case 8:
                    a[2][1] = "X";
                    i = "X";
                    break;
                case 9:
                    a[2][2] = "X";
                    j = "X";
                    break;
            }

        }
        else
        {
            cout << "Player 2 (O): Enter Grid Number (1-9)";
            switch(x)
            {
                case 1:
                    a[0][0] = "O";
                    b = "O";
                    break;
                case 2:
                    a[0][1] = "O";
                    c = "O";
                    break;
                case 3:
                    a[0][2] = "O";
                    d = "O";
                    break;
                case 4:
                    a[1][0] = "O";
                    e = "O";
                    break;
                case 5:
                    a[1][1] = "O";
                    f = "O";
                    break;
                case 6:
                    a[1][2] = "O";
                    g = "O";
                    break;
                case 7:
                    a[2][0] = "O";
                    h = "O";
                    break;
                case 8:
                    a[2][1] = "O";
                    i = "O";
                    break;
                case 9:
                    a[2][2] = "O";
                    j = "O";
                    break;
            
            }
        }

        count++;
    }
}

void displayGrid(string a, string b, string c, string d, string e, string f, string g, string h, string i)
{
    cout << "         |         |         " << endl;
    cout << "    " << a << "    |    " << b << "    |    " << c << endl;
    cout << "         |         |         " << endl;
    cout << "-----------------------------" << endl;
    cout << "         |         |         " << endl;
    cout << "    " << d << "    |    " << e << "    |    " << f << endl;
    cout << "         |         |         " << endl;
    cout << "-----------------------------" << endl;
    cout << "         |         |         " << endl;
    cout << "    " << g << "    |    " << h << "    |    " << i << endl;
    cout << "         |         |         " << endl;
}

bool checkHorizontal()
{
    if(a[0][0] == a[0][1] && a[0][1] == a[0][2] && a[0][2] == a[0][0])
    {
        return true;
    }
    
    if(a[1][0] == a[1][1] && a[1][1] == a[1][2] && a[1][2] == a[1][0])
    {
        return true;
    }

    if(a[2][0] == a[1][2] && a[1][2] == a[2][2] && a[2][2] == a[2][0])
    {
        return true;
    }

    return false;
}

bool checkDiagonal()
{
    if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == a[0][0])
    {
        return true;
    }

    if(a[2][0] == a[1][1] && a[1][1] == a[0][2] && a[0][2] == a[2][0])
    {
        return true;
    }

    return false;
}

bool checkVertical()
{
    if(a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[2][0] == a[0][0])
    {
        return true;
    }

    if(a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[2][1] == a[0][1])
    {
        return true;
    }

    if(a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[2][2] == a[0][2])
    {
        return true;
    }
    
    return false;
}