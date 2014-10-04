// Hejsan hoppsan. V�lkommen till sprint 2. Jobba med Axel, Kom igen, det blir kul. 
// Helvete Johan

// Jag tyckte det var kul

#include <stdlib.h>
#include <stdio.h>


#include "readToBuffer.h"

typedef struct edge *Edge;
typedef struct node *Node;

struct edge {
  unsigned short bus_line;
  char* travel_from;
  char* travel_to;
  unsigned short travel_time;
  Node* prev_node;
  Node* next_node;
  Edge* connected_nodes_edges;
};



struct node {
  unsigned short bus_line;
  char* bus_stop;
  unsigned short start_time;
  Edge* adjacent_edges;
  Node* next_node;
};





int welcomescreen(void){
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
  

  welcomescreen();
  return 0;
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

