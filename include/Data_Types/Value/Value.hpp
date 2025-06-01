#ifndef VALUE_HPP
#define VALUE_HPP


#include <string>
#include <memory>

enum class ValueType {
    Number,
    String,
    Boolean,
    Object,
    Array,
    Null,
    Function
};

struct Object;
struct Array;
struct Function;

struct Value {
    ValueType type;

    union {
        double number;
        bool boolean;
        std::string* str;
        Object* object;
        Array* array;
        Function* function;
    };

    Value();
    ~Value();
    Value(const Value&);
    Value& operator=(const Value&);

    static Value makeNumber(double);
    static Value makeString(const std::string&);
    static Value makeBoolean(bool);
    static Value makeNull();

    std::string toString() const;
};

#endif // VALUE_HPP