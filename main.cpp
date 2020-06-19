#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Mapa.h>
#include <Textures.h>
#include <Character.h>
#include <vector>
#include "Menu.h"
#include "Tablica_wynikow.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 400), "My window");
    std::vector<sf::RectangleShape> recs;
    Textures texture;
    sf::View view(sf::FloatRect(0,0,700,400));
    recs=texture.wczytaj();
    sf::Clock clock;
    Tablica_wynikow tab;
    sf::Texture background;
    if(!background.loadFromFile("Background.png")){
        std::cout<<"ERROR"<<std::endl;
    }
    sf::Sprite sprite(background);
    sf::Texture character;
    if(!character.loadFromFile("1x.png")){
        std::cout<<"ERROR";
    }
    Character posrac(character,0,291,43,27,72,74);
    Menu menu(window.getSize().x,window.getSize().y);
    menu.wczytajprz();
    menu.play();

    while (window.isOpen()) {

        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            posrac.events(event, window);
        }
        window.clear(sf::Color::White);

        window.draw(sprite);
        menu.drawGame(recs,window,posrac,texture,elapsed);
        menu.draw_prz(window, tab);
        menu.pause();
        menu.resume();
        posrac.setView(posrac,view);
        //menu.draw_prz(window,tab);
        window.setView(view);
        menu.draw(window, event);
        menu.checkmusic(event, window);
        window.display();

        //std::cout<<posrac.getPosition().y<<std::endl;
    }


    return 0;
}
