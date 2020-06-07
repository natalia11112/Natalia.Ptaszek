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
    std::vector<Textures> wczytaj (){
        std::vector<Textures> textures(13);
        std::fstream file("TEX.txt");
        if(file.is_open()){
            for (int i=0; i<13; i++){
                file>>textures[i].znaktex>>textures[i].nazwapliku;
            }
        }
        return textures;
    }
    std::vector<sf::Texture> text(){
        std::vector<sf::Texture> tex={grass, grassCL, grassCM, grassCR, grassL, grassM, grassR, dirtL, dirt, dirtR, dirtLC, dirtD, dirtRC};
        return tex;
    }
private: 
    std::string line;
    sf::Texture grass;
    sf::Texture grassCL;
    sf::Texture grassCM;
    sf::Texture grassCR;
    sf::Texture grassL;
    sf::Texture grassM;
    sf::Texture grassR;
    sf::Texture dirtL;
    sf::Texture dirt;
    sf::Texture dirtR;
    sf::Texture dirtLC;
    sf::Texture dirtD;
    sf::Texture dirtRC;

};
#endif // TILE_H
