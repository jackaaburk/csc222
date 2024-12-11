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

vector<Card> create_deck() {
    vector<Card> deck(52);
    int i = 0;
    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
    return deck;
}

void print_deck(const vector<Card>& deck) {
    for (const Card& card : deck) {
        cout << card.to_string() << endl;
    }
}

int main() {
    vector<Card> deck = create_deck();
    print_deck(deck);
    return 0;
}