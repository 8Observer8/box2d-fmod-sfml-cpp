#include <iostream>
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <fmod.h>

b2Vec2 gravity(0.0f, 9.8f);
b2World world(gravity);

FMOD_SYSTEM *m_pSystem;
FMOD_SOUND *m_pSound;
 
int main()
{
    // Print the gravity
    std::cout << gravity.y << std::endl;

    FMOD_System_Create(&m_pSystem, FMOD_VERSION);
    FMOD_System_Init(m_pSystem, 32, FMOD_INIT_NORMAL, 0);
    FMOD_System_CreateSound(m_pSystem, "sounds/gamestart.ogg", FMOD_LOOP_OFF | FMOD_2D, 0, &m_pSound);
    FMOD_System_PlaySound(m_pSystem, m_pSound, 0, false, 0);

    sf::RenderWindow window(sf::VideoMode(240, 240), "SFML works!");
    sf::CircleShape shape(120.f);
    shape.setFillColor(sf::Color::Green);
 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
 
        window.clear();
        window.draw(shape);
        window.display();
    }
 
    return 0;
}