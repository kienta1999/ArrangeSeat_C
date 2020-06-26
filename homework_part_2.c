/*
* The program includes contains seats of Students that allows assigning students to empty spaces.
*
* Completion time: 90 minutes
*
* @author Kien Ta
* @version C
*
* 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
char last_name[30] ;
char first_name[30];
};

struct examination_seating {
struct student **seating;
int numRowInExam;
int numColInExam;
//I am not so sure how to get size of array based on given pointer so I 
//decided to add 2 field to keep the size of the array student
};
//initiate Student pointer with default name
void student_init_default (struct student *p ) {
  // p -> last_name = "###";
  strcpy(p -> last_name, "###");
  strcpy(p -> first_name, "###");
}
//initiate Student pointer with given name separated by /
void student_init (struct student *p, char *info) {
  char* token = strtok(info, "/");
  strcpy(p -> first_name, token);
  token = strtok(NULL, "/");
  strcpy(p -> last_name, token);
}
//print the abbreviation of student's name
void student_to_string (struct student *p ) {
  printf("%c.%c.", p -> first_name[0], p -> last_name[0]);
}

//initiate the classroom seats with given dimension
void examination_seating_init (int rowNum, int columnNum, struct examination_seating *t ) {
    t ->  seating = (struct student**)malloc(rowNum * sizeof(struct student *)); 
    for (int k=0; k < columnNum; k++) 
         (t ->  seating)[k] = (struct student *)malloc(columnNum * sizeof(struct student));
  for(int i = 0; i < rowNum; i++){
    for(int j = 0; j < columnNum; j++){
      student_init_default(&(t -> seating)[i][j]);
    }
  }
  t -> numRowInExam = rowNum;
  t -> numColInExam = columnNum;
}
//Assign student to specific seat, if possible
int assign_student_at (int row, int col, struct examination_seating *t, struct student* p) {
  struct student s = (t -> seating)[row][col];
  if(strcmp(s.first_name, "###") == 0 && strcmp(s.last_name, "###") == 0){
    (t -> seating)[row][col] = *p;
    return 1;
  }
  else{
    return 0;
  }
}
//check if a given row and col are valid 
int check_boundaries (int row, int col, struct examination_seating *t) {
  struct student **seats = t -> seating;
  int num_row = t -> numRowInExam;
  int num_col = t -> numColInExam;
  if(row >= num_row || row < 0 || col >= num_col || col <0){
    return 0;
  }
  else{
    return 1;
  }
}
//print the map of students in the classroom
void examination_seating_to_string (struct examination_seating *t ) {
  struct student **seats = t -> seating;
  int num_row = t -> numRowInExam;
  int num_col = t -> numColInExam;
  printf("The current seating \n");
  printf("----------------------\n");
  for(int i = 0; i < num_row; i++){
    for(int j = 0; j < num_col; j++){
      student_to_string(&seats[i][j]);
      printf(" ");
    }
    printf("\n");
  }
}

int main() {
 struct examination_seating examination_seating;
 struct student temp_student;
 student_to_string(&temp_student);
 int row, col, rowNum, columnNum;
 char student_info[30];
 // Ask a user to enter a number of rows for a examination seating
 printf ("Please enter a number of rows for a examination seating.");
 scanf ("%d", &rowNum);
fflush(stdin);
 // Ask a user to enter a number of columns for a examination seating
 printf ("Please enter a number of columns for a examination seating.");
 scanf ("%d", &columnNum);
 fflush(stdin);
 // examination_seating
 examination_seating_init(rowNum, columnNum, &examination_seating);

 printf("Please enter a student information or enter \"Q\" to quit.");
 /*** reading a student's information ***/
 scanf ("%s", student_info);
 fflush(stdin);
 /* we will read line by line **/
 while (1 /* change this condition*/ ){
 printf ("\nA student information is read. \n");
 // printing information.
 printf ("%s", student_info);
 // student
 student_init (&temp_student, student_info);
 // Ask a user to decide where to seat a student by asking
 // for row and column of a seat
 printf ("Please enter a row number where the student wants to sit.");
 scanf("%d", &row);
 fflush(stdin);
 printf("Please enter a column number where the student wants to sit.");
 scanf("%d", &col);
 fflush(stdin);
// Checking if the row number and column number are valid
// (exist in the examination that we created.)
 if (check_boundaries(row, col, &examination_seating) == 0) {
 printf("\nrow or column number is not valid.");
 printf("A student %s %s is not assigned a seat.", temp_student.first_name,
temp_student.last_name);
 } else {
 // Assigning a seat for a student
 if (assign_student_at(row, col, &examination_seating, &temp_student) == 1){
 printf("\nThe seat at row %d and column %d is assigned to the student",row, col);
 student_to_string(&temp_student);
 examination_seating_to_string(&examination_seating);
 } else {
 printf("\nThe seat at row %d and column %d is taken. \n", row, col);
 }
 }
 // Read the next studentInfo
 printf ("Please enter a student information or enter \"Q\" to quit.");
 /*** reading a student's information ***/
 scanf("%s", student_info);
 fflush(stdin);
 }
};