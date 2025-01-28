#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

class Debug {
public:
    // Log a message to the console
    static void log(const std::string& message);

    // Log an object's position (plants, zombies, etc.)
    static void logPosition(const std::string& name, const sf::Sprite& sprite);

    // Log the current health of an object
    static void logHealth(const std::string& name, int health);

    // Draw a bounding box around an object's sprite for debugging
    static void drawBoundingBox(sf::RenderWindow& window, const sf::Sprite& sprite, sf::Color color = sf::Color::Red);

    // Enable/disable visual debugging (bounding boxes)
    static void enableVisualDebug(bool enable);

private:
    static bool visualDebugEnabled; // Internal flag for visual debugging
};

#endif
