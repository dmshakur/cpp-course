#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

class Movie {
private:
  std::string title;
  int user_rating;
  int watched;
  std::string mpaa_rating;
public:
  std::string get_title() {return title;}
  std::string get_movie();
  Movie(std::string title_value, std::string mpaa_rating_value, int user_rating_value, int watched_value);
};

#endif
