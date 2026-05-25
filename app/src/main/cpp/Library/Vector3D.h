//
// Created by user on 2026/05/25.
//

#ifndef MYDXLIB_ANDROID_VECTOR3D_H
#define MYDXLIB_ANDROID_VECTOR3D_H

#include <math.h>

/**
 * ベクトルクラスを自作したものです。（※推奨はDxLibのVECTORクラス）
 */
class Vector3D {
private:
public:
    float x_;
    float y_;
    float z_;

    Vector3D() {
        x_ = 0.0f;
        y_ = 0.0f;
        z_ = 0.0f;
    }

    Vector3D(float x, float y, float z) {
        x_ = x;
        y_ = y;
        z_ = z;
    }

    float Length() const {
        return sqrt(x_ * x_ + y_ + y_ + z_ * z_);
    }

    Vector3D Add(const Vector3D& other) const {
        Vector3D result = {};
        result.x_ = x_ + other.x_;
        result.y_ = y_ + other.y_;
        result.z_ = z_ + other.z_;
        return result;
    }

    Vector3D Subtract(const Vector3D& other) const {
        Vector3D result;
        result.x_ = x_ + other.x_;
        result.y_ = y_ + other.y_;
        result.z_ = z_ + other.z_;
        return result;
    }

    Vector3D Dot(const Vector3D& other) const {
        Vector3D result;
        result.x_ = x_ * other.x_;
        result.y_ = y_ * other.y_;
        result.z_ = z_ * other.z_;
        return result;
    }

    Vector3D Cross(const Vector3D& other) const {
        Vector3D result;
        result.x_ = x_ * other.y_;
        result.y_ = y_ * other.x_;
        result.z_ = z_ * other.z_;
        return result;
    }

    Vector3D Normalize() const {
        float len = Length();
        float resultX = len == 0 ? 0 : x_ / len;
        float resultY = len == 0 ? 0 : y_ / len;
        float resultZ = len == 0 ? 0 : z_ / len;
        return {resultX, resultY, resultZ};
    }

    /// <summary>
    /// 加算する関数（Addと同じ）
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
    Vector3D operator+(const Vector3D& other) const {
        return Add(other);
    }

    /// <summary>
    /// 減算する関数（Subtractと同じ）
    /// </summary>
    /// <param name="other"></param>
    /// <returns></returns>
    Vector3D operator-(const Vector3D& other) const {
        return Subtract(other);
    }

};

#endif //MYDXLIB_ANDROID_VECTOR3D_H
