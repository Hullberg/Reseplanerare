#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "readline.h"

struct edge;
struct node;

char buffer[128];


typedef struct edge {
  char* bus_line;             
  struct node* travel_from;   
  struct node* travel_to;     
  char* travel_time;          
} *Edge;

typedef struct node {
  char* name;
  struct edge* route;
  struct node* next_node;
} *Node;




char* removeSpace(char* string){
  while(string[0] == 32){
    string = string + 1;
  }
  return string;
}

Edge makeEdgeElements(Edge new_edge, char* string, int i){
  char* dick = removeSpace(string);
  switch (i){
  case 0:
    strcpy(new_edge->bus_line, dick);
    break;
  case 1:  
    strcpy(new_edge->travel_from->name, dick);
    break;
  case 2:  
    strcpy(new_edge->travel_to->name, dick);
    break;
  case 3:  
    strcpy(new_edge->travel_time, dick);
    break;
  }
  return new_edge;
}


Edge newEdge(char* string, Edge new_edge){
  char delim[2] = ",";
  for (int i = 0 ; i < 4; ++i) {
    makeEdgeElements(new_edge, string, i);
    string = strtok(NULL, delim);
  }
  return new_edge;
}



char* getInfo(char* filename){
  FILE* database = fopen(filename, "r");
  char* string = fgets(buffer, 128, database);
  return string;
}

Edge makeEdge (char* filename, Edge new_edge){
  char delim[2] = ","; 
  char* string = getInfo(filename);
  char* split_string = strtok(string, delim);
  return newEdge(split_string, new_edge);
}



int welcomeScreen(void){
  puts("\n\tWelcome to Travel Planner!");
  puts("       ____________");
  puts("      // PARTYBUS \\\\ ");
  puts("    ___________________     \\|/");
  puts("o  | [__] | [__]  [  ] |   (^^)");
  puts(" o |              [__] |   /||\\");
  puts("  o|___()_______()_____|    /\\");
  puts("");
  puts("\tLoading timetables...\n");
  return 0;
}



Edge allocate(void){
  Edge new_edge = malloc(sizeof(struct edge));
  new_edge->bus_line = malloc(strlen(buffer)+1);
  new_edge->travel_from = malloc(sizeof(struct node));
  new_edge->travel_from->name = malloc(strlen(buffer)+9); //beh�ver vara +9 h�r, vet ej varf�r
  new_edge->travel_to = malloc(sizeof(struct node));
  new_edge->travel_to->name =malloc(strlen(buffer)+9); //samma som ovan
  new_edge->travel_time = malloc(strlen(buffer)+1);
  return new_edge;
}

int main(int argc, char* argv[]){
  welcomeScreen();
  puts("\nLine:\tFrom:\t\t\tTo:\t\t\tTravel time:\n");
  char* test = argv[1];
  Edge new_edge = allocate();
  makeEdge(test, new_edge);
  printf("%s\t%s\t%s\t%s\n", new_edge->bus_line, (new_edge)->travel_from->name, (new_edge)->travel_to->name, (new_edge)->travel_time);

  return 1;
}


// Varje str�ngrad inneh�ller:
// (Busslinje, h�llplats, h�llplats, tid mellan stationerna) Exempel:
// 110, Polacksbacken, Grindstugan, 2

// Varje station har tre str�ngar
// (Busslinje, h�llplats, avg�ngstid) Exempel:
// 110, Lingonvägen, 05:00




// Olika saker vi kan g�ra, med s�kningar osv
/*
int mainloop(char *argv){


  int choice = -1;
  while(choice != 0){
    puts("Please choose an operation");
    puts("1. Enter starting destination"); // Vart man b�rjar, sedan f�ljdfr�ga om tid
    puts("2. Enter final destination"); // Vart man vill sluta, och senast när (typ)
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

