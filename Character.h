#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Character : public sf::Sprite{
public:
    Character();
    void wczytajtex();
    void setView(Character &character, sf::View &view);
    bool collisiond (const std::vector<sf::RectangleShape> &recs);
    bool collisionu (const std::vector<sf::RectangleShape> &recs);
    bool collisionl (const std::vector<sf::RectangleShape> &recs);
    bool collisionr (const std::vector<sf::RectangleShape> &recs);
    void events(sf::Event &event, sf::RenderWindow &window);
    void animate(const sf::Time &elapsed, const std::vector<sf::RectangleShape> &recs);
    void drawch(sf::RenderWindow &window, Character cha);
    void update(const float &deltaTime);
    sf::Vector2f zwrocPozycje();
    bool Over();
    void wyzeruj();
    int returnLives();
    void reduceLives();
    void increaseLives();
    void resetLives();
private:
    std::string name;
    float bounds_left = 0, bounds_right = 3400;
    float velocity_x = 150;
    float velocity_y = 430;
    bool onGround = true;
    bool released =false;
    float ground;
    float switchTime = 0.2f;
    int imageCount = 11;
    int currentImage = 0;
    float totalTime = 0.0f;
    float height = 75;
    float width = 73;
    int roznica = 0;
    int lives = 3;
    sf::Texture character;
};

#endif // CHARACTER_H
