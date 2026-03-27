#pragma once

#include "Vector4.h"

struct Matrix4 {
    float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;

    Matrix4() {     // Default Constructor
        m1 = 1; m2 = 0;
        m3 = 0; m4 = 0;
        m5 = 0; m6 = 1;
        m7 = 0; m8 = 0;
        m9 = 0; m10 = 0;
        m11 = 1; m12 = 0;
        m13 = 0; m14 = 0;
        m15 = 0; m16 = 1;
    }

    Matrix4(const Matrix4& m) {     // Copy Constructor
        m1 = m.m1; m2 = m.m2;
        m3 = m.m3; m4 = m.m4;
        m5 = m.m5; m6 = m.m6;
        m7 = m.m7; m8 = m.m8;
        m9 = m.m9; m10 = m.m10;
        m11 = m.m11; m12 = m.m12;
        m13 = m.m13; m14 = m.m14;
        m15 = m.m15; m16 = m.m16;
    }

    Matrix4(float ma1, float ma2, float ma3, float ma4, float ma5, float ma6, float ma7, float ma8, float ma9, float ma10, float ma11, float ma12, float ma13, float ma14, float ma15, float ma16) {    // Parameterised Constructor
        m1 = ma1; m2 = ma2;
        m3 = ma3; m4 = ma4;
        m5 = ma5; m6 = ma6;
        m7 = ma7; m8 = ma8;
        m9 = ma9; m10 = ma10;
        m11 = ma11; m12 = ma12;
        m13 = ma13; m14 = ma14;
        m15 = ma15; m16 = ma16;
    }

    Matrix4 operator = (Matrix4 m) { // Assignment
        m1 = m.m1; m2 = m.m2;
        m3 = m.m3; m4 = m.m4;
        m5 = m.m5; m6 = m.m6;
        m7 = m.m7; m8 = m.m8;
        m9 = m.m9; m10 = m.m10;
        m11 = m.m11; m12 = m.m12;
        m13 = m.m13; m14 = m.m14;
        m15 = m.m15; m16 = m.m16;
        return *this;
    }

    MathLibrary::Vector4 operator * (MathLibrary::Vector4 v) { // Multiplication with Vectors
        return MathLibrary::Vector4((v.x * m1) + (v.y * m5) + (v.z * m9) + (v.w * m13),
            (v.x * m2) + (v.y * m6) + (v.z * m10) + (v.w * m14),
            (v.x * m3) + (v.y * m7) + (v.z * m11) + (v.w * m15),
            (v.x * m4) + (v.y * m8) + (v.z * m12) + (v.w * m16)
        );
    }



    Matrix4 operator * (Matrix4 m) { // Multiplication
        Matrix4* ma2 = new Matrix4;
        // Row 1
        ma2->m1 = (m1 * m.m1) + (m5 * m.m2) + (m9 * m.m3) + (m13 * m.m4);
        ma2->m5 = (m1 * m.m5) + (m5 * m.m6) + (m9 * m.m7) + (m13 * m.m8);
        ma2->m9 = (m1 * m.m9) + (m5 * m.m10) + (m9 * m.m11) + (m13 * m.m12);
        ma2->m13 = (m1 * m.m13) + (m5 * m.m14) + (m9 * m.m15) + (m13 * m.m16);
        // Row 2
        ma2->m2 = (m2 * m.m1) + (m6 * m.m2) + (m10 * m.m3) + (m14 * m.m4);
        ma2->m6 = (m2 * m.m5) + (m6 * m.m6) + (m10 * m.m7) + (m14 * m.m8);
        ma2->m10 = (m2 * m.m9) + (m6 * m.m10) + (m10 * m.m11) + (m14 * m.m12);
        ma2->m14 = (m2 * m.m13) + (m6 * m.m14) + (m10 * m.m15) + (m14 * m.m16);
        // Row 3
        ma2->m3 = (m3 * m.m1) + (m9 * m.m2) + (m11 * m.m3) + (m15 * m.m4);
        ma2->m7 = (m3 * m.m5) + (m9 * m.m6) + (m11 * m.m7) + (m15 * m.m8);
        ma2->m11 = (m3 * m.m9) + (m9 * m.m10) + (m11 * m.m11) + (m15 * m.m12);
        ma2->m15 = (m3 * m.m13) + (m9 * m.m14) + (m11 * m.m15) + (m15 * m.m16);
        // Row 4
        ma2->m4 = (m4 * m.m1) + (m8 * m.m2) + (m12 * m.m3) + (m16 * m.m4);
        ma2->m8 = (m4 * m.m5) + (m8 * m.m6) + (m12 * m.m7) + (m16 * m.m8);
        ma2->m12 = (m4 * m.m9) + (m8 * m.m10) + (m12 * m.m11) + (m16 * m.m12);
        ma2->m16 = (m4 * m.m13) + (m8 * m.m14) + (m12 * m.m15) + (m16 * m.m16);

        return *ma2;
    }

