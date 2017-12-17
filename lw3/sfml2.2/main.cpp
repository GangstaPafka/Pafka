#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

using namespace std;
using namespace sf;
int main()
{
    constexpr int pointCount = 200;
    constexpr float amplitude = 50.f;
    constexpr float period = 1;
    const Vector2f position{400, 320};

    //создаем окно
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(
        VideoMode({800, 600}), "Polar Rouse",
        Style::Default, settings);

    Clock clock;

    //объявим фигуру
    ConvexShape ellipse;
    ellipse.setPosition({position});
    ellipse.setFillColor(Color(0xff, 0x09, 0x80));

    //вершины
    ellipse.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        const float radius = 200 * sin(6 * angle);
        sf::Vector2f point = sf::Vector2f{
            radius * sin(angle),
            radius * cos(angle)};
        ellipse.setPoint(pointNo, point);
    }

    //выполняем
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        const float wavePhase = clock.getElapsedTime().asSeconds() * float(2 * M_PI);
        const float x = amplitude * cos(wavePhase / period);
        const float y = amplitude * sin(wavePhase / period);
        const Vector2f offset = {x, y};

        ellipse.setPosition(position + offset);

        window.clear();
        window.draw(ellipse);
        window.display();
    }
}