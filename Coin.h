#ifndef COIN_H
#define COIN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <numeric>
#include <fstream>
#include "Character.h"
#include "Chest.h"

class Coin : public sf::Sprite{
public:
    Coin(){
        if(!coin.loadFromFile("Coin.png")){
            std::cout<<"ERROR"<<std::endl;
        }
    }
    void coins_plik1(){
        std::string linia;
        std::fstream plik("Coins1.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                pozycje1.emplace_back(linia);
            }
        }
    }
    void coins_plik2(){
        std::string linia;
        std::fstream plik("Coins2.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                pozycje2.emplace_back(linia);
            }
        }
    }
    void coins_plik3(){
        std::string linia;
        std::fstream plik("Coins3.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                pozycje3.emplace_back(linia);
            }
        }
    }
    void drawCoins1(){
        coins_plik1();
        oneCoin.setTexture(coin);
        oneCoin.setScale(0.2, 0.2);
        oneCoin.setTextureRect(sf::IntRect(33,31,65,65));
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                oneCoin.setPosition(j*25+6,i*25+6);
                if(pozycje1[i][j]=='0')
                    continue;
                if(pozycje1[i][j]=='1')
                    Coins1.emplace_back(oneCoin);
            }
        }
    }
    void drawCoins2(){
        coins_plik2();
        oneCoin.setTexture(coin);
        oneCoin.setScale(0.2, 0.2);
        oneCoin.setTextureRect(sf::IntRect(33,31,65,65));
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                oneCoin.setPosition(j*25+6,i*25+6);
                if(pozycje2[i][j]=='0')
                    continue;
                if(pozycje2[i][j]=='1')
                    Coins2.emplace_back(oneCoin);
            }
        }
    }
    void drawCoins3(){
        coins_plik3();
        oneCoin.setTexture(coin);
        oneCoin.setScale(0.2, 0.2);
        oneCoin.setTextureRect(sf::IntRect(33,31,65,65));
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                oneCoin.setPosition(j*25+6,i*25+6);
                if(pozycje3[i][j]=='0')
                    continue;
                if(pozycje3[i][j]=='1')
                    Coins3.emplace_back(oneCoin);
            }
        }
    }
    void collisionWithCharacter1(sf::RenderWindow &window, Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(unsigned int i=0; i<Coins1.size(); i++){
            auto boundr = Coins1[i].getGlobalBounds();
            if(bounds.intersects(boundr)){
                usun1[i]=1;
            }
            if(usun1[i]==0)
                window.draw(Coins1[i]);
        }
    }
    void collisionWithCharacter2(sf::RenderWindow &window, Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(unsigned int i=0; i<Coins2.size(); i++){
            auto boundr = Coins2[i].getGlobalBounds();
            if(bounds.intersects(boundr)){
                usun2[i]=1;
            }
            if(usun2[i]==0)
                window.draw(Coins2[i]);
        }
    }
    void collisionWithCharacter3(sf::RenderWindow &window, Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(unsigned int i=0; i<Coins3.size(); i++){
            auto boundr = Coins3[i].getGlobalBounds();
            if(bounds.intersects(boundr)){
                usun3[i]=1;
            }
            if(usun3[i]==0)
                window.draw(Coins3[i]);
        }
    }
    void wyzeruj1(){
        usun1 = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    }
    void wyzeruj2(){
        usun2 = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    }
    void wyzeruj3(){
        usun3 = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    }
    int punkty(){
        points = std::accumulate(usun1.begin(), usun1.end(), 0)+std::accumulate(usun2.begin(), usun2.end(), 0)+std::accumulate(usun3.begin(), usun3.end(), 0);
        return points;
    }
    void ifOpened(Chest &chest){
        if(chest.ifopened(0)==1)
            usun1[18]+=10;
        if(chest.ifopened(1)==1)
            usun2[25]+=15;
        if(chest.ifopened(2)==1)
            usun1[31]+=21;
    }
private:
    std::vector<std::string> pozycje1;
    std::vector<std::string> pozycje2;
    std::vector<std::string> pozycje3;
    sf::Texture coin;
    std::vector<sf::Sprite> Coins1;
    std::vector<sf::Sprite> Coins2;
    std::vector<sf::Sprite> Coins3;
    sf::Sprite oneCoin;
    int m_height=16,m_width=136;
    std::vector<int> usun1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> usun2 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> usun3 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int points = 0;
};

#endif // COIN_H
