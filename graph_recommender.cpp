#include "graph.cpp"
using namespace std;

MoviesGraph createGraphWithGenreToMovieEdges(vector<Movie> allMovies) {
    MoviesGraph popPicker;
    for (auto movie : allMovies)
        popPicker.addMovieToGenre(movie.getGenre(), movie);
    return popPicker;
}

void useGraphRecommender(vector<Movie> allMovies) {
    MoviesGraph popPicker = createGraphWithGenreToMovieEdges(allMovies);

    cout << "Please enter a username: " << endl;
    string username;
    cin >> username;
    popPicker.addUser(username);

    cout << "Enter your favorite movie genres. Enter 'q' when finished." << endl;
    string genre_input;
    vector<string> preferredGenres;

    do {
        cin >> genre_input;
        if (genre_input != "q") {
            cout << "Added " << genre_input << endl;
            preferredGenres.push_back(genre_input);
        }
    } while (genre_input != "q");

    cout << "All genres added." << endl;
    for (auto pref : preferredGenres)
        cout << pref << endl;

    popPicker.addPreferences(username, preferredGenres);

    string input_action = "";
    while (input_action != "3") {
        cout << "Type the corresponding number for which action you want to take." << endl;
        cout << "1. Recommend Movies" << endl;
        cout << "2. Add User" << endl;
        cout << "3. Quit" << endl;
        cin >> input_action;
        cin.ignore(); // Clear buffer before getline usage

        if (input_action == "1") {
            vector<string> commonGenres = popPicker.getCommonPrefs();
            set<Movie> commonMovies = popPicker.getCommonMovies(commonGenres);
            if (commonMovies.empty()) {
                cout << "No common movies found." << endl;
                continue;
            }

            for (auto movie : commonMovies)
                cout << "-" << movie.getName() << endl;

            string targetMovie;
            do {
                cout << "Type movie name and year for more information or type 'q' to go back." << endl;
                getline(cin, targetMovie);
                if (targetMovie != "q") {
                    bool found = false;
                    for (auto movie : commonMovies) {
                        if (movie.getName() == targetMovie) {
                            cout << movie.getDescription() << endl << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "Movie not found. Please try again." << endl;
                }
            } while (targetMovie != "q");

        } else if (input_action == "2") {
            cout << "Please enter a username:" << endl;
            cin >> username;
            popPicker.addUser(username);

            cout << "Enter your favorite movie genres. Enter 'q' when finished." << endl;
            preferredGenres.clear();

            do {
                cin >> genre_input;
                if (genre_input != "q") {
                    cout << "Added " << genre_input << endl;
                    preferredGenres.push_back(genre_input);
                }
            } while (genre_input != "q");

            cout << "All genres added." << endl;
            popPicker.addPreferences(username, preferredGenres);

        } else if (input_action == "3") {
            cout << "Goodbye." << endl;
        } else {
            cout << "Not a recognized command. Try again." << endl;
        }
    }
}
