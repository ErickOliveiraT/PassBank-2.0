/*
	Name: PassBank 2.0
	Author: Érick Oliveira
	Date: 17/05/18
	Description: Password Manager/Keeper
*/

#include "cripto.h"
#include "base64.h"

void erro()
{
	printf("\n\nError with archive manipulation\n\n");
	pause;
	exit;
}

bool verifyLogin(char *ent)
{
	char login[MAX_TAM_LOGIN];
	int i;
	
	FILE *arq;
	arq = fopen("Users_LoginDatabase.dat", "r");
	if (!arq) return false;
	
	while (fscanf(arq, " %s", &login) != EOF)
	{
		if (strcmp(login,ent) == 0)
		{
			fclose(arq);
			return true;
		}
	}
	
	fclose(arq);
	return false;
}

void cadastro()
{
	int i, tam_l, tam_s;
	string pass, pass2;
	char *login;
	
	login = (char *) malloc(sizeof(char) * MAX_TAM_LOGIN);
	fflush(stdin);
	cout << "\t Register user\n\n";
	cout << "Login: ";
	scanf(" %[^\n]s", login);
	
	if (verifyLogin(login) == true)
	{
		cout << "\n\nThis user already exits. Try another one.\n\n\n";
		pause;
		cls;
		cadastro();
	}
	
	fflush(stdin);
	cout << "Password: ";
	getline(cin, pass);
	cout << "Password again: ";
	getline(cin, pass2);
	
	if (pass != pass2)
	{
		cout << "\n\nPasswords don't match. Try again.\n\n";
		pause;
		cls;
		cadastro();
	}
	
	if (pass.length() > 256)
	{
		cout << "\n\nThe password can not be greater than 256. Try again.\n\n";
		pause;
		cls;
		cadastro();
	}
	
	saveLogin(login);
	savePass(pass);
	free(login);
	
	cout << "\n\nUser successfully registered\n\n\n";
	pause;
	cls;
	menu();	
}

void saveLogin(char *login)
{
	int i;
	FILE *arq;
	
	arq = fopen("Users_LoginDatabase.dat", "a");
	if (!arq) erro();
	
	for (i = 0; i < strlen(login); i++) fprintf(arq, "%c", login[i]);
	fprintf(arq, "\n");
	fclose(arq);	
}

void savePass(string pass)
{
	int i;
	FILE *arq;
	
	string encoded = base64_encode(reinterpret_cast<const unsigned char*>(pass.c_str()), pass.length());
	
	arq = fopen("Users_PassDatabase.dat", "a");	
	if (!arq) erro();
	
	fflush(stdin);
	for (i = 0; i < encoded.length(); i++) fprintf(arq, "%c", encoded[i]);
	fprintf(arq, "\n");
	
	fclose(arq);
}

void Login()
{
	char *login, *pass;
	int i, id;
	
	login = (char *) malloc(sizeof(char) * MAX_TAM_LOGIN);
	pass = (char *) malloc(sizeof(char) * MAX_TAM_PASS);
	cout << "\t Login\n\n";
	
	cout << "Login: ";
	scanf(" %[^\n]s", login);
	
	id = search_id(login);
	
	if (verifyLogin(login) == false || id == 0)
	{
		cout << "\n\nThis user does not exist.\n\n\n";
		pause;
		cls;
		Login();
	}
	
	cout << "Password: ";
	scanf(" %[^\n]s", pass);
	
	if (verifyPass(pass,id) == false)
	{
		cout << "\n\nIncorret Password\n\n\n";
		pause;
		cls;
		Login();
	}
	
	cls;
	UserPage(id);	
}

int search_id(char *login)
{
	char aux[MAX_TAM_LOGIN];
	int i, cont = 0;
	
	FILE *arq;
	arq = fopen("Users_LoginDatabase.dat", "r");
	if (!arq) return 0;
	
	while (fscanf(arq, " %s", &aux) != EOF)
	{
		cont++;
		if (strcmp(login,aux) == 0)
		{
			fclose(arq);
			return cont;
		}
	}
	
	fclose(arq);
	return 0;
}

bool verifyPass(char *ent, int id)
{
	char aux[MAX_TAM_PASS];
	int i, cont = 0;
	bool flag;
	string pass;
	
	for (i = 0; i < strlen(ent); i++) pass += ent[i];
	
	string encoded = base64_encode(reinterpret_cast<const unsigned char*>(pass.c_str()), pass.length());
	
	FILE *arq;
	arq = fopen("Users_PassDatabase.dat", "r");
	if (!arq) return false;
	
	while (fscanf(arq, " %s", &aux) != EOF)
	{
		cont++;
		if (cont == id) break;
	}
	
	pass.clear();
	for (i = 0; i < strlen(aux); i++) pass += aux[i];
	
    if (encoded == pass) flag = true;
    else flag = false;
	
	fclose(arq);
	return flag;
}

