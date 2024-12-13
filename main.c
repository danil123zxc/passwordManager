#include "common.h"
#include "input.h"
#include "storage.h"
#include "user.h"
#include"screenOut.h"
#define LENGTHOFSTRING 100
enum { ADD = 1, DELETE, EDIT, GENERATE, SHOWALL, QUIT };

int main() {
    char website[LENGTHOFSTRING], login[LENGTHOFSTRING], password[LENGTHOFSTRING];
    int input = 0, length, editIndex;
    char* generatedPassword;

    while (1) {
        showMenu();
        printf("�ɼ��� �����ϼ���: ");
        scanf("%d", &input);

        switch (input) {
        case ADD:
            printf("������Ʈ: ");
            scanf("%99s", website);
            printf("�α���: ");
            scanf("%99s", login);
            printf("��й�ȣ: ");
            scanf("%99s", password);
            allAccounts(website, login, password);
            break;
        case DELETE:
            printf("������ �α����� �Է��ϼ���: ");
            scanf("%99s", login);
            deleteNote(login);
            break;
        case EDIT:
            showNotes();
            printf("������ ������ �ε����� �Է��ϼ���: ");
            scanf("%d", &editIndex);
            editNote(editIndex - 1);
            break;
        case GENERATE:
            printf("��й�ȣ ���̸� �Է��ϼ���: ");
            scanf("%d", &length);
            generatedPassword = getRandomPassword(length);
            printf("������ ��й�ȣ: %s\n", generatedPassword);
            free(generatedPassword);
            break;
        case SHOWALL:
            showNotes();
            break;
        case QUIT:
            cleanupAccounts();
            return 0;
        default:
            printf("�߸��� �����Դϴ�!\n");
            break;
        }
    }

    return 0;
}