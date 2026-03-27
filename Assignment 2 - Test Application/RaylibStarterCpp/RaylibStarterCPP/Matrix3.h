#pragma once

#include "Vector3.h"

struct Matrix3 {
    float m1, m2, m3, m4, m5, m6, m7, m8, m9;

    Matrix3() {     // Default Constructor
        m1 = 1;
        m2 = 0;
        m3 = 0;
        m4 = 0;
        m5 = 1;
        m6 = 0;
        m7 = 0;
        m8 = 0;
        m9 = 1;
    }

    Matrix3(const Matrix3& m) {     // Copy Constructor
        m1 = m.m1;
        m2 = m.m2;
        m3 = m.m3;
        m4 = m.m4;
        m5 = m.m5;
        m6 = m.m6;
        m7 = m.m7;
        m8 = m.m8;
        m9 = m.m9;
    }

    Matrix3(float ma1, float ma2, float ma3, float ma4, float ma5, float ma6, float ma7, float ma8, float ma9) {    // Parameterised Constructor
        m1 = ma1;
        m2 = ma2;
        m3 = ma3;
        m4 = ma4;
        m5 = ma5;
        m6 = ma6;
        m7 = ma7;
        m8 = ma8;
        m9 = ma9;
    }

    Matrix3 operator = (Matrix3 m) {        // Assignment
        m1 = m.m1;
        m2 = m.m2;
        m3 = m.m3;
        m4 = m.m4;
        m5 = m.m5;
        m6 = m.m6;
        m7 = m.m7;
        m8 = m.m8;
        m9 = m.m9;
        return *this;
    }

    MathLibrary::Vector3 operator * (MathLibrary::Vector3 v) const {        // Multiply by Vector
        return (MathLibrary::Vector3(m1, m2, m3) * v.x) + (MathLibrary::Vector3(m4, m5, m6) * v.y) + (MathLibrary::Vector3(m7, m8, m9) * v.z);
    }

    const Matrix3 operator * (Matrix3 m) const {  // Multiply
        Matrix3* ma2 = new Matrix3;
        ma2->m1 = (m1 * m.m1) + (m4 * m.m2) + (m7 * m.m3);
        ma2->m4 = (m1 * m.m4) + (m4 * m.m5) + (m7 * m.m6);
        ma2->m7 = (m1 * m.m7) + (m4 * m.m8) + (m7 * m.m9);
        ma2->m2 = (m2 * m.m1) + (m5 * m.m2) + (m8 * m.m3);
        ma2->m5 = (m2 * m.m4) + (m5 * m.m5) + (m8 * m.m6);
        ma2->m8 = (m2 * m.m7) + (m5 * m.m8) + (m8 * m.m9);
        ma2->m3 = (m3 * m.m1) + (m6 * m.m2) + (m9 * m.m3);
        ma2->m6 = (m3 * m.m4) + (m6 * m.m5) + (m9 * m.m6);
        ma2->m9 = (m3 * m.m7) + (m6 * m.m8) + (m9 * m.m9);
        return *ma2;
    }

    Matrix3 operator *= (Matrix3 m) {       // Multiply Assignment
        Matrix3 ma2;
        ma2.m1 = (m1 * m.m1) + (m4 * m.m2) + (m7 * m.m3);
        ma2.m4 = (m1 * m.m4) + (m4 * m.m5) + (m7 * m.m6);
        ma2.m7 = (m1 * m.m7) + (m4 * m.m8) + (m7 * m.m9);
        ma2.m2 = (m2 * m.m1) + (m5 * m.m2) + (m8 * m.m3);
        ma2.m5 = (m2 * m.m4) + (m5 * m.m5) + (m8 * m.m6);
        ma2.m8 = (m2 * m.m7) + (m5 * m.m8) + (m8 * m.m9);
        ma2.m3 = (m3 * m.m1) + (m6 * m.m2) + (m9 * m.m3);
        ma2.m6 = (m3 * m.m4) + (m6 * m.m5) + (m9 * m.m6);
        ma2.m9 = (m3 * m.m7) + (m6 * m.m8) + (m9 * m.m9);
        *this = ma2;
        return *this;
    }

