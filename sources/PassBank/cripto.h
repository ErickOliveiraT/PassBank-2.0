//Cripto.h
/*
	Name: PassBank 2.0
	Author: Érick Oliveira
	Date: 17/05/18
	Description: Password Manager/Keeper
*/

#include <bits/stdc++.h>
#include <locale.h>
#include <windows.h>

#define cls system("cls")
#define pause system("pause")
#define SetColorGreen system("color 0a")
#define exit exit(0)
#define MAX_TAM_LOGIN 100
#define MAX_TAM_PASS 256
#define MAX_TAM_READ 10000

using namespace std;

void menu(); //Initial menu
void cadastro(); //Register new user
void Login(); //Login
bool verifyLogin(char *ent); //Verify if the login already exists
void erro(); //Error notification
void saveLogin(char *login); //Saves a login in the database
void savePass(string pass); //Saves a password in the database
int search_id(char *login); //Calculates de id for an user
bool verifyPass(char *ent, int id); //Verifies if the password is correct
void UserPage(int id); //User page
void NewPass(int id);  //Save a new password
void SeePass(int id);  //View discriptrion of saved passwords
void GetPass(int id);  //Get a saved password
void printName(int id); //Print username by id
void listPassDesc(int id); //List description of saved passes by user id
bool is_inList(char *find); //Verifies if the requested pass is in the user's list
