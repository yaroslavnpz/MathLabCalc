#include "List.h"
#include "MathType.h"


#include <algorithm>


namespace calc {

List::List(size_t size) : _data(new MathType[size]), _size(size) {}

List::List(const std::initializer_list<MathType>& val) : _data(new MathType[val.size()]), _size(val.size()) {
    std::copy(val.begin(), val.end(), _data.get());
}

void List::clear() {
    _data = nullptr;
    _size = 0;
}

MathType List::operator[](size_t iter) const {
    return _data[iter];
}

List List::operator+() const {
    List res(_size);
    for (size_t i = 0; i < _size; ++i)
        res[i] = +_data[i];
    return res;
}

List List::operator-() const {
    List res(_size);
    for (size_t i = 0; i < _size; ++i)
        res[i] = -_data[i];
    return res;
}

List List::operator!() const {
    List res(_size);
    for (size_t i = 0; i < _size; ++i)
        res[i] = !_data[i];
    return res;
}

List List::operator~() const {
    List res(_size);
    for (size_t i = 0; i < _size; ++i)
        res[i] = ~_data[i];
    return res;
}

List List::operator+(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] + val[j];
        }
    }
}

List List::operator-(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] - val[j];
        }
    }
}

List List::operator*(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] * val[j];
        }
    }
}

List List::operator/(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] / val[j];
        }
    }
}

List List::operator%(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] % val[j];
        }
    }
}

List List::intDiv(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i].intDiv(val[j]);
        }
    }
}

List List::operator&(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] & val[j];
        }
    }
}

List List::operator|(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] | val[j];
        }
    }
}

List List::operator^(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] ^ val[j];
        }
    }
}

List List::operator<<(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] << val[j];
        }
    }
}

List List::operator>>(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] >> val[j];
        }
    }
}

List List::operator&&(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] && val[j];
        }
    }
}

List List::operator||(const List& val) const {
    List res(_size + val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res[i * val._size + j] = _data[i] || val[j];
        }
    }
}

bool List::operator==(const List& val) const {
    if (_size != val._size)
        return false;
    for (size_t i = 0; i < _size; ++i)
        if (_data[i] != val[i])
            return false;
    return true;
}

bool List::operator!=(const List& val) const {
    if (_size != val._size)
        return true;
    for (size_t i = 0; i < _size; ++i)
        if (_data[i] != val[i])
            return true;
    return false;
}


}  // namespace calc
