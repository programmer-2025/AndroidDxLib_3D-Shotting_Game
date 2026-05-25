//
// Created by user on 2026/05/25.
//

#ifndef MYDXLIB_ANDROID_LOCATION3D_H
#define MYDXLIB_ANDROID_LOCATION3D_H

#include <math.h>

/**
 * 座標を自作したものです。（※推奨はDxLibのVECTORクラス）
 */
class Location3D {
private:
public:
    float x_;
    float y_;
    float z_;

    Location3D() {
        x_ = 0.0f;
        y_ = 0.0f;
        z_ = 0.0f;
    }

    Location3D(float x, float y, float z) {
        x_ = x;
        y_ = y;
        z_ = z;
    }

    /// <summary>
    /// 座標同士の距離を測る関数。
    /// </summary>
    /// <param name="otherLoc">測りたいLocation2Dを入れる。</param>
    /// <returns></returns>
    float Distance(const Location3D& otherLoc) const {
        return sqrt((x_ - otherLoc.x_) * (x_ - otherLoc.x_) +
                    (y_ - otherLoc.y_) * (y_ - otherLoc.y_) +
                    (z_ - otherLoc.z_) * (z_ - otherLoc.z_));
    }

    /// <summary>
    /// 座標同士を加算する関数。
    /// </summary>
    /// <param name="otherLoc">加算したいLocation2Dを入れる。</param>
    /// <returns></returns>
    Location3D operator+(const Location3D& otherLoc) const {
        Location3D result = Location3D(x_ + otherLoc.x_, y_ + otherLoc.y_, z_ + otherLoc.z_);
        return result;
    }

    /// <summary>
    /// 座標同士を減算する関数。
    /// </summary>
    /// <param name="otherLoc">減算したいLocation2Dを入れる。</param>
    /// <returns></returns>
    Location3D operator-(const Location3D& otherLoc) const {
        Location3D result = Location3D(x_ - otherLoc.x_, y_ - otherLoc.y_, z_ - otherLoc.z_);
        return result;
    }

    /// <summary>
    /// 座標同士をスカラー倍する関数。
    /// </summary>
    /// <param name="scalar">スカラー倍したいLocation2Dを入れる。</param>
    /// <returns></returns>
    Location3D operator*(const float& scalar) const {
        Location3D result = Location3D(x_ * scalar, y_ * scalar, z_ * scalar);
        return result;
    }

};

#endif //MYDXLIB_ANDROID_LOCATION3D_H
