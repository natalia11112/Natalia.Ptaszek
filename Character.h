#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Character : public sf::Sprite{
public:
    Character(sf::Texture &tex, float x, float y, float a, float b, float c, float d){
        setTexture(tex);
        setTextureRect(sf::IntRect(a,b,c,d));
        setScale(0.5,0.5);
        setPosition(x,y);
    }
    void setView(Character &character, sf::View &view){
        if(character.getPosition().x<350)
            view.setCenter(350,200);
        else if(character.getPosition().x>=400)
            view.setCenter(character.getPosition().x, 200);
    }
    bool collisiond (const std::vector<sf::RectangleShape> &recs){
        auto bounds = getGlobalBounds();
        for (auto rec : recs){
            auto boundr = rec.getGlobalBounds();
            if((bounds.top+bounds.height>=boundr.top+3 && bounds.top+bounds.height<=boundr.top+4) && ((bounds.left>=boundr.left && bounds.left<=boundr.left+boundr.width)
                   || (bounds.left+bounds.width>=boundr.left && bounds.left+bounds.width<=boundr.left+boundr.width) || (bounds.left+(bounds.width/2)>=boundr.left
                   && bounds.left+(bounds.width/2)<=boundr.left+boundr.width))){
                //std::cout<<"COLLISION";
                onGround=true;
                ground = boundr.top+3;
                released = false;
                return 1;
            }
        }
        onGround = false;
        return 0;
    }
    void events(sf::Event &event, sf::RenderWindow &window){
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space){
            released = true;
        }
    }
    void animate(const sf::Time &elapsed, const std::vector<sf::RectangleShape> &recs){
        auto bounds = getGlobalBounds();
        collisiond(recs);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    if(bounds.left>bounds_left)
                        move(-std::abs(velocity_x) * elapsed.asSeconds(), 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
                        move(std::abs(velocity_x) * elapsed.asSeconds(), 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && released == false) {
                    move(0,-velocity_y*elapsed.asSeconds());
                    onGround = false;
                    if(ground-getPosition().y+bounds.height>250)
                        released = true;
                }
                if(onGround == false && released == true && collisiond(recs)==0){
                    if(collisiond(recs)==1){
                        released=false;
                        move(0,-(getPosition().y+bounds.height-ground));
                    std::cout<<"YASS";
                    }
                    else
                        move(0,velocity_y*elapsed.asSeconds());
                }
                if(collisiond(recs)==0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    released = true;
    }
    void drawch(sf::RenderWindow &window, Character cha){
        window.draw(cha);
    }

private:
    std::string name;
    float bounds_left = 0, bounds_right = 700;
    float velocity_x = 150;
    float velocity_y = 430;
    bool onGround = true;
    bool released =false;
    float ground;

};

#endif // CHARACTER_H
