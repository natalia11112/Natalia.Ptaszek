#ifndef MAPA_H
#define MAPA_H
#include<vector>
#include<string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Tile.h>
#include <map>

class mapa{
public:

    void load(std::vector<Textures> &tex, std::vector<sf::Texture> &text) {
        for(int i=0; i<13; i++){
        if(!text[i].loadFromFile(tex[i].nazwapliku)){std::cout<<"ERROR";}
        }
    }
    std::map<char,sf::Texture> create_map(std::vector<Textures> &tex, std::vector<sf::Texture> &text){
        for (int i=0; i<13; i++){
            teksturki.emplace(tex[i].znaktex, text[i]);
        }
        return teksturki;
    }
    std::vector<sf::RectangleShape> prostokaty (){
        sf::Vector2f v1(25,25);
        rectangle.setSize(v1);
        for(int i=0; i<m_height; i++){
            for(int j=0; j<m_width; j++){
                rectangle.setPosition(j*v1.x,i*v1.y);
                if(mapka[i][j]==' ')
                    continue;
                for(auto it = teksturki.begin(); it !=teksturki.end(); it++){
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
    std::string name = "DIRT";
    sf::Texture grassCL;
    sf::Texture grassCM;
    sf::Texture grassCR;
    sf::Texture grassL;
    sf::Texture grassM;
    sf::Texture grassR;
    sf::Texture dirtL;
    sf::Texture dirt;
    sf::Texture dirtD;
    sf::Texture dirtR;
    sf::Texture dirtLC;
    sf::Texture dirtRC;
    std::map<char,sf::Texture> teksturki;
    std::string wyraz = "Grass.png";
    std::vector<sf::RectangleShape> recs;
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
    int m_height=16,m_width=56;
};


#endif // MAPA_H
