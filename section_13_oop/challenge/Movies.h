#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <string>
#include <vector>
#include "Movie.h"

class Movies {
private:
  std::vector<Movie> all_movies;
public:
  void get_all_movies();
  void add_movie(std::string title_value, std::string mpaa_rating_value, int user_rating_value, int watched_value);
  void search(std::string search_query);
  // Movies();
};

#endif
