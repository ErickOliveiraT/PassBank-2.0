#include <stdio.h>
#include <windows.h>

#define ENC_PASS_DESCRIPTION system("tesseract vr41egX9rYTw6YCpvK18 Pass_Description.dat Pass_Description_enc.dat")
#define DEL_PASS_DESCRIPTION system("del Pass_Description.dat")
#define DEL_PASS_DESCRIPTION_ENC system("del Pass_Description_enc.dat")
#define DEC_PASS_DESCRIPTION system("tesseract vr41egX9rYTw6YCpvK18 Pass_Description_enc.dat Pass_Description.dat")
#define ENC_USERS_LOGINDATABASE system("tesseract vr41egX9rYTw6YCpvK18 Users_LoginDatabase.dat Users_LoginDatabase_enc.dat")
#define DEC_USERS_LOGINDATABASE system("tesseract vr41egX9rYTw6YCpvK18 Users_LoginDatabase_enc.dat Users_LoginDatabase.dat ")
#define DEL_USERS_LOGINDATABASE_ENC system("del Users_LoginDatabase_enc.dat")
#define DEL_USERS_LOGINDATABASE system("del Users_LoginDatabase.dat")
#define ENC_USERS_PASSDATABASE system("tesseract vr41egX9rYTw6YCpvK18 Users_PassDatabase.dat Users_PassDatabase_enc.dat")
#define DEC_USERS_PASSDATABASE system("tesseract vr41egX9rYTw6YCpvK18 Users_PassDatabase_enc.dat Users_PassDatabase.dat ")
#define DEL_USERS_PASSDATABASE_ENC system("del Users_PassDatabase_enc.dat")
#define DEL_USERS_PASSDATABASE system("del Users_PassDatabase.dat")
#define ENC_LIST system("tesseract vr41egX9rYTw6YCpvK18 list.dat list_enc.dat")
#define DEC_LIST system("tesseract vr41egX9rYTw6YCpvK18 list_enc.dat list.dat")
#define DEL_LIST_ENC system("del list_enc.dat")
#define DEL_LIST system("del list.dat")
#define ENC_TEMP system("tesseract vr41egX9rYTw6YCpvK18 temp.dat temp_enc.dat")
#define DEC_TEMP system("tesseract vr41egX9rYTw6YCpvK18 temp_enc.dat temp.dat")
#define DEL_TEMP_ENC system("del temp_enc.dat")
#define DEL_TEMP system("del temp.dat")
#define SetColorGreen system("color 0a")

int main()
{
	SetConsoleTitle("Tesseract Launcher");
	SetColorGreen;
	
	int op;
	
	printf("\t Tesseract Launcher\n\n");
	printf(" 1 - Encript all\n");
	printf(" 2 - Decript all\n");
	printf(" 3 - Delete encryted\n");
	printf(" 4 - Delete decryted database\n\n");
	printf(" Option: ");
	scanf("%d", &op);
	
	if (op == 1)
	{
		ENC_PASS_DESCRIPTION;
		ENC_USERS_LOGINDATABASE;
		ENC_USERS_PASSDATABASE;
		ENC_LIST;
		ENC_TEMP;
		DEL_PASS_DESCRIPTION;
		DEL_USERS_LOGINDATABASE;
		DEL_USERS_PASSDATABASE;
		DEL_LIST;
		DEL_TEMP;
	}
	else if (op == 2)
	{
		DEC_PASS_DESCRIPTION;
		DEC_USERS_LOGINDATABASE;
		DEC_USERS_PASSDATABASE;
		DEC_LIST;
		DEC_TEMP;
		DEL_PASS_DESCRIPTION_ENC;
		DEL_USERS_LOGINDATABASE_ENC;
		DEL_USERS_PASSDATABASE_ENC;
		DEL_LIST_ENC;
		DEL_TEMP_ENC;
	}
	else if (op == 3)
	{
		DEL_PASS_DESCRIPTION_ENC;
		DEL_USERS_LOGINDATABASE_ENC;
		DEL_USERS_PASSDATABASE_ENC;
		DEL_LIST_ENC;
		DEL_TEMP_ENC;
	}
	else if (op == 4)
	{
		DEL_PASS_DESCRIPTION;
		DEL_USERS_LOGINDATABASE;
		DEL_USERS_PASSDATABASE;
		DEL_LIST;
		DEL_TEMP;
	}
	
	return 0;
}
