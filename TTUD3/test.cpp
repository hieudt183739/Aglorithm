#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int Input(char ip[], char port[]);

int main()
{
	char command[50];
	char ip[50];
	char port[50];
	memset(ip, 0, sizeof(ip));
	memset(port, 0, sizeof(port));
	 int a = Input(ip, port);
	cout << ip << "\n"
		 << port;

	return 0;
}

int Input(char ip[], char port[])
{
	char str[50];
	char command[50];

	int res = 0;
	int i = 0;
	memset(str, 0, sizeof(str));
	memset(command, 0, sizeof(command));
	fgets(str, sizeof(str), stdin);
	for (i = 0; i < strlen(str) - 1; i++)
	{

		if (str[i] == ' ')
		{

			if (strcmp(command, "TCPClient.exe") == 0)
			{
				res++;
			}
			break;
		}
		else
		{
			command[i] = str[i];
		}
	}
	int i1 = ++i;

	if (res == 0)
	{
		return -1;
	}

	for (; i < strlen(str) - 1; i++)
	{
		if (str[i] == ' ')
		{
			break;
		}
		ip[i - i1] = str[i];
	}
	int i2 = ++i;
	for (; i < strlen(str) - 1; i++)
	{
		port[i - i2] = str[i];
	}

	return 0;
}