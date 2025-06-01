#include "../../../include/Data_Types/Value/Value.hpp"
#include <stdexcept>
#include <sstream>

Value::Value() {
  this->type = ValueType::Null;
}

Value::~Value() {
    if (type == ValueType::String && str != nullptr) {
        delete str;
    }
}

Value::Value(const Value& other) {
    type = other.type;
    switch (type) {
        case ValueType::Number:
            number = other.number;
            break;
        case ValueType::Boolean:
            boolean = other.boolean;
            break;
        case ValueType::String:
            str = new std::string(*other.str);
            break;
        case ValueType::Object:
            object = other.object;
            break;
        case ValueType::Array:
            array = other.array;
            break;
        case ValueType::Function:
            function = other.function;
            break;
        case ValueType::Null:
            break;
    }
}

Value& Value::operator=(const Value& other) {
    if (this == &other) return *this;

    this->~Value();

    type = other.type;
    switch (type) {
        case ValueType::Number:
            number = other.number;
            break;
        case ValueType::Boolean:
            boolean = other.boolean;
            break;
        case ValueType::String:
            str = new std::string(*other.str);
            break;
        case ValueType::Object:
            object = other.object;
            break;
        case ValueType::Array:
            array = other.array;
            break;
        case ValueType::Function:
            function = other.function;
            break;
        case ValueType::Null:
            break;
    }

    return *this;
}

Value Value::makeNumber(double num) {
    Value val;
    val.type = ValueType::Number;
    val.number = num;
    return val;
}

Value Value::makeString(const std::string& s) {
    Value val;
    val.type = ValueType::String;
    val.str = new std::string(s);
    return val;
}

Value Value::makeBoolean(bool b) {
    Value val;
    val.type = ValueType::Boolean;
    val.boolean = b;
    return val;
}

Value Value::makeNull() {
    return Value();
}

std::string Value::toString() const {
    std::ostringstream oss;
    switch (type) {
        case ValueType::Number:
            oss << number;
            break;
        case ValueType::Boolean:
            oss << (boolean ? "true" : "false");
            break;
        case ValueType::String:
            oss << '"' << *str << '"';
            break;
        case ValueType::Null:
            oss << "null";
            break;
        case ValueType::Object:
            oss << "[object Object]";
            break;
        case ValueType::Array:
            oss << "[object Array]";
            break;
        case ValueType::Function:
            oss << "[function]";
            break;
    }
    return oss.str();
}