void UserPage(int id)
{
	int op;
	
	cout << "\t Welcome ";
	printName(id);
	
	cout << " 1 - Save a password\n";
	cout << " 2 - See my passwords\n";
	cout << " 3 - Get a password\n";
	cout << " 4 - Return to menu\n\n";
	cout << " Option: ";
	cin >> op;
	
	switch (op)
	{
		case 1:
			cls;
			NewPass(id);
		case 2:
			cls;
			SeePass(id);
		case 3:
			cls;
			GetPass(id);
		case 4:
			cls;
			menu();
		default:
			cls;
			UserPage(id);
	}
}

void NewPass(int id)
{
	int i;
	char *desc;
	string pass;
	
	FILE *arq;
	arq = fopen("Pass_Description.dat", "a");
	if (!arq) erro;
	
	desc = (char *) malloc(sizeof(char) * 100);
	
	cout << "\t Save a password\n\n";
	cout << "Password description: ";
	scanf(" %[^\n]s", desc);
	cout << "Password: ";
	fflush(stdin);
	getline(cin, pass);
	
	string encoded = base64_encode(reinterpret_cast<const unsigned char*>(pass.c_str()), pass.length());
	
	fprintf(arq, "%d::\n", id);
	for (i = 0; i < strlen(desc); i++) fprintf(arq, "%c", desc[i]);
	fprintf(arq, "\n");
	for (i = 0; i < encoded.length(); i++) fprintf(arq, "%c", encoded[i]);
	fprintf(arq, "\n");
	
	cout << "\n\nPassword saved sucessfully\n\n\n";
	pause;
	
	fclose(arq);
	free(desc);
	cls;
	UserPage(id);
}

void SeePass(int id)
{
	int i;
	char aux[MAX_TAM_READ];
	char str[10];
	
	FILE *arq, *write, *read;
	arq = fopen("Pass_Description.dat", "r");
	write = fopen("temp.dat", "w");
	read = fopen("temp.dat", "r");
	if(!arq || !write || !read) erro();
	
	fprintf(write, "%d", id);
	fprintf(write, "::\n");
	fclose(write);
	fscanf(read," %[^\n]s", &str); //str = id::
	fclose(read);
	
	cout << "\t Registered passwords\n\n";
	
	while (fscanf(arq, " %[^\n]s", aux) != EOF)
	{
		if (strcmp(aux,str) == 0)
		{
			fscanf(arq, " %[^\n]s", &aux);
			printf(" %s\n", aux);
			continue;
		}
	}
	
	printf("\n\n ");
	pause;
	fclose(arq);
	cls;
	UserPage(id);	
}

void GetPass(int id)
{
	int i;
	char *find, aux[100];
	
	find = (char *) malloc(sizeof(char) * MAX_TAM_LOGIN);
	listPassDesc(id);
	
	cout << "\t Get a password\n\n";
	cout << "Password description: ";
	scanf(" %[^\n]s", find);
	
	if (is_inList(find) == false)
	{
		cout << "\n\nThis password is not registered\n\n\n";
		pause;
		cls;
		GetPass(id);
	}
	
	FILE *arq;
	arq = fopen("Pass_Description.dat", "r");
	if (!arq) erro();
	
	while (fscanf(arq, " %[^\n]s", &aux) != EOF)
	{
		if (strcmp(find,aux) == 0)
		{
			fscanf(arq, " %[^\n]s", &aux);
			break;
		}
	}
	
	fclose(arq);
	string encoded;
	for (i = 0; i < strlen(aux); i++)  encoded += aux[i];
	string decoded = base64_decode(encoded);
	cout << endl;
	cout << "Your password is: ";
	cout << decoded << endl << endl << endl;
	pause;
	cls;
	UserPage(id);
}

void printName(int id)
{
	int cont = 1;
	char user[MAX_TAM_LOGIN];
	
	FILE *arq;
	arq = fopen("Users_LoginDatabase.dat", "r");
	if(!arq) erro();
	
	while (fscanf(arq, " %[^\n]s", &user) != EOF)
	{
		if (cont == id) break;
		cont++;
	}
	
	fclose(arq);
	printf("%s!\n\n", user);	
}

void listPassDesc(int id)
{
	int i;
	char aux[MAX_TAM_READ];
	char str[10];
	
	FILE *arq, *write, *read, *write2;
	arq = fopen("Pass_Description.dat", "r");
	write = fopen("temp.dat", "w");
	read = fopen("temp.dat", "r");
	write2 = fopen("list.dat", "w");
	if(!arq || !write || !read || !write2) erro();
	
	fprintf(write, "%d", id);
	fprintf(write, "::\n");
	fclose(write);
	fscanf(read," %[^\n]s", &str); //str = id::
	fclose(read);
	
	while (fscanf(arq, " %[^\n]s", aux) != EOF)
	{
		if (strcmp(aux,str) == 0)
		{
			fscanf(arq, " %[^\n]s", &aux);
			fprintf(write2,"%s\n", aux);
			continue;
		}
	}
	
	fclose(arq);
	fclose(write2);
}

bool is_inList(char *find)
{
	char aux[100];
	bool flag = false;
	
	FILE *arq;
	arq = fopen("list.dat", "r");
	if (!arq) erro();
	
	while (fscanf(arq, " %[^\n]s", &aux) != EOF)
	{
		if (strcmp(aux,find) == 0)
		{
			flag = true;
			break;
		}
	}
	fclose(arq);
	
	return flag;	
}
