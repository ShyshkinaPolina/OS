#include <stdio.h>
#include <time.h>
#include <malloc.h>

int tmp,n;

void deleteItem(int *a, int index) {
    int i=0;
    for (i=index;i<n-1;i++) {
        a[i] = a[i+1];
    }
    n--;
    a = (int *) realloc(a,n * sizeof(int));
}

int FindMin(int *a, int flag){
    int i, min = a[0], min_index=0;
    for(i=0;i<n;i++){
        if(a[i]<min){
          min=a[i];
          min_index = i;
        }
    }
    if (flag == 1) {
    	printf("min=%d\n",min);
        deleteItem(a, min_index);
    }
    else{
    	a[min_index]=min+tmp;
	}
    return min;
}

int main()
{
    srand(time(NULL));
    int i, tmp1, flag=0;
    printf("enter the number of material points: ");
    scanf("%d", &n);
    int *a;
    a = (int *) malloc(n * sizeof(int));
    printf("you have %d material points: ", n);
    for(i=0;i<n;i++){
        a[i] = rand() %1000;
        printf("%d ", a[i]);
    }
    printf("\n");
    while(n>1){
        flag = 1;
        tmp = FindMin(a, flag);
        flag = 0;
        FindMin(a, flag);
        for(i=0;i<n;i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
