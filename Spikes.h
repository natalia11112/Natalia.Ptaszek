#ifndef SPIKES_H
#define SPIKES_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Character.h"

class Spikes{
public:
    Spikes(){
        if(!SU.loadFromFile("Spike_Up.png")){
            std::cout<<"ERROR"<<std::endl;
        }
    }
    void spikes_plik1(){
        std::string linia;
        std::fstream plik("Spikes1.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                Spikees1.emplace_back(linia);
            }
        }
    }
    void spikes_plik2(){
        std::string linia;
        std::fstream plik("Spikes2.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                Spikees2.emplace_back(linia);
            }
        }
    }
    void spikes_plik3(){
        std::string linia;
        std::fstream plik("Spikes3.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                Spikees3.emplace_back(linia);
            }
        }
    }
    void spikes1(){
        spikes_plik1();
        spike.setScale(0.1, 0.1);
        spike.setTexture(SU);
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                spike.setPosition(j*25+6,i*25+18);
                if(Spikees1[i][j]=='0')
                    continue;
                if(Spikees1[i][j]=='1'){
                    Spiks1.emplace_back(spike);
                }
            }
        }
    }
    void spikes2(){
        spikes_plik2();
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                spike.setPosition(j*25+6,i*25+18);
                if(Spikees2[i][j]=='0')
                    continue;
                if(Spikees2[i][j]=='1'){
                    Spiks2.emplace_back(spike);
                }
            }
        }
    }
    void spikes3(){
        spikes_plik3();
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                spike.setPosition(j*25+6,i*25+18);
                if(Spikees3[i][j]=='0')
                    continue;
                if(Spikees3[i][j]=='1'){
                    Spiks3.emplace_back(spike);
                }
            }
        }
    }
    bool collision1(Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(auto &spi : Spiks1){
            auto boundr = spi.getGlobalBounds();
            if(bounds.intersects(boundr))
                return 1;
        }
        return 0;
    }
    bool collision2(Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(auto &spi : Spiks2){
            auto boundr = spi.getGlobalBounds();
            if(bounds.intersects(boundr))
                return 1;
        }
        return 0;
    }
    bool collision3(Character &cha){
        auto bounds = cha.getGlobalBounds();
        for(auto &spi : Spiks3){
            auto boundr = spi.getGlobalBounds();
            if(bounds.intersects(boundr))
                return 1;
        }
        return 0;
    }
    void drawspike1(sf::RenderWindow &window,Character &cha){
        for(auto &spi : Spiks1){
            window.draw(spi);
        }
        collision1(cha);
    }
    void drawspike2(sf::RenderWindow &window,Character &cha){
        for(auto &spi : Spiks2){
            window.draw(spi);
        }
        collision2(cha);
    }
    void drawspike3(sf::RenderWindow &window,Character &cha){
        for(auto &spi : Spiks3){
            window.draw(spi);
        }
        collision3(cha);
    }
private:
    sf::Sprite spike;
    std::vector<sf::Sprite> Spiks1;
    std::vector<sf::Sprite> Spiks2;
    std::vector<sf::Sprite> Spiks3;
    sf::Texture SU;
    int m_height = 16, m_width = 131;
    std::vector<std::string> Spikees1;
    std::vector<std::string> Spikees2;
    std::vector<std::string> Spikees3;
};

#endif // SPIKES_H
