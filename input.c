#include "common.h"
#include "user.h"

user loginAndPassword;
int accountIndex = 0;

void setWebsite(const char* website) {
    loginAndPassword.websiteName = malloc(strlen(website) + 1);
    strcpy(loginAndPassword.websiteName, website);
}

void setLogin(const char* login) {
    loginAndPassword.userLogin = malloc(strlen(login) + 1);
    strcpy(loginAndPassword.userLogin, login);
}

void setPassword(const char* password) {
    loginAndPassword.userPassword = malloc(strlen(password) + 1);
    strcpy(loginAndPassword.userPassword, password);
}

void allAccounts(const char* website, const char* login, const char* password) {
    setWebsite(website);
    setLogin(login);
    setPassword(password);
    accounts[accountIndex++] = loginAndPassword;
}
