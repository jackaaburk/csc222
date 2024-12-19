#include <string>

using namespace std;

enum Suit { NONE, CLUBS, DIAMONDS, HEARTS, SPADES };
enum Rank { JOKER, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, 
            NINE, TEN, JACK, QUEEN, KING, ACE };

struct Card
{
    Suit suit;
    Rank rank;

    Card();
    Card(int s, int r);

    bool operator==(const Card&) const;
    bool operator>(const Card&) const;
    bool operator<(const Card&) const;
    bool operator>=(const Card&) const;
    bool operator<=(const Card&) const;
    bool operator!=(const Card&) const;
    string to_string() const;
};

struct Deck {
    vector<Card> cards;

    Deck(int size);
    Deck();
    
    void print() const;
    void shuffle();
    void sort();
    Deck subdeck(int l, int h) const;
    void add_card(const Card& c);
    Card remove_card();
    void swap_cards(int i, int j);
};