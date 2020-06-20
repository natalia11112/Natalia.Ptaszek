#ifndef COIN_H
#define COIN_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Coin : public sf::Sprite{
public:
    Coin(){}
    std::vector<sf::Sprite> drawCoins(){
        if(!coin.loadFromFile("Coin.png")){std::cout<<"ERROR"<<std::endl;}
        oneCoin.setTexture(coin);
        oneCoin.setScale(0.2, 0.2);
        oneCoin.setTextureRect(sf::IntRect(33,31,65,65));
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                oneCoin.setPosition(j*25+6,i*25+6);
                if(pozycje[i][j]==' ')
                    continue;
                if(pozycje[i][j]=='0')
                    Coins.emplace_back(oneCoin);
            }
        }
        return Coins;
    }
private:
    std::vector<std::string> pozycje ={
        "                                                                                                            ",
        "                                                                                                            ",
        "                                                                                                            ",
        "                 0                                                                                          ",
        "                                                                                       000                  ",
        "                                                                                                            ",
        "                                                                                   0                        ",
        "                                                                                                            ",
        "                                                                                                            ",
        "          0                                 0                                                               ",
        "                                                                                                            ",
        "                                                     00                                                     ",
        "                                                                                                            ",
        "                                                                   00                                       ",
        "                                                                                                   00       ",
        "                                                                                                            ",
    };
    sf::Texture coin;
    std::vector<sf::Sprite> Coins;
    //std::vector<int> draw = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    sf::Sprite oneCoin;
    int m_height=16,m_width=108;

};

#endif // COIN_H
