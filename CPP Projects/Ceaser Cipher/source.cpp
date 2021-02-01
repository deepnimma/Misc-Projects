#include <iostream>
#include <string>
using namespace std;

string encryptor(string, int);
string decryptor(string, int);

int main()
{
	int f, n;
	string s;

	system("cls");

	cout << "Enter Function Index:" << endl;
	cout << "1. Encryption" << endl;
	cout << "2. Decryption" << endl;
	cin >> f;

	switch(f)
	{
		case 1:
			system("cls");
			cout << "Enter String: ";
			cin >> s;
			cout << "Enter Shift: ";
			cin >> n;
			string encrypted_string = encryptor(s, n);

			system("cls");

			cout << "Encrypted String: " << encrypted_string << endl;
			break;

		case 2:
			system("cls");
			cout << "Enter String: ";
			cin >> s;
			cout << "Enter Shift: ";
			cin >> n;

			string decrypted_string = decryptor(s, n);

			system("cls");

			cout << "Decrypted String: " << decrypted_string << endl;
			break;
			
		default:
			cout << "Invalid Flag" << endl;
			break;
	}
	return 0;
}

string encryptor(string s, int n)
{
	char m[10001];
	for(int i = 0; i < s.size(); i++)
	{
		m[i] = (int)s[i] + n;
	}

	string ret = m;

	return ret;
}

string decryptor(string s, int n)
{
	char m[100001];
	for(int i = 0; i < s.size(); i++)
	{
		m[i] = (int)s[i] - n;
	}

	string ret = m;

	return ret;
}
