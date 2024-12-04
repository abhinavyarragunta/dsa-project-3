#include <string>
#include <vector>
using namespace std;

class Movie {
private:
    string name;
    vector<string> genres;

public:
    Movie(string n) {name = n;}

    bool operator==(const Movie& other) const {return (this->name == other.name);}
    bool operator<(const Movie& other) const {return (this->name < other.name);}

    string getName() {return name;}
    vector<string> getGenres() {return genres;}

    void addGenre(string genre) {genres.push_back(genre);}
};