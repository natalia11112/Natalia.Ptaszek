#ifndef TABLICA_WYNIKOW_H
#define TABLICA_WYNIKOW_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Tablica_wynikow : public sf::RectangleShape{
public:
    Tablica_wynikow(){
        setSize(sf::Vector2f(700, 400));
        setFillColor(sf::Color(229,222,211));
        if(!font.loadFromFile("Font.ttf")){
            std::cout<<"ERROR"<<std::endl;
        }
        name.setFont(font);
        name.setFillColor(sf::Color::Black);
        name.setString("Tablica najlepszych: ");
        name.setPosition(sf::Vector2f(200, 30));
        name.setCharacterSize(40);

    }
    struct Dane{
        std::string nazwa;
        int punkty;
    };
    void drawt(sf::RenderWindow &window, Tablica_wynikow &tab){
        window.draw(tab);
        window.draw(name);
    }

private:
    std::vector<Dane> tablica;
    std::vector<sf::Text> teksty;
    sf::Text name;
    sf::Font font;


};

#endif // TABLICA_WYNIKÓW_H
