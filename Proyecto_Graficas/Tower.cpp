#include "Tower.h"

void Tower::setPosition(int a, int b) {
    posicion.x = a;
    posicion.y = b;
}

vectorPos Tower::getPosition(int a, int b) {
    return posicion;
}
