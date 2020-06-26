#ifndef CHEST_H
#define CHEST_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"

class Chest : public sf::Sprite{
public:
    Chest(){
        if(!chest.loadFromFile("Chest.png")){
            std::cout<<"ERROR"<<std::endl;
        }
        setTexture(chest);
        setTextureRect(sf::IntRect(59,269,width,height));
        setScale(0.28901734, 0.28901734);
        setPosition(3350,325);
    }
    void open(const float &deltaTime, Character &cha){
        auto bounds = cha.getGlobalBounds();
        auto boundr = getGlobalBounds();
        if(bounds.intersects(boundr)){
            totalTime += deltaTime;
            if(totalTime >= switchTime){
                totalTime -= switchTime;
                if(currentImage<imageCount)
                    currentImage++;
            }
            setTextureRect(sf::IntRect(59+currentImage*width+currentImage*48,269,width,height));
            if(currentImage==8 && opened[0]==0)
                opened[0] = 1;
            else if(currentImage==8 && opened[1]==0)
                opened[1] = 1;
            else if(currentImage==8 && opened[2]==0)
                opened[2] = 1;
        }
    }
    void reset(){
        currentImage = 0;
        setTextureRect(sf::IntRect(59,269,width,height));
    }
    void drawChest(sf::RenderWindow &window, Chest &chest, Character &cha, const float &deltaTime){
        window.draw(chest);
        chest.open(deltaTime, cha);
    }
    bool ifopened(int i){
        return opened[i];
    }
    void clear(){
        opened={0,0,0};
    }
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
