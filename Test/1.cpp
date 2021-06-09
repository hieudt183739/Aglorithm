#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int day, year;
   char weekday[20], month[20], dtm[100];

   strcpy( dtm, "Tuesday July 12 2016" );
   sscanf( dtm, "%s%s ", weekday, month);

   printf(weekday);
   printf("\n");
   printf(month);
    
   return(0);
}