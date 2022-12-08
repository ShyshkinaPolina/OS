#include <getopt.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void print_help() {
  printf("\nPROCESS ATTRIBUTES:\n");
  printf("-help, -h\tprint this help\n");
  printf("-all, -a\tprint all attributes\n");
  printf("-procid, -p\tprint process identifiers\n");
  printf("-groupid, -g\tprint process' group identifiers\n");
  printf("-realid, -r\tprint UID and GID \n");
  printf("-attr, -t\tprint eUID and eGID vals\n\n");
}

void print_pid() {
  printf("pid:\t%d\n", getpid());
}

void print_ppid() {
  printf("ppid:\t%d\n", getppid());
}

void print_pgrp() {
  printf("pgrp:\t%d\n", getpgrp());
}

void print_uid() {
  printf("uid:\t%d\n", getuid());
}

void print_euid() {
  printf("euid:\t%d\n", geteuid());
}

void print_gid() {
  printf("gid:\t%d\n", getgid());
}

void print_egid() {
  printf("egid:\t%d\n", getegid());
}

void print_attr() {
  print_euid();
  print_egid();
}

void print_realid() {
  print_uid();
  print_gid();
}

void print_procid() {
  print_pid();
  print_ppid();
}

void print_all() {
  print_pid();
  print_ppid();
  print_pgrp();
  print_uid();
  print_euid();
  print_gid();
  print_egid();
}

int main(int argc, char *argv[]) {

  int opt;
  const struct option long_opt[] = {
    {"help", no_argument, 0, 'h'},
    {"all", no_argument, 0, 'a'},
    {"pid", no_argument, 0, 'p'},
    {"groupid", no_argument, 0, 'g'},
    {"realid", no_argument, 0, 'r'},
    {"attr", no_argument, 0, 't'},
    {NULL, no_argument, NULL, 0}
	};
  while ((opt = getopt_long(argc, argv, "hapgrt", long_opt, NULL)) != -1){
    switch (opt){
      case 'h':{
        print_help();
        break;
      }
      case 'a':{
        print_all();
        break;
      }
      case 'p':{
        print_procid();
        break;
      }
      case 'g':{
        print_pgrp();
        break;
      }
      case 'r':{
        print_realid();
        break;
      }
      case 't':{
        print_attr();
        break;
      }
      case '?':{
        fprintf(stderr, "%s\n", "Unknown option");
        return -1;
      }
      default:{
        print_help();
        break;
      }
    }
  }
  return 0;
}
