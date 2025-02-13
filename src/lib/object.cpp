#include "object.hpp"
#include "vector2d.hpp"
#include <SDL_rect.h>
#include <SDL_render.h>
#include <cmath>
#include <cstdio>

Object::Object(Sprite sprite, Vector2d position, Vector2d velocity,
               Vector2d acceleration, float friction)
    : _sprite{sprite}, _position{position}, _velocity{velocity},
      _acceleration(acceleration), _friction{friction} {};
void Object::setPosition(const Vector2d pos) { this->_position = pos; }
Vector2d Object::getPosition() const { return this->_position; }
void Object::setXPosition(const float x) { this->_position.x = x; }
void Object::setYPosition(const float y) { this->_position.y = y; }
void Object::setVelocity(const Vector2d v) { this->_velocity = v; }
Vector2d Object::getVelocity() const { return this->_velocity; }
void Object::setAcceleration(const Vector2d a) { this->_acceleration = a; }
void Object::addAcceleration(const Vector2d a) { this->_acceleration = this->_acceleration + a; }
Vector2d Object::getAcceleration(const Vector2d a) const {
  return this->_acceleration;
}
void Object::addVelocity(const Vector2d v) {
  this->_velocity = this->_velocity + v;
}
void Object::move(const float ms) {
  this->_position = this->_position + this->_velocity * ms;
  this->_velocity = (this->_velocity + this->_acceleration * ms) * pow(1 - _friction, ms / 100);
}
void Object::draw(SDL_Renderer *renderer) const {
  this->_sprite.draw(renderer, this->_position);
}
