#include "Button.h"

Button::Button(float positionX, float positionY, float width, float height, Font font, std::string text, Color idleColour, Color hoverColour, Color activeColour) {
    this->shape.setRadius(width/2.0f);
    this->shape.setPosition(Vector2f(positionX,positionY));
    // Apply scaling to make it an oval
    this->shape.setScale(width / (width / 2.0f), height / (width / 2.0f));
    
    // Initialising button state
    isPressed = false;
    isHover = false;

    // Initialising button text
    this->font = font;
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(Color::Black);
    this->text.setCharacterSize(40);

    // Set text position to middle of button
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getRadius() * this->shape.getScale().x) - (this->text.getGlobalBounds().width / 2.0f),
        this->shape.getPosition().y + (this->shape.getRadius() * this->shape.getScale().y) - (this->text.getGlobalBounds().height / 2.0f) - (this->text.getGlobalBounds().height * 0.25f)
    );


    // Initialising button colours
    this->idleColour = idleColour;
    this->hoverColour = hoverColour;
    this->activeColour = activeColour;
    this->shape.setFillColor(this->idleColour);

    shape.setOutlineThickness(3);
    shape.setOutlineColor(Color::Black);
}

void Button::render(RenderTarget* target) {
    // Render the button
    target->draw(this->shape);
    target->draw(this->text);
}

void Button::updateButton(Vector2f(mousePosition)) {
    // Initialising button state
    isPressed = false;
    isHover = false;

    // If button is hovered by mouse
    if (this->shape.getGlobalBounds().contains(mousePosition)) {
        this->isHover = true;

        // If button is clicked
        if (Mouse::isButtonPressed(Mouse::Left)) {
            this->isPressed = true;
        }
    }

    // Changing button colour according to button state
    if (isHover && isPressed == true) {
        this->shape.setFillColor(this->activeColour);

    } else if (isHover == true && isPressed == false) {
        this->shape.setFillColor(this->hoverColour);

    } else if (isHover && isPressed == false) {
        this->shape.setFillColor(this->idleColour);
    } else {
        this->shape.setFillColor(this->idleColour); // If other cases occur
    }
}

const bool Button::getButtonState() {
    if (isPressed == true) {
        return true;
    }
    return false;
}

bool Button::isMouseOver(Vector2f mousePos) {
    FloatRect btnBounds = this->shape.getGlobalBounds(); //get the bounds of the button
    return btnBounds.contains(mousePos); //checks if mouse is hovering over button and within button bounds
}

Button::~Button() {}