#ifndef BOMBERMAN_HELPER_H
#define BOMBERMAN_HELPER_H

#include <SFML/Graphics.hpp>
class Helper
{
 public:
  static void createText(sf::Text& text, sf::Font& font, const std::string&
                                                           content, int font_size,
                         sf::Color text_colour, float x_pos, float y_pos);
};

#endif // BOMBERMAN_HELPER_H
