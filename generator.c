#include "common.h"
#define CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`~!@#$%^&*()-_=+[{]}\|;:',<.>/?  "

char* getRandomPassword(int length)
{
	char password[50];
	int i = 0;
	int characterLength = sizeof(CHARACTERS) - 1;
	for (i; i < length; i++)
	{
		int index = rand() % characterLength;
		password[i] = index;
	}
	return password;
}

