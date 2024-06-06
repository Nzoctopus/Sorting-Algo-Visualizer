/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "../include/include.hpp"

void cleared_animation(Window &window, sf::RectangleShape &rect, int pos, int numbers[5120])
{
    for (int i = 0; i < 5120; i++) {
        rect.setOutlineColor(sf::Color().White);
        if (i <= pos)
            rect.setOutlineColor(sf::Color().Green);
        rect.setSize(sf::Vector2f(0.25, numbers[i]));
        rect.setPosition(sf::Vector2f(i * 0.25, 1000 - numbers[i]));
        window.draw(rect);
    }
}

void init_variables(sf::RectangleShape &bg, sf::Text &text, sf::Font &font)
{
    bg.setFillColor(sf::Color(255, 255, 255, 20));
    bg.setSize(sf::Vector2f(1280, 250));
    bg.setOutlineColor(sf::Color().White);
    bg.setOutlineThickness(1);
    font.loadFromFile("rs/font.ttf");
    text.setFont(font);
}

int main(void)
{
    Window window(1280, 1000, "Visualizer");
    sf::Font font;
    sf::Text text;
    sf::RectangleShape rect;
    sf::RectangleShape bg;
    int animation_pos = 0;

    rect.setFillColor(sf::Color().Transparent);
    rect.setOutlineThickness(0.25);
    init_variables(bg, text, font);
    while(window.isOpen()) {
        window.pollEvent();
        window.clear();
        display_info(window, bg, text);
        if (!window.cleared) {
            animation_pos = 0;
            if (!window.current_sort)
                sort(window.numbers, window, rect);
            if (window.current_sort == 1)
                sort2(window.numbers, window, rect);
        } else {
            cleared_animation(window, rect, animation_pos, window.numbers);
            animation_pos = animation_pos > 5120 ? 5120 : animation_pos + 10;
        }
        window.display();
        window.pressed = 0;
        window.released = 0;
    }
    return 0;
}