#ifndef TABLICA_WYNIKOW_H
#define TABLICA_WYNIKOW_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ostream>
#include <fstream>
#include <algorithm>
#include "Coin.h"

class Tablica_wynikow : public sf::RectangleShape{
public:
    Tablica_wynikow();
    void drawt(sf::RenderWindow &window, Tablica_wynikow &tab);
    void wpisz_imie(sf::RenderWindow &window, sf::Event &event);
    std::string returnImie();
    void wyzeruj();
    void wczytajWyniki();
    void wynikiNaText();
    std::vector<sf::Text> zwraca1();
    std::vector<sf::Text> zwraca2();
    std::vector<sf::Text> zwraca3();
private:
    std::vector<std::pair<int, std::string>> tablica;
    std::pair<int, std::string> para;
    std::vector<sf::Text> teksty;
    sf::Text name;
    sf::Font font;
    sf::RectangleShape pros;
    sf::Text wpisz;
    sf::Text imie;
    sf::Text aa;
    sf::Text ab;
    sf::Text ac;
    std::vector<sf::Text> Lead1;
    std::vector<sf::Text> Lead2;
    std::vector<sf::Text> Lead3;
    std::string input;
    bool released = true;
    sf::Text points;
    std::vector<int> liczby={1,2,3,4,5,6,7,8,9,10};
};

#endif // TABLICA_WYNIKÓW_H
