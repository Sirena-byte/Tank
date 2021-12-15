////////////////////////////////////////////////////////////
//
// 
//SFML - простая и быстрая мультимедийная библиотека
// Copyright (C) 2007-2018 Лоран Гомила (laurent@sfml-dev.org)
//
// Это программное обеспечение предоставляется «как есть», без каких-либо явных или подразумеваемых гарантий.
// Ни в коем случае авторы не несут ответственности за любой ущерб, возникший в результате использования этого программного обеспечения.
//
// Всем предоставляется разрешение на использование этого программного обеспечения для любых целей,
// включая коммерческие приложения, а также свободно изменять и распространять его,
// со следующими ограничениями:
//
// 1. Не допускается искажение информации о происхождении этого программного обеспечения;
// вы не должны утверждать, что написали оригинальное программное обеспечение.
// Если вы используете это программное обеспечение в продукте, подтверждение
// в документации по продукту приветствуется, но не является обязательным.
//
// 2. Измененные исходные версии должны быть четко обозначены как таковые,
// и не должны быть искажены как оригинальное программное обеспечение.
//
// 3. Это примечание не может быть удалено или изменено из любого исходного дистрибутива.
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
template <typename T>
Rect<T>::Rect() :
left  (0),
top   (0),
width (0),
height(0)
{

}


////////////////////////////////////////////////////////////
template <typename T>
Rect<T>::Rect(T rectLeft, T rectTop, T rectWidth, T rectHeight) :
left  (rectLeft),
top   (rectTop),
width (rectWidth),
height(rectHeight)
{

}


////////////////////////////////////////////////////////////
template <typename T>
Rect<T>::Rect(const Vector2<T>& position, const Vector2<T>& size) :
left  (position.x),
top   (position.y),
width (size.x),
height(size.y)
{

}


////////////////////////////////////////////////////////////
template <typename T>
template <typename U>
Rect<T>::Rect(const Rect<U>& rectangle) :
left  (static_cast<T>(rectangle.left)),
top   (static_cast<T>(rectangle.top)),
width (static_cast<T>(rectangle.width)),
height(static_cast<T>(rectangle.height))
{
}


////////////////////////////////////////////////////////////
template <typename T>
bool Rect<T>::contains(T x, T y) const
{
    // Допускаются прямоугольники с отрицательными размерами, поэтому мы должны правильно с ними обращаться

    // Вычисляем реальный минимум и максимум прямоугольника по обеим осям
    T minX = std::min(left, static_cast<T>(left + width));
    T maxX = std::max(left, static_cast<T>(left + width));
    T minY = std::min(top, static_cast<T>(top + height));
    T maxY = std::max(top, static_cast<T>(top + height));

    return (x >= minX) && (x < maxX) && (y >= minY) && (y < maxY);
}


////////////////////////////////////////////////////////////
template <typename T>
bool Rect<T>::contains(const Vector2<T>& point) const
{
    return contains(point.x, point.y);
}


////////////////////////////////////////////////////////////
template <typename T>
bool Rect<T>::intersects(const Rect<T>& rectangle) const
{
    Rect<T> intersection;
    return intersects(rectangle, intersection);
}


////////////////////////////////////////////////////////////
template <typename T>
bool Rect<T>::intersects(const Rect<T>& rectangle, Rect<T>& intersection) const
{
    // Допускаются прямоугольники с отрицательными размерами, поэтому мы должны правильно с ними обращаться

    // Вычисление минимума и максимума первого прямоугольника по обеим осям
    T r1MinX = std::min(left, static_cast<T>(left + width));
    T r1MaxX = std::max(left, static_cast<T>(left + width));
    T r1MinY = std::min(top, static_cast<T>(top + height));
    T r1MaxY = std::max(top, static_cast<T>(top + height));

    // Вычислите минимум и максимум второго прямоугольника по обеим осям.
    T r2MinX = std::min(rectangle.left, static_cast<T>(rectangle.left + rectangle.width));
    T r2MaxX = std::max(rectangle.left, static_cast<T>(rectangle.left + rectangle.width));
    T r2MinY = std::min(rectangle.top, static_cast<T>(rectangle.top + rectangle.height));
    T r2MaxY = std::max(rectangle.top, static_cast<T>(rectangle.top + rectangle.height));

    // Вычислить границы пересечения
    T interLeft   = std::max(r1MinX, r2MinX);
    T interTop    = std::max(r1MinY, r2MinY);
    T interRight  = std::min(r1MaxX, r2MaxX);
    T interBottom = std::min(r1MaxY, r2MaxY);

    // Если пересечение действительное (положительная ненулевая площадь), то есть пересечение.
    if ((interLeft < interRight) && (interTop < interBottom))
    {
        intersection = Rect<T>(interLeft, interTop, interRight - interLeft, interBottom - interTop);
        return true;
    }
    else
    {
        intersection = Rect<T>(0, 0, 0, 0);
        return false;
    }
}


////////////////////////////////////////////////////////////
template <typename T>
inline bool operator ==(const Rect<T>& left, const Rect<T>& right)
{
    return (left.left == right.left) && (left.width == right.width) &&
           (left.top == right.top) && (left.height == right.height);
}


////////////////////////////////////////////////////////////
template <typename T>
inline bool operator !=(const Rect<T>& left, const Rect<T>& right)
{
    return !(left == right);
}
