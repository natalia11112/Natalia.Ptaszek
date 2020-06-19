#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Character.h"
#include "Textures.h"
#include "Tablica_wynikow.h"

class Menu{
public:
    Menu(const float &wid, const float &hei);
    ~Menu();

    void draw(sf::RenderWindow &window, sf::Event &event);
    void draw_prz(sf::RenderWindow &window, Tablica_wynikow &tab);
    void wczytajprz();
    void drawGame(std::vector<sf::RectangleShape> &recs, sf::RenderWindow &window, Character &cha, Textures &tex, const sf::Time &elapsed);
    struct przyciskimenu{
        int left;
        int top;
        float scalex;
        float scaley;
        int posx;
        int posy;
    };
    void play ();
    void pause();
    void resume();
    void checkmusic(sf::Event &event, sf::RenderWindow &window);


private:
    enum StanMenu {Start, Game, Pause, Leaderboard} stan = Start;
    int selectedindex;
    sf::Font font;
    sf::Text nazwa;
    sf::Texture tekstura;
    sf::Texture background;
    std::vector<sf::Sprite> icons;
    sf::Sprite icon;
    float height, width;
    sf::Sprite Background;
    bool music_playing = true;
    sf::Music music;
    bool paused;
    bool click = false;
    sf::Http http;
};

#endif // MENU_H
