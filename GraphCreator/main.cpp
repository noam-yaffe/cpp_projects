/*
Noam Yaffe
06/08/2023
In this program, I created a graph from nodes (vertices) and edges, all of which are contained and displayed through an adjacency matrix.
 */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void addEdge(int graphTable[][20], vector<char*> vertices, char* v1, char* v2, int weight);
vector<char*> removeVertex(vector<char*> vertices, char* vertex);
void removeEdge(int graphTable[][20], vector<char*> vertices, char* v1, char* v2);
void print(int graphTable[][20], vector<char*> vertices);

int main() {

  cout << "test" << endl;
  
  vector<char*> vertices;
  int graphTable[20][20];

  //initialize adjacency table
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      graphTable[i][j] = -1;
    }
  }
  
  char* vertex = new char[1];
  int weight = 0;
  
  char* input = new char[20];

  //instructions
  cout << "Welcome to Graph Creator! Here are the commands that you can use:" << endl;
  cout << endl;
  cout << "Type \"ADD VERTEX\" to add a labeled vertex to the graph." << endl;
  cout << "Type \"ADD EDGE\" to add an edge to the graph, connecting two vertices." << endl;
  cout << "Type \"REMOVE VERTEX\" to remove a vertex from the graph." << endl;
  cout << "Type \"REMOVE EDGE\" to remove an edge from the graph." << endl;
  cout << "Type \"PRINT\" to print out the graph's adjacency table" << endl;
  cout << "Type \"QUIT\" to end the program." << endl;
  
  do {
    
    cout << endl;
    cout << "Enter a command: ";
    cin.get(input, 20);
    cin.get();
    
    if (strcmp(input, "ADD VERTEX") == 0) {//add a vertex to the graph
      cout << endl;
      cout << "Enter a label for the vertex (one new character): ";
      cin >> vertex;
      cin.get();
      vertices.push_back(vertex);
      cout << endl;
      cout << "Vertex successfully added!" << endl;
      vertex = new char[1];
    }
    else if (strcmp(input, "ADD EDGE") == 0) {//add an edge connecting two vertices to the graph
      char* v1 = new char[1];
      char* v2 = new char[1];
      cout << endl;          
      cout << "Enter the first vertex's label: ";
      cin >> v1;
      cin.get();
      cout << "Enter the second vertex's label: ";
      cin >> v2;
      cin.get();
      cout << "Enter the weight of the edge: ";
      cin >> weight;
      cin.get();
      addEdge(graphTable, vertices, v1, v2, weight);
    }
    else if (strcmp(input, "REMOVE VERTEX") == 0) {//remove a vertex from the graph
      cout << endl;
      cout << "Enter the label of the vertex you want to remove: ";
      cin >> vertex;
      cin.get();
      vertices = removeVertex(vertices, vertex);
      vertex = new char[1];
    }
    else if (strcmp(input, "REMOVE EDGE") == 0) {//remove an edge form the graph
      cout << endl;
      char* v1 = new char[1];
      char* v2 = new char[1];
      cout << "Enter the first vertex's label: ";
      cin >> v1;
      cin.get();
      cout << "Enter the second vertex's label: ";
      cin >> v2;
      cin.get();
      removeEdge(graphTable, vertices, v1, v2);
    }
    else if (strcmp(input, "PRINT") == 0) {//call print method
      cout << endl;
      print(graphTable, vertices);
    }
    else if (strcmp(input, "QUIT") == 0) {//end the progrm
      cout << endl;
      cout << "The program has ended." << endl;
    }
    else {//invalid command
      cout << endl;
      cout << "You didn't enter a valid command!" << endl;
    }
    
  } while (strcmp(input, "QUIT") != 0);//program has ended
  
  return 0;
  
}

//adds an edge to the adjacency table
void addEdge(int graphTable[][20], vector<char*> vertices, char* v1, char* v2, int weight) {
  
  int counter = 0;
  
  int r, c = 0;
  
  vector<char*>::iterator itr;
  for (itr = vertices.begin(); itr < vertices.end(); itr++) {
    if (strcmp(*itr, v1) == 0) {
      c = counter;
    }
    if (strcmp(*itr, v2) == 0) {
      r = counter;
    }
    counter++;
  }
  
  graphTable[r][c] = weight;
  
}

//removes a vertex from the adjacency table
vector<char*> removeVertex(vector<char*> vertices, char* vertex) {
  
  vector<char*>::iterator itr;
  for (itr = vertices.begin(); itr < vertices.end(); itr++) {
    if (strcmp(*itr, vertex) == 0) {
      vertices.erase(itr);
      cout << endl;
      cout << "Vertex successfully deleted!" << endl;
      break;
    }
  }
  
  return vertices;

}

//removes an edge from the adjacency table
void removeEdge(int graphTable[][20], vector<char*> vertices, char* v1, char* v2) {

  int counter = 0;
  
  int r, c = 0;
  
  vector<char*>::iterator itr;
  for (itr = vertices.begin(); itr < vertices.end(); itr++) {
    if (strcmp(*itr, v1) == 0) {
      c = counter;
    }
    if (strcmp(*itr, v2) == 0) {
      r = counter;
    }
    counter++;
  }
  
  graphTable[r][c] = -1;
  
}

//prints out the adjacency table
void print(int graphTable[][20], vector<char*> vertices) {

  for (int i = 0; i < vertices.size(); i++) {
    cout << "   " << vertices.at(i);
  }
  cout << endl;
  
  for (int rows = 0; rows < vertices.size(); rows++) {
    cout << vertices.at(rows);
    for (int columns = 0; columns < vertices.size(); columns++) {
      cout << "  " << graphTable[rows][columns];
    }
    cout << endl;
  }
  
}
