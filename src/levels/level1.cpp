#include "levels/Level1.hpp"

class Level1::Sprites {
private:
    Texture backgroundTexture;
    Texture topbarTexture;
public:
    Sprite background;
    Sprite topbar;

    Vector2f topbarPos;
    Vector2f topbarSize;

    Sprites();
};

Level1::Sprites::Sprites() {
    topbarPos = { 280, 0 };
    topbarSize = { 522, 87 };

    backgroundTexture.loadFromFile("res/img/level/frontyard_3row.jpg");
    background.setTexture(backgroundTexture);

    topbarTexture.loadFromFile("res/img/topbar/bar4.png");
    topbar.setTexture(topbarTexture);
    topbar.setPosition(topbarPos);
}

vector<Row*>* Level1::makeRows() {
    return  new vector<Row*>{ makeRow1(), makeRow2(), makeRow3() };
}

Row* Level1::makeRow1() {
    vector<Zombie*>* zombies = new vector<Zombie*>{ new NullZombie(), new NullZombie() };
    return new Row(9, zombies);
}

Row* Level1::makeRow2() {
    vector<Zombie*>* zombies = new vector<Zombie*>{ new NullZombie(), new NullZombie() };
    return new Row(9, zombies);
}

Row* Level1::makeRow3() {
    vector<Zombie*>* zombies = new vector<Zombie*>{ new NullZombie(), new NullZombie() };
    return new Row(9, zombies);
}

Level1::Level1() : sprites(new Sprites()), Level(makeRows(), 3) { }

Level1::~Level1() {
    delete sprites;
    for (Row* row : *rows) {
        delete row;
    }
    delete rows;
}

GameState Level1::play(Event& event) {
    drawSprite(sprites->background);
    drawSprite(sprites->topbar);
    while (window.pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                window.close();
                return GameState::MAIN_MENU;
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape) {
                    return GameState::MAIN_MENU;
                }
            default:
                break;
        }
    }
    for (Row* row : *rows) {
        row->action();
    }
    return GameState::PLAY;
}