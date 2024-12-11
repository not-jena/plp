#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Song {
    private:
        std::string title;
        std::string artist;
        std::string genre;
        Song* next;

    public:
        Song(const std::string& t, const std::string& a, const std::string& g)
            : title(t), artist(a), genre(g), next(nullptr) {}

        std::string getTitle() const { return title; } //access my song details
        std::string getArtist() const { return artist; }
        std::string getGenre() const { return genre; }
        Song* getNext() const { return next; }

        void setNext(Song* n) { next = n; }

        //display song
        void display() const {
            std::cout << "Title: " << title << ", Artist: " << artist << ", Genre: " << genre << "\n";
        }

    public:
    //to compare genres
    bool compareTo(const Song& other) const {
        return genre == other.genre; // true if the genres are equal, false if not
    }
};

class Playlist { //my linked list
    private:
        Song* head;
        Song* tail;

    public:
        Playlist() : head(nullptr), tail(nullptr) {}

        //destruct
        ~Playlist() {
            Song* current = head;
            while (current) {
                Song* toDelete = current;
                current = current->getNext();
                delete toDelete;
            }
        }

    //add a song to playlist
    void addSong(const std::string& title, const std::string& artist, const std::string& genre) {
        Song* newSong = new Song(title, artist, genre);
        if (!head) { //if the playlist is empty
            head = newSong; //make the song the new head and tail
            tail = newSong;
        } else {
            tail->setNext(newSong); //else add it to the end of the list
            tail = newSong;
        }
    }

    //load PLPfinal.csv
    //trim my genre because i was having issues with my genre not matching the recommendations
    std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}


    void loadFromCSV(const std::string& filename) { //updated to parse and get rid of any extra spaces or special characters
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string title, artist, genre;

        
        std::getline(ss, title, ',');
        title = trim(title);
        std::getline(ss, artist, ',');
        artist = trim(artist);
        std::getline(ss, genre, ',');
        genre = trim(genre);

        // Add the song to the playlist
        addSong(title, artist, genre);
    }

    file.close();
    }


    //display my playlist
    void display() const {
        if (!head) {
            std::cout << "The playlist is empty.\n";
            return;
        }

        Song* current = head;
        while (current) { //transverse the playlist
            current->display();
            current = current->getNext();
        }
    }

    std::string findMostPopularGenre() const {
        if (!head) 
            return "No songs in the playlist :(";

        std::string mostPopularGenre;
        int maxCount = 0;

        Song* current = head;
        while (current) {
            int count = 0;
            Song* inner = head;
            while (inner) { //inner look to compare genre to other songs
                if (current->compareTo(*inner)) {
                    count++; //add to count
                }
                inner = inner->getNext();
            }
            if (count > maxCount) {
                maxCount = count;
                mostPopularGenre = current->getGenre();
            }
            current = current->getNext(); 
        }
        return mostPopularGenre;
    }


    std::string recommendSong() const {
    std::string popularGenre = findMostPopularGenre();
    //std::cout << "Debug: Popular Genre is [" << popularGenre << "]\n"; WORKING NOW!!!!!

    if (popularGenre == "No songs in the playlist") { 
        return "No songs in the playlist";
    } else if (popularGenre == "Indie") {
        return "My recommended song for you is 'ingydar' by Adrianne Lenker";
    } else if (popularGenre == "Rock") {
        return "My recommended song for you is 'Jigsaw Falling into Place' by Radiohead";
    } else if (popularGenre == "Country") {
        return "My recommended song for you is 'Do I Ever Cross Your Mind' by Chet Atkins";
    } else if (popularGenre == "Pop") {
        return "My recommended song for you is 'Talk' by beabadoobee";
    } else {
        return "No specific recommendation for this genre.";
    }}
};

int main() {
    Playlist playlist;

    std::string filename = "PLPfinal.csv";

    playlist.loadFromCSV(filename);

    std::cout << "\nSongs in the playlist:\n";
    playlist.display();

    std::cout << "Most Popular Genre: " << playlist.findMostPopularGenre() << std::endl;

    std::cout << playlist.recommendSong() << std::endl;

    return 0;
}
