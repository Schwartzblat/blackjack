class Card{
private:
    int value;
    int shape;
/*
 * 1-clubs
 * 2- spades
 * 3- hearts
 * 4- diamonds
 */
public:
    Card(int x, int y){
        this->value = x;
        this->shape = y;
    }
    Card(){
        this->value=0;
        this->shape=0;
    }
    int getShape() const{
        return this->shape;
    }
    int getValue() const{
        return this->value;
    }
    void setValue(int x){
        this->value = x;
    }
    void setShape(int x){
        this->shape = x;
    }
};
