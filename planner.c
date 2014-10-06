// Hejsan hoppsan. Välkommen till sprint 2. Jobba med Axel, Kom igen, det blir kul. 
// Helvete Johan
// Jag tyckte det var kul

#include <stdlib.h>
#include <stdio.h>


#include "readline.h"

typedef struct edge *Edge;
typedef struct node *Node;

char buffer[128];


struct edge {
  char* bus_line;             
  struct node* travel_from;   
  struct node* travel_to;     
  char* travel_time;          
  struct edge* next_node;
} ;

struct node {
  char* bus_line;
  struct edge* route;
  struct node* next;
} ;



/*

struct edge {
   bus_line;    //info
  char* travel_from;          //info
  char* travel_to;            //info
  int travel_time; //info
  Node* prev_node;            //metadata
  Node* next_node;            //metadata
};


struct node {
  int bus_line;    //info
  char* bus_stop;             //info
  int start_time;  //info
  Edge* adjacent_edges;       //metadata
  Node* next_node;            //metadata
};


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
*/




char* getSpecificInfo(char* string, char* str){
   char delim[2] = ",";
   if((string[0] == 32)){
    string = string + 1;
    str = string;
    string = strtok(NULL, delim);    
  }else{
    str = string;
    string = strtok(NULL, delim);    
  }
   return str;
}


Edge makeElementEdge (char* string, int information) {
  Edge new_edge = NULL;
  char* str = NULL;
  switch (information) {
  case 1:
    atoi(getSpecificInfo(string, str));
    new_edge->bus_line = atoi(str);
    break;
  case 2:
    getSpecificInfo(string, str);  
    new_edge->travel_from = str;
    break;
  case 3:
    getSpecificInfo(string, str);   
    new_edge->travel_to = str;
    break;
  case 4:
    atoi(getSpecificInfo(string, str));   
    new_edge->travel_time = atoi(str);
    break;  
  default:
    puts("FUck you");
  } 
  return new_edge;
}


char* getInfo(char* filename){
  FILE* database = fopen(filename, "r");
  char* string = fgets(buffer, 128, database);
  return string;
}

Edge makeEdge (char* filename){
  Edge new_edge = NULL;
  char delim[2] = ","; 
  char* string = getInfo(filename);
  char* split_string = strtok(string, delim);
  while (split_string != NULL){
    makeElementEdge(split_string, 1);
    makeElementEdge(split_string, 2);
    makeElementEdge(split_string, 3);
    makeElementEdge(split_string, 4);
 }
  printf("%d\t%s\t%s\t%d\n", new_edge->bus_line, new_edge->travel_from, new_edge->travel_to, new_edge->travel_time);
  return new_edge;
}

/*

int welcomeScreen(void){
  puts("\n Welcome to travelplanner!");
  puts("       ____________");
  puts("      // PARTYBUS \\\\ ");
  puts("    ___________________     \\|/");
  puts("o  | [__] | [__]  [  ] |   (^^)");
  puts(" o |              [__] |   /||\\");
  puts("  o|___()_______()_____|    /\\");
  puts(" Loading timetables\n");
  return 0;
}
*/

int main(int argc, char* argv[]){
  char* test = argv[1];
  makeEdge(test);


  return 0;
}








/*
Edge makeEdge (char* string) {
  char delim[2] = ","; 
  char* split_string;
  split_string = strtok(string, delim);
  while (split_string != NULL){
    if (split_string[0] == 32) {
      split_string = split_string + 1;
      split_string = strtok(NULL, delim);
    }else{    
      split_string = strtok(NULL, delim); 
    } 
  }
  return split_string;
}



void getInfo(char* filename){
  // Node new_node = NULL;
  FILE* database = fopen(filename, "r");
  char* string = fgets(buffer, 128, database);
  partitionLine(string);
  char* a_piece_of_info = NULL;
  while (strchr(string, atoi("\n")) != NULL){
    for (int i = 0; string[i] != atoi("\n"); i++) {
      strcpy(a_piece_of_info, string);
    }
  }
  printf("%s/n", string);
}




Edge makeEdge() {
  
}
void makeGraph(char* filename) {
  FILE* database = fopen(filename, "r");
  Node new_node = malloc(sizeof(struct node));
  Edge new_edge = malloc(sizeof(struct edge));
}

*/





// Varje strängrad innehåller:
// (Busslinje, hållplats, hållplats, tid mellan stationerna) Exempel:
// 110, Polacksbacken, Grindstugan, 2

// Varje station har tre strängar
// (Busslinje, hållplats, avgångstid) Exempel:
// 110, LingonvÃ¤gen, 05:00




// Olika saker vi kan gära, med säkningar osv
/*
int mainloop(char *argv){


  int choice = -1;
  while(choice != 0){
    puts("Please choose an operation");
    puts("1. Enter starting destination"); // Vart man börjar, sedan följdfråga om tid
    puts("2. Enter final destination"); // Vart man vill sluta, och senast nÃ¤r (typ)
    puts("0. Exit the programme.");
    printf("? ");
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin
    switch(choice){
    case 1:
      starter(argv);
      break;
    case 2:
      final(argv);
      break;
    case 0:
      puts("The partybus has stopped.");
      break;
    default:
      puts("Invalid operation, please try again.\n");
    }
  }
}
*/

