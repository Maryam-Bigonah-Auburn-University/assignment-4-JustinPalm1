#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
 private:
   string name;
   int score;
 public:
   Player() : name(""), score(0) {}
   Player(string newName, int newScore) : name(newName), score(newScore) {}
   void setName(string newName) {name = newName;}
   void setScore(int newScore) {score = newScore;}
   string getName() const {return name;}
   int getScore() const {return score;}
};
// Function to add a player
bool addPlayer(vector<Player>& players, const string& name, int score) {
    if (players.size() >= 10) {
        cout << "Cannot add more players. Maximum limit reached." << endl;
        return false;
    }
    players.emplace_back(name, score);
    return true;
}
// Function to print all players and their scores
void printPlayers(const vector<Player>& players) {
    cout << "Players and their scores:" << endl;
    for (const auto& player : players) {
        cout << "Name: " << player.getName() << ", Score: " << player.getScore() << endl;
    }
}

// Function to get a player's score by name
void getPlayerScore(const vector<Player>& players, const string& name) {
    for (const auto& player : players) {
        if (player.getName() == name) {
            cout << "Score of " << name << ": " << player.getScore() << endl;
            return;
        }
    }
    cout << "Player " << name << " not found." << endl;
}
// Function to remove a player by name
void removePlayer(vector<Player>& players, const string& name) {
    for (auto it = players.begin(); it != players.end(); ++it) {
        if (it->getName() == name) {
            players.erase(it);
            cout << "Player " << name << " removed." << endl;
            return;
        }
    }
    cout << "Player " << name << " not found." << endl;
}
int main() {
    vector<Player> players;
    string name;
    int score;
    int choice;

    while (true) {
        // Options for user
        cout << "\nMenu:\n";
        cout << "1. Add Player\n";
        cout << "2. Print Players\n";
        cout << "3. Get Player Score\n";
        cout << "4. Remove Player\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter player name: ";
                cin >> name;
                cout << "Enter player score: ";
                cin >> score;
                addPlayer(players, name, score);
                break;
            case 2:
                printPlayers(players);
                break;
            case 3:
                cout << "Enter player name to get score: ";
                cin >> name;
                getPlayerScore(players, name);
                break;
            case 4:
                cout << "Enter player name to remove: ";
                cin >> name;
                removePlayer(players, name);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
