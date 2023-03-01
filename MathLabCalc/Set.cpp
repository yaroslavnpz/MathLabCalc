#include "MathType.h"
#include "Set.h"


#include <sstream>


namespace calc {

Set::Set(const std::initializer_list<MathType>& val) : _data(val) {}

Set::Set(const MathType& val) {
    _data.insert(val);
}

Set::Set(Bool val) {
    _data.insert(val);
}

Set::Set(Int val) {
    _data.insert(val);
}

Set::Set(Double val) {
    _data.insert(val);
}

Set::Set(const Ratio& val) {
    _data.insert(val);
}

Set::Set(const Seg& val) {
    _data.insert(val);
}

Set::Set(const List& val) {
    for (size_t i = 0; i < val.size(); ++i)
        _data.insert(val[i]);
}

const std::wstring Set::getType() const {
    return L"Set";
}

const std::wstring Set::getName() const {
    std::wstringstream stream;
    stream << L'{';
    if (size() != 0)
        stream << _data.begin()->getName();
    for (auto t = ++_data.begin(); t != _data.end(); ++t)
        stream << L", " << t->getName();
    stream << L'}';
    return stream.str();
}

void Set::clear() {
    _data.clear();
}

const Set Set::operator+() const {
    Set res;
    for (auto& t : _data)
        res.insert(+t);
    return res;
}

const Set Set::operator-() const {
    Set res;
    for (auto& t : _data)
        res.insert(-t);
    return res;
}

const Set Set::operator~() const {
    Set res;
    for (auto& t : _data)
        res.insert(~t);
    return res;
}

const Set Set::operator+(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t + k);
    }
    return res;
}

const Set Set::operator-(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t - k);
    }
    return res;
}

const Set Set::operator*(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t * k);
    }
    return res;
}

const Set Set::operator/(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t / k);
    }
    return res;
}

const Set Set::operator%(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t % k);
    }
    return res;
}

const Set Set::intDiv(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t.intDiv(k));
    }
    return res;
}

const Set Set::operator&(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t & k);
    }
    return res;
}

const Set Set::operator|(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t | k);
    }
    return res;
}

const Set Set::operator^(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t ^ k);
    }
    return res;
}

const Set Set::operator<<(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t << k);
    }
    return res;
}

const Set Set::operator>>(const Set& val) const {
    Set res;
    for (auto& t : _data) {
        for (auto& k : val._data)
            res.insert(t >> k);
    }
    return res;
}

const Set Set::operator&&(const Set& val) const {
    Set res;
    for (auto& t : val._data) {
        if (_data.find(t) != _data.end())
            res.insert(t);
    }
    return res;
}

const Set Set::operator||(const Set& val) const {
    Set res = *this;
    for (auto& t : val._data)
        res.insert(t);
    return res;
}

const MathType Set::operator&&(const Bool val) const {
    if (val.getData())
        return val;
    else
        return false;
}

const MathType Set::operator||(const Bool val) const {
    if (val.getData())
        return val;
    else
        return *this;
}

bool Set::operator==(const Set& val) const {
    return _data == val._data;
}

bool Set::operator!=(const Set& val) const {
    return _data != val._data;
}

bool Set::operator<(const Set& val) const {
    return _data < val._data;
}

bool Set::operator<=(const Set& val) const {
    return _data <= val._data;
}

bool Set::operator>(const Set& val) const {
    return _data > val._data;
}

bool Set::operator>=(const Set& val) const {
    return _data >= val._data;
}

const Set abs(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(abs(t));
    return res;
}

const Set sqrt(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(sqrt(t));
    return res;
}

const Set log2(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(log2(t));
    return res;
}

const Set log10(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(log10(t));
    return res;
}

const Set ln(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(ln(t));
    return res;
}

const Set sin(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(sin(t));
    return res;
}

const Set cos(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(cos(t));
    return res;
}

const Set tg(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(tg(t));
    return res;
}

const Set ctg(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(ctg(t));
    return res;
}

const Set asin(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(asin(t));
    return res;
}

const Set acos(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(acos(t));
    return res;
}

const Set atg(const Set& val) {
    Set res;
    for (auto& t : val._data)
        res.insert(atg(t));
    return res;
}

const Set pow(const Set& val, const MathType& base) {
    Set res;
    for (auto& t : val._data) {
        res.insert(pow(t, base));
    }
    return res;
}

const Set pow(const Set& val, const Set& base) {
    Set res;
    for (auto& t : val._data)
        for (auto& k : base._data)
            res.insert(pow(t, k));
    return res;
}

const Set log(const Set& val, const MathType& base) {
    Set res;
    for (auto& t : val._data) {
        res.insert(log(t, base));
    }
    return res;
}

const Set log(const Set& val, const Set& base) {
    Set res;
    for (auto& t : val._data)
        for (auto& k : base._data)
            res.insert(pow(t, k));
    return res;
}

const Set join(const Set& val, const MathType& add) {
    Set res = val;
    res.insert(add);
    return res;
}

const Set join(const Set& val, const Set& add) {
    Set res = val;
    for (auto& t : add._data)
        res.insert(t);
    return res;
}

MathType min(const Set& val) {
    if (val.size() == 0)
        throw BadIterator();
    MathType res = *val._data.begin();
    for (auto& t : val._data)
        if (t < res)
            res = t;
    return res;
}

MathType max(const Set& val) {
    if (val.size() == 0)
        throw BadIterator();
    MathType res = *val._data.begin();
    for (auto& t : val._data)
        if (t > res)
            res = t;
    return res;
}

}  // namespace calc
