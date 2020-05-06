#include <stdio.h>

int main()
{
   int i, x;
   char str[100];

   printf("\nPlease enter a string:\t");
   gets(str);

   printf("\nPlease choose following options:\n");
   printf("1 = Encrypt the string.\n");
   printf("2 = Decrypt the string.\n");
   scanf("%d", &x);

   switch(x)
   {
   case 1:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 3;

      printf("\nEncrypted string: %s\n", str);
      break;

   case 2:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3;

      printf("\nDecrypted string: %s\n", str);
      break;

   default:
      printf("\nError\n");
   }
   return 0;
}
