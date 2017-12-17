#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Iniciali");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({20, 560});
    shape1.setRotation(0);
    shape1.setPosition({20, 20});
    shape1.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({20, 211});
    shape2.setRotation(270);
    shape2.setPosition({40, 40});
    shape2.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({20, 211});
    shape3.setRotation(270);
    shape3.setPosition({40, 300});
    shape3.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({20, 560});
    shape4.setRotation(0);
    shape4.setPosition({271, 20});
    shape4.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({20, 211});
    shape5.setRotation(270);
    shape5.setPosition({291, 300});
    shape5.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({20, 211});
    shape6.setRotation(270);
    shape6.setPosition({291, 40});
    shape6.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({20, 260});
    shape7.setRotation(0);
    shape7.setPosition({482, 20});
    shape7.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({20, 560});
    shape8.setRotation(12);
    shape8.setPosition({652, 20});
    shape8.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({20, 560});
    shape9.setRotation(348);
    shape9.setPosition({652, 24});
    shape9.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape9);

    sf::RectangleShape shape10;
    shape10.setSize({20, 120});
    shape10.setRotation(270);
    shape10.setPosition({600, 300});
    shape10.setFillColor(sf::Color(0xff, 0xff, 0xff));
    window.draw(shape10);

    window.display();

    sf::sleep(sf::seconds(5));
}