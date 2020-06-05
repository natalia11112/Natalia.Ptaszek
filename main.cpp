#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Mapa.h>
#include <Tile.h>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 400), "My window");
    sf::Texture dirt;
    if(!dirt.loadFromFile("Dirt.png")){
        return 1;
    }
    sf::Texture grass;
    if(!grass.loadFromFile("Grass.png")){
        return 1;
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        mapa map(800,400);
        std::vector<sf::RectangleShape> recs=map.prostokaty(dirt,grass);
        for(auto &rec : recs){
            window.draw(rec);
        }
        window.display();
    }


    return 0;
}
