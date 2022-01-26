/*2.14*/
/* Happy Valentine 's Day! */
#include<iostream>

class Mate
{
    private:
    char *Eyes;
    char *Hair;
    char *Character;
    public:
    Mate(char *eyes,char *hair,char *character);
    void her()
    {
        std::cout<<"I wanna a girl with "<< Eyes <<" eyes ";
        std::cout<<"and "<< Hair <<" hair."<<std::endl;
        std::cout<<"But the most importantly she has a "<< Character <<" character."<<std::endl;
    }
};

Mate::Mate(char *eyes,char *hair,char *character)
{
    Eyes = eyes;
    Hair = hair;
    Character = character;
}
void LoveU(int times)
    {
        std::cout<<"I will love you "<< times <<" times"<<std::endl;
    }

int main()
{
    Mate Like((char*)"Big",(char*)"Black",(char*)"Sweet");
    Like.her();
    LoveU(3000);
    std::cout<<"Happy Valentine's Day!"<<std::endl;
    return 0;
}