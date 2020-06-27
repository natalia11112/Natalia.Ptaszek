#include "Tablica_wynikow.h"

Tablica_wynikow::Tablica_wynikow(){
    setSize(sf::Vector2f(700, 400));
    setFillColor(sf::Color(229,222,211));
    if(!font.loadFromFile("Resources/Czcionka/Font.ttf")){
        std::cout<<"ERROR"<<std::endl;
    }
    name.setFont(font);
    name.setFillColor(sf::Color::Black);
    name.setString("Tablica najlepszych: ");
    name.setPosition(sf::Vector2f(200, 30));
    name.setCharacterSize(40);
}
void Tablica_wynikow::drawt(sf::RenderWindow &window, Tablica_wynikow &tab){
    window.draw(tab);
    window.draw(name);
}
void Tablica_wynikow::wpisz_imie(sf::RenderWindow &window, sf::Event &event){
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
std::string Tablica_wynikow::returnImie(){
    return input;
}
void Tablica_wynikow::wyzeruj(){
    input.clear();
}
void Tablica_wynikow::wczytajWyniki(){
    std::string linia;
    std::fstream plik("Resources/Pliki_txt/Najlepsze Wyniki.txt");
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

void Tablica_wynikow::wynikiNaText(){
    wczytajWyniki();
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
std::vector<sf::Text> Tablica_wynikow::zwraca1(){
    return Lead1;
}
std::vector<sf::Text> Tablica_wynikow::zwraca2(){
    return Lead2;
}
std::vector<sf::Text> Tablica_wynikow::zwraca3(){
    return Lead3;
}
