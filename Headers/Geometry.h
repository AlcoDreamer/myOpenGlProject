//
//  Geometry.h
//  MyProject
//
//  Created by dchernyshev on 08.11.17.
//  Copyright © 2017 dchernyshev. All rights reserved.
//

#ifndef Geometry_h
#define Geometry_h

#include <math.h>
#include "glm/vec3.hpp"
#include <iostream>

const long double EPS = 1e-9;

struct Vect3ld {
    long double x, y, z;
    Vect3ld() : x(0), y(0), z(0) {};
    Vect3ld(long double x, long double y, long double z) : x(x), y(y), z(z) {};
    Vect3ld operator+ (Vect3ld v) const {
        return Vect3ld(x + v.x, y + v.y, z + v.z);
    }
    Vect3ld operator* (Vect3ld v) const {
        return Vect3ld(z * v.y - y * v.z, x * v.z - z * v.x, y * v.x - x * v.y);
    }
    Vect3ld operator* (long double k) const {
        return Vect3ld(x * k, y * k, z * k);
    }
    long double len() {
        return sqrt(x * x + y * y + z * z);
    }
    Vect3ld normal (long double newLen) const {
        if (Vect3ld(x, y, z).len() < EPS)
            return Vect3ld();
        return Vect3ld(x, y, z) * (newLen / Vect3ld(x, y, z).len());
    }
};

struct Vect2ll {
    long long x, y;
    Vect2ll() : x(0), y(0) {};
    Vect2ll(long long x, long long y) : x(x), y(y) {};
};

#endif /* Geometry_h */
