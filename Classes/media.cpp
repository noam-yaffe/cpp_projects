#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media(char * name, int year) {
  strcpy(this->name, name);
  this->year = year;
}

Media::Media() {}

Media::~Media() {
  delete name;
}

char * Media::getName() {
  return name;
}

int Media::getYear() {
  return year;
}

int Media::getId() {
  return id;
}

void Media::print() {}
