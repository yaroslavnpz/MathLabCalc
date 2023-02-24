#include "List.h"
#include "MathType.h"
#include "MathType_templates.inl"


#include <algorithm>
#include <sstream>


namespace calc {

List::List(size_t size) : _data(new MathType[size]), _size(size) {}

List::List(const std::initializer_list<MathType>& val) : _data(new MathType[val.size()]), _size(val.size()) {
    std::copy(val.begin(), val.end(), _data.get());
}

List::List(const MathType& val) :_data(new MathType[1]), _size(1) {
    _data[0] = val;
}

List::List(Bool val) : _data(new MathType[1]), _size(1) {
    _data[0] = val;
}

List::List(Int val) : _data(new MathType[1]), _size(1) {
    _data[0] = val;
}

List::List(Double val) : _data(new MathType[1]), _size(1) {
    _data[0] = val;
}

List::List(const Ratio& val) : _data(new MathType[1]), _size(1) {
    _data[0] = val;
}

List::List(const Seg& val) : _data(new MathType[1]), _size(1) {
    _data[0] = val;
}

const std::wstring List::getType() const {
    return L"List";
}

const std::wstring List::getName() const {
    std::wstringstream stream;
    stream << L"{";
    for (size_t i = 0; i + 1 < size(); ++i)
        stream << _data[i].getName() << L", ";
    if (size() != 0)
        stream << _data[size() - 1].getName();
    stream << L"}";
    return stream.str();
}

void List::clear() {
    _data = nullptr;
    _size = 0;
}

MathType* List::begin() noexcept {
    return _data.get();
}

const MathType* List::begin() const noexcept {
    return _data.get();
}

MathType* List::end() noexcept {
    return _data.get() + _size;
}

const MathType* List::end() const noexcept {
    return _data.get() + _size;
}

const MathType List::operator[](size_t iter) const {
    return _data[iter];
}

const MathType List::operator[](Int val) const {
    return _data[val.getData()];
}

const List List::operator[](const List& val) const {
    const MathType th = *this;
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = th[val[i]];
    }
    return res;
}

List List::operator+() const {
    List res(_size);
    for (size_t i = 0; i < _size; ++i)
        res._data[i] = +_data[i];
    return res;
}

List List::operator-() const {
    List res(_size);
    for (size_t i = 0; i < _size; ++i)
        res._data[i] = -_data[i];
    return res;
}

List List::operator!() const {
    List res(_size);
    for (size_t i = 0; i < _size; ++i)
        res._data[i] = !_data[i];
    return res;
}

List List::operator~() const {
    List res(_size);
    for (size_t i = 0; i < _size; ++i)
        res._data[i] = ~_data[i];
    return res;
}

List List::operator+(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] + val[j];
        }
    }
    return res;
}

List List::operator-(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] - val[j];
        }
    }
    return res;
}

List List::operator*(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] * val[j];
        }
    }
    return res;
}

List List::operator/(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] / val[j];
        }
    }
    return res;
}

List List::operator%(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] % val[j];
        }
    }
    return res;
}

List List::intDiv(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i].intDiv(val[j]);
        }
    }
    return res;
}

List List::operator&(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] & val[j];
        }
    }
    return res;
}

List List::operator|(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] | val[j];
        }
    }
    return res;
}

List List::operator^(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] ^ val[j];
        }
    }
    return res;
}

List List::operator<<(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] << val[j];
        }
    }
    return res;
}

List List::operator>>(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] >> val[j];
        }
    }
    return res;
}

List List::operator&&(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] && val[j];
        }
    }
    return res;
}

