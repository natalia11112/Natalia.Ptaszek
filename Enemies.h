#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Character.h"
#include "Textures.h"

class Enemies{
public:
    Enemies();
    void enemies_plik1();
    void enemies_plik2();
    void enemies_plik3();
    void enemies1();
    void enemies2();
    void enemies3();
    void drawenemy1(sf::RenderWindow &window,Character &cha);
    void drawenemy2(sf::RenderWindow &window,Character &cha);
    void drawenemy3(sf::RenderWindow &window,Character &cha);
    void falldown1(Character &cha, const sf::Time &elapsed);
    void falldown2(Character &cha, const sf::Time &elapsed);
    void falldown3(Character &cha, const sf::Time &elapsed);
    bool collisionWithPosrac1(Character &cha);
    bool collisionWithPosrac2(Character &cha);
    bool collisionWithPosrac3(Character &cha);
    void wyzeruj1();
    void wyzeruj2();
    void wyzeruj3();
private:
    sf::Texture mace;
    sf::Sprite enemy;
    std::vector<std::string> Venemy1;
    std::vector<std::string> Venemy2;
    std::vector<std::string> Venemy3;
    std::vector<sf::Sprite> Venemies1;
    std::vector<sf::Sprite> Venemies2;
    std::vector<sf::Sprite> Venemies3;
    std::vector<sf::Sprite> VenemiesNew1;
    std::vector<sf::Sprite> VenemiesNew2;
    std::vector<sf::Sprite> VenemiesNew3;
    int m_height=16,m_width=136;
    std::vector<float> height1 = {135, 135};
    std::vector<float> height2 = {135, 135, 135, 135};
    std::vector<float> height3 = {135, 135, 135, 135, 135, 135, 135, 135, 135, 135};
    float velocity_y = 100;
    std::vector<int> fallen1 = {0,0};
    std::vector<int> fallen2 = {0,0,0,0};
    std::vector<int> fallen3 = {0,0,0,0,0,0,0,0,0,0};
    std::vector<sf::RectangleShape> texs;
};

#endif // ENEMIES_H
