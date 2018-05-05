### Value Initialization

```C++
int n{};
```

value initialization - C++11 -
http://en.cppreference.com/w/cpp/language/value_initialization

int n = 0; vs int n{};
https://stackoverflow.com/questions/35911501/is-there-a-difference-between-int-x-and-int-x-0

```C++
int n = 0; // copy initialization
int n{};   // value initialization
```

Brace initialization
or
Uniform initialization

initializations:

```C++
int n{42};
int n = 42;
int n(42);
auto n{42};  // Compiler determines type
```


Defect in C++11 - type here would be deduced as std::initializer_list<int>
auto n{42};
Fixed in C++17
Clang applies the fix to C++11


---
### constexpr

- use for constants known at compile time

```C++
constexpr double pi = 3.14159265;
```

---
### const placement

Equivalent, but the left side is more idiomatic English:

```C++
const int x;  <==>  int const x;
func(std::string const& s) <==> func(const std::string& s)
```

---
### C++11 Move Semantics

Allow large objects to be returned out of functions in a more performant way, with no special syntax changes
return bigResult; // Will do the right thing


---
### C++11 Trailing return type syntax

int fun(double x)
-becomes->
auto fun(double x) -> int

This is useful when declaring template functions that have return types that are dependent on the template typenames.

```C++
template<typename X, typename Y>
auto multiply(X x, Y y) -> decltype(x * y)
{
  return x * y;
}
```

Otherwise, you don't know the return type to specify in a leading position.
Also note that auto and decltype are both being used.


---
### std::vector initialization

```C++
std::vector<int> v1{10};  // one element vector with value [10]
std::vector<int> v2(10);  // vector with capacity of 10 - [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```


---
### Range for with references

```C++
std::vector v;

for (auto & e : v) {
  // e ...
}

for (auto const& e : v) {
// or for (const auto & e : v) {
  // e ...
}
```

---
### CMakeLists.txt

set(CMAKE_CXX_STANDARD 11)

---
### auto

An example where it's more than syntactic sugar, where it's difficult without it:

```C++
template<typename X, typename Y>
void do_magic(const X& x, const Y& y)
{
  auto result = x * y;  // What is the type of result?
  // ...
}
```

---
### Lambda expressions

```C++
[](){ return 1 + 2; }
```
[] - lambda introducer
() - parameter list
{} - body

They are implemented as functors by the compiler.

Lambda with trailing return type:
[](int i) -> double { if (i > 10) return 0.0; return double(i); }

Parameter limitations:
- No default values for parameters
- No variable length argument lists
- No unnamed parameters


---
### Storing Lambdas -

```C++
auto f = [](int i) { return i > 10; }
f(5); // false
```


std::function - can be bound to anything function-like

```C++
#include <functional>

class LambdaStore
{
  std::function<bool(double)> _stored_lambda;  // lambda stored in a member var. std::function takes <ReturnType(ArgTypes)>

public:
  // A method that returns a lambda
  std::function<int(int)> get_abs() const
  {
    return [](int i) { return abs(i); };
  }

  // Mutator for a lambda member
  void set_lambda(const std::function<bool(double)>& lambda)
  {
    _stored_lambda = lambda;
  }
};


LambdaStore ls;
ls.set_lambda([](double d) { return d > 0.0; });
auto abs_lambda = ls.get_abs();
abs_lambda(-10);  // 10
```

---
### Lambdas capture variables - closure

```C++
[today](JetPlane& jet) { jet.require_service(today); }
// today in the introducer is captured from the environment
```

Local variables always need to be captured explicitly.
Capturing by reference -
```[&var](){}```

- Up to you to make sure the references are still valid when the lambda is invoked, otherwise undefined behavior

Note - you can't capture globals(/?) by reference:
```C++
auto x = 10;
auto f = [&x]() { return x; }  // Doesn't work
```

---
### Lambdas - default capture modes

You can capture multiple variables in the same way without having to write a list.
Note - not all variables are captured, just the ones that are used in the lambda expression.

```C++
int a, b, c, d;
[=]() { return (a > b) && (c < d); };  // Capture everything by value - [=]
[&]() { a = b = c = d = 10; }  // Capture everything by reference - [&]
```

C++11 - You can override default capture modes

```C++
[=, &a]() { a = 20; }
[&, d]() { d = 20; }  // Doesn't compile because d is captured by value, not by reference
```

Scott Meyers claims that using default capture modes is not advised -- read further.

---
### Lambdas - capturing class members
You have to capture this to use a member:
[this]() { ... }

'this' is always captured by value


---
### Mutable Lambdas

By default, lambdas can't modify captured values. To get around this, use the ```mutable``` keyword.

```C++
vector<pair<int, int>> flight_hours;
// populate ...

auto running_total = 100;

for_each(flight_hours.begin(), flight_hours.end(),
    [running_total](pair<int, int>& x) mutable
        { running_total += x.first; x.second = running_total; });
```

Now running_total can maintain state.
Note that mutable lambdas cannot be passed by const reference.


---
### Debugging

Run cmake with the debug option:
```
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
```

Launch lldb for test_prog with args: -x /path/file.txt
```bash
$ lldb
(lldb) file ./test_prog
Current executable set to './test_prog' (x86_64).
(lldb) r -x /path/file.txt
Process 55661 launched: './test_prog' (x86_64)
...
Process 55661 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x80)
...
Target 1: (test_prog) stopped.
(lldb) thread list
Process 55661 stopped
* thread #1: tid = 0xb00ee1, 0x0000000100050566 test_prog ...
(lldb) thread backtrace
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x80)
...
```

---
### Move semantics and rvalue references
From Stroustrop's /A Tour of C++/

Move semantics allow moving an expensive object, rather than copying it.
The ```&&``` designates an rvalue reference, which is a reference to an rvalue (vs lvalue), loosely something that can't be assigned to, such as the return value from a function call. "So an rvalue reference is something that nobody else can assign to, so that we can safely 'steal' its value."

From Stroustrop:

```C++
class Vector
{
  // ...
  Vector(const Vector& a);             // copy constructor
  Vector& operator=(const Vector& a);  // copy assignment
  Vector(Vector&& a);                  // move constructor, notice no 'const'
  Vector& operator=(Vector&& a);       // move assignment, notice no 'const'
};

// ...

Vector::Vector(Vector&& a)
  : elem{a.elem},    // "grab the elements" from a
    sz{a.sz}
{
  a.elem = nullptr;  // now a has no elements
  a.sz = 0;
}
```

Given this class definition, consider the code below:

```C++
void f(const Vector& x, const Vector& y, const Vector& z)
{
  Vector r;
  // ...
  r = x + y + z;
  // ...
}
```

With the move constructor defined, the compiler will choose it for the return value from f(...), so no copying of vectors occurs.

You can also be explicit with std::move(), in cases where the compiler can't determine a move.

```C++
Vector f()
{
  Vector x(1000);
  Vector y(1000);
  Vector z(1000);
  z = x;             // copy
  y = std::move(x);  // move
  return z;          // move
}
```

---

