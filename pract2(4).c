#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct { 
 double * array; 
 int size; 
}ArrayList; 
 
ArrayList list; 
void add(double); 
void insert(int, double); 
void myRemove(int); 
void set(int, double); 
double get(int); 
 
int main() { 
 int menubar, menuflag=1; 
 list.size = 0; 
 while(menuflag==1) { 
  printf("1. Add item to the end of list\n"); 
  printf("2. Insert item into the list\n"); 
  printf("3. List size\n"); 
  printf("4. Remove item by index\n"); 
  printf("5. Change item value\n"); 
  printf("6. Get value by index\n"); 
  printf("7. Show array\n"); 
  printf("0. Exit\n"); 
  printf("Enter: "); 
  scanf("%d", &menubar); 
  switch(menubar) { 
   case 0: { 
    // 
    free(list.array); 
    list.size = 0; 
    menuflag = 0; 
    break; 
   } 
   case 1: { 
    double value; 
    printf("Enter value: "); 
    scanf("%lf", &value); 
    add(value); 
    break; 
   } 
   case 2: { 
    double value; 
    int index; 
    printf("Enter value: "); 
    scanf("%lf", &value); 
    printf("Enter index: "); 
    scanf("%d", &index); 
    insert(index, value); 
    break; 
   } 
   case 3: { 
    printf("%d\n", list.size); 
    break; 
   } 
   case 4: { 
    int index; 
    printf("Enter index: "); 
    scanf("%d", &index); 
    myRemove(index); 
    break; 
   } 
   case 5: { 
    double value; 
    int index; 
    printf("Enter value: "); 
    scanf("%lf", &value); 
    printf("Enter index: "); 
    scanf("%d", &index); 
    set(index, value); 
    break; 
   } 
   case 6: { 
    int index; 
    printf("Enter index: "); 
    scanf("%d", &index); 
    printf("%lf\n", get(index)); 
    break; 
   } 
   case 7: { 
    int i=0; 
    for(i = 0; i < list.size; i++) { 
     printf("%.2lf ",list.array[i]); 
    } 
    printf("\n"); 
    break; 
   } 
   default: { 
    printf("Incorrect Number\n"); 
    break; 
   } 
  } 
 } 
   
 return 0; 
} 
 
void add(double value) { 
 list.size++; 
 list.array = (double*)realloc(list.array, list.size*sizeof(double)); 
 list.array[list.size-1] = value; 
} 
 
void insert(int index, double value) { 
 if (index <= list.size) { 
  list.size++; 
  list.array = (double*)realloc(list.array, list.size*sizeof(double)); 
  int i = 0; 
  for (i = list.size - 2; i >= index; i--) { 
   list.array[i+1] = list.array[i]; 
  } 
  list.array[index] = value; 
 } else { 
  printf("Incorrect index\n"); 
 } 
} 
 
void myRemove(int index) {
 if (index == list.size - 1) {
  list.size--;
  list.array = (double*)realloc(list.array, list.size*sizeof(double)); 
  return;
 }
 int i = 0; 
 for(i = index; i < list.size - 1; i++) { 
  list.array[i] = list.array[i + 1]; 
 } 
 list.size--; 
  list.array = (double*)realloc(list.array, list.size*sizeof(double)); 
} 
 
void set(int index, double value) { 
 list.array[index] = value; 
} 
 
double get(int index) { 
 return list.array[index]; 
}
