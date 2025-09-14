#include <iostream>
#include <string>

class GameEntry;
class Scoreboard;

class GameEntry {
    private:
        std::string name;
        int score;

    public:
        GameEntry(const std::string& n="", int s=0);
        
        const std::string& get_name() const;
        
        int get_score() const;
};


GameEntry::GameEntry(const std::string& n, int s)
    : name{n}, score{s} {}

const std::string& GameEntry::get_name() const { 
    return name; 
}

int GameEntry::get_score() const { 
    return score; 
}

class Scoreboard {
    private:
        //dynamic memory GameEntry[cap]    
        GameEntry* board{nullptr};
        int capacity;       // capacity
        int num_entries{0}; // actual entries

    public:
        Scoreboard(int cap=10);
        int get_capacity() const;
        int get_num_entries() const;
        const GameEntry& get_entry(int i) const;
        void add(int score, const std::string& name);
        GameEntry remove(int i);
        ~Scoreboard(); // destructor
        // Copy/Move constructor (not now)
        // Copy/Move assignment operator (not now)
};

Scoreboard::Scoreboard(int capacity) 
    : capacity{capacity}, 
    board{new GameEntry[capacity]} {}

Scoreboard::~Scoreboard() {
    delete[] board;
}

int Scoreboard::get_capacity() const { 
    return this->capacity; 
}

int Scoreboard::get_num_entries() const { 
    return this->num_entries; 
}

const GameEntry& Scoreboard::get_entry(int i) const { 
    if (i<0 || i >= num_entries)
        throw std::out_of_range("Invalid index");
    return this->board[i];
}

// Attempts to add a new score to the scoreboard (if high enough)
void Scoreboard::add(int score, const std::string& name) {
    // is the new entry e really a high score?
    bool is_space{num_entries < capacity};
    auto lowest_score{0};
    if (num_entries > 0)
        lowest_score = board[num_entries - 1].get_score();
    bool is_new_score_higher{score > lowest_score};

    if (is_space || is_new_score_higher) {//OR
        if (is_space) // no drop
            num_entries++;

        // shift any lower scores rightward 
        int j{num_entries - 1}; //index for score
        while (j>0 && board[j-1].get_score() < score) {
            board[j] = board[j - 1];  //shift right
            j--;
        }
        //assignment is overloaded (temp stack object copied to heap)
        board[j] = GameEntry(name, score);
    }
}

// Removes and returns the scoreboard entry at index i
GameEntry Scoreboard::remove(int i) {
    if (i<0 || i>=num_entries) 
        throw std::out_of_range("Invalid index");
    GameEntry temp{board[i]}; // save the entry to return

    //start from index to be removed 
    //and shift right till num_entries
    for (int j{i}; j<num_entries-1; j++) //count up from i
        board[j] = board[j+1];
    num_entries--; //reduce the entries by 1
    return temp; // return deleted for confirmation
}

int main() {
    Scoreboard board(5);  // capacity of 5

    board.add(800, "P1"); board.add(650, "P2");
    board.add(400, "P3"); board.add(360, "P4");
    board.add(240, "P5");

    std::cout << "Current Scoreboard:\n";
    for (int i{0}; i<board.get_num_entries(); i++) {
        std::cout << i + 1 << ". " 
            << board.get_entry(i).get_name() << ": "
            << board.get_entry(i).get_score() << "\t";
    }

    board.add(700, "P3");

    std::cout << "\nUpdated Scoreboard:\n";
    for (int i{0}; i<board.get_num_entries(); i++) {
        std::cout << i + 1 << ". " 
            << board.get_entry(i).get_name() << ":"
            << board.get_entry(i).get_score() << "\t";
    }
    std::cout << "\n";
}
/*
Current Scoreboard:
1. P1: 800      2. P2: 650      3. P3: 400      4. P4: 360      5. P5: 240
Updated Scoreboard:
1. P1:800       2. P3:700       3. P2:650       4. P3:400       5. P4:360
*/