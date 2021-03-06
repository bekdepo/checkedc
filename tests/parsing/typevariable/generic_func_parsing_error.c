// Tests to make sure parsing errors for generic function calls are detected
// properly.
//
// RUN: %clang_cc1 -verify %s

_For_any(T) _Ptr<T> Foo(_Ptr<T> a, _Ptr<T> b) {
  return a;
}

void CallGenericFunction() {
  int num = 0;
  _Ptr<int> x = &num;
  Foo<int int>(x, x); //expected-error{{cannot combine with previous 'int' declaration specifier}}
  Foo<int, >(x, x); //expected-error{{expected a type}}
  Foo<, , >(x, x); //expected-error{{expected a type}}
  Foo(x, x); //expected-error{{expected a list of type arguments for a generic function}}
}
