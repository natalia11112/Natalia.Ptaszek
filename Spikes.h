#ifndef SPIKES_H
#define SPIKES_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Character.h"

class Spikes{
public:
    Spikes();
    void spikes_plik1();
    void spikes_plik2();
    void spikes_plik3();
    void spikes1();
    void spikes2();
    void spikes3();
    bool collision1(Character &cha);
    bool collision2(Character &cha);
    bool collision3(Character &cha);
    void drawspike1(sf::RenderWindow &window,Character &cha);
    void drawspike2(sf::RenderWindow &window,Character &cha);
    void drawspike3(sf::RenderWindow &window,Character &cha);
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
