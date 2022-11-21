#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "videogame.h"
#include "music.h"
#include "movie.h"

using namespace std;

void add(vector<Media*> &database);
void search(vector <Media*> &database, char * nameToSearch);
void del(vector <Media*> &database, char * nameToDelete);

int main() {

  vector<Media*> database;
  char input[10];
  char * name = new char[20];
  
  cout << "Welcome to your Media Database!" << endl;
  cout << endl;
  cout << "Type \"ADD\" to add a media." << endl;
  cout << "Type \"SEARCH\" to search for and print out a media." << endl;
  cout << "Type \"DELETE\" to delete a media." << endl;
  cout << "Type \"QUIT\" to quit." << endl;

  do {
    cout << endl;
    cout << "Enter a command: ";
    cin.get(input, 10);
    cin.get();
    if (strcmp(input, "ADD") == 0) {
      add(database);
    }
    else if (strcmp(input, "SEARCH") == 0) {
      cout << endl;
      cout << "Enter the title of the media you want to search for: ";
      cin.get(name, 20);
      cin.get();
      search(database, name);
    }
    else if (strcmp(input, "DELETE") == 0) {
      cout << endl;
      cout << "Enter the title of the media you want to delete: ";
      cin.get(name, 20);
      cin.get();
      del(database, name);
    }
    else if (strcmp(input, "QUIT") == 0) {
      cout << endl;
      cout << "This program has ended." << endl;
    }
    else {
      cout << "You didn't enter a valid command!" << endl;
    }
  } while (strcmp(input, "QUIT") != 0);

  return 0;
  
}

void add(vector<Media*> &database) {

  char * name = new char[20];
  int year = 0;
  int mediaType = 0;

  cout << endl;
  cout << "1) Video game" << endl;
  cout << "2) Music" << endl;
  cout << "3) Movie" << endl;
  cout << endl;
  
  do {
  cout << "Enter the media type you wish to add to your database (# from above): ";
  cin >> mediaType;
  cin.get();
  if (mediaType < 1 || mediaType > 3) {
    cout << endl;
    cout << "You did not enter a valid choice! Try again." << endl;
  }
  cout << endl;
  } while (mediaType < 1 || mediaType > 3);
  
  cout << "Enter the name of the media: ";
  cin.getline(name, 20);
  cout << endl;

  cout << "Enter the year when the media released: ";
  cin >> year;
  cin.get();
  cout << endl;

  if (mediaType == 1) {
    //add a videogame
    char * publisher = new char[20];
    int rating = 0;
    cout << "Enter the publisher of the media: ";
    cin.getline(publisher, 20);
    cout << endl;
    cout << "Enter the rating of the media (1-5): ";
    cin >> rating;
    cin.get();
    cout << endl;
    Videogame* videogame = new Videogame(name, year, publisher, rating, mediaType);
    database.push_back(videogame);
  }
  else if (mediaType == 2) {
    //add music
    char * publisher = new char[20];
    int duration = 0;
    char * artist = new char[20];
    cout << "Enter the publisher of the media: ";
    cin.getline(publisher, 20);
    cout << endl;
    cout << "Enter the duration of the media (in minutes): ";
    cin >> duration;
    cin.get();
    cout << endl;
    cout << "Enter the artist of the media: ";
    cin.getline(artist, 20);
    cout << endl;
    Music* music = new Music(name, year, publisher, duration, artist,
			     mediaType);
    database.push_back(music);
  }
  else if (mediaType == 3) {
    //add a movie
    char * director = new char[20];
    int duration = 0;
    int rating = 0;
    cout << "Enter the director of the media: ";
    cin.getline(director, 20);
    cout << endl;
    cout << "Enter the duration of the media (in minutes): ";
    cin >> duration;
    cout << endl;
    cout << "Enter the rating of the media (1-5): ";
    cin >> rating;
    cin.get();
    cout << endl;
    Movie* movie = new Movie(name, year, director, duration, rating,
			     mediaType);
    database.push_back(movie);
   }

  cout << "Media has been successfully added." << endl;
  
}

void search(vector <Media*> &database, char * nameToSearch) {

  int match = 0;
  
  vector<Media*>::iterator ptr;
  cout << endl;
  for (ptr = database.begin(); ptr < database.end(); ptr++) {
    if ((*ptr)->getId() == 1) {
      Videogame* videogame = static_cast<Videogame*>(*ptr);
        if (strcmp(nameToSearch, videogame->getName()) == 0) {     
	  videogame->print();
	  match++;
	}
    }
    else if ((*ptr)->getId() == 2) {
      Music* music = static_cast<Music*>(*ptr);
        if (strcmp(nameToSearch, music->getName()) == 0) {
          music->print();
          match++;
        }
    }
    else if ((*ptr)->getId() == 3) {
      Movie* movie = static_cast<Movie*>(*ptr);
        if (strcmp(nameToSearch, movie->getName()) == 0) {
          movie->print();
          match++;
        }
    }
  }

  if (match == 0) {
    cout << "No media in your database matched the name you entered." << endl;
  }
  
}

void del(vector <Media*> &database, char * nameToDelete) {

  int deleted = 0;
  int cont = 0;

  vector<Media*>::iterator ptr;
  cout << endl;
  for (ptr = database.begin(); ptr < database.end(); ptr++) {
    if ((*ptr)->getId() == 1) {
      Videogame* videogame = static_cast<Videogame*>(*ptr);
      if (strcmp(nameToDelete, videogame->getName()) == 0) {
	cout << "Here is the media you are about to delete:" << endl;
	cout << endl;
	videogame->print();
	cout << endl;
      }
    }
    else if ((*ptr)->getId() == 2) {
      Music* music = static_cast<Music*>(*ptr);
      if (strcmp(nameToDelete, music->getName()) == 0) {
        cout << "Here is the media you are about to delete:" << endl;
        cout << endl;
        music->print();
        cout << endl;
      }
    }
    else {
      Movie* movie = static_cast<Movie*>(*ptr);
      if (strcmp(nameToDelete, movie->getName()) == 0) {
        cout << "Here is the media you are about to delete:" << endl;
        cout << endl;
        movie->print();
        cout << endl;
      }
    }
    cout << "Enter 1 if you want to delete this media, enter 2 if not: ";	   cin >> cont;
    cin.get();
    if (cont == 1) {
      delete *ptr;
      database.erase(ptr);
      cout << endl;
      cout << "Media Successfully deleted" << endl;
      deleted++;
      break;
    }
    else {
      cout << endl;
      cout << "The media was not deleted" << endl;
      deleted++;
      break;
    }
  }

  if (deleted == 0) {
    cout << "No media in your database matched the name you entered." << endl;
  }

  
}
