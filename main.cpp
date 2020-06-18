#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Mapa.h>
#include <Textures.h>
#include <Character.h>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 400), "My window");
    std::vector<sf::RectangleShape> recs;
    Textures texture;
    recs=texture.wczytaj();
    sf::Clock clock;

    sf::Texture background;
    if(!background.loadFromFile("Background.png")){
        std::cout<<"ERROR"<<std::endl;
    }
    background.setRepeated(true);
    sf::Sprite sprite(background);
    sf::Texture character;
    if(!character.loadFromFile("1x.png")){
        std::cout<<"ERROR";
    }
    Character posrac(character, 0,291,43,27,72,74);
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            posrac.events(event, window, elapsed);
        }
        window.clear(sf::Color::White);
        window.draw(sprite);
        for(auto &rec : recs){
            window.draw(rec);
        }
        posrac.animate(elapsed, recs);
        window.draw(posrac);
        window.display();
        //std::cout<<posrac.getPosition().y<<std::endl;
    }


    return 0;
}
