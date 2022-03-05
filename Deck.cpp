#include "Card.cpp"
#include <bits/stdc++.h>
class Deck{
private:
    Card cards[52];
public:
    Deck(){
        for (int i = 1; i < 14; i++) {
            for (int j = 1; j < 5; j++) {
                this->cards[(i-1)*4+j-1] = *new Card(i, j);
            }
        }
    }
    void shuffle(){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(this->cards, this->cards + 52,
                std::default_random_engine(seed));
    }
    Card * getCards(){
        return this->cards;
    }




};
