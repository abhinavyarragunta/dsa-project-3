🎥 **Popcorn Picks**

Introduction:
Are you having trouble deciding on a movie to watch with your friends or by yourself? Introducing Popcorn Picks! This program provides personalized movie recommendations based on your favorite genres. Whether you're watching solo or with friends, Popcorn Picks helps you find movies that align with your shared preferences. Simply enter your favorite genres, and Popcorn Picks will curate a list of movies that fit your needs!

Graph Implementation Features:
1. Movie Storage & Interconnected:
Graph can store User, Genre, or Movie nodes in tripartite form. Users can only connect to Genres, and Genres can only connect to Movies.
2. Multi-User Scale:
New User nodes and edges to Genre nodes can be added in constant time complexity. The entire recommendation and intersection algorithm can account for any number of users and genres.

Using Graph PopcornPicker:
1. Create initial User Profile with username, list genre preferences and press 'q' when finished.
2. Choose to Recommend Movies, Add User, Quit
   Recommend Movies will list all movies with the genres that the users prefer
   Add User will create new User Profile with same process (future movie recommendations will be from the intersection of all users' preferred genre)
3. After Recommended Movie list, input a movie [Name (Year)] to return an in-depth description of the movie
4. Repeat process

Hashtable Implementation Features:
1. Movie Storage & Management
Efficient Movie Storage: Movies are stored in a hash table, with the movie title as the key and the genre as the value. This allows for fast lookups and efficient retrieval of movie information.
Resizable Hash Table: The system dynamically resizes the hash table as more movies are added, ensuring that the program remains efficient even when handling large datasets (10,000+ movies).
2. Genre-Based Search
Search by Title: You can quickly search for a movie by its title to retrieve its genre.
Search by Genre: The system supports searching for all movies of a specific genre, making it easier to explore films within your preferred category.
3. Personalized Recommendations
Shared Genre Preferences: If you're watching with friends, Popcorn Picks can take input from multiple users and determine the genres they all share.
Movie Recommendations: Based on the genres common among all users, Popcorn Picks generates a list of movies that match these shared genres, ensuring that everyone will find something they enjoy.
4. Optimized for Large Datasets
The program uses a custom hash table implementation, optimized with linear probing and dynamic resizing, to ensure fast and efficient operations even with thousands of entries.
5. Scalable for Multiple Users
You can input genre preferences for multiple users. The system will then calculate shared genres among all users and recommend movies accordingly.

Using Popcorn Picks - Hashtable Implementation:

Insert Movies: The program starts by loading a predefined dataset of movies into the hash table. Each movie is added with its title (key) and genre (value). This happens automatically when you run the program.
Provide User Preferences Once the movies are loaded, you'll be prompted to enter the genres that you and your friends enjoy. You can input multiple users' genres.

For each user, type in the genres they enjoy
Type "q" when you're done entering genres for that user.
After entering all users' genres, type "done" to stop adding users.

After collecting the genres from all users, Popcorn Picks will:

Find the genres that are common across all users.
Recommend movies that match these shared genres.
If no common genres are found, the system will notify you and suggest trying again with different genres.
The program will display a list of movie recommendations based on the shared genres. If no movies match the selected genres, the program will inform you that there are no recommendations at this time.

**Graph vs. Hash Table Time Complexity: Hash Table is faster because of its insertion and search method being of constant computational complexity.**

In order to run the code in this repository, first clone the repository on to your local device, this can be through downloading it as a zip.
Next, if you want to use a g++ complier. Run the following commands in order to execute the program:

"g++ main.cpp movie.cpp -c"

"g++ main.o movie.o -o program"

"program"

We hope you enjoy the program and find some new movies to watch! 
