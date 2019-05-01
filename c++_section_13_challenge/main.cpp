#include <iostream>
#include <vector>
#include <string>
#include "Movies.cpp"

using namespace std;

void add_movie_to_collection() {
  string title_value;
  string mpaa_rating_value;
  int user_rating_value;
  int watched_value;

  cout << "Please enter a title: ";
  cin >> title_value;
  cout << "Please enter the mpaa rating for the film: ";
  cin >> mpaa_rating_value;
  cout << "Please enter a numerical rating for the film: ";
  cin >> user_rating_value;
  cout << "Please enter a number representing the number of times you have seen the film in question: ";
  cin >> watched_value;

  user_collection.add_movie(title_value, mpaa_rating_value, user_rating_value, watched_value);
}

void user_menu() {

  char user_input;

  cout << "=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
  cout << "\nPlease enter one of the following" << endl;
  cout << "A: add a movie, S: show all movies, D: display a movies info, E: exit the program" << endl;
  cin >> user_input;

  if (user_input == 'A' || user_input == 'a') {
    add_movie_to_collection();
    user_menu();
  } else if (user_input == 'S' || user_input == 's') {
    user_collection.get_all_movies();
    user_menu();
  } else if (user_input == 'D' || user_input == 'd') {
    string search_query;
    cout << "Enter the movies name you wish to view: ";
    cin >> search_query;
    user_collection.search(search_query);
    user_menu();
  } else if (user_input == 'E' || user_input == 'e') {
    cout << "Exiting program now..." << endl;
    delete user_collection;
    return;
  } else {
    cout << "Invalid input" << endl;
    user_menu();
  }
}

int main() {

  Movies user_collection;

  cout << "\nWelcome to your personal film catalogue" << endl;
  user_menu();

  return 0;
}
