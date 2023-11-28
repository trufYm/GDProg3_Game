#include <Player.hpp>

Player::Player() //Default constructor
{
    texture = loadPlayerTexture(1);

    sprite.setTexture(texture);
    sprite.setScale(2, 2);
    sprite.setPosition(1000, 1000);

    speed = 10;

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

void Player::changeSpriteTexture(int currentEra)
{
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
