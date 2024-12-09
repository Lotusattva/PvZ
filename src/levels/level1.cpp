#include "levels/Level1.hpp"

Level1Sprites::Level1Sprites() {
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

Level1::~Level1() {
    delete sprites;
    for (Row* row : *rows) {
        delete row;
    }
    delete rows;
}

void Level1::action() {
    window->draw(sprites->background);
    window->draw(sprites->topbar);
    for (Row* row : *rows) {
        row->action();
    }
}