#include "Movie.h"

Movie::Movie(std::string title_value, int user_rating_value, int watched_value, std::string mpaa_rating_value)
  : title{title_value}, user_rating{user_rating_value}, watched{watched_value}, mpaa_rating{mpaa_rating_value} {
}

std::string Movie::get_movie() {
  return "Title: " + title + ", MPAA Rating: " + mpaa_rating + ", User Rating: " + user_rating + ", Watched: " + watched;
}
