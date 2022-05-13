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
    Text(const std::string& text, const int posX, const int posY)
    {
        SetText(text);
        SetPosX(posX);
        SetPosY(posY);
    }

    /**
     * Initializes a new Text object.
     * @param text Text to initialize.
     * @param position Vector2 position of the text.
     * @return void.
     */
    Text(const std::string& text, const ::Vector2& position)
    {
        SetText(text);
        SetPosX(static_cast<int>(position.x));
        SetPosY(static_cast<int>(position.y));
    }

    ~Text() {
    }

    /**
     * @brief Draw text with values in class.
     * 
     */
    void DrawText() {
        ::DrawText(_text.c_str(), _posX, _posY, _fontSize, _color);
    }
  
    std::string GetText() const { return _text; }
    void SetText(const std::string& text) { _text = text; }

    int GetFontSize() const { return _fontSize; }
    void SetFontSize(int fontSize) { _fontSize = fontSize; }

    // Font GetFont() const { return _font; }
    // void SetFont(const Font& font) { _font = font; }

    Color GetColor() const { return _color; }
    void SetColor(const Color& color) { _color = color; }

    int GetPosX() const { return _posX; }
    void SetPosX(int posX) { _posX = posX; }

    int GetPosY() const { return _posY; }
    void SetPosY(int posY) { _posY = posY; }

    Text& operator=(const Text& text) {
        return *this;
    }

    /**
     * Draw text using font and color
     *
     * @see ::DrawText
     */
    static inline void DrawText(const std::string& text, const int posX, const int posY, const int fontSize, const ::Color& color) {
        ::DrawText(text.c_str(), posX, posY, fontSize, color);
    }

    /**
     * Draw text using font and color, with position defined as Vector2
     *
     * @see ::DrawText
     */
    static inline void DrawText(const std::string& text, const ::Vector2& pos, const int fontSize, const ::Color& color) {
        ::DrawText(text.c_str(), static_cast<int>(pos.x), static_cast<int>(pos.y), fontSize, color);
    }

    /**
     * Draw text using font, color, position, font size and spacing
     *
     * @see ::DrawTextEx
     */
    static inline void DrawTextEx(const Font& font, const std::string& text, const ::Vector2& position, const float fontSize, const float spacing, const ::Color& color) {
        ::DrawTextEx(font, text.c_str(), position, fontSize, spacing, color);
    }

    /**
     * Draw text using font, color, position, origin, font size and spacing
     *
     * @see ::DrawTextPro
     */
    static inline void DrawTextPro(const Font& font, const std::string& text, const ::Vector2& position, const ::Vector2& origin, const float rotation, const float fontSize, const float spacing, const ::Color& color) {
        ::DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize, spacing, color);
    }

  private:
    std::string _text = "";
    int _fontSize = 10;
    // Font _font;
    Color _color = WHITE;
    int _posX = 0;
    int _posY = 0;
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_TEXT_HPP_
