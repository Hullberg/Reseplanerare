
#include "readline.h"

void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
}


void partitionLine(char* string) {
  char delim[2] = ","; 
  char* split_string;
  split_string = strtok(string, delim);
  while (split_string != NULL){
    if (split_string[0] == 32) {
      split_string = split_string + 1;
    }else{    
      printf("%s\n", split_string);
      split_string = strtok(NULL, delim);
    } 
  }
}
/*
int main () {
  char string[128] = "10, Biomedicinskt centrum, Akademiska sodra, 3";
  partitionLine(string);
  return 1;
}


*/
