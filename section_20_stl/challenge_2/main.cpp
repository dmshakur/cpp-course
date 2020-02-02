// Section 20
// Challenge 2
//  Lists
#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <sstream>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
  public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string set_name(std::string new_name) {
        name = new_name;
    }
    std::string set_artist(std::string new_artist) {
        artist = new_artist;
    }
    int set_rating(int new_rating) {
        rating = new_rating;
    }
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "\nPlaying:\n" << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    std::cout << std::endl;
    for (auto song : playlist)
        std::cout << song << (song == current_song ? " < current song\n" : "\n");
}

int main()
{
    std::list<Song> playlist {
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };

    auto current_song = playlist.begin();

    char input;

    while (input != 'q')
    {
        std::cout << std::endl;
        display_menu();
        std::cin >> input;

        tolower(input);

        switch(input)
        {
            case 'f':
                current_song = playlist.begin();
                break;
            case 'n':
                {
                    if (*current_song == playlist.back())
                        current_song = playlist.begin();
                    else
                        ++current_song;
                    play_current_song(*current_song);
                }
                break;
            case 'p':
                {
                    if (*current_song == playlist.front())
                        while (!(*current_song == playlist.back()))
                            ++current_song;
                    else
                        --current_song;
                    play_current_song(*current_song);
                }
                break;
            case 'a':
                {
                    Song temp;
                    std::string name, artist;
                    int rating;

                    std::cout << "\nEnter song info now, Song title: ";
                    std::cin >> name;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    temp.set_name(name);

                    std::cout << "\nEnter artist name: ";
                    std::cin >> artist;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    temp.set_artist(artist);

                    std::cout << "\nEnter 0-5 rating for song: ";
                    std::cin >> rating;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    temp.set_rating(rating);

                    playlist.emplace(current_song, name, artist, rating);
                    play_current_song(*current_song);
                }
                break;
            case 'l':
                display_playlist(playlist, *current_song);
                break;
            case 'q':
                break;
        }
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}