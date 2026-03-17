
#include <iostream>

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

    Vector3 operator /= (Vector3 v) {   // Division Assignment
        x /= v.x;
        y /= v.y;
        z /= v.z;
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
        Vector3 *v3 = new Vector3;
        v3->x = (y * v1.z) - (z * v1.y);
        v3->y = (z * v1.x) - (x * v1.z);
        v3->z = (x * v1.y) - (y * v1.x);
        return *v3;
    }

    bool IsApproximatelyEqual(Vector3 v) {

        
        if (//   Checks if v.x is between x +- 1e-4            Checks if v.y is between y +- 1e-4            Checks if v.z is between z +- 1e-4
            ((x - 1e-4) <= v.x) && ((x + 1e-4) >= v.x)  && ((y - 1e-4) <= v.y) && ((y + 1e-4) >= v.y) && ((z - 1e-4) <= v.z) && ((z + 1e-4) >= v.z)) {
            return true;
        }
        return false;
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


int main()
{
    Vector3 a(13.5, -48.23, 862);
    Vector3 b(5, 3.99, -12);

    std::cout << a.Dot(b) << "\n";

    // a.Normalise();

    print(a.Cross(b));

    

    std::cout << a.Cross(b).IsApproximatelyEqual(Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f));
    //std::cout << a.x << " - " << a.y << " - " << a.z << "\n";

}


void print(Vector3 v) {
    std::cout << "\n" << v.x << "\n";
    std::cout << v.y << "\n";
    std::cout << v.z << "\n";
}

