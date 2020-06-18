#ifndef TILE_H
#define TILE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
class Textures {
public:
    char znaktex;
    std::string nazwapliku;
    std::vector<sf::RectangleShape> wczytaj (){
        sf::Context context;

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
            rectangle.setSize(sf::Vector2f(25,25));
            for(int i=0; i<m_height; i++){
                for(int j=0; j<m_width; j++){
                    rectangle.setPosition(j*rectangle.getSize().x,i*rectangle.getSize().y);
                    if(mapka[i][j]==' ')
                        continue;
                    for(auto it = map_of_textures.begin(); it !=map_of_textures.end(); it++){
                        if (mapka[i][j]==it->first){
                            rectangle.setTexture(&it->second);
                            recs.emplace_back(rectangle);
                        }
                    }
                }
            }
            return recs;
        }

private: 
    sf::Texture texture;
    std::map<char,sf::Texture> map_of_textures;
    std::vector<std::string> mapka ={
        "                                                        ",
        "                                                        ",
        "                                                        ",
        "                                                        ",
        "                 0                                      ",
        "                                                        ",
        "               0                                        ",
        "                                                        ",
        "             0                                          ",
        "                                                        ",
        "       12223          123           0       0          4",
        "                                                      48",
        "                                        0          45588",
        "45556                         4556              45588888",
        "78889                         7889              78888889",
        "ABBBC                         ABBC              ABBBBBBC",
    };
    sf::RectangleShape rectangle;
    std::vector<sf::RectangleShape> recs;
    int m_height=16,m_width=56;
};
#endif // TILE_H
