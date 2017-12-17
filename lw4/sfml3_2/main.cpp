#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace sf;

struct Circle
{
    CircleShape head;
    Vector2f position;
    float rotation = 0;
};

// Переводим полярные координаты в декартовые.
Vector2f toEuclidean(float radius, float angle)
{
    return {
        radius * cos(angle),
        radius * sin(angle)};
}

// Переводим радианы в градусы
float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

// Обновляет позиции и повороты частей стрелки согласно текущему состоянию стрелки.
void updateCircle1Elements(Circle &circle)
{
    const Vector2f headOffset = toEuclidean(40, circle.rotation);
    circle.head.setPosition(circle.position + headOffset);
    circle.head.setRotation(toDegrees(circle.rotation));
}

void updateCircle2Elements(Circle &circle)
{
    const Vector2f headOffset = toEuclidean(40, circle.rotation);
    circle.head.setPosition(circle.position + headOffset);
    circle.head.setRotation(toDegrees(circle.rotation));
}

// Инициализирует фигуру-стрелку
void initCircle1(Circle &circle)
{
    circle.position = {310, 300};
    circle.head.setRadius(16);
    circle.head.setOrigin(-2, 16);
    circle.head.setFillColor(Color::Cyan);

    updateCircle1Elements(circle);
}

void initCircle2(Circle &circle)
{
    circle.position = {490, 300};
    circle.head.setRadius(16);
    circle.head.setOrigin(-2, 16);
    circle.head.setFillColor(Color::Cyan);

    updateCircle2Elements(circle);
}

void onMouseMove(const Event::MouseMoveEvent &event, Vector2f &mousePosition)
{
    cout << "mouse x=" << event.x << " , y=" << event.y << endl;

    mousePosition = {float(event.x), float(event.y)};
}

// Опрашивает и обрабатывает доступные события в цикле.
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

// Обновляет фигуру, указывающую на мышь
void updateCircle1(const Vector2f &mousePosition, Circle &circle)
{
    const Vector2f delta = mousePosition - circle.position;
    circle.rotation = atan2(delta.y, delta.x);
    updateCircle1Elements(circle);
}

void updateCircle2(const Vector2f &mousePosition, Circle &circle)
{
    const Vector2f delta = mousePosition - circle.position;
    circle.rotation = atan2(delta.y, delta.x);
    updateCircle2Elements(circle);
}

void update(const Vector2f &mousePosition, Circle &circle1, Circle &circle2)
{
    updateCircle1(mousePosition, circle1);
    updateCircle2(mousePosition, circle2);
}

void initShapes(ConvexShape &shape1, ConvexShape &shape2)
{
    const Vector2f shapeRadius = {75.f, 150.f};
    constexpr int pointCount = 200;

    shape1.setPosition({310, 300});
    shape1.setFillColor(Color::White);

    shape2.setPosition({490, 300});
    shape2.setFillColor(Color::White);

    shape1.setPointCount(pointCount);
    shape2.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        Vector2f point = {
            shapeRadius.x * sin(angle),
            shapeRadius.y * cos(angle)};
        shape1.setPoint(pointNo, point);
        shape2.setPoint(pointNo, point);
    }
}

// Рисует и выводит один кадр
void redrawFrame(RenderWindow &window, Circle &circle1, Circle &circle2, Shape &shape1, Shape &shape2)
{
    window.clear();
    window.draw(shape1);
    window.draw(shape2);
    window.draw(circle1.head);
    window.draw(circle2.head);
    window.display();
}

// Программа рисует в окне стрелку, которая поворачивается вслед за курсором мыши.
int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(
        VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Eye1", Style::Default, settings);

    Circle circle1;
    Circle circle2;
    Vector2f mousePosition;

    sf::ConvexShape shape1;
    sf::ConvexShape shape2;

    initCircle1(circle1);
    initCircle2(circle2);
    initShapes(shape1, shape2);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, circle1, circle2);
        redrawFrame(window, circle1, circle2, shape1, shape2);
    }
}