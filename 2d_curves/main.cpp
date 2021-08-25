#include <../../curves.h>
#include <algorithm>
#include <random>

static const double PI = 3.14;

int main() {
  size_t size = 50;
  double t = PI / 4.0;
  std::vector<Line> lines;
  std::vector<Ellipse> ellipses;

  std::random_device rd;
  std::uniform_real_distribution<double> distr(0.0, 5.0);
  std::mt19937 gen(rd());

  for (size_t i = 0; i < size; ++i) {
    std::vector<double> pnt = { distr(gen), distr(gen) };
    std::vector<double> drctn = { distr(gen), distr(gen) };
    lines.push_back(Line(pnt, drctn));
  }

  for (size_t i = 0; i < size; ++i) {
    ellipses.push_back(Ellipse(distr(gen), distr(gen)));
  }

  for (size_t i = 0; i < size; ++i) {
    lines[i].print(t);
    ellipses[i].print(t);
  }

  return 0;
}