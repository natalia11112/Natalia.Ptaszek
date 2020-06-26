#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Mapa.h>
#include <Textures.h>
#include <Character.h>
#include <vector>
#include "Menu.h"
#include "Enemies.h"
#include "Tablica_wynikow.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 400), "My window");
    std::ofstream zapis("Najlepsze Wyniki.txt", std::ios::app);
    Textures texture;
    texture.utworzMape();
    std::vector<sf::RectangleShape> recs1 = texture.wczytaj1();
    std::vector<sf::RectangleShape> recs2 = texture.wczytaj2();
    std::vector<sf::RectangleShape> recs3 = texture.wczytaj3();
    sf::View view(sf::FloatRect(0,0,700,400));
    sf::Clock clock;
    Tablica_wynikow tab;
    sf::Texture background;
    if(!background.loadFromFile("Background.png")){
        std::cout<<"ERROR"<<std::endl;
    }
    sf::Sprite sprite(background);
    std::vector<sf::Sprite> backs;
    for(int i=0; i<5; i++){
        sprite.setPosition(700*i,0);
        backs.emplace_back(sprite);
    }
     std::vector<int> returny;

    sf::Texture character;
    if(!character.loadFromFile("1x.png")){
        std::cout<<"ERROR";
    }
    Character posrac(character);
    Menu menu(window.getSize().x,window.getSize().y);
    menu.wczytajprz();
    menu.play();
    Coin coin;
    coin.drawCoins1();
    coin.drawCoins2();
    coin.drawCoins3();
    Enemies enemy;
    enemy.enemies1();
    enemy.enemies2();
    enemy.enemies3();
    tab.wynikiNaText();
    Spikes spike;
    spike.spikes1();
    spike.spikes2();
    spike.spikes3();
    Chest chest;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();
        sf::Event event;
        while (window.pollEvent(event)){
            posrac.events(event, window);
        }
        window.clear(sf::Color::White);
        for(auto &spr : backs){
            window.draw(spr);
        }
        menu.drawGame(recs1, recs2, recs3, tab,window,posrac,texture,elapsed, deltaTime, enemy, coin, spike, chest);
        menu.draw_prz(window, tab, event);
        menu.pause();
        menu.resume();
        posrac.setView(posrac,view);
        window.setView(view);
        menu.draw(window, event, posrac);
        menu.checkmusic(event, window, tab);
        menu.wyzeruj(posrac, coin, enemy, tab);
        window.display();
    }
    std::vector<int> punkty = menu.zwrocPunkty();
    std::vector<std::string> imiona = menu.zwrocImiona();
    for(unsigned int i=0; i<punkty.size(); i++){
        zapis<<imiona[i]<<" "<<punkty[i]<<std::endl;
    }
    zapis.close();


    return 0;
}
