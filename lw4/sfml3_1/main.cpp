#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace sf;

//initialisation
void init(ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(Color(0xff, 0x80, 0x00));
}

//perevod
float toDegres(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

//obrabotka
void onMouseMove(const Event::MouseMoveEvent &event, Vector2f &mousePosition)
{
    cout << "mouse x=" << event.x << " , y=" << event.y << endl;

    mousePosition = {float(event.x), float(event.y)};
}

//opros i obrabotka sobitiy
void pollEvents(RenderWindow &window, Vector2f &mousePosition)
{
    Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window.close();
            break;
        case Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

//obnova
void update(const Vector2f &mousePosition, ConvexShape &pointer, float time)
{
    const Vector2f delta = mousePosition - pointer.getPosition();
    const float maxAngulerSpeed = 15;
    float requiredRotation = atan2(delta.y, delta.x);
    if (requiredRotation < 0)
    {
        requiredRotation += 2 * M_PI;
    }
    requiredRotation = toDegres(requiredRotation);
    const float DeltaAngle = maxAngulerSpeed * time;
    float rotation = min(abs(requiredRotation - DeltaAngle), DeltaAngle);
    cout << "DeltaAngle: " << DeltaAngle << endl;
    cout << "requiredRotation: " << requiredRotation << endl;
    cout << "pointer.getRotation: " << pointer.getRotation() << endl;
    if (requiredRotation < pointer.getRotation())
    {
        if ((requiredRotation + 180) < pointer.getRotation())
        {
            pointer.setRotation(pointer.getRotation() + rotation);
        }
        else
        {
            pointer.setRotation(pointer.getRotation() - rotation);
        }
    }
    else
    {
        if ((requiredRotation - 180) > pointer.getRotation())
        {
            pointer.setRotation(pointer.getRotation() - rotation);
        }
        else
        {
            pointer.setRotation(pointer.getRotation() + rotation);
        }
    }
}

//risuem
void redrawFrame(RenderWindow &window, ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Pointer folows mouse", Style::Default, settings);

    ConvexShape pointer;
    Vector2f mousePosition;

    Clock clock;
    init(pointer);
    while (window.isOpen())
    {
        float time = clock.restart().asSeconds();
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, time);
        redrawFrame(window, pointer);
    }
}