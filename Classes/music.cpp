#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

Music::Music(char * name, int year, char * publisher, int duration,
	     char * artist, int id) {
  strcpy(this->name, name);
  this->year = year;
  type = new char[20];
  strcpy(type, "Music");
  this->duration = duration;
  strcpy(this->publisher, publisher);
  strcpy(this->artist, artist);
  this->id = id;
}

Music::~Music() {
  delete publisher;
  delete artist;
}

void Music::print() {
  cout << "Type: " << type << endl;
  cout << "Name: " << name << endl;
  cout << "Year: " << year << endl;
  cout << "Publisher: " << publisher;
  cout << "Duration: " << duration << " minutes" << endl;
  cout << "Artist: " << artist << endl;
}
