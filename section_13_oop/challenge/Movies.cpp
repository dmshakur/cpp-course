#include "Movies.h"

void Movies::get_all_movies() {
  std::cout << std::endl;
  for (auto movie: all_movies)
    std::cout << movie.get_movie() << std::endl;
  std::cout << std::endl;
}

void Movies::add_movie(std::string title_value, std::string mpaa_rating_value, int user_rating_value, int watched_value) {
  all_movies.push_back(Movie(title_value, mpaa_rating_value, user_rating_value, watched_value));
}

void Movies::search(std::string search_query) {
  for (auto movie: all_movies) {
    if (movie.get_title() == search_query) {
      std::cout << movie.get_movie() << std::endl;
      return;
    }
  }
  std::cout << "No matches" << std::endl;
}
