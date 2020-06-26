#ifndef TILE_H
#define TILE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
class Textures : public sf::RectangleShape{
public:
    void utworzMape(){
        std::vector<Textures> textures(13);
        std::fstream file("TEX.txt");
        if(file.is_open()){
            for (int i=0; i<13; i++){
                file>>textures[i].znaktex>>textures[i].nazwapliku;
            }
        }
        for (int i=0; i<13; i++){
            if (!texture.loadFromFile(textures[i].nazwapliku)){
                std::cout<<"ERROR"<<std::endl;
            }
            map_of_textures.emplace(textures[i].znaktex, texture);
        }
    }
    void mapa_plik1(){
        std::string linia;
        std::fstream plik("Mapa1.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                mapka1.emplace_back(linia);
            }
        }
    }
    void mapa_plik2(){
        std::string linia;
        std::fstream plik("Mapa2.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                mapka2.emplace_back(linia);
            }
        }
    }
    void mapa_plik3(){
        std::string linia;
        std::fstream plik("Mapa3.txt");
        if(plik.is_open()){
            for(int i=0; i<m_height; i++){
                plik>>linia;
                mapka3.emplace_back(linia);
            }
        }
    }
    std::vector<sf::RectangleShape> wczytaj1 (){
        mapa_plik1();
            rectangle.setSize(sf::Vector2f(25,25));
            for(int i=0; i<m_height; i++){
                for(int j=0; j<m_width; j++){
                    rectangle.setPosition(j*rectangle.getSize().x,i*rectangle.getSize().y);
                    if(mapka1[i][j]=='0')
                        continue;
                    for(auto it = map_of_textures.begin(); it !=map_of_textures.end(); it++){
                        if (mapka1[i][j]==it->first){
                            rectangle.setTexture(&it->second);
                            recs1.emplace_back(rectangle);
                        }
                    }
                }
            }
            return recs1;
        }
    std::vector<sf::RectangleShape> wczytaj2 (){
        mapa_plik2();
            rectangle.setSize(sf::Vector2f(25,25));
            for(int i=0; i<m_height; i++){
                for(int j=0; j<m_width; j++){
                    rectangle.setPosition(j*rectangle.getSize().x,i*rectangle.getSize().y);
                    if(mapka2[i][j]=='0')
                        continue;
                    for(auto it = map_of_textures.begin(); it !=map_of_textures.end(); it++){
                        if (mapka2[i][j]==it->first){
                            rectangle.setTexture(&it->second);
                            recs2.emplace_back(rectangle);
                        }
                    }
                }
            }
            return recs2;
        }
    std::vector<sf::RectangleShape> wczytaj3 (){
        mapa_plik3();
            rectangle.setSize(sf::Vector2f(25,25));
            for(int i=0; i<m_height; i++){
                for(int j=0; j<m_width; j++){
                    rectangle.setPosition(j*rectangle.getSize().x,i*rectangle.getSize().y);
                    if(mapka3[i][j]=='0')
                        continue;
                    for(auto it = map_of_textures.begin(); it !=map_of_textures.end(); it++){
                        if (mapka3[i][j]==it->first){
                            rectangle.setTexture(&it->second);
                            recs3.emplace_back(rectangle);
                        }
                    }
                }
            }
            return recs3;
        }
    void drawTex1(sf::RenderWindow &window){
        for(auto &rec : recs1){
            window.draw(rec);
        }
    }
    void drawTex2(sf::RenderWindow &window){
        for(auto &rec : recs2){
            window.draw(rec);
        }
    }
    void drawTex3(sf::RenderWindow &window){
        for(auto &rec : recs3){
            window.draw(rec);
        }
    }

private: 
    char znaktex;
    std::string nazwapliku;
    sf::Texture texture;
    std::map<char,sf::Texture> map_of_textures;
    std::vector<std::string> mapka1;
    std::vector<std::string> mapka2;
    std::vector<std::string> mapka3;
    sf::RectangleShape rectangle;
    std::vector<sf::RectangleShape> recs1;
    std::vector<sf::RectangleShape> recs2;
    std::vector<sf::RectangleShape> recs3;
    int m_height=16,m_width=136;
};
#endif // TILE_H