    Matrix4 operator *= (Matrix4 m) { // Multiplication Assignment
        Matrix4* ma2 = new Matrix4;
        // Row 1
        ma2->m1 = (m1 * m.m1) + (m5 * m.m2) + (m9 * m.m3) + (m13 * m.m4);
        ma2->m5 = (m1 * m.m5) + (m5 * m.m6) + (m9 * m.m7) + (m13 * m.m8);
        ma2->m9 = (m1 * m.m9) + (m5 * m.m10) + (m9 * m.m11) + (m13 * m.m12);
        ma2->m13 = (m1 * m.m13) + (m5 * m.m14) + (m9 * m.m15) + (m13 * m.m16);
        // Row 2
        ma2->m2 = (m2 * m.m1) + (m6 * m.m2) + (m10 * m.m3) + (m14 * m.m4);
        ma2->m6 = (m2 * m.m5) + (m6 * m.m6) + (m10 * m.m7) + (m14 * m.m8);
        ma2->m10 = (m2 * m.m9) + (m6 * m.m10) + (m10 * m.m11) + (m14 * m.m12);
        ma2->m14 = (m2 * m.m13) + (m6 * m.m14) + (m10 * m.m15) + (m14 * m.m16);
        // Row 3
        ma2->m3 = (m3 * m.m1) + (m9 * m.m2) + (m11 * m.m3) + (m15 * m.m4);
        ma2->m7 = (m3 * m.m5) + (m9 * m.m6) + (m11 * m.m7) + (m15 * m.m8);
        ma2->m11 = (m3 * m.m9) + (m9 * m.m10) + (m11 * m.m11) + (m15 * m.m12);
        ma2->m15 = (m3 * m.m13) + (m9 * m.m14) + (m11 * m.m15) + (m15 * m.m16);
        // Row 4
        ma2->m4 = (m4 * m.m1) + (m8 * m.m2) + (m12 * m.m3) + (m16 * m.m4);
        ma2->m8 = (m4 * m.m5) + (m8 * m.m6) + (m12 * m.m7) + (m16 * m.m8);
        ma2->m12 = (m4 * m.m9) + (m8 * m.m10) + (m12 * m.m11) + (m16 * m.m12);
        ma2->m16 = (m4 * m.m13) + (m8 * m.m14) + (m12 * m.m15) + (m16 * m.m16);

        *this = *ma2;
        return *ma2;
    }

