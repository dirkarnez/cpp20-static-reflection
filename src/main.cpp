#include <iostream>
#include <string>
#include <typeinfo>

// Example struct
struct Person {
    std::string name;
    int age;
    double height;
};

// Helper function to print the name and type of a member variable
template <typename T>
void printMember(const T& instance, const char* memberName) {
    if constexpr (std::is_same_v<decltype(instance.name), std::string>) {
        if (std::string(memberName) == "name") {
            std::cout << "Member: name, Type: " << typeid(instance.name).name() << ", Value: " << instance.name << std::endl;
            return;
        }
    }

    if constexpr (std::is_same_v<decltype(instance.age), int>) {
        if (std::string(memberName) == "age") {
            std::cout << "Member: age, Type: " << typeid(instance.age).name() << ", Value: " << instance.age << std::endl;
            return;
        }
    }

    if constexpr (std::is_same_v<decltype(instance.height), double>) {
        if (std::string(memberName) == "height") {
            std::cout << "Member: height, Type: " << typeid(instance.height).name() << ", Value: " << instance.height << std::endl;
            return;
        }
    }

    std::cout << "Member: " << memberName << " not found." << std::endl;
}

// Struct introspection using constexpr and decltype(auto)
template <typename T>
void introspectStruct() {
    std::cout << "Struct Name: " << typeid(T).name() << std::endl;

    // Introspect member variables
    std::cout << "Member Variables:" << std::endl;
    printMember(T{}, "name");
    printMember(T{}, "age");
    printMember(T{}, "height");

    // Introspect member functions
    // ...
}

int main() {
    // Perform introspection on the Person struct
    introspectStruct<Person>();

    return 0;
}
