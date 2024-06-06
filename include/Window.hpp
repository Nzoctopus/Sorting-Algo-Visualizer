/*
** EPITECH PROJECT, 2024
** SORT
** File description:
** Window
*/

#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <map>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SFML/Config.hpp"

class Window {
    public:
        Window();
        Window(int width, int height, const std::string& title = "");
        ~Window();

        void create(int width, int height, const std::string& title = "");

        virtual void update();
        void clear();
        void close();
        void draw(sf::Drawable &entity);
        void display();
        bool isOpen();
        void pollEvent();
        void play_sound(const std::string &name);
        bool released;
        bool pressed;
        bool hold;
        bool cleared;
        sf::Vector2f get_mouse_pos(void);
        sf::Sound sound;
        int current_sort;
        void randomize_numbers();
        int numbers[5120];
        int comparaisons;
        int modifications;
        float elapsed_time;
        float get_elapsed_time();
    private:
        sf::Clock clock;
        sf::RenderWindow *window;
        int width;
        int height;
        sf::SoundBuffer sb;
};
