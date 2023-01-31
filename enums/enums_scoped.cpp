/*
SCOPED ENUMS

- They are strongly typed (they won’t implicitly convert to integers)

- strongly scoped (the enumerators are only placed into the scope region of the enumeration).

*/

enum class Food
{
    apple,
    pear,
    porridge,
};

int main() {

    using enum Food; // bring all Food enumerators into current scope (C++20)
    // We can now access the enumerators of Color without using a Color:: prefix


    enum class Color // "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
    {
        red, // red is considered part of Color's scope region
        blue,
    };

    enum class Fruit
    {
        banana, // banana is considered part of Fruit's scope region
        apple,
    };

    Color color { Color::red }; // note: red is not directly accessible, we have to use Color::red
    Fruit fruit { Fruit::banana }; // note: banana is not directly accessible, we have to use Fruit::banana

    if (color == fruit) // compile error: the compiler doesn't know how to compare different types Color and Fruit
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n";


    return 0;
}