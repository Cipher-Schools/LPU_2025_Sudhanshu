// File: single-inheritance.cpp
// Topic: Types of Inheritance in C++ with notes, ASCII flowcharts, and examples
// Author: GitHub Copilot
//
// Overview:
// Inheritance allows a class (derived) to reuse and extend another class (base).
// Common types:
// 1) Single
// 2) Multiple
// 3) Multilevel
// 4) Hierarchical
// 5) Hybrid (combination, often using virtual inheritance to solve diamond)
// Access control matters: public, protected, private inheritance.
//
// General access rules for public inheritance:
// - public in Base -> public in Derived
// - protected in Base -> protected in Derived
// - private in Base -> not accessible in Derived
//
// For private inheritance:
// - public/protected in Base -> private in Derived
//
// For protected inheritance:
// - public/protected in Base -> protected in Derived
//
// Virtual inheritance solves the "diamond problem" by sharing one Base subobject.
//
// Flowchart legend (ASCII):
// [ClassName] -> inheritance arrow indicates "is-a" relationship.
//
// ---------------------------------------------------------------
// 1) Single Inheritance
// Base -> Derived
// Flowchart:
// [Base] ---> [Derived]
//
// Use-case: Extend a single base with new behavior.

#include <iostream>
#include <string>
#include <vector>

namespace single_inheritance {
    class Base {
    protected:
        int id;
    public:
        Base(int id) : id(id) {}
        void greet() const { std::cout << "Base::greet, id=" << id << "\n"; }
    };

    // Public inheritance: Derived "is-a" Base
    class Derived : public Base {
    public:
        Derived(int id) : Base(id) {}
        void work() const { std::cout << "Derived::work using Base id=" << id << "\n"; }
    };

    void demo() {
        Derived d(1);
        d.greet(); // inherited public
        d.work();
    }
}

// ---------------------------------------------------------------
// 2) Multiple Inheritance
// Derived inherits from two or more bases.
// Flowchart:
// [A] ---\
//         ---> [Derived]
// [B] ---/
//
// Use-case: Combine interfaces/behaviors from multiple sources.

namespace multiple_inheritance {
    class Logger {
    public:
        void log(const std::string& msg) const { std::cout << "[log] " << msg << "\n"; }
    };
    class Serializer {
    public:
        std::string toJson(int v) const { return std::string("{\"v\":") + std::to_string(v) + "}"; }
    };

    class Service : public Logger, public Serializer {
        int value{};
    public:
        Service(int v) : value(v) {}
        void run() {
            log("Service running");
            std::cout << "JSON: " << toJson(value) << "\n";
        }
    };

    void demo() {
        Service s(42);
        s.run();
    }
}

// ---------------------------------------------------------------
// 3) Multilevel Inheritance
// Base -> Mid -> Derived
// Flowchart:
// [Base] ---> [Mid] ---> [Derived]
//
// Use-case: Progressive specialization.

namespace multilevel_inheritance {
    class Animal {
    public:
        void breathe() const { std::cout << "Animal breathing\n"; }
    };
    class Mammal : public Animal {
    public:
        void nurse() const { std::cout << "Mammal nursing\n"; }
    };
    class Dog : public Mammal {
    public:
        void bark() const { std::cout << "Dog barking\n"; }
    };

    void demo() {
        Dog d;
        d.breathe();
        d.nurse();
        d.bark();
    }
}

// ---------------------------------------------------------------
// 4) Hierarchical Inheritance
// Multiple Derived classes from the same Base.
// Flowchart:
//            ---> [DerivedA]
// [Base] ---|
//            ---> [DerivedB]
//
// Use-case: Different specializations share a common base.

namespace hierarchical_inheritance {
    class Shape {
    protected:
        std::string name;
    public:
        Shape(std::string n) : name(std::move(n)) {}
        virtual double area() const = 0; // interface
        virtual ~Shape() = default;
    };

