#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

int main() { 
	char *s; 
	char name[100] = "TEST";
	char value[100] = "TESTVALUE";
	int overwrite = 0;
	int menubar = 0;
	while (menubar != -1) {
		printf("1. USE SETENV\n");
		printf("2. USE PUTENV\n");
		printf("0. EXIT\n");
		printf("ENTER: ");
		scanf("%d",&menubar);
		switch(menubar) {
		case 0: {
      			printf("BYE\n");
      			menubar = -1;
      			break;
		}
		case 1: {
			if (strcmp(name,"") == 0 || strcmp(value,"") == 0) {
        			printf("You see this message because the name or value are not entered.\n");
				printf("Enter name: ");
				scanf("%s", name);
				printf("Enter value: ");
				scanf("%s", value);
				printf("Enter overwrite flag(0 - not, 1 - true): ");
				scanf("%d", &overwrite);
			}
			int result = setenv(name, value, overwrite);
			if (result == -1) {
				printf("Error, not enough memory\n");
			}
			printf("%s\n", getenv(name));
			break;
			}
			case 2: {
			if (strcmp(name,"") == 0 || strcmp(value,"") == 0) {
				printf("You see this message because the name or value are not entered.\n");
				printf("Enter name: ");
				scanf("%s", name);
				printf("Enter value: ");
				scanf("%s", value);
				}
			char insertString[10000];
			strcat(insertString, name);
			strcat(insertString, "=");
			strcat(insertString, value);
			int result = putenv(insertString);
			if (result == -1) {
				printf("Error, not enough memory\n");
			}
			printf("%s\n", getenv(name));
			break;
			}
		}
	}
	return 0; 
}
