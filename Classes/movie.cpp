#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

Movie::Movie(char * name, int year, char * director, int duration,
             int rating, int id) {
  strcpy(this->name, name);
  this->year = year;
  type = new char[20];
  strcpy(type, "Movie");
  strcpy(this->director, director);
  this->duration = duration;
  this->rating = rating;
  this->id = id;
}

Movie::~Movie() {
  delete director;
}

void Movie::print() {
  cout << "Type: " << type << endl;
  cout << "Name: " << name << endl;
  cout << "Year: " << year << endl;
  cout << "Director: " << director << endl;
  cout << "Duration: " << duration << " minutes" << endl;
  cout << "Rating: " << rating << endl;
}
