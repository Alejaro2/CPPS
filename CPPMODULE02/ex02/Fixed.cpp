#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const int n) : _value(n << _fractionalBits) {}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed &src) { *this = src; }

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other)
    this->_value = other.getRawBits();
  return *this;
}

Fixed::~Fixed(void) {}


int Fixed::getRawBits(void) const { 
  return this->_value; 
}

void Fixed::setRawBits(int const raw) { 
  this->_value = raw; 
}

float Fixed::toFloat(void) const {
  return (float)this->_value / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const { 
  return this->_value >> _fractionalBits; 
}


bool Fixed::operator>(const Fixed &other) const {
  return this->_value > other._value;
}
bool Fixed::operator<(const Fixed &other) const {
  return this->_value < other._value;
}
bool Fixed::operator>=(const Fixed &other) const {
  return this->_value >= other._value;
}
bool Fixed::operator<=(const Fixed &other) const {
  return this->_value <= other._value;
}
bool Fixed::operator==(const Fixed &other) const {
  return this->_value == other._value;
}
bool Fixed::operator!=(const Fixed &other) const {
  return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
  Fixed result;
  result.setRawBits(this->_value + other._value);
  return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed result;
  result.setRawBits(this->_value - other._value);
  return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed result;
  long tmp;
  tmp = (long)this->_value * (long)other._value;
  result.setRawBits(tmp >> _fractionalBits);
  return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed result;
  long tmp;
  tmp = (long)this->_value << _fractionalBits;
  result.setRawBits(tmp / other._value);
  return result;
}

Fixed &Fixed::operator++(void) {
  this->_value++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  this->_value++;
  return tmp;
}

Fixed &Fixed::operator--(void) {
  this->_value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  this->_value--;
  return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a < b)
    return a;
  return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a < b)
    return a;
  return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a > b)
    return a;
  return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a > b)
    return a;
  return b;
}


std::ostream &operator<<(std::ostream &out, const Fixed &other) {
  out << other.toFloat();
  return out;
}