    class Circle : public Shape {
        double r;
    public:
        Circle(double r) : Shape("Circle"), r(r) {}
        double area() const override { return 3.14159 * r * r; }
    };

    class Rectangle : public Shape {
        double w, h;
    public:
        Rectangle(double w, double h) : Shape("Rectangle"), w(w), h(h) {}
        double area() const override { return w * h; }
    };

    void demo() {
        std::vector<Shape*> shapes;
        shapes.push_back(new Circle(2.0));
        shapes.push_back(new Rectangle(3.0, 4.0));
        for (auto* s : shapes) {
            std::cout << "Area=" << s->area() << "\n";
            delete s;
        }
    }
}

// ---------------------------------------------------------------
// 5) Hybrid Inheritance (combination)
// Often involves the "Diamond" and virtual inheritance.
// Diamond without virtual:
//           [Base]
//          /      \
//      [Left]    [Right]
//          \      /
//          [Derived]
//
// Problem: Derived contains two Base subobjects (ambiguity).
// Solution: use "virtual" to share one Base.
//
// Flowchart with virtual:
//           [Base]
//          /      \
//   virtual       virtual
//      [Left]    [Right]
//          \      /
//          [Derived]

namespace hybrid_inheritance {
    class Base {
    public:
        int common = 0;
        void hello() const { std::cout << "Base hello, common=" << common << "\n"; }
    };

    // Virtual inheritance ensures only one Base subobject exists.
    class Left : virtual public Base {
    public:
        void setLeft(int x) { common = x; }
    };
    class Right : virtual public Base {
    public:
        void setRight(int y) { common += y; }
    };

    class Derived : public Left, public Right {
    public:
        void show() const { hello(); }
    };

    void demo() {
        Derived d;
        d.setLeft(10);
        d.setRight(5);
        d.show(); // common = 15, single Base subobject
    }
}

// ---------------------------------------------------------------
// Access Specifier Effects Demo
// Shows how public/protected/private inheritance changes visibility.

namespace access_inheritance {
    class Base {
    public:
        void pub() const { std::cout << "Base public\n"; }
    protected:
        void prot() const { std::cout << "Base protected\n"; }
    private:
        void priv() const { std::cout << "Base private\n"; }
    };

    class PublicDerived : public Base {
    public:
        void test() {
            pub();   // OK: remains public
            prot();  // OK: accessible as protected
            // priv(); // Error: not accessible
        }
    };

    class PrivateDerived : private Base {
    public:
        void test() {
            pub();   // OK: becomes private in this class
            prot();  // OK: becomes private in this class
        }
    };
    void callPublicDerived() {
        PublicDerived d;
        d.pub();  // OK
        d.test();
    }
    void callPrivateDerived() {
        PrivateDerived d;
        // d.pub(); // Error: pub is private within PrivateDerived
        d.test();
    }
}

// ---------------------------------------------------------------
// Best Practices:
// - Prefer public inheritance to model "is-a" relationships.
// - Use composition over inheritance if "has-a" fits better.
// - Avoid deep inheritance hierarchies; favor interfaces (pure virtual).
// - Use virtual inheritance to resolve the diamond, but keep it minimal.
// - Mark base destructors virtual when deleting via base pointers.
// - Consider final/override keywords to clarify intent.

// ---------------------------------------------------------------
// Main: run concise demos for each type.

int main() {
    std::cout << "\n--- Single ---\n";
    single_inheritance::demo();

    std::cout << "\n--- Multiple ---\n";
    multiple_inheritance::demo();

    std::cout << "\n--- Multilevel ---\n";
    multilevel_inheritance::demo();

    std::cout << "\n--- Hierarchical ---\n";
    hierarchical_inheritance::demo();

    std::cout << "\n--- Hybrid (virtual inheritance) ---\n";
    hybrid_inheritance::demo();

    std::cout << "\n--- Access Specifiers ---\n";
    access_inheritance::callPublicDerived();
    access_inheritance::callPrivateDerived();

    return 0;
}