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
  unsigned short bus_line;    //info
  char* travel_from;          //info
  char* travel_to;            //info
  unsigned short travel_time; //info
  Node* prev_node;            //metadata
  Node* next_node;            //metadata
};


struct node {
  unsigned short bus_line;    //info
  char* bus_stop;             //info
  unsigned short start_time;  //info
  Edge* adjacent_edges;       //metadata
  Node* next_node;            //metadata
};


char* splitLine (char* a_line){
  char* split_string = strtok(a_line, ",");
  while (split_string != NULL) {
    
  }
}




/*

char* splitline(char *dest, int n, FILE *source){
  char* string = readline(dest, n, source);
  char* comma = strchr(string, ',');
  while (comma != NULL) comma = '\0';
  return string;
}
*/



Node makeNode(char* string) {
  Node new_node = NULL;
  char* split_string = strtok(string, ",");
  while (split_string != NULL) {
    
    
  }
}

Edge makeEdge() {
  
}


void makeGraph(char* filename) {
  FILE* database = fopen(filename, "r");
  Node new_node = malloc(sizeof(struct node));
  Edge new_edge = malloc(sizeof(struct edge));
}










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


int main(void){
  welcomeScreen();
  return 0;
}











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

