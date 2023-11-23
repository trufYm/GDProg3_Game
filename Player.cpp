#include <Player.hpp>

Player::Player() //Default constructor
{
    if (!texture.loadFromFile("donpersimmon.png"))
        cout << "Error loading player texture." << endl;

    sprite.setTexture(texture);
    sprite.setPosition(1000, 1000);

    speed = 10;

    up = false;
    down = false;
    left = false;
    right = false;

    dt = 0;
    mult = 60.f;
}

Player::Player(string name)
{
    playerName = name;
    if (!texture.loadFromFile("donpersimmon.png"))
        cout << "Error loading player texture." << endl;

    sprite.setTexture(texture);
    sprite.setPosition(1000, 1000);

    speed = 10;

    up = false;
    down = false;
    left = false;
    right = false;

    dt = 0;
    mult = 60.f;
}

//Process keyboard input
void Player::processEvents(Keyboard::Key key, bool isPressed)
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
void Player::update()
{
    Vector2f movement;
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

//Helper functions

void Player::drawTo(RenderWindow& window)
{
    window.draw(sprite);
}

Sprite Player::getSprite()
{
    return sprite;
}

Vector2f Player::getPosition()
{
    return sprite.getPosition();
}

FloatRect Player::getGlobalBounds()
{
    return sprite.getGlobalBounds();
}

float Player::getSpeed()
{
    return speed;
}

void Player::setPosition(Vector2f pos)
{
    sprite.setPosition(pos.x, pos.y);
}
