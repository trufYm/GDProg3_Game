#include <Player.hpp>

Player::Player() //Default constructor
{
    currentEra = 1;

    texture = loadPlayerTexture(currentEra);

    sprite.setTexture(texture);
    sprite.setScale(2, 2);
    sprite.setPosition(2000, 2000);

    speed = 6;

    up = false;
    down = false;
    left = false;
    right = false;
}

//Process keyboard input
void Player::processInput(Keyboard::Key key, bool isPressed)
{
    if (isPressed)
    {
        if (key == Keyboard::W)
            up = true;
        if (key == Keyboard::A)
            left = true;
        if (key == Keyboard::S)
            down = true;
        if (key == Keyboard::D)
            right = true;
    }
    else
    {
        up = false;
        down = false;
        left = false;
        right = false;
    }
}

/*Main movement function. Takes current speed value and multiplies by delta time
and a multiplier (depending on desired FPS) to be independent from framerate*/
void Player::movePlayer()
{
    Vector2f movement;

    float dt = 0;
    float mult = 60.f;

    dt = clock.restart().asSeconds();
    if (up)
        movement.y -= speed * dt * mult;
    if (down)
        movement.y += speed * dt * mult;
    if (left)
        movement.x -= speed * dt * mult;
    if (right)
        movement.x += speed * dt * mult;

    sprite.move(movement);
}

//Rocket
void Player::autoMove()
{
    Vector2f movement;

    float dt = 0;
    float mult = 60.f;

    dt = clock.restart().asSeconds();

    movement.x += 3 * dt * mult;
    movement.y = 0;

    sprite.move(movement);
}

void Player::changeCurrentEra(int era)
{
    if (currentEra == era)
        return;

    currentEra = era;

    texture = loadPlayerTexture(currentEra);

    sprite.setTexture(texture);
}

//Helper functions

void Player::drawTo(RenderWindow& window) const
{
    window.draw(sprite);
}

Vector2f Player::getPosition()
{
    return sprite.getPosition();
}

FloatRect Player::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

float Player::getSpeed() const
{
    return speed;
}

void Player::setPosition(Vector2f pos)
{
    sprite.setPosition(pos.x, pos.y);
}

void Player::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Player::changeSpriteColor()
{
    sprite.setColor(Color::Transparent);
}