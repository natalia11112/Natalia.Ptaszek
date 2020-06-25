#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Character.h"
#include "Textures.h"
#include "Menu.h"

class Enemies{
public:
    Enemies(){
        if(!mace.loadFromFile("Mace.png")){
            std::cout<<"ERROR"<<std::endl;
        }
    }
    void enemies_plik(){
        std::string linia;
        std::fstream plik("Enemies.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                Venemy.emplace_back(linia);
            }
        }
    }
    void enemies(){
        enemies_plik();
        enemy.setTexture(mace);
        enemy.setScale(0.390625, 0.390625);
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                enemy.setPosition(j*25,i*25);
                if(Venemy[i][j]=='0')
                    continue;
                if(Venemy[i][j]=='1')
                    VenemiesNew.emplace_back(enemy);
            }
        }
        Venemies = VenemiesNew;
    }
    void drawenemy(sf::RenderWindow &window,Character &cha){
        for(auto &ven : Venemies){
            window.draw(ven);
        }
        collisionWithPosrac(cha);
    }
    void falldown(Character &cha, const sf::Time &elapsed){

        for(unsigned int i=0; i<Venemies.size(); i++){
            if(cha.zwrocPozycje().x+50>=Venemies[i].getPosition().x && cha.zwrocPozycje().y<=Venemies[i].getPosition().y+143)
                fallen[i] = true;
            if(height[i]>0 && fallen[i] == 1){
                Venemies[i].move(0,velocity_y*elapsed.asSeconds());
                height[i]= height[i]-velocity_y*elapsed.asSeconds();
            }
        }
    }
    bool collisionWithPosrac(Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(auto &ven : Venemies){
            auto boundr = ven.getGlobalBounds();
            if(bounds.intersects(boundr))
                return 1;
        }
        return 0;
    }
    void wyzeruj(){
        fallen = {0,0};
        height = {135,135};
        Venemies = VenemiesNew;
    }
private:
    sf::Texture mace;
    sf::Sprite enemy;
    std::vector<std::string> Venemy;
    std::vector<sf::Sprite> Venemies;
    std::vector<sf::Sprite> VenemiesNew;
    int m_height=16,m_width=108;
    std::vector<float> height = {135, 135};
    float velocity_y = 100;
    std::vector<int> fallen = {0,0};
    std::vector<sf::RectangleShape> texs;
};

#endif // ENEMIES_H
