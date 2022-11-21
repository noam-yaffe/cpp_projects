#include <iostream>
#include <cstring>
#include "videogame.h"

using namespace std;

Videogame::Videogame(char * name, int year, char * publisher, int rating, int id) {
  strcpy(this->name, name);
  this->year = year;
  type = new char[20];
  strcpy(type, "Video game");
  strcpy(this->publisher, publisher);
  this->rating = rating;
  this->id = id;
}

Videogame::~Videogame() {
  delete publisher;
}

void Videogame::print() {
  cout << "Type: " << type << endl;
  cout << "Name: " << name << endl;
  cout << "Year: " << year << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Rating: " << rating << endl;
}
