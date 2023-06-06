#include <iostream>
#include <cstring>

using namespace std;

int main() {

  //char vertices[20];
  //int graphTable[20][20];

  //char vertex;
  //int edge;
  
  char * input = new char[20];
  
  cout << "Welcome to Graph Creator! Here are the commands that you can use:" << endl;
  cout << endl;
  cout << "Type \"ADD VERTEX\" to add a labeled vertex to the graph." << endl;
  cout << "Type \"ADD EDGE\" to add an edge to the graph, connecting two vertices." << endl;
  cout << "Type \"REMOVE VERTEX\" to remove a vertex from the graph." << endl;
  cout << "Type \"REMOVE EDGE\" to remove an edge from the graph." << endl;
  cout << "Type \"QUIT\" to end the program." << endl;
  cout << endl;
  
  do {

    cout << "Enter a command: ";
    cin >> input;
    cin.get();
    
    if (strcmp(input, "ADD VERTEX")) {
      cout << "adding a vertex..." << endl;
    }
    else if (strcmp(input, "ADD EDGE")) {
      cout << "adding an edge..." << endl;
    }
    else if (strcmp(input, "REMOVE VERTEX")) {
      cout << "removing a vertex..." << endl;
    }
    else if (strcmp(input, "REMOVE EDGE")) {
      cout << "remove an edge..." << endl;
    }
    
  } while (strcmp(input, "QUIT") != 0);
   
  return 0;
  
}
