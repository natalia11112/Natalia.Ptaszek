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
            released = 0;
        }
        if(event.type == sf::Event::KeyReleased && released ==0){
            released = 1;
        }
        imie.setString(input);
        window.draw(imie);

    }
    std::string returnImie(){
        return input;
    }
    void wyzeruj(){
        input.clear();
    }
    void wczytajWyniki(){
        std::string linia;
        std::fstream plik("Najlepsze Wyniki.txt");
        if(plik.is_open()){
            while(!plik.eof()){
                plik>>para.second>>para.first;
                tablica.emplace_back(para);
            }
            tablica.erase(tablica.end()-1);
            std::sort(tablica.begin(), tablica.end());
            std::reverse(tablica.begin(), tablica.end());
        }
    }

    void wynikiNaText(){
        wczytajWyniki();
        if(!font.loadFromFile("Font.ttf")){
            std::cout<<"ERROR"<<std::endl;
        }
        aa.setFont(font);
        aa.setFillColor(sf::Color::Black);
        aa.setCharacterSize(25);
        ab.setFont(font);
        ab.setFillColor(sf::Color::Black);
        ab.setCharacterSize(25);
        ac.setFont(font);
        ac.setFillColor(sf::Color::Black);
        ac.setCharacterSize(25);
        for(int i=0; i<10; i++){
            aa.setString(std::to_string(liczby[i]));
            aa.setPosition(sf::Vector2f(100,80+i*30));
            Lead1.emplace_back(aa);
            ab.setString(tablica[i].second);
            ab.setPosition(sf::Vector2f(200,80+i*30));
            Lead2.emplace_back(ab);
            ac.setString(std::to_string(tablica[i].first));
            ac.setPosition(sf::Vector2f(350,80+i*30));
            Lead3.emplace_back(ac);
        }
    }
    std::vector<sf::Text> zwraca1(){
        return Lead1;
    }
    std::vector<sf::Text> zwraca2(){
        return Lead2;
    }
    std::vector<sf::Text> zwraca3(){
        return Lead3;
    }
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
