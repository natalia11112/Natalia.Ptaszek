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
    Coin();
    void coins_plik1();
    void coins_plik2();
    void coins_plik3();
    void drawCoins1();
    void drawCoins2();
    void drawCoins3();
    void collisionWithCharacter1(sf::RenderWindow &window, Character &cha);
    void collisionWithCharacter2(sf::RenderWindow &window, Character &cha);
    void collisionWithCharacter3(sf::RenderWindow &window, Character &cha);
    void wyzeruj1();
    void wyzeruj2();
    void wyzeruj3();
    void wyzeruj4();
    int punkty();
    void ifOpened(Chest &chest);
    void changePointsToLives(Character &cha);
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
    std::vector<int> usun1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> usun2 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> usun3 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> dodatki={0,0};
    int points = 0;
};

#endif // COIN_H
