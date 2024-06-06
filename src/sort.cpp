/*
** EPITECH PROJECT, 2024
** sort
** File description:
** sort
*/

#include "../include/include.hpp"
#include "../include/Window.hpp"

void sort2(int numbers[5120], Window &window, sf::RectangleShape &rect)
{
    int tmp = 0;
    int counter = 0;
    int index_2 = 5119;
    
    for (int i = 0; i < 5119; i++) {
        rect.setOutlineColor(sf::Color().White);
        if (numbers[i] > numbers[i + 1]) {
            tmp = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = tmp;
            rect.setOutlineColor(sf::Color().Red);
            window.modifications++;
            counter++;
        }
        if (numbers[index_2] < numbers[index_2 - 1]) {
            tmp = numbers[index_2];
            numbers[index_2] = numbers[index_2 - 1];
            numbers[index_2 - 1] = tmp;
            rect.setOutlineColor(sf::Color().Red);
            window.modifications++;
            counter++;
        }
        rect.setSize(sf::Vector2f(0.25, numbers[i]));
        rect.setPosition(sf::Vector2f(i * 0.25, 1000 - numbers[i]));
        window.draw(rect);
        index_2--;
        window.comparaisons++;
        window.elapsed_time = window.get_elapsed_time();
    }
    if (!counter)
        window.cleared = true;
}

void sort(int numbers[5120], Window &window, sf::RectangleShape &rect)
{
    int tmp = 0;
    int counter = 0;
    
    for (int i = 0; i < 5119; i++) {
        rect.setOutlineColor(sf::Color().White);
        if (numbers[i] > numbers[i + 1]) {
            tmp = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = tmp;
            rect.setOutlineColor(sf::Color().Red);
            counter++;
            window.modifications++;
        }
        rect.setSize(sf::Vector2f(0.25, numbers[i]));
        rect.setPosition(sf::Vector2f(i * 0.25, 1000 - numbers[i]));
        window.draw(rect);
        window.comparaisons++;
        window.elapsed_time = window.get_elapsed_time();
    }
    if (!counter)
        window.cleared = true;
}
