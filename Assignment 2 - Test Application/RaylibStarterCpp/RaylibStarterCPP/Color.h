#pragma once

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