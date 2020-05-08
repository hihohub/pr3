#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"

/* James Smith
   CS 2750
   project 3: linked lists
   UMSL
*/

int validate(char * num){
   int valid = 1;
   for(int count = 0; count < strlen(num); ++count){
      if(!(isdigit(num[count]))){
         valid = 0;
         break;
      }
   }
   return valid;
}

int main(){
   Node * head = NULL;
   Node * tail = NULL;
   int keepgoing = 1;
   int destroyed = 0;
   char num[80];
   int x;
   do {
      printf("menu: \n\t1) insert head\n\t2) insert tail\n\t3) delete a node\n\t4) delete all\n\t5) display\n\t6) exit\n");
      scanf("%s",num);
      if(validate(num)==0){
         printf("please input a number\n");
         continue;
      }
      x = (int)strtol(num,NULL,10);
      switch(x){
         case 1:
            printf("input a number\n");
            scanf("%s",num);
            if(validate(num)==0){
               printf("invalid input\n");
               break;
            }
            x = (int)strtol(num,NULL,10);
            head = List_insert(head,x);
            destroyed = 0;
            break;
         case 2:
            if(destroyed==1 || head==NULL){
               printf("please insert a head first\n");
               break;
            }
            printf("input a number\n");
            scanf("%s",num);
            if(validate(num)==0){
               printf("invalid input\n");
               break;
            }
            x = (int)strtol(num,NULL,10);
            tail = List_insert_last(head,x);
            break;
         case 3:
            if(head==NULL){
               printf("please input a number first\n");
               break;
            }
            printf("input a number\n");
            scanf("%s",num);
            if(validate(num)==0){
               printf("invalid input\n");
               break;
            }
            x = (int)strtol(num,NULL,10);
            head = List_delete(head,x);
            break;
         case 4:
            List_destroy(head);
            head = NULL;
            tail = NULL;
            destroyed = 1;
            break;
         case 5:
            List_print(head);
            break;
         case 6:
            keepgoing = 0;
            break;
         default:
            printf("invalid input\n");
            break; 
      }
   } while(keepgoing==1);
}

