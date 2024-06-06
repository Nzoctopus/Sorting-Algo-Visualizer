/*
** EPITECH PROJECT, 2024
** display
** File description:
** display
*/

#include "../include/include.hpp"

void display_stats(Window &window, sf::RectangleShape &bg, sf::Text &text)
{
    text.setPosition(sf::Vector2f(0, 25));
    text.setString("Number of comparaisons:");
    window.draw(text);
    text.setPosition(sf::Vector2f(275, 25));
    text.setString(std::to_string(window.comparaisons));
    window.draw(text);
    text.setPosition(sf::Vector2f(0, 50));
    text.setString("Number of modifications:");
    window.draw(text);
    text.setPosition(sf::Vector2f(285, 50));
    text.setString(std::to_string(window.modifications));
    window.draw(text);
    text.setPosition(sf::Vector2f(0, 75));
    text.setString("Elapsed Time:");
    window.draw(text);
    text.setPosition(sf::Vector2f(150, 75));
    text.setString(std::to_string(window.elapsed_time));
    window.draw(text);
}

void display_controls(Window &window, sf::RectangleShape &bg, sf::Text &text)
{
    text.setPosition(sf::Vector2f(675, 0));
    text.setString("(Q or Escape or ALT + F4) -> Quit");
    window.draw(text);
    text.setPosition(sf::Vector2f(675, 25));
    text.setString("(1) -> Switch to Bubble Sort (and Randomize)");
    window.draw(text);
    text.setPosition(sf::Vector2f(675, 50));
    text.setString("(2) -> Switch to Cocktail Shaker Sort (and Randomize)");
    window.draw(text);
    text.setPosition(sf::Vector2f(675, 75));
    text.setString("(R) -> Randomize");
    window.draw(text);
}

void display_info(Window &window, sf::RectangleShape &bg, sf::Text &text)
{
    window.draw(bg);
    text.setCharacterSize(20);
    text.setPosition(sf::Vector2f(0, 0));
    text.setString("Current sorting algorithm:");
    window.draw(text);
    text.setPosition(sf::Vector2f(300, 0));
    if (!window.current_sort)
        text.setString("Bubble Sort");
    if (window.current_sort == 1)
        text.setString("Cocktail Shaker Sort *");
    window.draw(text);
    text.setPosition(sf::Vector2f(0, 100));
    text.setString("Worst Case: O(n^2)\nAverage Case: O(n^2)\nBest Case: O(n)");
    window.draw(text);
    text.setPosition(sf::Vector2f(0, 175));
    if (window.cleared)
        text.setString("Status: Completed");
    else
        text.setString("Status: Not Completed");
    window.draw(text);
    display_stats(window, bg, text);
    display_controls(window, bg, text);
}
