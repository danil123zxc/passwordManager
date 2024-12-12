#include "common.h"
#include "user.h"
void showMenu()
{
	printf("1. 추가");
	printf("2. 삭제");
	printf("3. 변경");
	printf("4. 생성");
	printf("5. 전체 노트");
	printf("6. 종료");
}

void showNotes()
{
	printf("All notes:");
	printf("website name\tlogin\tpassword\n");
	for (int i = 0; i < 100; i++)
	{
		printf("%s\t%s\t%s\n", accounts[i].websiteName, accounts[i].userLogin, accounts[i].userPassword);
	}
}
