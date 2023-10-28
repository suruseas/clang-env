#include <stdio.h>

struct student
{
  int id;
  char grade;
  float avarage;
};

typedef struct student STUDENT_TYPE;

STUDENT_TYPE initialize_student_record(STUDENT_TYPE s)
{
  s.id++;
  s.grade = ' x';
  s.avarage = 0.0;
  return s;
}

int main()
{
  STUDENT_TYPE student;

  student.id = 20;
  student.grade = 'a';
  student.avarage = 300.000;

  printf("%d %c %f\n", student.id, student.grade, student.avarage);
  student = initialize_student_record(student);
  printf("%d %c %f\n", student.id, student.grade, student.avarage);

  return 0;
}
