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
    void enemies_plik1(){
        std::string linia;
        std::fstream plik("Enemies1.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                Venemy1.emplace_back(linia);
            }
        }
    }
    void enemies_plik2(){
        std::string linia;
        std::fstream plik("Enemies2.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                Venemy2.emplace_back(linia);
            }
        }
    }
    void enemies_plik3(){
        std::string linia;
        std::fstream plik("Enemies3.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                Venemy3.emplace_back(linia);
            }
        }
    }
    void enemies1(){
        enemies_plik1();
        enemy.setTexture(mace);
        enemy.setScale(0.390625, 0.390625);
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                enemy.setPosition(j*25,i*25);
                if(Venemy1[i][j]=='0')
                    continue;
                if(Venemy1[i][j]=='1')
                    VenemiesNew1.emplace_back(enemy);
            }
        }
        Venemies1 = VenemiesNew1;
    }
    void enemies2(){
        enemies_plik2();
        enemy.setTexture(mace);
        enemy.setScale(0.390625, 0.390625);
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                enemy.setPosition(j*25,i*25);
                if(Venemy2[i][j]=='0')
                    continue;
                if(Venemy2[i][j]=='1')
                    VenemiesNew2.emplace_back(enemy);
            }
        }
        Venemies2 = VenemiesNew2;
    }
    void enemies3(){
        enemies_plik3();
        enemy.setTexture(mace);
        enemy.setScale(0.390625, 0.390625);
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                enemy.setPosition(j*25,i*25);
                if(Venemy3[i][j]=='0')
                    continue;
                if(Venemy3[i][j]=='1')
                    VenemiesNew3.emplace_back(enemy);
            }
        }
        Venemies3 = VenemiesNew3;
    }
    void drawenemy1(sf::RenderWindow &window,Character &cha){
        for(auto &ven : Venemies1){
            window.draw(ven);
        }
        collisionWithPosrac1(cha);
    }
    void drawenemy2(sf::RenderWindow &window,Character &cha){
        for(auto &ven : Venemies2){
            window.draw(ven);
        }
        collisionWithPosrac2(cha);
    }
    void drawenemy3(sf::RenderWindow &window,Character &cha){
        for(auto &ven : Venemies3){
            window.draw(ven);
        }
        collisionWithPosrac3(cha);
    }
    void falldown1(Character &cha, const sf::Time &elapsed){
        for(unsigned int i=0; i<Venemies1.size(); i++){
            if(cha.zwrocPozycje().x+50>=Venemies1[i].getPosition().x && cha.zwrocPozycje().y<=Venemies1[i].getPosition().y+143)
                fallen1[i] = true;
            if(height1[i]>0 && fallen1[i] == 1){
                Venemies1[i].move(0,velocity_y*elapsed.asSeconds());
                height1[i]= height1[i]-velocity_y*elapsed.asSeconds();
            }
        }
    }
    void falldown2(Character &cha, const sf::Time &elapsed){
        for(unsigned int i=0; i<Venemies2.size(); i++){
            if(cha.zwrocPozycje().x+50>=Venemies2[i].getPosition().x && cha.zwrocPozycje().y<=Venemies2[i].getPosition().y+143)
                fallen2[i] = true;
            if(height2[i]>0 && fallen2[i] == 1){
                Venemies2[i].move(0,velocity_y*elapsed.asSeconds());
                height2[i]= height2[i]-velocity_y*elapsed.asSeconds();
            }
        }
    }
    void falldown3(Character &cha, const sf::Time &elapsed){
        for(unsigned int i=0; i<Venemies3.size(); i++){
            if(cha.zwrocPozycje().x+50>=Venemies3[i].getPosition().x && cha.zwrocPozycje().y<=Venemies3[i].getPosition().y+143)
                fallen3[i] = true;
            if(height3[i]>0 && fallen3[i] == 1){
                Venemies3[i].move(0,velocity_y*elapsed.asSeconds());
                height3[i]= height3[i]-velocity_y*elapsed.asSeconds();
            }
        }
    }
    bool collisionWithPosrac1(Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(auto &ven : Venemies1){
            auto boundr = ven.getGlobalBounds();
            if(bounds.intersects(boundr))
                return 1;
        }
        return 0;
    }
    bool collisionWithPosrac2(Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(auto &ven : Venemies2){
            auto boundr = ven.getGlobalBounds();
            if(bounds.intersects(boundr))
                return 1;
        }
        return 0;
    }
    bool collisionWithPosrac3(Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(auto &ven : Venemies3){
            auto boundr = ven.getGlobalBounds();
            if(bounds.intersects(boundr))
                return 1;
        }
        return 0;
    }
    void wyzeruj1(){
        fallen1 = {0,0};
        height1 = {135,135};
        Venemies1 = VenemiesNew1;
    }
    void wyzeruj2(){
        fallen2 = {0,0,0,0};
        height2 = {135, 135, 135, 135};
        Venemies2 = VenemiesNew2;
    }
    void wyzeruj3(){
        fallen3 = {0,0,0,0,0,0,0,0,0,0};
        height3 = {135, 135, 135, 135, 135, 135, 135, 135, 135, 135};
        Venemies3 = VenemiesNew3;
    }
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
