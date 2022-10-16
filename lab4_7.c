#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h>

int main() { 
	char *s; 
	char name[100] = "TEST";
	if (strcmp(name,"") == 0) {
		printf("Clear all env\n");
		int result = clearenv();
		if (result == -1) {
			printf("Error\n");
			return 0;
		}
	} else {
		int result = unsetenv(name);
		if (result == -1) {
			printf("ERROR\n");
		return 0;
		}
	}
	int i=0;
	while (__environ[i] != NULL) {
		printf("%s\n",__environ[i]);
		i++;
	}
	return 0; 
}
