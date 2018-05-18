/*
	Name: PassBank 2.0
	Author: Érick Oliveira
	Date: 17/05/18
	Description: Password Manager/Keeper
*/

#include "cripto.h"

int main(void)
{
	SetConsoleTitle("PassBank 2.0");
	setlocale(LC_ALL, "Portuguese");
	SetColorGreen;
	menu();
}

void menu()
{
	int op;

	cout << "\t PassBank 2.0 by Cripto S.A\n\n";
	cout << " 1 - Login\n";
	cout << " 2 - Register user\n";
	cout << " 3 - Exit\n\n";
	cout << " Option: ";
	cin >> op;
	
	switch (op)
	{
		case 1:
			cls;
			Login();
		case 2:
			cls;
			cadastro();
		case 3:
			exit;
		default:
			cls;
			menu();
	}
}
