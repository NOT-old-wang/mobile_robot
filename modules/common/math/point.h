/*
Copyright 2019

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#ifndef MODULES_COMMON_MATH_POINT_H_
#define MODULES_COMMON_MATH_POINT_H_

#include <cmath>

namespace mobile_robot {
namespace common {
namespace math {
/**
 * \class Point
 */
class Point {
 public:
  /**
   * \brief default constructor, init a point with coordinate(0,0)
   */
  Point() : x_(0.0), y_(0.0) {}

  /**
   * \brief construct a point with coordinate(x,y)
   * \param x x-coordinate
   * \param y y-coordinate
   */
  Point(double x, double y) : x_(x), y_(y) {}

  /**
   * \brief copy constructor
   * \param p another Point type instance
   */
  Point(const Point &p) : x_(p.x_), y_(p.y_) {}

  /**
   * \brief assign current point values with a new point
   * \param p another Point type instance
   */
  Point &operator=(const Point &p) {
    if (this == &p) {
      return *this;
    }

    this->x_ = p.x_;
    this->y_ = p.y_;
    return *this;
  }

  /**
   * \brief x setter
   * \param x x-coordinate
   */
  inline void set_x(double x) { x_ = x; }

  /**
   * \brief y setter
   * \param y y-coordinate
   */
  inline void set_y(double y) { y_ = y; }

  /**
   * \brief x,y setter
   * \param x x-coordinate
   * \param y y-coordinate
   */
  inline void Set(double x, double y) {
    x_ = x;
    y_ = y;
  }

  /**
   * \brief x getter
   * \return x-coordinate
   */
  inline const double x() const { return x_; }

  /**
   * \brief y getter
   * \return y-coordinate
   */
  inline const double y() const { return y_; }

  /**
   * \brief get the distance from current point to another point
   * \param point the target point to calculate distanc
   * \return the distance
   */
  inline const double GetDistance(Point point) const {
    return std::hypot(point.x() - x_, point.y() - y_);
  }

  Point GetTransitionalPoint(const Point &pt, float theta, float radius) const {
    auto x =
        x_ - (x_ - pt.x()) * radius * std::tan(theta / 2) / GetDistance(pt);
    auto y =
        y_ - (y_ - pt.y()) * radius * std::tan(theta / 2) / GetDistance(pt);
    return Point(x, y);
  }

 private:
  double x_;
  double y_;
};

}  // namespace math
}  // namespace common
}  // namespace mobile_robot
#endif  // MODULES_COMMON_MATH_POINT_H_
