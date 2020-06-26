#include "Menu.h"
#include <iostream>

Menu::Menu(const float &wid, const float &hei){
    height = hei;
    width = wid;
    if(!font.loadFromFile("Font.ttf")){
        std::cout<<"ERROR"<<std::endl;
    }
    nazwa.setFont(font);
    nazwa.setFillColor(sf::Color::Red);
    nazwa.setString("Czerwony biegacz");
    nazwa.setPosition(sf::Vector2f(width/2-221.5,height/2-150));
    nazwa.setCharacterSize(54);
    Gameover.setFont(font);
    Gameover.setFillColor(sf::Color::Red);
    Gameover.setString("Koniec gry");
    Gameover.setPosition(sf::Vector2f(width/2-126.5,height/2-150));
    Gameover.setCharacterSize(54);
    Points.setFont(font);
    Points.setFillColor(sf::Color::Black);
    Points.setString(punkty);
    Points.setCharacterSize(25);
    koniec.setFont(font);
    koniec.setFillColor(sf::Color::Red);
    koniec.setString("Wygrana");
    koniec.setPosition(width/2-100,height/2-150);
    koniec.setCharacterSize(54);
}
Menu::~Menu(){

}
void Menu::draw(sf::RenderWindow &window, sf::Event &event, Character &cha){
    auto bounds = icons[0].getGlobalBounds();
    if(!(event.type == sf::Event::MouseButtonReleased)){
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        if((event.mouseButton.button == sf::Mouse::Left && mouse_pos.x<bounds.left+bounds.width && mouse_pos.x>bounds.left && mouse_pos.y<bounds.top+bounds.height && mouse_pos.y>bounds.top && stan == Start)){
           stan = Wpisz_imie;
        }
    }
    if(stan == Start || stan == Wpisz_imie)
        window.draw(nazwa);
    if(cha.Over()==1)
        stan=GameOver;
}
void Menu::draw_prz(sf::RenderWindow &window, Tablica_wynikow &tab, sf::Event &event){

    if(stan == Start || stan == Wpisz_imie)
        window.draw(Background);
    if(stan == Wpisz_imie){
        tab.wpisz_imie(window,event);
        window.draw(icons[7]);
    }
    if(stan == Start ){
        for(unsigned int i=0; i<icons.size()-3; i++){
            if(i==1 && music_playing ==1)
                continue;
            if(i==2 && music_playing ==0)
                continue;
            window.draw(icons[i]);
        }
    }
    if(stan == Leaderboard){
        Lead1=tab.zwraca1();
        Lead2=tab.zwraca2();
        Lead3=tab.zwraca3();
        tab.drawt(window, tab);
        for(unsigned int i=0; i<Lead1.size(); i++){
            window.draw(Lead1[i]);
            window.draw(Lead2[i]);
            window.draw(Lead3[i]);
        }
        window.draw(icons[6]);

    }
    if(stan==GameOver){
        window.draw(Background);
        window.draw(Gameover);
        window.draw(icons[8]);
        window.draw(icons[6]);
    }

}
void Menu::wczytajprz(){
    if(!tekstura.loadFromFile("Icons.png")){
        std::cout<<"ERROR"<<std::endl;
    }
    std::fstream file("kordikon.txt");
    std::vector<przyciskimenu> buttons(9);
    if(file.is_open()){
        for (int i=0; i<9; i++){
            file>>buttons[i].left>>buttons[i].top>>buttons[i].scalex>>buttons[i].scaley>>buttons[i].posx>>buttons[i].posy;

        }
    }
    icon.setTexture(tekstura);
    for(auto &butt : buttons){
        icon.setTextureRect(sf::IntRect(butt.left, butt.top, 128, 128));
        icon.setScale(butt.scalex, butt.scaley);
        icon.setPosition(butt.posx, butt.posy);
        icons.emplace_back(icon);

    }
    if(!background.loadFromFile("BlurBack.png")){
        std::cout<<"ERROR"<<std::endl;
    }
    Background.setTexture(background);
    Background.setScale(0.36458333,0.37037);
}
void Menu::drawGame(std::vector<sf::RectangleShape> &recs1, std::vector<sf::RectangleShape> &recs2,std::vector<sf::RectangleShape> &recs3, Tablica_wynikow &tab, sf::RenderWindow &window,
    Character &cha, Textures &tex, const sf::Time &elapsed, const float &deltaTime, Enemies &enemy, Coin &coin, Spikes &spike, Chest &chest){
    points = coin.punkty();
    punkty = std::to_string(points);
    Points.setString(punkty);
    if(cha.getPosition().x>=350 && cha.getPosition().x<3050){
        Points.setPosition(cha.getPosition().x-340,Points.getPosition().y);
    }
    if(cha.getPosition().x>=3050){
        Points.setPosition(2710,Points.getPosition().y);
    }
    if(stan == GameOver){
        view.setSize(700,400);
        view.setCenter(350,200);
        window.setView(view);
        if(saved==0){
            PunktyPrzej.emplace_back(points);
            imiona.emplace_back(tab.returnImie());
            saved = 1;
        }
        nowaGra =1;
        chest.reset();
        chest.clear();
    }
    if(stan == Game1){
        saved = 0;
        tex.drawTex1(window);
        chest.drawChest(window, chest, cha, deltaTime);
        cha.drawch(window,cha);
        window.draw(Points);
        spike.drawspike1(window,cha);
        enemy.drawenemy1(window, cha);
        coin.collisionWithCharacter1(window, cha);
        enemy.falldown1(cha,elapsed);
        cha.animate(elapsed, recs1);
        cha.update(deltaTime);
        chest.ifopened(0);
        if(enemy.collisionWithPosrac1(cha)==1)
            stan = GameOver;
        if(spike.collision1(cha)==1)
            stan = GameOver;
        if(chest.ifopened(0)==1){
            coin.ifOpened(chest);
            stan = Game2;
            cha.wyzeruj();
            Points.setPosition(10,10);
            chest.reset();
        }
    }
    if(stan == Game2){
        tex.drawTex2(window);
        chest.drawChest(window, chest, cha, deltaTime);
        cha.drawch(window,cha);
        window.draw(Points);
        spike.drawspike2(window,cha);
        enemy.drawenemy2(window, cha);
        coin.collisionWithCharacter2(window, cha);
        enemy.falldown2(cha,elapsed);
        cha.animate(elapsed, recs2);
        cha.update(deltaTime);
        chest.ifopened(1);
        if(enemy.collisionWithPosrac2(cha)==1)
            stan = GameOver;
        if(spike.collision2(cha)==1)
            stan = GameOver;
        if(chest.ifopened(1)==1){
            coin.ifOpened(chest);
            stan = Game3;
            cha.wyzeruj();
            Points.setPosition(10,10);
            chest.reset();
        }
    }
    if(stan == Game3){
        tex.drawTex3(window);
        chest.drawChest(window, chest, cha, deltaTime);
        cha.drawch(window,cha);
        window.draw(Points);
        spike.drawspike3(window,cha);
        enemy.drawenemy3(window, cha);
        coin.collisionWithCharacter3(window, cha);
        enemy.falldown3(cha,elapsed);
        cha.animate(elapsed, recs3);
        cha.update(deltaTime);
        chest.ifopened(2);
        if(enemy.collisionWithPosrac3(cha)==1)
            stan = GameOver;
        if(spike.collision3(cha)==1)
            stan = GameOver;
        if(chest.ifopened(2)==1){
            coin.ifOpened(chest);
            stan = Wygrana;
            cha.wyzeruj();
            Points.setPosition(10,10);
            chest.reset();
        }
    }
    if(stan == Wygrana){
        window.draw(koniec);
        window.draw(icons[6]);
    }
}

