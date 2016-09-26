#pragma once

#include <cstdint>

typedef enum
{
    Null_Type,
    Integer_Type,
    Boolean_Type,
    Double_Type,
    Pointer_Type,
} ValueType;

class Value {
    union
    {
        int64_t i64;
        double f64;
        void *ptr;
    } raw_;

    ValueType type_;

  public:
      Value();
      Value(int8_t value);
      Value(int16_t value);
      Value(int32_t value);
      Value(int64_t value);
      Value(bool value);
      Value(double value);

      ValueType Type() const;

      int64_t AsInteger();
      double AsDouble();
      void *AsPointer();
};
