#include "../../inc/PvZ.hpp"
#include "../../inc/levels/Level1.hpp"

Level1Sprites::Level1Sprites() {
    topbarPos = { 280, 0 };
    topbarSize = { 522, 87 };

    backgroundTexture.loadFromFile("../res/img/level/frontyard_3row.jpg");
    background.setTexture(backgroundTexture);

    topbarTexture.loadFromFile("../res/img/topbar/bar4.png");
    topbar.setTexture(topbarTexture);
    topbar.setPosition(topbarPos);
}

vector<Row*>* Level1::makeRows() {
    vector<Row*>* rows = new vector<Row*>(3);
    (*rows)[0] = makeRow1();
    (*rows)[1] = makeRow2();
    (*rows)[2] = makeRow3();
    return rows;
}

Row* Level1::makeRow1() {
    vector<Zombie*>* zombies = new vector<Zombie*>(2);
    (*zombies)[0] = new NullZombie();
    (*zombies)[1] = new NullZombie();
    vector<std::chrono::milliseconds>* zombieSpawnTimes = new vector<std::chrono::milliseconds>(2);
    (*zombieSpawnTimes)[0] = 1000ms;
    (*zombieSpawnTimes)[1] = 2000ms;
    Row* row = new Row(9, zombies, zombieSpawnTimes);
    return row;
}

Row* Level1::makeRow2() {
    vector<Zombie*>* zombies = new vector<Zombie*>(2);
    (*zombies)[0] = new NullZombie();
    (*zombies)[1] = new NullZombie();
    vector<std::chrono::milliseconds>* zombieSpawnTimes = new vector<std::chrono::milliseconds>(2);
    (*zombieSpawnTimes)[0] = 1000ms;
    (*zombieSpawnTimes)[1] = 2000ms;
    Row* row = new Row(9, zombies, zombieSpawnTimes);
    return row;
}

Row* Level1::makeRow3() {
    vector<Zombie*>* zombies = new vector<Zombie*>(2);
    (*zombies)[0] = new NullZombie();
    (*zombies)[1] = new NullZombie();
    vector<std::chrono::milliseconds>* zombieSpawnTimes = new vector<std::chrono::milliseconds>(2);
    (*zombieSpawnTimes)[0] = 1000ms;
    (*zombieSpawnTimes)[1] = 2000ms;
    Row* row = new Row(9, zombies, zombieSpawnTimes);
    return row;
}

Level1::Level1() : Level(makeRows(), 3), sprites(new Level1Sprites()) {}

Level1::~Level1() {
    delete sprites;
    for (Row* row : *rows) {
        delete row;
    }
    delete rows;
}