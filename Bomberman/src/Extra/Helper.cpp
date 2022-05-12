#include "Helper.h"

void Helper::createText(sf::Text& text, sf::Font& font, const std::string& content,
                              int font_size, sf::Color text_colour,
                              float x_pos,  float y_pos)
{
  text.setString(content);
  text.setFont(font);
  text.setCharacterSize(font_size);
  text.setFillColor(text_colour);
  text.setPosition(x_pos - text.getGlobalBounds().width / 2,y_pos - text.getGlobalBounds().height / 2);
}