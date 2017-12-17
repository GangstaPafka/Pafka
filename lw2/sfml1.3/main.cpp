#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0xff, 0xff, 0x8));
    trapeze.setPosition({400, 150});
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-150, 0});
    trapeze.setPoint(1, {+150, 0});
    trapeze.setPoint(2, {+320, 120});
    trapeze.setPoint(3, {-320, 120});

    sf::RectangleShape shape1;
    shape1.setSize({500, 300});
    shape1.setPosition({150, 270});
    shape1.setFillColor(sf::Color(0x69, 0x41, 0x12));

    sf::RectangleShape shape2;
    shape2.setSize({200, 80});
    shape2.setRotation(90);
    shape2.setPosition({300, 370});
    shape2.setFillColor(sf::Color(0x80, 0x80, 0x80));

    sf::RectangleShape shape3;
    shape3.setSize({80, 40});
    shape3.setRotation(90);
    shape3.setPosition({540, 130});
    shape3.setFillColor(sf::Color(0x80, 0x80, 0x80));

    sf::RectangleShape shape4;
    shape4.setSize({60, 40});
    shape4.setPosition({490, 90});
    shape4.setFillColor(sf::Color(0x80, 0x80, 0x80));

    sf::CircleShape shape5(15);
    shape5.setPosition({510, 60});
    shape5.setFillColor(sf::Color(0xf0, 0xf0, 0xf0));

    sf::CircleShape shape6(18);
    shape6.setPosition({520, 50});
    shape6.setFillColor(sf::Color(0xf0, 0xf0, 0xf0));

    sf::CircleShape shape7(15);
    shape7.setPosition({530, 42});
    shape7.setFillColor(sf::Color(0xf0, 0xf0, 0xf0));

    sf::CircleShape shape8(20);
    shape8.setPosition({540, 35});
    shape8.setFillColor(sf::Color(0xf0, 0xf0, 0xf0));

    sf::RenderWindow window(sf::VideoMode({800, 600}), "House");
    window.clear();
    window.draw(trapeze);
    window.draw(shape1);
    window.draw(shape2);
    window.draw(shape3);
    window.draw(shape4);
    window.draw(shape5);
    window.draw(shape6);
    window.draw(shape7);
    window.draw(shape8);
    window.display();

    sf::sleep(sf::seconds(5));
}