#include "common.h"
#include "user.h"
void showMenu() {
    printf("1. 추가 2. 삭제 3. 수정 4. 비밀번호 생성 5. 모든 계정 보기 6. 종료\n");
}

void showNotes() {
    printf("\t웹사이트\t로그인\t비밀번호\n");
    for (int i = 0; i < accountIndex; i++) {
        printf("%d\t%s\t%s\t%s\n", i + 1, accounts[i].websiteName, accounts[i].userLogin, accounts[i].userPassword);
    }
}