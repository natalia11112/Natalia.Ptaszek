#ifndef MAPA_H
#define MAPA_H
#include<vector>
#include<string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Tile.h>

class mapa{
public:
    mapa(int width, int height){
        m_width = width;
        m_height = height;
    }

    std::vector<sf::RectangleShape> prostokaty (const sf::Texture &tex1, const sf::Texture &tex2){

        std::vector<std::string> mapka ={
            "               GGG    G         ",
            "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
            "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ",
        };
        std::vector<sf::RectangleShape> recs;
        sf::Vector2f v1(25,25);
        for(int i=0; i<3; i++){
            for(int j=0; j<32; j++){

                if (mapka[i][j]=='Z'){
                    rectangle.setTexture(&tex1);
                    rectangle.setPosition(j*25,325+i*25);
                    rectangle.setSize(v1);
                    recs.emplace_back(rectangle);
                }
                if(mapka[i][j]==' ')
                    continue;
                if (mapka[i][j]=='G'){
                    rectangle.setTexture(&tex2);
                    rectangle.setPosition(j*25,325+i*25);
                    rectangle.setSize(v1);
                    recs.emplace_back(rectangle);
                }
            }
        }
        return recs;
    }
private:

    sf::RectangleShape rectangle;
    int m_height,m_width;
};


#endif // MAPA_H
