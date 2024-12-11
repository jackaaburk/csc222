#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Card {
    int suit, rank;

    Card();
    Card(int s, int r);
    string to_string() const;
    bool operator==(const Card& c2) const;
    bool operator>(const Card& c2) const;
    bool operator<=(const Card& c2) const;
};

Card::Card() : suit(0), rank(0) {}

Card::Card(int s, int r) : suit(s), rank(r) {}

string Card::to_string() const {
    vector<string> suit_strings = {"None", "Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> rank_strings = {"Joker", "Ace", "2", "3", "4", "5", "6", "7", 
                                    "8", "9", "10", "Jack", "Queen", "King"};
    if (rank == 0) 
        return rank_strings[rank];
    return rank_strings[rank] + " of " + suit_strings[suit];
}

bool Card::operator==(const Card& c2) const {
    return (rank == c2.rank && suit == c2.suit);
}

bool Card::operator>(const Card& c2) const {
    if (suit > c2.suit) return true;
    if (suit < c2.suit) return false;
    return rank > c2.rank;
}

bool Card::operator<=(const Card& c2) const {
    return !(this->operator>(c2));
}

int main() {
    Card card1(2, 11), card2(2, 9);
    cout << (card1 > card2) << endl;
    cout << (card1 <= card2) << endl;
    return 0;
}