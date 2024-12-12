#include "common.h"
#include "user.h"

user loginAndPassword;

void setWebsite(char* website)
{
	loginAndPassword.websiteName = website;
}

void setLogin(char* login)
{
	loginAndPassword.userLogin = login;
}

void setPassword(char* password)
{
	loginAndPassword.userPassword = password;
}



void allAccounts(char* website, char* login, char* password)
{
	int i = 0;
	setWebsite(website);
	setLogin(login);
	setPassword(password);
	accounts[i++] = loginAndPassword;
}