#ifndef RAYLIB_CPP_INCLUDE_TEXT_HPP_
#define RAYLIB_CPP_INCLUDE_TEXT_HPP_

#include <string>

#include "./raylib.hpp"
#include "./RaylibException.hpp"
#include "./raylib-cpp-utils.hpp"

namespace raylib {
/**
 * Text Functions.
 */
class Text {
 public:
    /**
     * Initializes a new Text object.
     * @param text Text to initialize.
     * @return void.
     */
    Text(const std::string& text = "")
    {
        SetText(text);
    }
    
    /**
     * Initializes a new Text object.
     * @param text Text to initialize.
     * @param posX X position of the text.
     * @param posY Y position of the text.
     * @return void.
     */
    Text(const std::string& text, const float posX, const float posY)
    {
        _text = text;
        _position.x = posX;
        _position.y = posY;
    }

    /**
     * Initializes a new Text object.
     * @param text Text to initialize.
     * @param posX X position of the text.
     * @param posY Y position of the text.
     * @return void.
     */
    Text(const std::string& text, const ::Vector2& position)
    {
        _text = text;
        _position = position;
    }

    /**
     * Initializes a new Text object.
     * @param font Font to initialize.
     * @param text Text to initialize.
     * @param posX X position of the text.
     * @param posY Y position of the text.
     * @return void.
     */
    Text(const ::Font& font, const std::string& text, const ::Vector2& position, const float fontSize, const float spacing, const ::Color& color)
    {
        _font = font;
        _text = text;
        _position = position;
        _fontSize = fontSize;
        _spacing = spacing;
        _color = color;
    }
    

    ~Text() {
    }

    /**
     * @brief Draw text with values in class.
     * 
     */
    void Draw() {
        ::DrawTextEx(_font, _text.c_str(), _position, _fontSize, _spacing, _color);
    }
  
    std::string GetText() const { return _text; }
    void SetText(const std::string& text) { _text = text; }

    float GetFontSize() const { return _fontSize; }
    void SetFontSize(float fontSize) { _fontSize = fontSize; }

    //Font GetFont() const { return _font; }
    void SetFont(const ::Font& font) { _font = font; }

    Color GetColor() const { return _color; }
    void SetColor(const ::Color& color) { _color = color; }

    float GetPosX() const { return _position.GetX(); }
    void SetPosX(float posX) { _position.SetX(posX); }

    float GetPosY() const { return _position.GetY(); }
    void SetPosY(float posY) { _position.SetY(posY); }

    Vector2 GetPosition() const { return _position; }
    void SetPosition(const ::Vector2& position) { _position = position; }

    float GetSpacing() const { return _spacing; }
    void SetSpacing(float spacing) { _spacing = spacing; }

    Text& operator=(const Text& text) {
        return *this;
    }

    /**
     * Draw text using font and color
     *
     * @see ::DrawText
     */
    static inline void Draw(const std::string& text, const int posX, const int posY, const int fontSize, const ::Color& color) {
        ::DrawText(text.c_str(), posX, posY, fontSize, color);
    }

    /**
     * Draw text using font and color, with position defined as Vector2
     *
     * @see ::DrawText
     */
    static inline void Draw(const std::string& text, const ::Vector2& pos, const int fontSize, const ::Color& color) {
        ::DrawText(text.c_str(), static_cast<int>(pos.x), static_cast<int>(pos.y), fontSize, color);
    }

    /**
     * Draw text using font, color, position, font size and spacing
     *
     * @see ::DrawTextEx
     */
    static inline void Draw(const ::Font& font, const std::string& text, const ::Vector2& position, const float fontSize, const float spacing, const ::Color& color) {
        ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, color);
    }

    /**
     * Draw text using font, color, position, origin, font size and spacing
     *
     * @see ::DrawTextPro
     */
    static inline void Draw(const ::Font& font, const std::string& text, const ::Vector2& position, const ::Vector2& origin, const float rotation, const float fontSize, const float spacing, const ::Color& color) {
        ::DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, color);
    }

  private:
    std::string _text = "";
    float _fontSize = 10;
    Font _font = ::GetFontDefault();
    Color _color = WHITE;
    Vector2 _position = {0.0, 0.0};
    float _spacing = 0;
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_TEXT_HPP_
