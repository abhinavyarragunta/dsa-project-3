#include <iostream>
#include "parseMovies.h"
#include "hash_map.h"

int main() {
    // Replace "movies.csv" with the path to your CSV file
    std::string csvFilePath = "../moviedata.csv";
    std::unordered_map<std::string, std::vector<std::string>> movieMap = parseMovies(csvFilePath);

    // THE FOLLOWING IS EXAMPLE CODE
    // IT IS ONLY THERE TO TEST THE CSV PARSING WORKING CORRECTLY
    // Example: Display the parsed data
    for (const auto& [movie, genres] : movieMap) {
        std::cout << "Movie: " << movie << "\nGenres: ";
        for (const std::string& genre : genres) {
            std::cout << genre << " ";
        }
        std::cout << std::endl;
    }
    // END OF CSV PARSING TEST

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
    
        std::cout << "1. Create Account\n";
        std::cout << "2. List Movies\n";
        std::cout << "3. Quit\n";
        std::cout << "Choose an option (1, 2, 3): ";
        break;
    }
        return 0;
}
