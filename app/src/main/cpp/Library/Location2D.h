//
// Created by user on 2026/03/12.
//

#ifndef MYDXLIB_ANDROID_LOCATION2D_H
#define MYDXLIB_ANDROID_LOCATION2D_H

#include <math.h>

class Location2D {
private:
public:
    float x_;
    float y_;

    Location2D() {
        x_ = 0.0f;
        y_ = 0.0f;
    }

    Location2D(float x, float y) {
        x_ = x;
        y_ = y;
    }

    /// <summary>
    /// 座標同士の距離を測る関数。
    /// </summary>
    /// <param name="otherLoc">測りたいLocation2Dを入れる。</param>
    /// <returns></returns>
    float Distance(const Location2D& otherLoc) const {
        return sqrt((x_ - otherLoc.x_) * (x_ - otherLoc.x_) +
                    (y_ - otherLoc.y_) * (y_ - otherLoc.y_));
    }

    /// <summary>
    /// 座標同士を加算する関数。
    /// </summary>
    /// <param name="otherLoc">加算したいLocation2Dを入れる。</param>
    /// <returns></returns>
    Location2D operator+(const Location2D& otherLoc) const {
        Location2D result = Location2D(x_ + otherLoc.x_, y_ + otherLoc.y_);
        return result;
    }

    /// <summary>
    /// 座標同士を減算する関数。
    /// </summary>
    /// <param name="otherLoc">減算したいLocation2Dを入れる。</param>
    /// <returns></returns>
    Location2D operator-(const Location2D& otherLoc) const {
        Location2D result = Location2D(x_ - otherLoc.x_, y_ - otherLoc.y_);
        return result;
    }

    /// <summary>
    /// 座標同士をスカラー倍する関数。
    /// </summary>
    /// <param name="scalar">スカラー倍したいLocation2Dを入れる。</param>
    /// <returns></returns>
    Location2D operator*(const float& scalar) const {
        Location2D result = Location2D(x_ * scalar, y_ * scalar);
        return result;
    }

};


#endif //MYDXLIB_ANDROID_LOCATION2D_H
