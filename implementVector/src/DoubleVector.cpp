#include <memory>
#include <initializer_list>
#include <algorithm>

#include <stdexcept>
#include <iostream>
#include "DoubleVector.h"

namespace learncpp
{
    // Zeros-initialized vector
    DoubleVector::DoubleVector(size_t size) : size_{size}, capacity_{size}, arr_{std::make_unique<double[]>(size)} {};
    
    DoubleVector::DoubleVector(std::initializer_list<double> li) : size_{li.size()}, capacity_{li.size()}, arr_{std::make_unique<double[]>(li.size())} 
    {
        std::copy(li.begin(), li.end(), arr_.get());
    };

    DoubleVector::DoubleVector(const DoubleVector& other) : size_{other.size_}, capacity_{other.capacity_}, arr_{other.capacity_ ? std::make_unique<double[]>(other.capacity_) : nullptr}
    {
        if (other.arr_)
            std::copy(other.arr_.get(), other.arr_.get() + other.capacity_, this->arr_.get());
    };

    DoubleVector::DoubleVector(DoubleVector &&other) noexcept : size_{other.size_}, capacity_{other.capacity_}, arr_{std::move(other.arr_)}
    {
        // Lastly, invalidate the remaining stuff from the initial vector
        other.size_ = 0;
        other.capacity_ = 0;
        other.arr_ = nullptr;
    };

    DoubleVector& DoubleVector::operator=(const DoubleVector &other)
    {
        if (this == &other)
            return *this;

        size_ = other.size_;
        capacity_ = other.capacity_;

        arr_ = other.capacity_ ? std::make_unique<double[]>(other.capacity_) : nullptr;
        if (other.arr_)
            std::copy(other.arr_.get(), other.arr_.get() + other.capacity_, this->arr_.get());  
        return *this;
    };

    DoubleVector& DoubleVector::operator=(DoubleVector &&other) noexcept
    {
        if (this == &other)
            return *this;

        size_ = other.size_;
        capacity_ = other.capacity_;
        arr_ = std::move(other.arr_);
        other.size_ = 0;
        other.capacity_ = 0;
        other.arr_ = nullptr;
        return *this;
    };

    void DoubleVector::reserve(size_t capacity)
    {
        if (capacity <= capacity_)
            return;

        auto new_arr = std::make_unique<double[]>(capacity);
        if (arr_)
        {
            std::copy(arr_.get(), arr_.get() + capacity_, new_arr.get());  
        }
        arr_ = std::move(new_arr);
        capacity_ = capacity;
    };

    void DoubleVector::push_back(double element)
    {
        if (size_ == capacity_)
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);

        arr_[size_] = element;
        ++size_;
    };

    double& DoubleVector::operator[](size_t index)
    {
        if (index >= size_)
        {
            throw std::out_of_range("Index out of range");
        }

        return arr_[index];
    };

    const double& DoubleVector::operator[](size_t index) const
    {
        if (index >= size_)
        {
            throw std::out_of_range("Index out of range");
        }

        return arr_[index];
    };

    std::ostream& operator<<(std::ostream& stream, const DoubleVector& vec)
    {
        for (size_t i = 0; i < vec.size(); ++i)
            stream << vec[i] << " ";
        stream << std::endl;
        return stream;
    };
}
