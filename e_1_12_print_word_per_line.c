#include <stdio.h>

int main()
{
   int c;
   int flag = 0;

   while((c = getchar()) != EOF) {
      if((c == ' ') || (c == '\t')) {
         flag = 1;
      }
      if((flag == 1) && (c != ' ') && (c != '\t')) {
         printf("\n%c", c);
         flag = 0;
      }else {
         printf("%c", c);
      }
   }
   return 0;
}
