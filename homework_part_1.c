/*
* The program includes the methods to initialize, sort, and print array of integer, and also calculate factorial of integer.
* Completion time: 45 minutes
*
* @author Kien Ta
* @version C
*/
#include <stdio.h>

void initialize_array(int* p, int size);
void print_array(int* p, int size);
int get_size(int* p);
void selection_sort(int* p, int size);
int factorial(int n);

int main()
{
  int a [10] = {3, 5, 6, 8, 12, 13, 16, 17, 18, 20};
  int b [6]= {18, 16, 19, 3 ,14, 6};
  int c [5]= {5, 2, 4, 3, 1};

  // testing initialize_array
  print_array(a, 10); // print: 3, 5, 6, 8, 12, 13, 16, 17, 18, 20
  initialize_array(a, 10);
  print_array(a, 10); // print: 0, 5, 0, 5, 0, 5, 0, 5, 0, 5
  
  // testing selection_sort
  print_array(b, 6); // print: 18, 16, 19, 3 ,14, 6
  selection_sort (b, 6);
  print_array(b, 6); // print: 19, 18, 16, 14, 6, 3

  // testing factorial
  printf("Factorail of 5 - %d\n", factorial (5)); //print: 120
  c[0] = factorial (c[0]);
  c[1] = factorial (c[2]);
  print_array(c, 5); // print: 120, 24, 4, 3, 1
  return 0;
}
void initialize_array(int* p, int size){
  for(int i = 0; i < size; i++){
    if(i % 2 == 0){
      p[i] = 0;
    }
    else{
      p[i] = 5;
    }
  }
}

void print_array(int* p, int size){
  //loop through every element in the array
    while(size > 0){
        printf("%d ", *p);
        p++;
        size--;
    }
    //printf \n to go to new line
    printf("\n");
}

void selection_sort(int* p, int size){
  for(int i = 0; i < size; i++){
    int max_val = p[i];
    int max_index = i;
    //max_val store the max element starting from index i 
    //max_index is the index of min
    for(int j = i + 1; j < size; j++){
      if(max_val < p[j]){
        max_val = p[j];
        max_index = j;
      }
    }
    //swap i to the biggest element
    p[max_index] = p[i];
    p[i] = max_val;
  }
}

int factorial(int n){
  //Base case
  if(n == 0){
    return 1;
  }
  
  return n * factorial(n - 1);
}