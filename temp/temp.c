#include<stdlib.h>
#include<string.h>
typedef struct Stu{
  int id;
  char name[20];
  struct Stu *next;
} Stu;
int main(){
  Stu *head;
  Stu *p = head;
  int count = 0;
  while(p!=NULL){
    if(strlen(p->name)>5){
      count++;
    }
    p = p->next;
  }
}