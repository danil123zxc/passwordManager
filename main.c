#include "common.h"
#include "input.h"
#include"generator.h"
#include "storage.h"
#include "user.h"
#include"showMenu.h"
enum { ADD, DELETE, EDIT, GENERATE, SHOWALL, QUIT };
int main()
{
	char* website, password, login;
	int input = 0;
	int length;

	while (1)
	{
		getchar();
		showMenu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			printf("Website name: \n");
			scanf("%s", &website);
			getchar();
			printf("Login: \n");
			scanf("%s", &login);
			getchar();
			printf("Password: \n");
			scanf("%s", &password);
			getchar();
			allAccounts(website, login, password);
			getchar();
			break;
		case DELETE:
			break;
		case EDIT:
			showNotes();
			break;
		case GENERATE:
			printf("비밀번호 길을 입력: ");
			scanf("%d", &length);
			printf("%s", getRandomPassword(length));
			break;
		case SHOWALL:
			showNotes();
			break;
		case QUIT:
			break;
		default:
			printf("실패");
			break;
		}
	}

	return 0;
}