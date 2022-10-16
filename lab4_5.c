#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <stddef.h> 

int main() { 
	char *s; 
	char name[100] = "USER"; 
	if (strcmp(name,"") == 0) { 
	printf("Вы видите это сообщение, посколько изначально имя переменной окружения не указано. Вы можете его ввести сейчас(независимо от регистра): "); 
	scanf("%s", name); 
	} 
	s = getenv(name); 
	printf("%s\n", s); 
	return 0; 
}
