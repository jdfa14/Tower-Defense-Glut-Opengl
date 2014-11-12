#pragma once
#include "StaticObject.h"

typedef struct {
    int x;
    int y;
} vectorPos;

class Tower : public StaticObject
{
    private:
        vectorPos posicion;
    public:
        Tower();
        void setPosition(int, int);
        void getPosition(int, int);
};

