/*
** EPITECH PROJECT, 2024
** ALGO
** File description:
** Window
*/

#include "../include/Window.hpp"
#include <SFML/Window/Window.hpp>

Window::Window()
{
    this->create(1280, 720, "EMPTY");
    this->width = 1280;
    this->cleared = false;
    this->height = 720;
    this->current_sort = 0;
    this->comparaisons = 0;
    this->modifications = 0;
    this->randomize_numbers();
    this->elapsed_time = 0;
}

Window::Window(int width, int height, const std::string& title)
{
    this->create(width, height, title);
    this->width = width;
    this->height = height;
    this->cleared = false;
    this->current_sort = 0;
    this->comparaisons = 0;
    this->modifications = 0;
    this->randomize_numbers();
    this->elapsed_time = 0;
}

Window::~Window()
{
    this->close();
    delete this->window;
}

void Window::create(int width, int height, const std::string& title)
{
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Titlebar);
}

void Window::update()
{
}

void Window::clear()
{
    this->window->clear();
}

void Window::close()
{
    this->window->close();
}

void Window::draw(sf::Drawable &entity)
{
    this->window->draw(entity);
}

void Window::display()
{
    this->window->display();
}

bool Window::isOpen()
{
    return this->window->isOpen();
}

void Window::pollEvent()
{
    sf::Event event;

    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->close();
        if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Q))
            exit(0);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
            this->randomize_numbers();
            this->clock.restart();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1) {
            this->randomize_numbers();
            this->current_sort = 0;
            this->cleared = false;
            this->comparaisons = 0;
            this->modifications = 0;
            this->clock.restart();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {
            this->randomize_numbers();
            this->current_sort = 1;
            this->cleared = false;
            this->comparaisons = 0;
            this->modifications = 0;
            this->clock.restart();
        }
        if (event.type == sf::Event::MouseButtonReleased)
            this->released = true;
        else
            this->released = false;
        if (event.type == sf::Event::MouseButtonPressed)
            this->pressed = true;
        else
            this->pressed = false;
        this->hold = sf::Mouse().isButtonPressed(sf::Mouse::Left);
    }
}

void Window::play_sound(const std::string &name)
{
    this->sb.loadFromFile(name);
    this->sound.setBuffer(sb);
    this->sound.play();
}

void Window::randomize_numbers(void)
{
    for (int i = 0; i < 5120; i++)
        this->numbers[i] = rand() % 720;
    this->cleared = false;
}

float Window::get_elapsed_time(void)
{
    return this->clock.getElapsedTime().asSeconds();
}

sf::Vector2f Window::get_mouse_pos(void)
{
    sf::Vector2i mpos = sf::Mouse().getPosition(*this->window);
    return sf::Vector2f(mpos.x, mpos.y);
}