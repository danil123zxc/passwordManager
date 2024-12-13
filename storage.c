#include "common.h"
#include "user.h"
#define CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()-_=+[{]}\|;:',<.>/?  "

void deleteNote(const char* login) {
    for (int i = 0; i < accountIndex; i++) {
        if (accounts[i].userLogin && strcmp(accounts[i].userLogin, login) == 0) {
            free(accounts[i].websiteName);
            free(accounts[i].userLogin);
            free(accounts[i].userPassword);

            accounts[i].websiteName = NULL;
            accounts[i].userLogin = NULL;
            accounts[i].userPassword = NULL;

            for (int j = i; j < accountIndex - 1; j++) {
                accounts[j] = accounts[j + 1];
            }

            accountIndex--;
            printf("삭제되었습니다!\n");
            return;
        }
    }
    printf("계정을 찾을 수 없습니다!\n");
}

void editNote(int index) {
    if (index < 0 || index >= accountIndex) {
        printf("잘못된 인덱스입니다!\n");
        return;
    }

    int choice;
    char buffer[100];
    printf("1. 웹사이트 수정 2. 로그인 수정 3. 비밀번호 수정\n옵션을 선택하세요: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("새 웹사이트를 입력하세요: ");
        scanf("%99s", buffer);
        free(accounts[index].websiteName);
        accounts[index].websiteName = malloc(strlen(buffer) + 1);
        strcpy(accounts[index].websiteName, buffer);
        break;
    case 2:
        printf("새 로그인을 입력하세요: ");
        scanf("%99s", buffer);
        free(accounts[index].userLogin);
        accounts[index].userLogin = malloc(strlen(buffer) + 1);
        strcpy(accounts[index].userLogin, buffer);
        break;
    case 3:
        printf("새 비밀번호를 입력하세요: ");
        scanf("%99s", buffer);
        free(accounts[index].userPassword);
        accounts[index].userPassword = malloc(strlen(buffer) + 1);
        strcpy(accounts[index].userPassword, buffer);
        break;
    default:
        printf("잘못된 선택입니다!\n");
        break;
    }
}


void cleanupAccounts() {
    for (int i = 0; i < accountIndex; i++) {
        free(accounts[i].websiteName);
        free(accounts[i].userLogin);
        free(accounts[i].userPassword);
    }
    accountIndex = 0;
}

char* getRandomPassword(int length)
{
    char* password;
    password = malloc((length + 1) * sizeof(char));
    int i = 0;
    int characterLength = strlen(CHARACTERS);
    for (i; i < length; i++)
    {
        int index = rand() % characterLength;
        password[i] = CHARACTERS[index];
    }
    password[length] = '\0';
    return password;
}