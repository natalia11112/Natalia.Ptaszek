#include "Textures.h"

void Textures::utworzMape(){
    std::vector<Textures> textures(13);
    std::fstream file("Resources/Pliki_txt/TEX.txt");
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
void Textures::mapa_plik1(){
    std::string linia;
    std::fstream plik("Resources/Pliki_txt/Mapa1.txt");
    if(plik.is_open()){
        for(int i=0; i<m_height; i++){
            plik>>linia;
            mapka1.emplace_back(linia);
        }
    }
}
void Textures::mapa_plik2(){
    std::string linia;
    std::fstream plik("Resources/Pliki_txt/Mapa2.txt");
    if(plik.is_open()){
        for(int i=0; i<m_height; i++){
            plik>>linia;
            mapka2.emplace_back(linia);
        }
    }
}
void Textures::mapa_plik3(){
    std::string linia;
    std::fstream plik("Resources/Pliki_txt/Mapa3.txt");
    if(plik.is_open()){
        for(int i=0; i<m_height; i++){
            plik>>linia;
            mapka3.emplace_back(linia);
        }
    }
}
std::vector<sf::RectangleShape> Textures::wczytaj1 (){
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
std::vector<sf::RectangleShape> Textures::wczytaj2 (){
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
std::vector<sf::RectangleShape> Textures::wczytaj3 (){
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
void Textures::drawTex1(sf::RenderWindow &window){
    for(auto &rec : recs1){
        window.draw(rec);
    }
}
void Textures::drawTex2(sf::RenderWindow &window){
    for(auto &rec : recs2){
        window.draw(rec);
    }
}
void Textures::drawTex3(sf::RenderWindow &window){
    for(auto &rec : recs3){
        window.draw(rec);
    }
}