void Menu::play(){
    if(!music.openFromFile("Music.wav")){
        std::cout<<"ERROR"<<std::endl;
    }
    music.setLoop(true);
    if(music_playing == true)
        music.play();


}
void Menu::pause(){
    if(music_playing == 0){
        music.pause();
        paused = 1;
    }

}

void Menu::checkmusic(sf::Event &event, sf::RenderWindow &window, Tablica_wynikow &tab){
    a = tab.returnImie();
    auto bounds = icons[0].getGlobalBounds();
    if(music_playing == 1)
        bounds = icons[1].getGlobalBounds();
    else
        bounds = icons[2].getGlobalBounds();
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left
            && mouse_pos.x<bounds.left+bounds.width && mouse_pos.x>bounds.left && mouse_pos.y<bounds.top+bounds.height
            && mouse_pos.y>bounds.top && stan == Start  && paused == 0 && click == 0){
            music_playing = 0;
            click = 1;
    }
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left
    && mouse_pos.x<bounds.left+bounds.width && mouse_pos.x>bounds.left && mouse_pos.y<bounds.top+bounds.height
    && mouse_pos.y>bounds.top && stan == Start && paused == 1 && click == 0){
        music_playing = 1;
        click = 1;
    }
    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && click == 1)
        click = 0;
    auto boundout = icons[5].getGlobalBounds();
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left
    && mouse_pos.x<boundout.left+boundout.width && mouse_pos.x>boundout.left && mouse_pos.y<boundout.top+boundout.height
    && mouse_pos.y>boundout.top && stan == Start){
        window.close();
    }
    auto boundlead = icons[4].getGlobalBounds();
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left
    && mouse_pos.x<boundlead.left+boundlead.width && mouse_pos.x>boundlead.left && mouse_pos.y<boundlead.top+boundlead.height
    && mouse_pos.y>boundlead.top && stan == Start){
        stan = Leaderboard;
    }
    auto boundhome = icons[6].getGlobalBounds();
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left
    && mouse_pos.x<boundhome.left+boundhome.width && mouse_pos.x>boundhome.left && mouse_pos.y<boundhome.top+boundhome.height
    && mouse_pos.y>boundhome.top && (stan == Leaderboard || stan == GameOver || stan == Wygrana)){
        stan = Start;
    }
    auto boundstart = icons[7].getGlobalBounds();
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left
    && mouse_pos.x<boundstart.left+boundstart.width && mouse_pos.x>boundstart.left && mouse_pos.y<boundstart.top+boundstart.height
    && mouse_pos.y>boundstart.top && stan == Wpisz_imie && a.size()>0){
        Points.setPosition(10,10);
        stan = Game1;

    }
    auto boundnew =  icons[8].getGlobalBounds();
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left
    && mouse_pos.x<boundnew.left+boundnew.width && mouse_pos.x>boundnew.left && mouse_pos.y<boundnew.top+boundnew.height
    && mouse_pos.y>boundnew.top && stan == GameOver){
        stan = Wpisz_imie;
        nowaGra = 0;
    }
}

void Menu::resume(){
    if(music_playing == 1 && paused == 1){
        music.play();
        paused = 0;
    }
}
void Menu::wyzeruj(Character &cha, Coin &coin, Enemies &enemy, Tablica_wynikow &tab){
    if(nowaGra == 1){
        cha.wyzeruj();
        coin.wyzeruj1();
        coin.wyzeruj2();
        coin.wyzeruj3();
        enemy.wyzeruj1();
        enemy.wyzeruj2();
        enemy.wyzeruj3();
        tab.wyzeruj();
    }
}
std::vector<std::string> Menu::zwrocImiona(){
    return imiona;
}
std::vector<int> Menu::zwrocPunkty(){
    return PunktyPrzej;
}

