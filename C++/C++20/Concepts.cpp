//=========================================================
// There are a variety of syntactic forms for enforcing concepts:
//=========================================================

// Forms for function parameters:
// `T` is a constrained type template parameter.
template <my_concept T> void f(T v);

// `T` is a constrained type template parameter.
template <typename T> requires my_concept<T> void f(T v);

// `T` is a constrained type template parameter.
template <typename T> void f(T v) requires my_concept<T>;

// `v` is a constrained deduced parameter.
void f(my_concept auto v);

// `v` is a constrained non-type template parameter.
template <my_concept auto v> void g();

// Forms for auto-deduced variables:
// `foo` is a constrained auto-deduced value.
my_concept auto foo = ...;

// Forms for lambdas:
// `T` is a constrained type template parameter.
auto f = []<my_concept T> (T v)
{
  // ...
};

// `T` is a constrained type template parameter.
auto f = []<typename T> requires my_concept<T> (T v)
{
  // ...
};

// `T` is a constrained type template parameter.
auto f = []<typename T> (T v) requires my_concept<T>
{
  // ...
};

// `v` is a constrained deduced parameter.
auto f = [](my_concept auto v)
{
  // ...
};

// `v` is a constrained non-type template parameter.
auto g = []<my_concept auto v> ()
{
  // ...
};

//=========================================================
// The requires keyword is used either to start a requires clause or a requires expression
//=========================================================
// `requires` clause.
template <typename T> requires my_concept<T> void f(T);

// `requires` expression.
template <typename T> concept callable = requires (T f) { f(); };

// `requires` clause and expression on same line.
template <typename T> requires requires (T x) { x + x; } T add(T a, T b)
{
  return a + b;
}

//=========================================================
// typename - Type requirements - denoted by the typename keyword followed by a type name, asserts that the given type name is valid.
//=========================================================
template <typename T> concept C = requires
{
                     // Requirements on type `T`:
  typename T::value; // A) has an inner member named `value`
  typename S<T>;     // B) must have a valid class template specialization for `S`
  typename Ref<T>;   // C) must be a valid alias template substitution
};

//=========================================================
// Compound requirements - an expression in braces followed by a trailing return type or type constraint.
//=========================================================
template <typename T> concept C = requires(T x)
{
  {*x} -> typename T::inner;		// the type of the expression `*x` is convertible to `T::inner`
  {x + 1} -> std::same_as<int>;		// the expression `x + 1` satisfies `std::same_as<decltype((x + 1))>`
  {x * 1} -> T;						// the type of the expression `x * 1` is convertible to `T`
};

//=========================================================
// Nested requirements - denoted by the requires keyword, specify additional constraints (such as those on local parameter arguments).
//=========================================================
template <typename T> concept C = requires(T x)
{
  requires std::same_as<sizeof(x), size_t>;
};
