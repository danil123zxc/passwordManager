#include "common.h"
#include "user.h"
void showMenu()
{
	printf("1. �߰�");
	printf("2. ����");
	printf("3. ����");
	printf("4. ����");
	printf("5. ��ü ��Ʈ");
	printf("6. ����");
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
