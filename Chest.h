#ifndef CHEST_H
#define CHEST_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

class Chest : public sf::Sprite{
public:
    Chest();
    void open(const float &deltaTime, Character &cha);
    void reset();
    void drawChest(sf::RenderWindow &window, Chest &chest, Character &cha, const float &deltaTime);
    bool ifopened(int i);
    void clear();
private:
    sf::Texture chest;
    float switchTime = 0.2f;
    int imageCount = 9;
    int currentImage = 0;
    float totalTime = 0.0f;
    int width = 173;
    int height = 184;
    std::vector<int> opened = {0,0,0};
};

#endif // CHEST_H
