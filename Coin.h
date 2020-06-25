#ifndef COIN_H
#define COIN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <numeric>
#include "Character.h"

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
    void collisionWithCharacter(sf::RenderWindow &window, Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(unsigned int i=0; i<Coins.size(); i++){
            auto boundr = Coins[i].getGlobalBounds();
            if(bounds.intersects(boundr)){
                usun[i]=1;
            }
            if(usun[i]==0)
                window.draw(Coins[i]);
        }
    }
    void wyzeruj(){
        usun = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    }
    int punkty(){
        points = std::accumulate(usun.begin(), usun.end(), 0);
        return points;
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
    std::vector<int> usun = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int points = 0;
};

#endif // COIN_H
