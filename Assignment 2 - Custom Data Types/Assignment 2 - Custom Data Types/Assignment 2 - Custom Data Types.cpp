
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
        x *= -1;
        y *= -1;
        z *= -1;
        return *this;
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

    Vector4(Vector4& i) { // Copy Constructor
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
        v1->w = w;
        return *v1;
    }

    Vector4 operator - (Vector4 v) {    // Subtraction
        Vector4* v1 = new Vector4;
        v1->x = x - v.x;
        v1->y = y - v.y;
        v1->z = z - v.z;
        v1->w = w;
        return *v1;
    }

    Vector4 operator * (Vector4 v) {    // Multiplication
        Vector4* v1 = new Vector4;
        v1->x = x * v.x;
        v1->y = y * v.y;
        v1->z = z * v.z;
        v1->w = w;
        return *v1;
    }

    Vector4 operator / (Vector4 v) {    // Division
        Vector4* v1 = new Vector4;
        v1->x = x / v.x;
        v1->y = y / v.y;
        v1->z = z / v.z;
        v1->w = w;
        return *v1;
    }

    Vector4 operator * (float f) {      // Multiplication with Float
        Vector4* v1 = new Vector4;
        v1->x = x * f;
        v1->y = y * f;
        v1->z = z * f;
        v1->w = w;
        return *v1;
    }

    Vector4 operator / (float f) {      // Division with Float
        Vector4* v1 = new Vector4;
        v1->x = x / f;
        v1->y = y / f;
        v1->z = z / f;
        v1->w = w;
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
        return *this;
    }

    Vector4 operator -= (Vector4 v) {   // Subtraction Assignment
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector4 operator *= (Vector4 v) {   // Multiplication Assignment
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    Vector4 operator *= (float f) {   // Multiplication Assignment
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }

    Vector4 operator /= (float f) {   // Division Assignment
        x /= f;
        y /= f;
        z /= f;
        return *this;
    }

    Vector4 operator - () {             // Negative
        x *= -1;
        y *= -1;
        z *= -1;
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
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
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
    }

    Vector4 Normalised() {
        return *(new Vector4(x / Magnitude(), y / Magnitude(), z / Magnitude(), w));
    }

    float Dot(Vector4 v) {
        return x * v.x + y * v.y + z * v.z;
    }

    Vector4 Cross(Vector4 v1) {
        Vector4* v3 = new Vector4;
        v3->x = (y * v1.z) - (z * v1.y);
        v3->y = (z * v1.x) - (x * v1.z);
        v3->z = (x * v1.y) - (y * v1.x);
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
        return v2->Magnitude();

    }

};

struct Matrix3 {

};

struct Matrix4 {

};

struct Color {
    unsigned int R, G, B, A;

    Color() { // Default Constructor
        R = 0;
        G = 0;
        B = 0;
        A = 255;
    }

    Color(Color& x) { // Copy Constructor
        R = x.R;
        G = x.G;
        B = x.B;
        A = x.A;
    }

    Color(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha) { // Parameterised Constructor
        R = red;
        G = green;
        B = blue;
        A = alpha;
    }

};

void print(Vector3 v);
void print(Vector4 v);


int main()
{
    Vector4 a(1, 20, 3, 1);
    Vector4 b(-7, -4, -5, 51);

    const Vector3 c(1, 5, 8);

    a += b;

    print(a);
    std::cout << c[1];

    //std::cout << a.x << " - " << a.y << " - " << a.z << "\n";

    

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


