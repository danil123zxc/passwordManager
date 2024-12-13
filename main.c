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
        printf("옵션을 선택하세요: ");
        scanf("%d", &input);

        switch (input) {
        case ADD:
            printf("웹사이트: ");
            scanf("%99s", website);
            printf("로그인: ");
            scanf("%99s", login);
            printf("비밀번호: ");
            scanf("%99s", password);
            allAccounts(website, login, password);
            break;
        case DELETE:
            printf("삭제할 로그인을 입력하세요: ");
            scanf("%99s", login);
            deleteNote(login);
            break;
        case EDIT:
            showNotes();
            printf("수정할 계정의 인덱스를 입력하세요: ");
            scanf("%d", &editIndex);
            editNote(editIndex - 1);
            break;
        case GENERATE:
            printf("비밀번호 길이를 입력하세요: ");
            scanf("%d", &length);
            generatedPassword = getRandomPassword(length);
            printf("생성된 비밀번호: %s\n", generatedPassword);
            free(generatedPassword);
            break;
        case SHOWALL:
            showNotes();
            break;
        case QUIT:
            cleanupAccounts();
            return 0;
        default:
            printf("잘못된 선택입니다!\n");
            break;
        }
    }

    return 0;
}