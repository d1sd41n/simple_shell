#include "holberton.h"


int main()
{
   char *tmp;
   tmp = _getenv("PWD");
   printf("%s\n", tmp);
   return 0;
}


