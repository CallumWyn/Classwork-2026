
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

struct Vector3 {
    float x, y, z;

    Vector3() { // Default Constructor
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3(const Vector3& i) { // Copy Constructor
        x = i.x;
        y = i.y;
        z = i.z;
    }

    Vector3(float x1, float y1, float z1) { // Parameterised Constructor
        x = x1;
        y = y1;
        z = z1;
    }

    Vector3 operator + (Vector3 v) {    // Addition
        Vector3* v1 = new Vector3;
        v1->x = x + v.x;
        v1->y = y + v.y;
        v1->z = z + v.z;
        return *v1;
    }

    Vector3 operator - (Vector3 v) {    // Subtraction
        Vector3* v1 = new Vector3;
        v1->x = x - v.x;
        v1->y = y - v.y;
        v1->z = z - v.z;
        return *v1;
    }

    Vector3 operator * (Vector3 v) {    // Multiplication
        Vector3* v1 = new Vector3;
        v1->x = x * v.x;
        v1->y = y * v.y;
        v1->z = z * v.z;
        return *v1;
    }

    Vector3 operator / (Vector3 v) {    // Division
        Vector3* v1 = new Vector3;
        v1->x = x / v.x;
        v1->y = y / v.y;
        v1->z = z / v.z;
        return *v1;
    }

    Vector3 operator * (float f) {      // Multiplication with Float
        Vector3* v1 = new Vector3;
        v1->x = x * f;
        v1->y = y * f;
        v1->z = z * f;
        return *v1;
    }

    Vector3 operator / (float f) {      // Division with Float
        Vector3* v1 = new Vector3;
        v1->x = x / f;
        v1->y = y / f;
        v1->z = z / f;
        return *v1;
    }

    Vector3 operator = (Vector3 v) {    // Assignment
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Vector3 operator += (Vector3 v) {   // Addition Assignment
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3 operator -= (Vector3 v) {   // Subtraction Assignment
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector3 operator *= (Vector3 v) {   // Multiplication Assignment
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    Vector3 operator *= (float f) {   // Multiplication Assignment
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    Vector3 operator /= (float f) {   // Division Assignment
        x /= f;
        y /= f;
        z /= f;
        return *this;
    }

    Vector3 operator - () {             // Negative
        Vector3* v = new Vector3;
        v->x = x * -1;
        v->y = y * -1;
        v->z = z * -1;
        return *v;
    }

    bool operator == (Vector3 v) {      // Equality
        if ((x == v.x) && (y == v.y) && (z == v.z)) { return true; }
        else { return false; }
    }

    bool operator != (Vector3 v) {      // Inequality
        if ((x != v.x) || (y != v.y) || (z != v.z)) { return true; }
        else { return false; }
    }

    float& operator [] (int i) {
        if (i == 0) { return x; }
        else if (i == 1) { return y; }
        else if (i == 2) { return z; }
    }

    const float& operator [] (int i) const {
        if (i == 0) { return x; }
        else if (i == 1) { return y; }
        else if (i == 2) { return z; }
    }

    float Magnitude() {                 // Magnitude of the vector
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    // This one has to go below the magnitude function as it uses the magnitude to figure out which one is smaller
    bool operator < (Vector3 v) {      // Less than
        if (Magnitude() < v.Magnitude()) { return true; }
        else { return false; }
    }

    void Normalise() {
        float magnitude = Magnitude();
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
    }

    Vector3 Normalised() {
        return Vector3(x / Magnitude(), y / Magnitude(), z / Magnitude());
    }

    float Dot(Vector3 v) {
        return x * v.x + y * v.y + z * v.z;
    }

    Vector3 Cross(Vector3 v1) {
        Vector3* v3 = new Vector3;
        v3->x = (y * v1.z) - (z * v1.y);
        v3->y = (z * v1.x) - (x * v1.z);
        v3->z = (x * v1.y) - (y * v1.x);
        return *v3;
    }

    bool IsApproximatelyEqual(Vector3 v) {


        if (//   Checks if v.x is between x +- 1e-4            Checks if v.y is between y +- 1e-4            Checks if v.z is between z +- 1e-4
            ((x - 1e-4) <= v.x) && ((x + 1e-4) >= v.x) && ((y - 1e-4) <= v.y) && ((y + 1e-4) >= v.y) && ((z - 1e-4) <= v.z) && ((z + 1e-4) >= v.z)) {
            return true;
        }
        return false;
    }

    float AngleBetween(Vector3 v) {
        float cos = (Dot(v)) / (Magnitude() * v.Magnitude());
        cos = acos(cos);

        return cos;
    }

    float Distance(Vector3 v) {
        Vector3* v2 = new Vector3;
        v2->x = -x + v.x;
        v2->y = -y + v.y;
        v2->z = -z + v.z;
        return v2->Magnitude();

    }

    float Angle2D() {
        return atan2(y, x) * (180 / M_PI); // Multiplies arctan by 180/PI to convert it into degrees
    }

};

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
        v1->w = w + v.w;
        return *v1;
    }

    Vector4 operator - (Vector4 v) {    // Subtraction
        Vector4* v1 = new Vector4;
        v1->x = x - v.x;
        v1->y = y - v.y;
        v1->z = z - v.z;
        v1->w = w - v.w;
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
        v1->w = w * f;
        return *v1;
    }

    Vector4 operator / (float f) {      // Division with Float
        Vector4* v1 = new Vector4;
        v1->x = x / f;
        v1->y = y / f;
        v1->z = z / f;
        v1->w = w / f;
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
        w += v.w;
        return *this;
    }

    Vector4 operator -= (Vector4 v) {   // Subtraction Assignment
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
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
        w *= f;
        return *this;
    }

    Vector4 operator /= (float f) {   // Division Assignment
        x /= f;
        y /= f;
        z /= f;
        w /= f;
        return *this;
    }

    Vector4 operator - () {             // Negative
        x *= -1;
        y *= -1;
        z *= -1;
        w *= -1;
        return *this;
    }

    bool operator == (Vector4 v) {      // Equality
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
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
    }

    // This one has to go below the magnitude function as it uses the magnitude to figure out which one is smaller
    bool operator < (Vector4 v) {      // Less than
        if (Magnitude() < v.Magnitude()) { return true; }
        else { return false; }
    }

    void Normalise() {
        float magnitude = Magnitude();
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
        w /= magnitude;
    }

    Vector4 Normalised() {
        return *(new Vector4(x / Magnitude(), y / Magnitude(), z / Magnitude(), w / Magnitude()));
    }

    float Dot(Vector4 v) {
        return x * v.x + y * v.y + z * v.z + w * v.w;
    }

    Vector4 Cross(Vector4 v1) {
        Vector4* v3 = new Vector4;
        v3->x = (y * v1.z) - (z * v1.y);
        v3->y = (z * v1.x) - (x * v1.z);
        v3->z = (x * v1.y) - (y * v1.x);
        v3->w = 0;
        return *v3;
    }

    bool IsApproximatelyEqual(Vector4 v) {


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


// m1 | m4 | m7
// m2 | m5 | m8
// m3 | m6 | m9
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

    Vector3 operator * (Vector3 v) {        // Multiply by Vector
        return (Vector3(m1, m2, m3) * v.x) + (Vector3(m4, m5, m6) * v.y) + (Vector3(m7, m8, m9) * v.z);
    }

    Matrix3 operator * (Matrix3 m) const {  // Multiply
        Matrix3 *ma2 = new Matrix3;
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

    bool operator == (Matrix3 m) {          // Equality
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

    const float& operator [] (int i) const{ // Index
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
        Matrix3 *matrix = new Matrix3;
        matrix->m1 =  cos(f); matrix->m4 = sin(f); matrix->m7 = 0;
        matrix->m2 = -sin(f); matrix->m5 = cos(f); matrix->m8 = 0;
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

    Vector3 GetRight() {
        return Vector3(m4, m5, m6);
    }

    Vector3 GetForward() {
        return Vector3(m1, m4, m7);
    }

    Vector3 GetTranslate() {
        return Vector3(m7, m8, m9);
    }

    bool IsApproximatelyEqual(Matrix3 m) {
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

// m1  |  m5  | m9  | m13
// m2  |  m6  | m10 | m14
// m3  |  m7  | m11 | m15
// m4  |  m8  | m12 | m16
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

    Matrix4 operator = (Matrix4 m) {
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

    Vector4 operator * (Vector4 v) {
        return Vector4((v.x * m1) + (v.y * m5) + (v.z * m9)  + (v.w * m13),
                       (v.x * m2) + (v.y * m6) + (v.z * m10) + (v.w * m14),
                       (v.x * m3) + (v.y * m7) + (v.z * m11) + (v.w * m15),
                       (v.x * m4) + (v.y * m8) + (v.z * m12) + (v.w * m16)
            );
    }

                                // m1  |  m5  | m9  | m13
                                // m2  |  m6  | m10 | m14
                                // m3  |  m7  | m11 | m15
                                // m4  |  m8  | m12 | m16
    // m1  |  m5  | m9  | m13   
    // m2  |  m6  | m10 | m14
    // m3  |  m7  | m11 | m15
    // m4  |  m8  | m12 | m16


    Matrix4 operator * (Matrix4 m) {
        Matrix4* ma2 = new Matrix4;
        // Row 1
        ma2->m1 = (m1 * m.m1) + (m5 * m.m2)   + (m9 * m.m3)  + (m13 * m.m4);
        ma2->m5 = (m1 * m.m5) + (m5 * m.m6)   + (m9 * m.m7)  + (m13 * m.m8);
        ma2->m9 = (m1 * m.m9) + (m5 * m.m10)  + (m9 * m.m11) + (m13 * m.m12);
        ma2->m13 =(m1 * m.m13) + (m5 * m.m14) + (m9 * m.m15) + (m13 * m.m16);
        // Row 2
        ma2->m2 =  (m2 * m.m1)  + (m6 * m.m2)  + (m10 * m.m3)  + (m14 * m.m4);
        ma2->m6 =  (m2 * m.m5)  + (m6 * m.m6)  + (m10 * m.m7)  + (m14 * m.m8);
        ma2->m10 = (m2 * m.m9)  + (m6 * m.m10) + (m10 * m.m11) + (m14 * m.m12);
        ma2->m14 = (m2 * m.m13) + (m6 * m.m14) + (m10 * m.m15) + (m14 * m.m16);
        // Row 3
        ma2->m3 =  (m3 * m.m1)  + (m9 * m.m2)  + (m11 * m.m3)  + (m15 * m.m4);
        ma2->m7 =  (m3 * m.m5)  + (m9 * m.m6)  + (m11 * m.m7)  + (m15 * m.m8);
        ma2->m11 = (m3 * m.m9)  + (m9 * m.m10) + (m11 * m.m11) + (m15 * m.m12);
        ma2->m15 = (m3 * m.m13) + (m9 * m.m14) + (m11 * m.m15) + (m15 * m.m16);
        // Row 4
        ma2->m4 =  (m4 * m.m1)  + (m8 * m.m2)  + (m12 * m.m3)  + (m16 * m.m4);
        ma2->m8 =  (m4 * m.m5)  + (m8 * m.m6)  + (m12 * m.m7)  + (m16 * m.m8);
        ma2->m12 = (m4 * m.m9)  + (m8 * m.m10) + (m12 * m.m11) + (m16 * m.m12);
        ma2->m16 = (m4 * m.m13) + (m8 * m.m14) + (m12 * m.m15) + (m16 * m.m16);
        
        return *ma2;
    }

    Matrix4 operator *= (Matrix4 m) {
        Matrix4* ma2 = new Matrix4;
        // Row 1
        ma2->m1 = (m1 * m.m1) + (m5 * m.m2)   + (m9 * m.m3)  + (m13 * m.m4);
        ma2->m5 = (m1 * m.m5) + (m5 * m.m6)   + (m9 * m.m7)  + (m13 * m.m8);
        ma2->m9 = (m1 * m.m9) + (m5 * m.m10)  + (m9 * m.m11) + (m13 * m.m12);
        ma2->m13 =(m1 * m.m13) + (m5 * m.m14) + (m9 * m.m15) + (m13 * m.m16);
        // Row 2
        ma2->m2 =  (m2 * m.m1)  + (m6 * m.m2)  + (m10 * m.m3)  + (m14 * m.m4);
        ma2->m6 =  (m2 * m.m5)  + (m6 * m.m6)  + (m10 * m.m7)  + (m14 * m.m8);
        ma2->m10 = (m2 * m.m9)  + (m6 * m.m10) + (m10 * m.m11) + (m14 * m.m12);
        ma2->m14 = (m2 * m.m13) + (m6 * m.m14) + (m10 * m.m15) + (m14 * m.m16);
        // Row 3
        ma2->m3 =  (m3 * m.m1)  + (m9 * m.m2)  + (m11 * m.m3)  + (m15 * m.m4);
        ma2->m7 =  (m3 * m.m5)  + (m9 * m.m6)  + (m11 * m.m7)  + (m15 * m.m8);
        ma2->m11 = (m3 * m.m9)  + (m9 * m.m10) + (m11 * m.m11) + (m15 * m.m12);
        ma2->m15 = (m3 * m.m13) + (m9 * m.m14) + (m11 * m.m15) + (m15 * m.m16);
        // Row 4
        ma2->m4 =  (m4 * m.m1)  + (m8 * m.m2)  + (m12 * m.m3)  + (m16 * m.m4);
        ma2->m8 =  (m4 * m.m5)  + (m8 * m.m6)  + (m12 * m.m7)  + (m16 * m.m8);
        ma2->m12 = (m4 * m.m9)  + (m8 * m.m10) + (m12 * m.m11) + (m16 * m.m12);
        ma2->m16 = (m4 * m.m13) + (m8 * m.m14) + (m12 * m.m15) + (m16 * m.m16);
        
        *this = *ma2;
        return *ma2;
    }

};

struct Color {
    unsigned int rgba = 0;

    Color() { // Default Constructor
        rgba = 255;
    }

    Color(Color& x) { // Copy Constructor
        rgba = x.rgba;
    }

    Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) { // Parameterised Constructor
        rgba |= red << 24;
        rgba |= green << 16;
        rgba |= blue << 8;
        rgba |= alpha;
    }

    unsigned char GetRed() const {
        return rgba >> 24;
    }

    void SetRed(unsigned char red) {
        rgba &= 0xFFFFFF;
        rgba |= red << 24;
    }

    unsigned char GetGreen() const {
        return rgba >> 16 & 0xFF;
    }

    void SetGreen(unsigned char green) {
        rgba &= 0xFF00FFFF;
        rgba |= green << 16;
    }

    unsigned char GetBlue() const {
        return rgba >> 8 & 0xFF;
    }

    void SetBlue(unsigned char blue) {
        rgba &= 0xFFFF00FF;
        rgba |= blue << 8;
    }

    unsigned char GetAlpha() const {
        return rgba & 0xFF;
    }

    void SetAlpha(unsigned char alpha) {
        rgba &= 0xFFFFFF00;
        rgba |= alpha;
    }

    bool operator == (Color c) const {
        if (rgba == c.rgba) {
            return true;
        }
        return false;
    }

};

void print(Vector3 v);
void print(Vector4 v);
void print(Matrix3 m);
void print(Matrix4 m);


int main()
{
    //Vector4 a(1, 20, 3, 1);
    //Vector4 b(-7, -4, -5, 51);

    Vector3 c(1500, 1500, 0);
    //Vector3 d(1400, 1400, 0);

    /*Color col(32, 64, 0, 255);
    Color col2(32, 64, 0, 255);*/
    
    /*Matrix3 ma1(1, 3, 1, 2, 2, 2, 3, 1, 3);
    Matrix3 ma2(4, 6, 4, 5, 5, 6, 6, 4, 5);*/

    //Matrix3 ma3(-0.188076824f, 0.f, 0.982154310f,
    //             0.f,          1.f, 0.f,
    //            -0.982154310f, 0.f,-0.188076824f);
    //Vector3 v3(13.5f, -48.23f, 862);

    /*print(ma1 * ma2);
    Matrix3 ma3(1, 3, 1, 2, 2, 2, 3, 1, 3);
    std::cout << '\n' << ma1[8] << '\n';

    print(Matrix3::MakeRotate(3.98f));
    print(Matrix3::MakeScale(2.0f,2.0f));

    print(Matrix3::MakeRotate(9.62f));
    print(Matrix3::MakeRotate(9.62f).GetForward());
    print(Matrix3::MakeRotate(9.62f).GetRight());

    std::cout << '\n' << ma1.IsApproximatelyEqual(ma3) << '\n';*/

    /*ma3 *= ma2;
    print(ma3);*/


    /*a += b;*/


    /*std::cout << (col == col2) << '\n';
    std::cout << (int)col.GetAlpha() << "\n";
    col.SetAlpha(128);

    std::cout << (int)col.GetRed() << '\n';
    std::cout << (int)col.GetGreen() << '\n';
    std::cout << (int)col.GetBlue() << '\n';
    std::cout << (int)col.GetAlpha();*/


    /*std::cout << (c.Dot(d));
    std::cout << "\n" << c.Magnitude() * d.Magnitude() * cos(c.AngleBetween(d));
    std::cout << "\n" << (c.AngleBetween(d));*/
    //std::cout << c[1];

    //std::cout << a.x << " - " << a.y << " - " << a.z << "\n";

    //Vector4 e(13.5f, -48.23, 862.f, 1.f);
    
    Matrix4 m4(1, 3, 1, 2,
               2, 2, 3, 1,
               3, 5, 1, 4,
               2, 2, 5, 8);
    Matrix4 m5(4, 6, 4, 5,
               5, 6, 6, 4,
               5, 10, -9, -3,
               2, -12, -7, 3);

    m4 *= m5;
    print(m4);

}


void print(Vector3 v) {
    std::cout << "\n" << v.x << "\n";
    std::cout << v.y << "\n";
    std::cout << v.z << "\n";
}
void print(Vector4 v) {
    std::cout << "\n" << v.x << "\n";
    std::cout << v.y << "\n";
    std::cout << v.z << "\n";
    std::cout << v.w << "\n";
}

void print(Matrix3 m) {
    std::cout << "\n | " << m.m1 << " | " << m.m4 << " | " << m.m7 << " | "
              << "\n | " << m.m2 << " | " << m.m5 << " | " << m.m8 << " | "
              << "\n | " << m.m3 << " | " << m.m6 << " | " << m.m9 << " | " << '\n';
}

void print(Matrix4 m) {
    std::cout << "\n | " << m.m1 << " | " << m.m5 << " | " << m.m9  << " | " << m.m13 << " | "
              << "\n | " << m.m2 << " | " << m.m6 << " | " << m.m10 << " | " << m.m14 << " | "
              << "\n | " << m.m3 << " | " << m.m7 << " | " << m.m11 << " | " << m.m15 << " | "
              << "\n | " << m.m4 << " | " << m.m8 << " | " << m.m12 << " | " << m.m16 << " | " << '\n';
}
