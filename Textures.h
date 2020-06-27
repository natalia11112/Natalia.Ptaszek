#ifndef TILE_H
#define TILE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
class Textures : public sf::RectangleShape{
public:
    void utworzMape();
    void mapa_plik1();
    void mapa_plik2();
    void mapa_plik3();
    std::vector<sf::RectangleShape> wczytaj1 ();
    std::vector<sf::RectangleShape> wczytaj2 ();
    std::vector<sf::RectangleShape> wczytaj3 ();
    void drawTex1(sf::RenderWindow &window);
    void drawTex2(sf::RenderWindow &window);
    void drawTex3(sf::RenderWindow &window);
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
