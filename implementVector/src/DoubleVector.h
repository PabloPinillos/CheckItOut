#include <memory>
#include <initializer_list>

namespace learncpp
{
    class DoubleVector
    {
    public:
        // Default empty ctor and destructor
        DoubleVector() = default;
        ~DoubleVector() = default;

        // Zeros-initialized vector
        explicit DoubleVector(size_t size);
        // Initializer list ctor
        DoubleVector(std::initializer_list<double> li);
        // Copy ctor
        DoubleVector(const DoubleVector& other);
        // Move ctor
        DoubleVector(DoubleVector &&other) noexcept;
        // Copy assignment
        DoubleVector& operator=(const DoubleVector &other);
        // Move assignment
        DoubleVector& operator=(DoubleVector &&other) noexcept;

        // Typical vector operations
        void reserve(size_t capacity);
        void push_back(double element);

        // Access operators
        double& operator[](size_t index);
        const double& operator[](size_t index) const;

        // Getters for size and capacity
        inline size_t size() const noexcept { return size_; }
        inline size_t capacity() const noexcept { return capacity_; }

        // A way to print the vector
        friend std::ostream& operator<<(std::ostream& stream, const DoubleVector& vec);

    private:
        size_t size_;
        size_t capacity_;
        std::unique_ptr<double[]> arr_;
    };
}