List List::operator||(const List& val) const {
    List res(_size * val._size);
    for (size_t i = 0; i < _size; ++i) {
        for (size_t j = 0; j < val._size; ++j) {
            res._data[i * val._size + j] = _data[i] || val[j];
        }
    }
    return res;
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

bool List::operator<(const List& val) const {
    for (size_t i = 0; i < _size && i < val._size; ++i) {
        if (_data[i] > val[i])
            return false;
        else if (_data[i] < val[i])
            return true;
    }
    if (_size < val.size())
        return true;
    return false;
}

bool List::operator<=(const List& val) const {
    for (size_t i = 0; i < _size && i < val._size; ++i) {
        if (_data[i] > val[i])
            return false;
        else if (_data[i] < val[i])
            return true;
    }
    if (_size <= val.size())
        return true;
    return false;
}

bool List::operator>(const List& val) const {
    for (size_t i = 0; i < _size && i < val._size; ++i) {
        if (_data[i] < val[i])
            return false;
        else if (_data[i] > val[i])
            return true;
    }
    if (_size > val.size())
        return true;
    return false;
}

bool List::operator>=(const List& val) const {
    for (size_t i = 0; i < _size && i < val._size; ++i) {
        if (_data[i] < val[i])
            return false;
        else if (_data[i] > val[i])
            return true;
    }
    if (_size >= val.size())
        return true;
    return false;
}

List abs(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = abs(val[i]);
    }
    return res;
}

List sqrt(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = sqrt(val[i]);
    }
    return res;
}

List log2(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = log2(val[i]);
    }
    return res;
}

List log10(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = log10(val[i]);
    }
    return res;
}

List ln(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = ln(val[i]);
    }
    return res;
}

List sin(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = sin(val[i]);
    }
    return res;
}

List cos(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = cos(val[i]);
    }
    return res;
}

List tg(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = tg(val[i]);
    }
    return res;
}

List ctg(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = ctg(val[i]);
    }
    return res;
}

List asin(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = asin(val[i]);
    }
    return res;
}

List acos(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = acos(val[i]);
    }
    return res;
}

List atg(const List& val) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = atg(val[i]);
    }
    return res;
}

List pow(const List& val, const MathType& base) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = pow(val[i], base);
    }
    return res;
}

List pow(const List& val, const List& base) {
    List res(val.size() * base.size());
    for (size_t i = 0; i < val.size(); ++i) {
        for (size_t j = 0; j < base.size(); ++j) {
            res._data[i * base.size() + j] = pow(val[i], base[j]);
        }
    }
    return res;
}

List log(const List& val, const MathType& base) {
    List res(val.size());
    for (size_t i = 0; i < val.size(); ++i) {
        res._data[i] = log(val[i], base);
    }
    return res;
}

List log(const List& val, const List& base) {
    List res(val.size() * base.size());
    for (size_t i = 0; i < val.size(); ++i) {
        for (size_t j = 0; j < base.size(); ++j) {
            res._data[i * base.size() + j] = log(val[i], base[j]);
        }
    }
    return res;
}

List sort(const List& val) {
    List res(val.size());
    std::copy(val.begin(), val.end(), res.begin());
    std::sort(res.begin(), res.end());
    return res;
}

List unique(const List& val) {
    List res(val.size());
    std::copy(val.begin(), val.end(), res.begin());
    res._size = std::unique(res.begin(), res.end()) - res.begin();
    return res;
}

List reverse(const List& val) {
    List res(val.size());
    std::copy(val.begin(), val.end(), res.begin());
    std::reverse(res.begin(), res.end());
    return res;
}

List join(const List& val, const MathType& add) {
    List res(val.size() + 1);
    std::copy(val.begin(), val.end(), res.begin());
    res._data[val.size()] = add;
    return res;
}

List join(const List& val, const List& add) {
    List res(val.size() + add.size());
    std::copy(val.begin(), val.end(), res.begin());
    std::copy(add.begin(), add.end(), res.begin() + val.size());
    return res;
}

MathType min(const List& val) {
    if (val.size() == 0)
        throw BadIterator();
    auto res = val[0];
    for (size_t i = 1; i < val.size(); ++i)
        if (val[i] < res)
            res = val[i];
    return res;
}

MathType max(const List& val) {
    if (val.size() == 0)
        throw BadIterator();
    auto res = val[0];
    for (size_t i = 1; i < val.size(); ++i)
        if (val[i] > res)
            res = val[i];
    return res;
}

}  // namespace calc
