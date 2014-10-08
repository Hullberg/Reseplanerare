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


// createNode
// Error if already exists, otherwise append to top of list
// Uses arguments (previous_bus_stops, new_bus_stop)
// Does *NOT* work, need to replace x with the list of busstops...
// Not sure what to return from the function either. A list of all busstops and their buslines?
Edge createNode(Node* x, Node* new_Node){
  int found = 0;
    while (x != NULL){
      if (strcmp(x->name, new_Node->name) == 0){
	puts("That node already exists in the planner.");
	  found = 1;
	}
      else{
	x = x->next_node;
      }
    }
      if (!found){
	puts("Node is unique");
	Node newNode = malloc(sizeof(struct node));
	strcpy(new_Node, newNode);
	new_Node->next_node = x;
	x = newNode;
	return x;
      }
      else{
	return x;
      }
      return x;
}

// connectNodes
// Takes two stops and creates an edge between them, with busline and time
/*int createEdge(Node* stop1, Node* stop2){
  
  return 0;
}
*/

// removeNode
// Removes a busstop from the list

//removeEdge
// Removes the edge between two stops

// shortestPath
// The shortest way between two stops


char* removeSpace(char* string){
   if(string[0] == 32){
     string = string + 1;
  }
   return string;
}

// Eftersom vi kör makeEdgeElements 4 ggr så mallocar vi 24 saker... Frigör efter varje gång?
Edge makeEdgeElements(Edge new_edge, char* string, int i){
  switch (i){
  case 0:
    new_edge->bus_line = malloc(strlen(buffer) + 1);
    strcpy(new_edge->bus_line, removeSpace(string));
    free(new_edge->bus_line); //Freeee falling
    break;
  case 1:
    new_edge->travel_from = malloc(sizeof(struct node));
    new_edge->travel_from->name = malloc(strlen(buffer) + 1);
    strcpy(new_edge->travel_from->name, removeSpace(string));
    free(new_edge->travel_from); // Frigör, men hjälper inte
    free(new_edge->travel_from->name);
    break;
  case 2:
    new_edge->travel_to = malloc(sizeof(struct node));
    new_edge->travel_to->name = malloc(strlen(buffer) + 1);
    strcpy(new_edge->travel_to->name, removeSpace(string));
    free(new_edge->travel_to); // Det fungerar inte Axel
    free(new_edge->travel_to->name);
    break;
  case 3: 
    new_edge->travel_time = malloc(strlen(buffer) + 1);
    strcpy(new_edge->travel_time, removeSpace(string));
    free(new_edge->travel_time); // Tycker inte om det här!
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

// argv will have 3 arguments:
// 1. the programme itself
// 2. A file containing nodes (Busline, stop, starting times)
// 3. A file containing edges (Busline, stop1, stop2, time taken to travel between)

int main(int argc, char* argv[]){
  char* test = argv[1];
  Edge new_edge = malloc(sizeof(struct edge));
  makeEdge(test, new_edge);
  printf("%s\t%s\t%s\t%s\n", new_edge->bus_line, new_edge->travel_from->name, new_edge->travel_to->name, new_edge->travel_time);

  return 1;
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

