#pragma once
#include "settings.h"
struct RandomObjects {
    sf::Texture texture;
    sf::Sprite sprite;
    bool visible; // ����, �����������, ������ �� ������ ���� ���������
};
void RandomObjectsINIT(RandomObjects& obj, std::string fileName) {
    obj.texture.loadFromFile(fileName);
    obj.sprite.setTexture(obj.texture);
    obj.visible = false;
}
void randomizePosition(RandomObjects& obj) {
    int x = rand() % 1000;
    int y = rand() % 1000;
    obj.sprite.setPosition(x, y);
}
bool isOnScreen(int screenWidth, int screenHeight, RandomObjects& obj) {
    sf::FloatRect bounds = obj.sprite.getGlobalBounds();
    return (bounds.left >= 0 && bounds.left + bounds.width <= screenWidth
        && bounds.top >= 0 && bounds.top + bounds.height <= screenHeight);
}

// ����� ��� ���������� ��������� �������
void RandomObjupdate(int screenWidth, int screenHeight, RandomObjects& obj) {
    // � ������������ 1/100 ������ ���������� ������� � ������������ � ��������� �������
   
        if (rand() % 300 == 1) {
            obj.visible = true;
            randomizePosition(obj);
        }
 
    // ���� ������ ����� � ��������� �� ��������� ������, �� �� ���������� ���������
    if (obj.visible == true && !isOnScreen(screenWidth, screenHeight, obj)) {
        obj.visible = false;
    }
}
void RandomObjectsDraw(sf::RenderWindow& window, RandomObjects& obj) {
    if (obj.visible == true) {
        window.draw(obj.sprite);
    }
}