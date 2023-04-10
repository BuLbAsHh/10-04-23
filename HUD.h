#pragma once
#include "settings.h"
struct HUD {
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible = true;
};
void HudInit(HUD& obj, std::string fileName) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
}

void HUDobjupdate(HUD& obj, sf::Vector2f pos,int a) {
    if (a == 1) {
        obj.sprite.setPosition(pos);
    }
}
void HudDraw(sf::RenderWindow& window, HUD& obj) {

    if (obj.visible == true) {
        window.draw(obj.sprite);
    }
}

class CursorArrow {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool visible;
public:
    CursorArrow() {
        texture.loadFromFile("sprites\\hud\\Cursor.png");
        sprite.setTexture(texture);
        visible = true;

    }
  
    void update(sf::Vector2f pos) {
        sprite.setPosition(pos);

    }
  
    void draw(sf::RenderWindow& window) {
        if (visible == true) {
            window.draw(sprite);
        }
    }
};