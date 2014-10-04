
#include "readToBuffer.h"


void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
}

void getInput (char* buffer, int stringChoice) {    
  printf("Enter key: ");
  readline(buffer, 128, stdin);
  if (stringChoice == 1) {
    puts("Searching database...\n"); 
  } else {
    puts("Searching database for duplicate keys... \n"); }
}


