/*
09/27/2022
Noam Yaffe
In this program, the user can make a list of student which includes each of the student's first and last names, their ID, and their GPA.
These components are determined by the user's input, and the user can choose to add or delete a certain student by giving their respective ID,
and can print our all of the students currently in the vector.
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

//struct for student data
struct Student {

  char first [20];
  char last[20];
  int id;
  float gpa;
  
};

//methods
void add(vector<Student*> &students);
void print(vector<Student*> &students);
void del(vector<Student*> &students, int idToDelete);

int main() {

  int idToDelete;
  char input[10];
  //vector that holds all the students
  vector<Student*> students;

  //welcome message and commands
  cout << "Welcome to StudentList! Here are the commands you can use:" << endl;
  cout << endl;
  cout << "Type \"ADD\" to add a student." << endl;
  cout << "Type \"DELETE\" to delete a student." << endl;
  cout << "Type \"PRINT\" to print out all the students." << endl;
  cout << "Type \"QUIT\" to quit." << endl;
  
  //where the user can start doing stuff
  do {
    //getting user input for the command
    cout << endl;
    cout << "Enter a command: ";
    cin.get(input, 10);
    cin.get();
    //checking what the command they entered is
    if (strcmp(input, "ADD") == 0) {
      add(students);
    }
    else if (strcmp(input, "DELETE") == 0) {
      cout << "Enter the ID of the student you want to remove: ";
      cin >> idToDelete;
      cin.get();
      del(students, idToDelete);
    }
    else if (strcmp(input, "PRINT") == 0) {
      print(students);
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << endl;
      cout << "This program has ended." << endl;
    }
    //if the user didn't enter a valid command
    else {
      cout << "You didn't enter a valid command!" << endl;
    }
  } while (strcmp(input, "QUIT") != 0);//only end the program when 
  
  return 0;
  
}

//method for adding a student to the vector
void add(vector<Student*> &students) {

  Student *student = new Student();

  cout << endl;
  cout << "First Name: ";
  cin >> student->first;
  cout << "Last Name: ";
  cin >> student->last;
  cout << "ID: ";
  cin >> student->id;
  cout << "GPA: ";
  cin >> student->gpa;
  students.push_back(student);
  cin.get();
  cout << endl;
  cout << "Student has been added." << endl;
  
}

//method for printing out all the students and their information from the vector
void print(vector<Student*> &students) {

  vector<Student*>::iterator ptr;
  cout << endl;
  cout << "Current students in the list:" << endl;
  for (ptr = students.begin(); ptr < students.end(); ptr++) {
    cout << endl;
    cout << "Name: " << (*ptr)->first << " " << (*ptr)->last << endl;
    cout << "ID: " << (*ptr)->id << endl;
    cout << setprecision(3) << "GPA: " << (*ptr)->gpa << endl;
  }
  
}

//method for deleting specific students from the vector, who are chosen through the id inputted by the user
void del(vector<Student*> &students, int idToDelete) {

  vector<Student*>::iterator ptr;
  for (ptr = students.begin(); ptr < students.end(); ptr++) {
    if ((*ptr)->id == idToDelete) {
      students.erase(ptr);
      cout << "Student has been deleted." << endl;
      break;
    }
  }

}
