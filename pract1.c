#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void generateTrio(int *trio) {
    srand(time(NULL));
    trio[0] = rand()%8;
    trio[1] = rand()%8;
    trio[2] = rand()%8;
}

int checkCombination(int *trio) {
    if (trio[0] == 0) {
        if (trio[1] == 0) {
            if (trio[2] == 0) {
                return 1;
            }
        }
    } else if (trio[0] == 1) {
        if (trio[1] == 1) {
            if (trio[2] == 1) {
                return 1;
            }
        }
    } else if (trio[0] == 2) {
        if (trio[1] == 2) {
            if (trio[2] == 2) {
                return 1;
            }
        }
    } else if (trio[0] == 3) {
        if (trio[1] == 3) {
            if (trio[2] == 3) {
                return 1;
            }
        }
    } else if (trio[0] == 4) {
        if (trio[1] == 4) {
            if (trio[2] == 4) {
                return 1;
            }
        }
    } else if (trio[0] == 5) {
        return 1;
    } else if (trio[0] == 7) {
        if (trio[1] == 7) {
            if (trio[2] == 7) {
                return 2;
            }
        }
        return 1;
    } else if (trio[0] == 6) {
        if (trio[1] == 6) {
            if (trio[2] == 6) {
                return -1;
            }
        }
    }
    return 0;
}

int main()
{
    system("chcp 1251");
	system("cls");
	int trio[3], money=5000, result;
    while (money>0) {
        printf("Денег на счету: %d\n", money);
        money-=75;
        generateTrio(trio);
        printf("Вам выпала комбинация: %d|%d|%d\n", trio[0],trio[1],trio[2]);
        result = checkCombination(trio);
        if (result==-1) {
            money-=500;
        } else if (result==1) {
            money+=100;
        } else if (result==2) {
            printf("ДЖЕКПОТ, Ваша сумма: %d\n", money+=10000);
            return 0;
        }
        sleep(1);
    }
    printf("Ваши деньги закончились\n");
    return 0;
}