    const bool operator == (Matrix4 m) const { // Equality
        if ((m1 == m.m1) && (m2 == m.m2) && (m3 == m.m3) && (m4 == m.m4)) {
            if ((m5 == m.m5) && (m6 == m.m6) && (m7 == m.m7) && (m8 == m.m8)) {
                if ((m9 == m.m9) && (m10 == m.m10) && (m11 == m.m11) && (m12 == m.m12)) {
                    if ((m13 == m.m13) && (m14 == m.m14) && (m15 == m.m15) && (m16 == m.m16)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool operator != (Matrix4 m) { // Equality
        if ((m1 == m.m1) && (m2 == m.m2) && (m3 == m.m3) && (m4 == m.m4)) {
            if ((m5 == m.m5) && (m6 == m.m6) && (m7 == m.m7) && (m8 == m.m8)) {
                if ((m9 == m.m9) && (m10 == m.m10) && (m11 == m.m11) && (m12 == m.m12)) {
                    if ((m13 == m.m13) && (m14 == m.m14) && (m15 == m.m15) && (m16 == m.m16)) {
                        return false;
                    }
                }
            }
        }
        return false;
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
        else if (i == 9) { return m10; }
        else if (i == 10) { return m11; }
        else if (i == 11) { return m12; }
        else if (i == 12) { return m13; }
        else if (i == 13) { return m14; }
        else if (i == 14) { return m15; }
        else if (i == 15) { return m16; }
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
        else if (i == 9) { return m10; }
        else if (i == 10) { return m11; }
        else if (i == 11) { return m12; }
        else if (i == 12) { return m13; }
        else if (i == 13) { return m14; }
        else if (i == 14) { return m15; }
        else if (i == 15) { return m16; }
    }


    static Matrix4 MakeRotateX(float f) {
        return Matrix4(1, 0, 0, 0, 0, cosf(f), -sinf(f), 0, 0, sinf(f), cosf(f), 0, 0, 0, 0, 1);
    }


    static Matrix4 MakeRotateY(float f) {
        return Matrix4(cosf(f), 0, sinf(f), 0, 0, 1, 0, 0, -sinf(f), 0, cosf(f), 0, 0, 0, 0, 1);
    }

    static Matrix4 MakeRotateZ(float f) {
        return Matrix4(cosf(f), sinf(f), 0, 0,
            -sinf(f), cosf(f), 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);
    }

    static Matrix4 MakeScale(float x, float y, float z) {
        return Matrix4(x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1);
    }

    MathLibrary::Vector4 GetForward() {
        return MathLibrary::Vector4(m9, m10, m11, m12);
    }

    MathLibrary::Vector4 GetRight() {
        return MathLibrary::Vector4(m1, m2, m3, m4);
    }

    MathLibrary::Vector4 GetUp() {
        return MathLibrary::Vector4(m5, m6, m7, m8);
    }

    MathLibrary::Vector4 GetPosition() {
        return MathLibrary::Vector4(m13, m14, m15, m16);
    }

    bool IsApproximatelyEqual(Matrix4 m) const {
        if ((m.m1 > (m1 - 1e-4)) && (m.m1 < (m1 + 1e-4)) && (m.m2 > (m2 - 1e-4)) && (m.m2 < (m2 + 1e-4)) && (m.m3 > (m3 - 1e-4)) && (m.m3 < (m3 + 1e-4))) {
            if ((m.m4 > (m4 - 1e-4)) && (m.m4 < (m4 + 1e-4)) && (m.m5 > (m5 - 1e-4)) && (m.m5 < (m5 + 1e-4)) && (m.m6 > (m6 - 1e-4)) && (m.m6 < (m6 + 1e-4))) {
                if ((m.m7 > (m7 - 1e-4)) && (m.m7 < (m7 + 1e-4)) && (m.m8 > (m8 - 1e-4)) && (m.m8 < (m8 + 1e-4)) && (m.m9 > (m9 - 1e-4)) && (m.m9 < (m9 + 1e-4))) {
                    if ((m.m10 > (m10 - 1e-4)) && (m.m10 < (m10 + 1e-4)) && (m.m11 > (m11 - 1e-4)) && (m.m11 < (m11 + 1e-4)) && (m.m12 > (m12 - 1e-4)) && (m.m12 < (m12 + 1e-4))) {
                        if ((m.m13 > (m13 - 1e-4)) && (m.m13 < (m13 + 1e-4)) && (m.m14 > (m14 - 1e-4)) && (m.m14 < (m14 + 1e-4)) && (m.m15 > (m15 - 1e-4)) && (m.m15 < (m15 + 1e-4))) {
                            if ((m.m13 > (m13 - 1e-4)) && (m.m13 < (m13 + 1e-4))) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    void SetTranslate(float x, float y, float z) {
        m13 = x;
        m14 = y;
        m15 = z;
    }

    static Matrix4 MakeTranslation(float x, float y, float z) {
        return Matrix4(1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            x, y, z, 1);
    }

};
