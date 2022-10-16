#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>
#include <sys/utsname.h>

int main(){
	char name[100];
	int result = gethostname(name,100);
	printf("%s\n",name);
	struct utsname name2;
	int result2 = uname(&name2);
	printf("%s\n", name2.sysname);
	printf("%s\n", name2.nodename);
	printf("%s\n", name2.release);
	printf("%s\n", name2.version);
	printf("%s\n", name2.machine);
	printf("%ld\n",gethostid());
	return 0;	
}
