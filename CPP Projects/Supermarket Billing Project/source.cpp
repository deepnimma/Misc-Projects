#include <iostream>
#include <string>
using namespace std;

void give_item_names(string[], double[]);

int main()
{
    double prices[13], final_price, quantity, price = 0;
    int x;
    string item_names[13], items = "";
    bool quit = false;

    give_item_names(item_names, prices);

    while(quit == false)
    {
        system("CLS");
        cout << "########################################" << endl;
        cout << "   Welcome to Your Local Supermarket!" << endl;
        cout << "     Please Select The Item Below!" << endl;
        cout << "########################################" << endl;
    
        // prices = {12.60, 30.12, 25.32, 0.5, 120.23, 78.27, 100.21, 25.03, 46.23, 51.87, 1000.32, 500.23, 40000.65};
        

        cout << endl << "Item List: " << endl;
        cout << "Format: (index) {item name} [price per kg]" << endl;
        cout << "1. Apple [$12.60]" << endl;
        cout << "2. Banana [$30.12]" << endl;
        cout << "3. Tomato [$25.32]" << endl;
        cout << "4. Potato [$0.5]" << endl;
        cout << "5. Onion [$120.23]" << endl;
        cout << "6. Grapes [$78.27]" << endl;
        cout << "7. Strawberries [$100.21]" << endl << endl;

        cout << "8. Water Bottle [$25.03]" << endl;
        cout << "9. Orange Juice [$46.23]" << endl;
        cout << "10. Grape Juice [$51.87]" << endl << endl;
        
        cout << "11. Television [$1,000.32]" << endl;
        cout << "12. Games Console [$500.23]" << endl;
        cout << "13. Computer [$40,000.65]" << endl;

        // for(int i = 0; i < 13; i++)
        // {
        //     cout << prices[i] << " " << item_names[i] << endl;
        // }

        cout << endl << "Please Enter Index Number: ";
        cin >> x;
        x--;
        cout << endl;
        cout << "Please Enter Quantity: ";
        cin >> quantity;

        char f;

        // switch(f)
        // {
        //     case "Y":
        //         quit = true;
        //     case "N":
        //         quit = false;
        //     default:
        //         quit = false;
        // }

        // else
        //     quit = false;

        price = price + quantity * prices[x];
        items += " " + to_string(quantity) + " " + items[x];

        cout << "Current Price: " << price << endl;
        cout << "Items: " << items << endl;

        cout << "Quit? (Y/N): ";
        cin >> f;

        if(f == 'Y')
            quit = true;


    }

    cout << "Price: " << price << endl;
    cout << "Items: " << items << endl;

}

void give_item_names(string i[], double z[])
{
    i[0] = "Apple(s)";
    i[1] = "Banana(s)";
    i[2] = "KG of Tomato";
    i[3] = "KG of Potato";
    i[4] = "KG of Onion";
    i[5] = "KG of Grapes";
    i[6] = "KG of Strawberries";
    i[7] = "Water Bottle(s)";
    i[8] = "Orange Juice Box(es)";
    i[9] = "Grape Juice Box(es)";
    i[10] = "Television(s)";
    i[11] = "Games Console(s)";
    i[12] = "Computer(s)";


    z[0] = 12.60;
    z[1] = 30.12;
    z[2] = 25.32;
    z[3] = 0.5;
    z[4] = 120.23;
    z[5] = 78.27;
    z[6] = 100.21;
    z[7] = 25.03;
    z[8] = 46.23;
    z[9] = 51.87;
    z[10] = 1000.32;
    z[11] = 500.23;
    z[12] = 40000.65;
}
