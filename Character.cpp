#include "Character.h"
Character::Character(){
    setTexture(character);
    setTextureRect(sf::IntRect(43,27,width,height));
    setScale(0.5,0.5);
    setPosition(0,291);
}
void Character::wczytajtex(){
    sf::Context context;
    if(!character.loadFromFile("Resources/Pliki_png/1x.png")){
        std::cout<<"ERROR";
    }
}
void Character::setView(Character &character, sf::View &view){
    if(character.getPosition().x<350)
        view.setCenter(350,200);
    else if(character.getPosition().x>=350 && character.getPosition().x<3050)
        view.setCenter(character.getPosition().x, 200);
    else if(character.getPosition().x>=3050)
        view.setCenter(3050,200);
}
bool Character::collisiond (const std::vector<sf::RectangleShape> &recs){
    auto bounds = getGlobalBounds();
    for (auto rec : recs){
        auto boundr = rec.getGlobalBounds();
        if((bounds.top+bounds.height>=boundr.top+3 && bounds.top+bounds.height<=boundr.top+6) && ((bounds.left+10>=boundr.left && bounds.left+10<=boundr.left+boundr.width)
               || (bounds.left+bounds.width-10>=boundr.left && bounds.left+bounds.width-17<=boundr.left+boundr.width) || (bounds.left+(bounds.width/2)>=boundr.left
               && bounds.left+(bounds.width/2)<=boundr.left+boundr.width))){
            onGround=true;
            ground = boundr.top+3;
            released = false;
            return 1;
        }
    }
    onGround = false;
    return 0;
}
bool Character::collisionu (const std::vector<sf::RectangleShape> &recs){
    auto bounds = getGlobalBounds();
    for (auto rec : recs){
        auto boundr = rec.getGlobalBounds();
        if((bounds.top<=boundr.top+boundr.height && bounds.top>boundr.top) && ((bounds.left+10>=boundr.left && bounds.left+10<=boundr.left+boundr.width)
               || (bounds.left+bounds.width-10>=boundr.left && bounds.left+bounds.width-17<=boundr.left+boundr.width) || (bounds.left+(bounds.width/2)>=boundr.left
               && bounds.left+(bounds.width/2)<=boundr.left+boundr.width))){
            released = 1;
            return 1;
        }
    }
    return 0;
}
bool Character::collisionl (const std::vector<sf::RectangleShape> &recs){
auto bounds = getGlobalBounds();
    for (auto rec : recs){
        auto boundr = rec.getGlobalBounds();
        if((bounds.left<=boundr.left+boundr.width && bounds.left>boundr.left) && ((bounds.top<boundr.top+boundr.height && bounds.top>boundr.top+6)
                || (bounds.top+bounds.height<boundr.top+boundr.height && bounds.top+bounds.height>boundr.top+6)
                || (bounds.top+(bounds.height/2)<boundr.top+boundr.height && bounds.top+(bounds.height/2)>boundr.top+6))){
            return 1;
        }
    }
    return 0;
}
bool Character::collisionr (const std::vector<sf::RectangleShape> &recs){
    auto bounds = getGlobalBounds();
        for (auto rec : recs){
            auto boundr = rec.getGlobalBounds();
            if((bounds.left+bounds.height>=boundr.left && bounds.left+bounds.height<boundr.left+boundr.height) && ((bounds.top<boundr.top+boundr.height && bounds.top>boundr.top+6)
                    || (bounds.top+bounds.height<boundr.top+boundr.height && bounds.top+bounds.height>boundr.top+6)
                    || (bounds.top+(bounds.height/2)<boundr.top+boundr.height && bounds.top+(bounds.height/2)>boundr.top+6))){
                return 1;
            }
        }
        return 0;
}
void Character::events(sf::Event &event, sf::RenderWindow &window){
    if (event.type == sf::Event::Closed)
        window.close();
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space){
        released = true;
    }
}
void Character::animate(const sf::Time &elapsed, const std::vector<sf::RectangleShape> &recs){
    auto bounds = getGlobalBounds();
    collisiond(recs);
    collisionl(recs);
    collisionr(recs);
    collisionu(recs);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && collisionl(recs)==0) {
                if(bounds.left+1>bounds_left)
                    move(-std::abs(velocity_x) * elapsed.asSeconds(), 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && collisionr(recs)==0 ) {
                if(bounds.left+bounds.width<bounds_right)
                    move(std::abs(velocity_x) * elapsed.asSeconds(), 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && released == false && collisionu(recs)==0) {
                move(0,-velocity_y*elapsed.asSeconds());
                onGround = false;
                if(ground-getPosition().y+bounds.height>250)
                    released = true;
            }
            if(onGround == false && released == true && collisiond(recs)==0){
                if(collisiond(recs)==1){
                    released=false;
                    move(0,-(getPosition().y+bounds.height-ground));
                }
                else
                    move(0,velocity_y*elapsed.asSeconds());
            }
            if(collisiond(recs)==0 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                released = true;
}
void Character::drawch(sf::RenderWindow &window, Character cha){
    window.draw(cha);
}
void Character::update(const float &deltaTime){
    totalTime += deltaTime;
    if(totalTime >= switchTime){
        totalTime -= switchTime;
        currentImage++;
        if(currentImage >= imageCount){
            currentImage = 0;
            roznica = 0;
        }

        if((currentImage == 2 || currentImage == 5 || currentImage == 7 || currentImage == 10))
            roznica++;
    }


        setTextureRect(sf::IntRect(43+currentImage*width+currentImage*13+roznica,27,width,height));
}

sf::Vector2f Character::zwrocPozycje(){
    sf::Vector2f pozycja(getPosition().x, getPosition().y);
    return pozycja;
}
bool Character::Over(){
    auto bounds = getGlobalBounds();
    if(bounds.top+bounds.height>=400)
        return 1;
    else
        return 0;
}
void Character::wyzeruj(){
    setPosition(0,291);
    onGround = true;
    released = false;
    currentImage = 0;
    roznica = 0;
}
int Character::returnLives(){
    return lives;
}
void Character::reduceLives(){
    lives--;
}
void Character::increaseLives(){
    lives++;
}
void Character::resetLives(){
    lives=3;
}
