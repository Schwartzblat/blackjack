#include <iostream>
#include "Deck.cpp"
using namespace std;
const string shapes[] = {"undefined", "clubs", "spades", "hearts", "diamonds"};
const string values[] = {"undefined", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

void printCards(Card *cards, int size){
    for(int i=0;i<size;i++){
        cout<<values[cards[i].getValue()]<<" "<<shapes[cards[i].getShape()]<<endl;
    }
}

int sum(Card *cards, int size){
    int sum=0;
    int aces =0;
    for(int i=0;i<size;i++){
        if(cards[i].getValue()==1){
            aces++;
            sum+=11;
        }else if(cards[i].getValue()>=10){
            sum+=10;
        }else{
            sum+=cards[i].getValue();
        }
    }
    while(sum>21 && aces>0){
        sum=sum-10;
        aces--;
    }
    return sum;
}

int finish(){
    cout<<endl<<"press any key to exit"<<endl;
    cin.sync();
    cin.get();
    return 0;
}


int main() {
    Deck deck = *new Deck();

    deck.shuffle();
    Card *cards = deck.getCards();
    cout<< "To play the game press ENTER"<<endl;
    cin.ignore();

    int cardsCounter=0;
    int yourCardsCounter =0;
    int hisCardsCounter=0;

    Card *yours = new Card[20];
    Card *his = new Card[20];

    yours[yourCardsCounter] = cards[cardsCounter];
    yourCardsCounter++;
    cardsCounter++;
    cout<<"Your first card is: "<<values[yours[0].getValue()]<<" "<<shapes[yours[0].getShape()]<<endl;
    yours[yourCardsCounter] = cards[cardsCounter];
    yourCardsCounter++;
    cardsCounter++;
    cout<<"Your second card is: "<<values[yours[1].getValue()]<<" "<<shapes[yours[1].getShape()]<<endl<<endl;

    his[hisCardsCounter] = cards[cardsCounter];
    hisCardsCounter++;
    cardsCounter++;
    cout<<"Your opponent's first card is: "<<values[his[0].getValue()]<<" "<<shapes[cards[0].getShape()]<<endl;
    his[hisCardsCounter] = cards[cardsCounter];
    hisCardsCounter++;
    cardsCounter++;

    int yourSum = sum(yours, yourCardsCounter);
    cout<<"The sum of your cards is "<<yourSum<<endl;
    if (yourSum==21){
        cout<<"You win";
        return finish();
    }
    bool running = true;
    int input;
    while(running) {
        cout << "To hit, enter 0\nTo Stand, enter 1\n";
        cin>>input;
        if(input==0){
            yours[yourCardsCounter] = cards[cardsCounter];
            yourCardsCounter++;
            cardsCounter++;
            cout<<"Your cards now:"<<endl<<endl;
            printCards(yours, yourCardsCounter);
            cout<<endl;
            yourSum = sum(yours, yourCardsCounter);
            cout<<"the sum of your cards is "<<yourSum<<endl;
            if(yourSum>21){
                cout<<"You lost";
                return finish();
            }else if(yourSum==21){
                cout<<"You win";
                return finish();
            }
        }else{
            running = false;
        }
    }
    yourSum = sum(yours, yourCardsCounter);
    cout<<"Your final sum is "<<yourSum<<endl<<endl;

    int hisSum = sum(his, hisCardsCounter);
    cout<<"CPU have this cards:"<<endl;
    printCards(his,hisCardsCounter);
    cout<<endl<<"His sum is "<<hisSum<<endl;

    while(hisSum<22 && hisSum<yourSum){
        his[hisCardsCounter] = cards[cardsCounter];
        cout<<"CPU choose HIT and his new card is: "<<values[his[hisCardsCounter].getValue()]<<" "<<shapes[his[hisCardsCounter].getShape()]<<endl;
        hisCardsCounter++;
        cardsCounter++;
        hisSum = sum(his, hisCardsCounter);
        cout<<"CPU's sum is "<<hisSum<<endl;
    }
    if(hisSum>21||yourSum>hisSum){
        cout<<"You win";
        return finish();
    }
    cout<<"You lost";    
    return finish();
}
