#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>

int main(){
	int i=0;
	while (__environ[i] != NULL) {
		printf("%s\n",__environ[i]);
		i++;
	}
	return 0; 
}
