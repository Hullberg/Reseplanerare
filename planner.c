#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "readline.h"

struct node;

char buffer[128];

// �NDRAT STRUKTEN
typedef struct edge {
  char* bus_line;             
  char* travel_from;   
  char* travel_to;     
  char* travel_time;
  struct edge* next;
} *Edge;

typedef struct node {
  char* bus_line;
  char* name;
  char* start_time; 
  struct node* next;
} *Node;



char* removeSpace(char* string){
  while(string[0] == 32){
    string = string + 1;
  }
  return string;
}

char* getInfo(FILE* database){
  //FILE* database = fopen(filename, "r");
  char* string = fgets(buffer, 128, database);
  return string;
}


//EDGE

/*
Edge makeEdgeElements(Edge new_edge, char* string, int i){
  char* value_for_insertion = removeSpace(string);
  switch (i){
  case 0:
    strcpy(new_edge->bus_line, value_for_insertion);
    break;
  case 1:  
    strcpy(new_edge->travel_from->name, value_for_insertion);
    break;
  case 2:  
    strcpy(new_edge->travel_to->name, value_for_insertion);
    break;
  case 3:  
    strcpy(new_edge->travel_time, value_for_insertion);
    break;
  }
  return new_edge;
}


Edge newEdge(char* string, Edge new_edge){
  for (int i = 0 ; i < 4; ++i) {
    makeEdgeElements(new_edge, string, i);
    string = strtok(NULL, ",");
  }
  return new_edge;
}

Edge makeEdge (FILE* filename, Edge new_edge){ 
  char* string = getInfo(filename);
  char* split_string = strtok(string, ",");
  return newEdge(split_string, new_edge);
}
*/

//NODE

Node makeNodeElements(Node new_node, char* string, int i) {
  char* value_for_insertion = removeSpace(string);
  switch (i){
  case 0:
    strcpy(new_node->name, value_for_insertion);
    break;
  case 1:  
    strcpy(new_node->route->bus_line, value_for_insertion);
    break;
  case 2:  
    strcpy(new_node->start_time, value_for_insertion);
    break;
  }
  return new_node;
}

Node newNode(char* string, Node new_node){
  for (int i = 0; i < 3; ++i) {
    makeNodeElements(new_node, string, i);
    string = strtok(NULL, ",");
  }
  return new_node;
}

Node makeNode(FILE* database, Node new_node){
  char* string = getInfo (database);
  char* split_string = strtok(string, ",");
  return newNode(split_string, new_node);
}

//MEMORY ALLOCATION
/*
Edge allocateEdge(void){
  Edge new_edge = malloc(sizeof(struct edge));
  new_edge->bus_line = malloc(strlen(buffer)+1);
  new_edge->travel_from = malloc(sizeof(struct node));
  new_edge->travel_from->name = malloc(strlen(buffer)+1); 
  new_edge->travel_to = malloc(sizeof(struct node));
  new_edge->travel_to->name =malloc(strlen(buffer)+1); 
  new_edge->travel_time = malloc(strlen(buffer)+1);
  
  return new_edge;
}
*/

Node allocateNode (void) {
  Node new_node = malloc(sizeof(struct node)); 
  new_node->name = malloc(strlen(buffer)+1);
  new_node->route = malloc(sizeof(struct edge));
  new_node->route->bus_line = malloc(strlen(buffer)+1); 
  new_node->next = malloc(sizeof(struct node));
  new_node->next->name = malloc(strlen(buffer)+1); 
  new_node->start_time = malloc(strlen(buffer)+1);
  return new_node;
}

//HYBRIS


Node makeAllNodes(char* filename) {
  FILE* database = fopen(filename, "r");
  Node node_list = NULL;
  while (!(feof(database))){
    Node new_node = allocateNode();
    makeNode(database, new_node);
    new_node->next = node_list;
    node_list = new_node;
  }
  return node_list;
}


/*

void makeGraph() {         
  
}
*/


int main(int argc, char* argv[]){
  //welcomeScreen();
  //char* edgefile = argv[1];
  char* nodefile = argv[1];
  //Edge new_edge = allocateEdge();
  makeAllNodes(nodefile);
  //makeEdge(edgefile, new_edge);

  return 1;
}





// createNode
// Error if already exists, otherwise append to top of list
// Uses arguments (previous_bus_stops, new_bus_stop)
// Does *NOT* work, need to replace x with the list of busstops...
// Not sure what to return from the function either. A list of all busstops and their buslines?

/*     FUCK YOUR FUNCTION NIGGA

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


*/

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


/*
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


*/

// argv will have 3 arguments:
// 1. the programme itself
// 2. A file containing nodes (Busline, stop, starting times)
// 3. A file containing edges (Busline, stop1, stop2, time taken to travel between)

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

