#include "Chest.h"

Chest::Chest(){
    if(!chest.loadFromFile("Resources/Pliki_png/Chest.png")){
        std::cout<<"ERROR"<<std::endl;
    }
    setTexture(chest);
    setTextureRect(sf::IntRect(59,269,width,height));
    setScale(0.28901734, 0.28901734);
    setPosition(3350,325);
}
void Chest::open(const float &deltaTime, Character &cha){
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
void Chest::reset(){
    currentImage = 0;
    setTextureRect(sf::IntRect(59,269,width,height));
}
void Chest::drawChest(sf::RenderWindow &window, Chest &chest, Character &cha, const float &deltaTime){
    window.draw(chest);
    chest.open(deltaTime, cha);
}
bool Chest::ifopened(int i){
    return opened[i];
}
void Chest::clear(){
    opened={0,0,0};
}
