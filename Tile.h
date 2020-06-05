#ifndef TILE_H
#define TILE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Tile : public sf::Sprite{
public:
    Tile(const sf::Texture &tex, float &x, float &y){
        setTexture(tex);
        setPosition(x,y);
        setScale(0.0625,0.0625);
    }
};
#endif // TILE_H
