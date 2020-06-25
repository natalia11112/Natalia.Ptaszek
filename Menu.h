#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Character.h"
#include "Textures.h"
#include "Coin.h"
#include "Tablica_wynikow.h"
#include "Enemies.h"

class Menu{
public:
    Menu(const float &wid, const float &hei);
    ~Menu();

    void draw(sf::RenderWindow &window, sf::Event &event, Character &cha);
    void draw_prz(sf::RenderWindow &window, Tablica_wynikow &tab, sf::Event &event);
    void wczytajprz();
    void drawGame(std::vector<sf::RectangleShape> &recs, Tablica_wynikow &tab, sf::RenderWindow &window, Character &cha, Textures &tex,
    const sf::Time &elapsed, const float &deltaTime, Enemies &enemy, Coin &coin);
    struct przyciskimenu{
        int left;
        int top;
        float scalex;
        float scaley;
        int posx;
        int posy;
    };
    void wyzeruj(Character &cha, Coin &coin, Enemies &enemy, Tablica_wynikow &tab);
    void play ();
    void pause();
    void resume();
    void checkmusic(sf::Event &event, sf::RenderWindow &window);
    std::vector<std::string> zwrocImiona();
    std::vector<int> zwrocPunkty();

private:
    enum StanMenu {Start, Leaderboard, Wpisz_imie, Game, Pause, GameOver} stan = Start;
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
    std::vector<sf::RectangleShape> coins;
    sf::Text Gameover;
    bool nowaGra = false;
    sf::View view;
    sf::Text Points;
    int points = 0;
    std::string punkty;
    std::vector<int> PunktyPrzej;
    std::vector<std::string> imiona;
    bool saved = 0;
    std::vector<sf::Text> Lead1;
    std::vector<sf::Text> Lead2;
    std::vector<sf::Text> Lead3;

};

#endif // MENU_H
