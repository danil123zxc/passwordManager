#include "common.h"
#include "user.h"
void showMenu() {
    printf("1. �߰� 2. ���� 3. ���� 4. ��й�ȣ ���� 5. ��� ���� ���� 6. ����\n");
}

void showNotes() {
    printf("\t������Ʈ\t�α���\t��й�ȣ\n");
    for (int i = 0; i < accountIndex; i++) {
        printf("%d\t%s\t%s\t%s\n", i + 1, accounts[i].websiteName, accounts[i].userLogin, accounts[i].userPassword);
    }
}