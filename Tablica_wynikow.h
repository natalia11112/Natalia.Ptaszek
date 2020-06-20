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
    void wpisz_imie(sf::RenderWindow &window, sf::Event &event){
        pros.setSize(sf::Vector2f(200,50));
        pros.setPosition(250,150);
        pros.setFillColor(sf::Color(229,222,211));
        wpisz.setFont(font);
        wpisz.setFillColor(sf::Color::Black);
        wpisz.setString("Wpisz imie do 8 znakow");
        wpisz.setPosition(sf::Vector2f(160,100));
        wpisz.setCharacterSize(35);
        window.draw(pros);
        window.draw(wpisz);
        imie.setFont(font);
        imie.setFillColor(sf::Color::Black);
        imie.setPosition(sf::Vector2f(260,160));
        imie.setCharacterSize(30);
        if(event.type == sf::Event::TextEntered && event.text.unicode> 33 && event.text.unicode < 127 && released == 1 && input.size()<8){
            input += static_cast<char>(event.text.unicode);

            imie.setString(input);
            std::cout<<input<<" ";

            released = 0;
        }
        if(event.type == sf::Event::KeyReleased && released ==0){
            released = 1;
        }
        window.draw(imie);

    }
    void wynik(){

    }

private:
    std::vector<Dane> tablica;
    std::vector<sf::Text> teksty;
    sf::Text name;
    sf::Font font;
    sf::RectangleShape pros;
    sf::Text wpisz;
    sf::Text imie;
    std::string input;
    bool released = true;
    sf::Text points;

};

#endif // TABLICA_WYNIKÓW_H
