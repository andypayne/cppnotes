#include <iostream>

class Rectangle
{
private:
  double width_{};
  double height_{};

public:
  Rectangle() = default;

  Rectangle(double w, double h)
    : width_{w},
      height_{h}
  {}

  double Width() const { return width_; }
  double Height() const { return height_; }

  double Area() const
  {
    return width_ * height_;
  }

  double Perimeter() const
  {
    return 2 * (width_ + height_);
  }

  void Scale(double scaleFactor)
  {
    width_ *= scaleFactor;
    height_ *= scaleFactor;
  }
};


void printInfo(const Rectangle& r) {
  std::cout << "Rectangle width = " << r.Width()
            << ", height = " << r.Height()
            << ",\n"
            << "area = " << r.Area()
            << ", perimeter = " << r.Perimeter()
            << "\n\n";
}

int main()
{
  std::cout << "Default constructed rectangle:\n";
  Rectangle r1{};
  printInfo(r1);

  std::cout << "Rectangle r{10, 20}:\n";
  Rectangle r2{10, 20};
  printInfo(r2);
  std::cout << "After 2x scaling:\n";
  r2.Scale(2);
  printInfo(r2);

  std::cout << "sizeof(Rectangle) = " << sizeof(Rectangle) << "\n";
  std::cout << "sizeof(r2) = " << sizeof(r2) << "\n";
  return 0;
}

