#include <Execution/Value.h>

Value::Value()
{
    type_ = Null_Type;
}

Value::Value(int8_t value)
{
    type_ = Integer_Type;
    raw_.i64 = value;
}

Value::Value(int16_t value)
{
    type_ = Integer_Type;
    raw_.i64 = value;
}

Value::Value(int32_t value)
{
    type_ = Integer_Type;
    raw_.i64 = value;
}

Value::Value(int64_t value)
{
    type_ = Integer_Type;
    raw_.i64 = value;
}

Value::Value(bool value)
{
    type_ = Boolean_Type;
    raw_.i64 = (value == true) ? 1 : 0;
}

Value::Value(double value)
{
    type_ = Double_Type;
    raw_.f64 = value;
}

ValueType Value::Type() const
{
    return type_;
}

int64_t Value::AsInteger()
{
    return raw_.i64;
}

double Value::AsDouble()
{
    return raw_.f64;
}

void *Value::AsPointer()
{
    return raw_.ptr;
}
