#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Mapa.h>
#include <Tile.h>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 400), "My window");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        mapa map;
        std::vector<sf::Texture> tex;
        std::vector<Textures> tex2;
        Textures texture;
        tex=texture.text();
        tex2=texture.wczytaj();

        map.load(tex2, tex);
        map.create_map(tex2,tex);
        std::vector<sf::RectangleShape> recs=map.prostokaty();
        for(auto &rec : recs){
            window.draw(rec);
        }

        window.display();
    }


    return 0;
}
