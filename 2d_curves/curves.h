#pragma once
#include <iostream>
#include <vector>
#include <math.h>

class Curve {
public:
  virtual void print(double t) = 0;
};

class Line : public Curve {
protected:
  std::vector<double> point;
  std::vector<double> direction;

public:
  Line() {
    point = std::vector<double>(2, 0.0);
    direction = std::vector<double>(2, 0.0);
  }

  Line(std::vector<double>& _point, std::vector<double>& _direction) {
    point = _point;
    direction = _direction;
  }

  void print(double t) {
    std::vector<double> _point = get_point();
    std::vector<double> _direction = get_direction();
    std::cout << "Line: " << std::endl;
    std::cout << "  Point: (" << _point[0] + _direction[0] * t << "; " << _point[1] + _direction[1] * t << ")\n";
    std::cout << "  Direction: (" << _direction[0] << "; " << _direction[1] << ")\n";
    std::cout << "----------------------------------------------------\n";
  };

  std::vector<double> get_point() { return point; };
  void set_point(std::vector<double>& _point) { point = _point; };
  std::vector<double> get_direction() { return direction; };
  void set_direction(std::vector<double>& _direction) { direction = _direction; };
};

class Ellipse : public Curve {
protected:
  double radius_X;
  double radius_Y;

public:
  Ellipse() {
    radius_X = 0.0;
    radius_Y = 0.0;
  }

  Ellipse(double rad_X, double rad_Y) {
    radius_X = rad_X;
    radius_Y = rad_Y;
  }

  void print(double t) {
    double a = get_radius_X();
    double b = get_radius_Y();
    std::cout << "Ellipse: " << std::endl;
    std::cout << "  Point: (" << a * cos(t) << "; " << b * sin(t) << ")\n";
    std::cout << "  Direction: (" << -a * sin(t) << "; " << b * cos(t) << ")\n";
    std::cout << "----------------------------------------------------\n";
  }
  ;
  double get_radius_X() { return radius_X; };
  void set_radius_X(double _radius_X) { radius_X = _radius_X; };
  double get_radius_Y() { return radius_Y; };
  void set_direction(double _radius_Y) { radius_Y = _radius_Y; };
};
