#ifndef EVENTHANDLE_HPP
#define EVENTHANDLE_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

void gamePause();

void gameResume();

void handleKeyPress(const Event& event);

void handleMouseClick(const Event& event);

void handleMouseRelease(const Event& event);

void handleMouseMovement(const Event& event);

#endif // EVENTHANDLE_HPP