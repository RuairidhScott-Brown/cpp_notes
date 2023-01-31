/*
LVALUE REFERENCES


- Lvalue references can’t be bound to non-modifiable lvalues

- Once initialized, a reference in C++ cannot be reseated,
  meaning it cannot be changed to reference another object.

- Reference variables follow the same scoping and duration rules that normal variables do

- When an object being referenced is destroyed before a reference to it, the reference is
  left referencing an object that no longer exists. Such a reference is called a dangling
  reference. Accessing a dangling reference leads to undefined behavior.


*/