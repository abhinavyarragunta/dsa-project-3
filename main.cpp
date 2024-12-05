#include <iostream>
#include "graph_recommender.cpp"
#include "hash_recommender.cpp"
#include "hash_map.cpp"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<Movie> createMoviesFromAPI(string filename) {
    vector<Movie> movies;
    ifstream file(filename);
    string line;
    const string delimiter = " ::: ";

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return movies;
    }

    while (getline(file, line)) {
        vector<string> fields;
        int start = 0;
        int end = line.find(delimiter);

        while (end != string::npos) {
            fields.push_back(line.substr(start, end - start));
            start = end + delimiter.length();
            end = line.find(delimiter, start);
        }
        fields.push_back(line.substr(start));

        string title = fields[1];
        string genre = fields[2];
        string description = fields[3];

        Movie newMovie(title, genre, description);
        movies.push_back(newMovie);
    }

    file.close();
    return movies;
}

int main() {
    string csvFilePath = "movie_genre_description.txt";
    vector<Movie> movies = createMoviesFromAPI(csvFilePath);

    while (true) {
        std::cout << """  _____                                   _____ _      _        \n"
                     " |  __ \\                                 |  __ (_)    | |       \n"
                     " | |__) |__  _ __   ___ ___  _ __ _ __   | |__) |  ___| | _____ \n"
                     " |  ___/ _ \\| '_ \\ / __/ _ \\| '__| '_ \\  |  ___/ |/ __| |/ / __|\n"
                     " | |  | (_) | |_) | (_| (_) | |  | | | | | |   | | (__|   <\\__ \\\n"
                     " |_|   \\___/| .__/ \\___\\___/|_|  |_| |_| |_|   |_|\\___|_|\\_\\___/\n"
                     "            | |                                                 \n"
                     "            |_|  \n""";

        std::cout << "Please choose which data structure you would like to use: (1) graph (2) hash map\n";
        std::cout << "Choose an option (1, 2)\n";

        string dataStructureChoice;
        cin >> dataStructureChoice;
        if (dataStructureChoice == "1") useGraphRecommender(movies);
        else if (dataStructureChoice == "2") useHashRecommender(movies);
        else cout << "Data Structure not available." << endl;

    }
}
