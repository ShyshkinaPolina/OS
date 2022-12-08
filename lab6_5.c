#include <pwd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <getopt.h>
#include <string.h>
#include <sys/types.h>

#define GREEN_COLOR_BOLD "\033[1m\033[32m"
#define BLUE_COLOR_BOLD "\033[1m\033[34m"
#define RED_COLOR_BOLD "\033[1m\033[31m"
#define	RESET_COLOR "\033[0m"

#define DEFAULT_BUF_SIZE 127


void exit_func(void) {
	printf("Wait for 3 seconds...\n");
	sleep(3);
	pid_t pid = fork();
	if (pid == 0) {
		execvp("clear", NULL);
	}
}

void print_help() {
	printf("-h,--help\tshow usage help\n");
	printf("-b,--buffer <size>\tset buffer size\n");
}

void execute(char *com, char *argv0) {
	char *delim = " ";
	char *token = strtok(com, delim);
	int count = 0;
	while (token) {
		count += 1;
		token = strtok(NULL, delim);
	}
	int countend = count;
	char *args[countend+1];
	token = strtok(com, delim);
	args[0] = argv0;
	char *command = malloc(sizeof(char*));
	while(token) {
		if (countend == count) {
			memcpy(command, token, sizeof(token));
			token = strtok(NULL, delim);
			continue;
			count = 1;
		}
		memcpy(args[count], token, sizeof(token));
		token = strtok(NULL, delim);
		count += 1;
	}
	args[countend] = NULL;
	pid_t pid = fork();
	if (pid == 0) {
		execvp(command, args);
		return;
	}
	else return;
}

int main(int argc, char *argv[]) {
	if (atexit(exit_func))
		fprintf(stderr, "Some error during finishing occured\n");

	size_t buf_size = DEFAULT_BUF_SIZE;

	int opt;
	const struct option long_opt[] = {
		{"help", no_argument, 0, 'h'},
		{"buffer", required_argument, 0, 'b'},
		{NULL, no_argument, NULL, 0}
	};
	while ((opt = getopt_long(argc, argv, "b:h", long_opt, NULL)) != -1){
		switch (opt){
			case 'h':{
				print_help();
				break;
			}
			case 'b':{
				buf_size = atoi(optarg);
				break;
			}
			case '?':{
				fprintf(stderr, "Wrong option usage\n");
				return;
			}
			default:{
				printf("Use -h/--help option to get help\n");
				break;
			}
		}
	}

	char * full_uname = (getpwuid(getuid()))->pw_gecos;
	printf("\n\nCurrent user:%s\t%s%s\n\n", GREEN_COLOR_BOLD, full_uname, RESET_COLOR);
	char *uname = getlogin();
	char *end_com = (char *) malloc (4);
	end_com = strcpy(end_com, "stop");
	char cwd[1024];
	char *com = (char *) malloc (buf_size);
	const char* args[] = {NULL};
	do {
		printf("%s%s%s:", RED_COLOR_BOLD, uname, RESET_COLOR);
		getcwd(cwd, sizeof(cwd));
		printf("%s%s%s$ ", BLUE_COLOR_BOLD, cwd, RESET_COLOR);
		scanf("%s", com);
		if (strcmp(end_com, com) == 0)
			break;
		execute(com, argv[0]);
	} 
	while (true);
	free(com);
	printf("\n\n");
	return 0;
}
