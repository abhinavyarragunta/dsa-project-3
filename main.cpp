#include <iostream>
#include "graph_recommender.cpp"
//#include "hash_recommender.cpp"
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
    // Replace "movies.csv" with the path to your CSV file
    string csvFilePath = "movie_genre_description.txt";
    vector<Movie> movies = createMoviesFromAPI(csvFilePath);
    for (int i = 0; i < 4; i++) {
        cout << movies[i].getName() << " " << movies[i].getGenre() << " " << movies[i].getDescription() << endl;
    }

    // THE FOLLOWING IS EXAMPLE CODE
    // IT IS ONLY THERE TO TEST THE CSV PARSING WORKING CORRECTLY
    // Example: Display the parsed data
    /*for (const auto& [movie, genres] : movies) {
        std::cout << "Movie: " << movie << "\nGenres: ";
        for (const std::string& genre : genres) {
            std::cout << genre << " ";
        }
        std::cout << std::endl;
    }
    // END OF CSV PARSING TEST
*/
    while (true) {
        std::cout << """  _____                                   _____ _      _        \n"
                     " |  __ \\                                 |  __ (_)    | |       \n"
                     " | |__) |__  _ __   ___ ___  _ __ _ __   | |__) |  ___| | _____ \n"
                     " |  ___/ _ \\| '_ \\ / __/ _ \\| '__| '_ \\  |  ___/ |/ __| |/ / __|\n"
                     " | |  | (_) | |_) | (_| (_) | |  | | | | | |   | | (__|   <\\__ \\\n"
                     " |_|   \\___/| .__/ \\___\\___/|_|  |_| |_| |_|   |_|\\___|_|\\_\\___/\n"
                     "            | |                                                 \n"
                     "            |_|  \n""";

        std::cout << "Please choose which data structure you would like to use: (1) hash map (2) graph\n";
        std::cout << "Choose an option (1, 2)\n\n";
        //todo: if 1, use hashRecommender function
        //todo: if 2, use graphRecommender function

        //options below are already implemented in respective functions
        std::cout << "1. Create Account\n";
        std::cout << "2. List Movies\n";
        std::cout << "3. Quit\n";
        std::cout << "Choose an option (1, 2, 3): ";
        break;
    }
        return 0;
}