    const bool operator == (Matrix3 m) const {          // Equality
        if (m1 == m.m1 && (m2 == m.m2) && (m3 == m.m3) && (m4 == m.m4) && (m5 == m.m5) && (m6 == m.m6) && (m7 == m.m7) && (m8 == m.m8) && (m9 == m.m9)) {
            return true;
        }
        return false;
    }

    bool operator != (Matrix3 m) {          // Inequality
        if (m1 == m.m1 && (m2 == m.m2) && (m3 == m.m3) && (m4 == m.m4) && (m5 == m.m5) && (m6 == m.m6) && (m7 == m.m7) && (m8 == m.m8) && (m9 == m.m9)) {
            return false;
        }
        return true;
    }

    float& operator [] (int i) { // Index
        if (i == 0) { return m1; }
        else if (i == 1) { return m2; }
        else if (i == 2) { return m3; }
        else if (i == 3) { return m4; }
        else if (i == 4) { return m5; }
        else if (i == 5) { return m6; }
        else if (i == 6) { return m7; }
        else if (i == 7) { return m8; }
        else if (i == 8) { return m9; }
    }

    const float& operator [] (int i) const { // Index
        if (i == 0) { return m1; }
        else if (i == 1) { return m2; }
        else if (i == 2) { return m3; }
        else if (i == 3) { return m4; }
        else if (i == 4) { return m5; }
        else if (i == 5) { return m6; }
        else if (i == 6) { return m7; }
        else if (i == 7) { return m8; }
        else if (i == 8) { return m9; }
    }

    static Matrix3 MakeRotate(float f) {
        Matrix3* matrix = new Matrix3;
        matrix->m1 = cos(f); matrix->m4 = -sin(f); matrix->m7 = 0;
        matrix->m2 = sin(f); matrix->m5 = cos(f); matrix->m8 = 0;
        matrix->m3 = 0;       matrix->m6 = 0;      matrix->m9 = 1;
        return *matrix;
    }

    static Matrix3 MakeScale(float x, float y) {
        Matrix3* matrix = new Matrix3;
        matrix->m1 = x;     matrix->m4 = 0;   matrix->m7 = 0;
        matrix->m2 = 0;     matrix->m5 = y;   matrix->m8 = 0;
        matrix->m3 = 0;     matrix->m6 = 0;   matrix->m9 = 1;
        return *matrix;
    }

    static Matrix3 MakeTranslate(float x, float y) {
        Matrix3* matrix = new Matrix3;
        matrix->m1 = 1;     matrix->m4 = 0;   matrix->m7 = x;
        matrix->m2 = 0;     matrix->m5 = 0;   matrix->m8 = y;
        matrix->m3 = 0;     matrix->m6 = 0;   matrix->m9 = 1;
        return *matrix;
    }

    MathLibrary::Vector3 GetRight() {
        return MathLibrary::Vector3(m4, m5, m6);
    }

    MathLibrary::Vector3 GetForward() {
        return MathLibrary::Vector3(m1, m2, m3);
    }

    MathLibrary::Vector3 GetTranslate() {
        return MathLibrary::Vector3(m7, m8, m9);
    }

    bool IsApproximatelyEqual(Matrix3 m) const {
        if ((m.m1 > (m1 - 1e-4)) && (m.m1 < (m1 + 1e-4)) && (m.m2 > (m2 - 1e-4)) && (m.m2 < (m2 + 1e-4)) && (m.m3 > (m3 - 1e-4)) && (m.m3 < (m3 + 1e-4))) {
            if ((m.m4 > (m4 - 1e-4)) && (m.m4 < (m4 + 1e-4)) && (m.m5 > (m5 - 1e-4)) && (m.m5 < (m5 + 1e-4)) && (m.m6 > (m6 - 1e-4)) && (m.m6 < (m6 + 1e-4))) {
                if ((m.m7 > (m7 - 1e-4)) && (m.m7 < (m7 + 1e-4)) && (m.m8 > (m8 - 1e-4)) && (m.m8 < (m8 + 1e-4)) && (m.m9 > (m9 - 1e-4)) && (m.m9 < (m9 + 1e-4))) {
                    return true;
                }
            }
        }
        return false;
    }

};
