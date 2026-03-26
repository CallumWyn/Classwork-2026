#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

struct Vector4 {
    float x, y, z, w;

    Vector4() { // Default Constructor
        x = 0;
        y = 0;
        z = 0;
        w = 0;
    }

    Vector4(const Vector4& i) { // Copy Constructor
        x = i.x;
        y = i.y;
        z = i.z;
        w = i.w;
    }

    Vector4(float x1, float y1, float z1, float w1) { // Parameterised Constructor
        x = x1;
        y = y1;
        z = z1;
        w = w1;
    }

    Vector4 operator + (Vector4 v) {    // Addition
        Vector4* v1 = new Vector4;
        v1->x = x + v.x;
        v1->y = y + v.y;
        v1->z = z + v.z;
        v1->w = /*w + v.w*/w;
        return *v1;
    }

    Vector4 operator - (Vector4 v) {    // Subtraction
        Vector4* v1 = new Vector4;
        v1->x = x - v.x;
        v1->y = y - v.y;
        v1->z = z - v.z;
        v1->w = /*w - v.w*/w;
        return *v1;
    }

    Vector4 operator * (Vector4 v) {    // Multiplication
        Vector4* v1 = new Vector4;
        v1->x = x * v.x;
        v1->y = y * v.y;
        v1->z = z * v.z;
        v1->w = w * v.w;
        return *v1;
    }

    Vector4 operator / (Vector4 v) {    // Division
        Vector4* v1 = new Vector4;
        v1->x = x / v.x;
        v1->y = y / v.y;
        v1->z = z / v.z;
        v1->w = w / v.w;
        return *v1;
    }

    Vector4 operator * (float f) {      // Multiplication with Float
        Vector4* v1 = new Vector4;
        v1->x = x * f;
        v1->y = y * f;
        v1->z = z * f;
        v1->w = w;
        // v1->w = w * f;
        return *v1;
    }

    Vector4 operator / (float f) {      // Division with Float
        Vector4* v1 = new Vector4;
        v1->x = x / f;
        v1->y = y / f;
        v1->z = z / f;
        v1->w = w;
        // v1->w = w / f;
        return *v1;
    }

    Vector4 operator = (Vector4 v) {    // Assignment
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }

    Vector4 operator += (Vector4 v) {   // Addition Assignment
        x += v.x;
        y += v.y;
        z += v.z;
        //w += v.w;
        return *this;
    }

    Vector4 operator -= (Vector4 v) {   // Subtraction Assignment
        x -= v.x;
        y -= v.y;
        z -= v.z;
        // w -= v.w;
        return *this;
    }

    Vector4 operator *= (Vector4 v) {   // Multiplication Assignment
        x *= v.x;
        y *= v.y;
        z *= v.z;
        w *= v.w;
        return *this;
    }

    Vector4 operator *= (float f) {   // Multiplication Assignment
        x *= f;
        y *= f;
        z *= f;
        // w *= f;
        return *this;
    }

    Vector4 operator /= (float f) {   // Division Assignment
        x /= f;
        y /= f;
        z /= f;
        // w /= f;
        return *this;
    }

    Vector4 operator - () {             // Negative
        x *= -1;
        y *= -1;
        z *= -1;
        // w *= -1;
        return *this;
    }

    bool operator == (Vector4 v) const {      // Equality
        if ((x == v.x) && (y == v.y) && (z == v.z) && (w == v.w)) { return true; }
        else { return false; }
    }

    bool operator != (Vector4 v) {      // Inequality
        if ((x != v.x) || (y != v.y) || (z != v.z) || (w != v.w)) { return true; }
        else { return false; }
    }

    float& operator [] (int i) {
        if (i == 0) { return x; }
        else if (i == 1) { return y; }
        else if (i == 2) { return z; }
        else if (i == 3) { return w; }
    }

    const float& operator [] (int i) const {
        if (i == 0) { return x; }
        else if (i == 1) { return y; }
        else if (i == 2) { return z; }
        else if (i == 3) { return w; }
    }

    float Magnitude() {                 // Magnitude of the vector
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    // This one has to go below the magnitude function as it uses the magnitude to figure out which one is smaller
    bool operator < (Vector4 v) {      // Less than
        if (Magnitude() < v.Magnitude()) { return true; }
        else { return false; }
    }

    void Normalise() {
        float magnitude = Magnitude();
        if (magnitude != 0) {
            x /= magnitude;
            y /= magnitude;
            z /= magnitude;
        }
        else {
            x = 0;
            y = 0;
            z = 0;
        }

        // w /= magnitude;
    }

    Vector4 Normalised() {

        if (Magnitude() != 0) { return *(new Vector4(x / Magnitude(), y / Magnitude(), z / Magnitude(), w/*w / Magnitude()*/)); }
        else { return *(new Vector4(0, 0, 0, w)); }
    }

    float Dot(Vector4 v) {
        return x * v.x + y * v.y + z * v.z /*+ w * v.w*/;
    }

    Vector4 Cross(Vector4 v1) {
        Vector4* v3 = new Vector4;
        v3->x = (y * v1.z) - (z * v1.y);
        v3->y = (z * v1.x) - (x * v1.z);
        v3->z = (x * v1.y) - (y * v1.x);
        v3->w = 0;
        return *v3;
    }

    bool IsApproximatelyEqual(Vector4 v) const {


        if (//   Checks if v.x is between x +- 1e-4            Checks if v.y is between y +- 1e-4            Checks if v.z is between z +- 1e-4
            ((x - 1e-4) <= v.x) && ((x + 1e-4) >= v.x) && ((y - 1e-4) <= v.y) && ((y + 1e-4) >= v.y) && ((z - 1e-4) <= v.z) && ((w + 1e-4) >= v.w) && ((w - 1e-4) <= v.w) && ((w + 1e-4) >= v.w)) {
            return true;
        }
        return false;
    }

    float AngleBetween(Vector4 v) {
        float cos = (Dot(v)) / (Magnitude() * v.Magnitude());
        cos = acos(cos);

        return cos;
    }

    float Distance(Vector4 v) {
        Vector4* v2 = new Vector4;
        v2->x = -x + v.x;
        v2->y = -y + v.y;
        v2->z = -z + v.z;
        v2->w = -w + v.w;
        return v2->Magnitude();

    }

};