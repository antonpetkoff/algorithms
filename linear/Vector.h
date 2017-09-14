#ifndef ALGORITHMS_VECTOR_H
#define ALGORITHMS_VECTOR_H

#include <cstdlib>
#include <cmath>

template <class T>
class Vector {
private:
    static constexpr std::size_t RESIZE_FACTOR = 2;
    static constexpr double SCALE_FACTOR = (sqrt(5) + 1) / 2.0;

    T * _buffer;
    std::size_t _capacity;
    std::size_t _size;

    static void fill(T* const buffer, const std::size_t length, const T& value) {
        for(int i = 0; i < length; ++i) {
            buffer[i] = value;
        }
    }

    const std::size_t optimalCapacity(const std::size_t totalCapacity, const std::size_t takenCapacity) {
        if (takenCapacity == totalCapacity) {
            return RESIZE_FACTOR * totalCapacity;
        } else if (takenCapacity < 2 * totalCapacity) {
            return totalCapacity / RESIZE_FACTOR;
        }
    }

    void ensureCapacity() {
        if (_size < _capacity && _size > 0.5 * _capacity) {
            return;
        }
        resize(optimalCapacity(_capacity, _size));
    }
public:
    Vector();
    Vector(const std::size_t size, const T& value);
    Vector(const Vector<T>& v);
    ~Vector();

    inline constexpr const std::size_t size() const                   { return _size; }
    inline constexpr const T& operator[](const std::size_t pos) const { return _buffer[pos]; }
    inline T& operator[](const std::size_t pos)                       { return _buffer[pos]; }

    inline constexpr T* begin() const                           { return _buffer; }
    inline constexpr T* end() const                             { return _buffer + _size; }

    void resize(const std::size_t capacity, const T& value);
    void push_back(const T& value);
    void pop_back();
};

template<typename T>
Vector<T>::Vector() {
    _capacity = 16;
    _size = 0;
    _buffer = new T[_capacity];
}

template<typename T>
Vector<T>::Vector(const std::size_t size, const T& value) {
    _capacity = size;
    _buffer = new T[_capacity];
    fill(_buffer, _capacity, value);
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v) {
    _capacity = v._capacity;
    _buffer = new T[_capacity];

    for (int i = 0; i < v._capacity; ++i) {
        _buffer[i] = v._buffer[i];
    }
}

template<typename T>
Vector<T>::~Vector(){
    delete[] _buffer;
}

template<typename T>
void Vector<T>::resize(const std::size_t capacity, const T& value = T()) {
    // allocate new buffer
    T* const new_buffer = new T[capacity];

    // move old data to new buffer
    T* iter = _buffer;
    T* iter_end = _buffer + _capacity;
    for (int i = 0; i < capacity; ++i) {
        if (iter != iter_end) {
            new_buffer[i] = *iter;
            ++iter;
        } else {
            new_buffer[i] = value;
        }
    }

    // delete old buffer
    delete[] _buffer;
    _buffer = new_buffer;
    _capacity = capacity;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    // ensureCapacity();
    if (_size == _capacity) {
        resize(static_cast<const std::size_t>(_capacity * SCALE_FACTOR));
    }
    _buffer[_size++] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    if (_size > 0) {
        _size--;
    }
}

#endif //ALGORITHMS_VECTOR_H
