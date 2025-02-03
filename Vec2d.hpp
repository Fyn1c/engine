#pragma once

struct Vec2d {

    double x;
    double y;
    const double defaultLenght = 1.0;
    double lenght;

    Vec2d() {};
    Vec2d(double x, double y) {
        this->x = x;
        this->y = y;
    }
    Vec2d(double x, double y, double len) {
        this->x = x;
        this->y = y;
        this->lenght = len;
    }

    Vec2d operator=(const Vec2d& vec);
    Vec2d operator-();

    double getLenght() {
        if (this->lenght) {
            return lenght;
        }
        return defaultLenght;
    }
};

Vec2d Vec2d::operator=(const Vec2d& vec) {
    return Vec2d{ vec.x, vec.y };
}
Vec2d Vec2d::operator-() {
    return Vec2d{ -this->x, -this->y };
}
Vec2d operator*(const double& num, const Vec2d& vec) {
    return Vec2d{ vec.x * num, vec.y * num };
}
Vec2d operator*(const Vec2d& vec, const double& num) {
    return Vec2d{ vec.x * num, vec.y * num };
}
Vec2d operator+=(const Vec2d& vec1, const Vec2d& vec2) {
    return Vec2d{ vec1.x + vec2.x, vec1.y + vec2.y };
}
Vec2d operator/(const Vec2d& vec, const double& num) {
    return Vec2d{ vec.x / num, vec.y / num };
}
Vec2d operator-(const Vec2d& vec1, const Vec2d& vec2) {
    return Vec2d{ vec1.x - vec2.x, vec1.y - vec2.y };
}
Vec2d operator+(const Vec2d& vec1, const Vec2d& vec2) {
    return Vec2d{ vec1.x + vec2.x, vec1.y + vec2.y };
}