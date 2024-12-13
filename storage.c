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
            printf("�����Ǿ����ϴ�!\n");
            return;
        }
    }
    printf("������ ã�� �� �����ϴ�!\n");
}

void editNote(int index) {
    if (index < 0 || index >= accountIndex) {
        printf("�߸��� �ε����Դϴ�!\n");
        return;
    }

    int choice;
    char buffer[100];
    printf("1. ������Ʈ ���� 2. �α��� ���� 3. ��й�ȣ ����\n�ɼ��� �����ϼ���: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("�� ������Ʈ�� �Է��ϼ���: ");
        scanf("%99s", buffer);
        free(accounts[index].websiteName);
        accounts[index].websiteName = malloc(strlen(buffer) + 1);
        strcpy(accounts[index].websiteName, buffer);
        break;
    case 2:
        printf("�� �α����� �Է��ϼ���: ");
        scanf("%99s", buffer);
        free(accounts[index].userLogin);
        accounts[index].userLogin = malloc(strlen(buffer) + 1);
        strcpy(accounts[index].userLogin, buffer);
        break;
    case 3:
        printf("�� ��й�ȣ�� �Է��ϼ���: ");
        scanf("%99s", buffer);
        free(accounts[index].userPassword);
        accounts[index].userPassword = malloc(strlen(buffer) + 1);
        strcpy(accounts[index].userPassword, buffer);
        break;
    default:
        printf("�߸��� �����Դϴ�!\n");
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