#pragma once

#include <string>
#include <cmath>
#include <optional>
#include "rational.h"
#include "pow.h"

using Error = std::string;

template<typename Number>
class Calculator{
private:
    Number n_ = 0;
    std::optional<Number> mem_;

    bool IsInt(){
        if constexpr (std::is_same_v<Number, int>){
            return true;
        }
        return false;
    }
    bool IsDouble(){
        if constexpr (std::is_same_v<Number, double>){
            return true;
        }
        return false;
    }
        bool IsFloat(){
            if constexpr (std::is_same_v<Number, float>){
                return true;
            }
            return false;
        }
    bool IsUint8_t(){
        if constexpr (std::is_same_v<Number, uint8_t>){
            return true;
        }
        return false;
    }
    bool IsInt64_t(){
        if constexpr (std::is_same_v<Number, int64_t>){
            return true;
        }
        return false;
    }
    bool IsSize_t(){
        if constexpr (std::is_same_v<Number, size_t>){
            return true;
        }
        return false;
    }
    bool IsRational(){
        if constexpr (std::is_same_v<Number, Rational>){
            return true;
        }
        return false;
    }

public:
    std::optional<Error> Set(Number n){
        n_ = n;
        return std::nullopt;
    }
    Number GetNumber() const{
        return n_;
    }
    std::optional<Error> Add(Number n){
        n_ += n;
        return std::nullopt;
    }
    std::optional<Error> Sub(Number n){
        n_ -= n;
        return std::nullopt;
    }
    std::optional<Error> Div(Number n){
        if(!IsDouble() && !IsFloat() && n == 0){
            return "Division by zero";
        }
        n_ /= n;
        return std::nullopt;
    }
    std::optional<Error> Mul(Number n){
        n_ *= n;
        return std::nullopt;
    }

    std::optional<Error> Pow(Number exp) {
        if (is_zero(n_) && is_zero(exp)) {
            return "Zero power to zero";
        }

        if constexpr (std::is_same_v<Number, Rational>) {
            if (exp.GetDenominator() != 1) {
                return "Fractional power is not supported";
            }
            n_ = PowRational(n_, exp);
            return std::nullopt;
        }

        else if constexpr (std::is_integral_v<Number>) {
            if (exp < Number(0)) {
                return "Integer negative power";
            }
            n_ = IntegerPow(n_, static_cast<long long>(exp));
            return std::nullopt;
        }

        else {
            n_ = static_cast<Number>(std::pow(static_cast<double>(n_), static_cast<double>(exp)));
            return std::nullopt;
        }
    }

    std::optional<Error> Save(Number n){
        mem_ = n;
        return std::nullopt;
    }
    std::optional<Error> Load(Number n){
        if(mem_.has_value()){
            n_ = mem_.value();
            return std::nullopt;
        }
        return "Mem is clear";
    }
};
