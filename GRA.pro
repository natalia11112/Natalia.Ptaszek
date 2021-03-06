TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"
SOURCES += \
        Character.cpp \
        Chest.cpp \
        Coin.cpp \
        Enemies.cpp \
        Menu.cpp \
        Spikes.cpp \
        Tablica_wynikow.cpp \
        Textures.cpp \
        main.cpp
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    Character.h \
    Chest.h \
    Coin.h \
    Enemies.h \
    Menu.h \
    Spikes.h \
    Tablica_wynikow.h \
    Textures.h
