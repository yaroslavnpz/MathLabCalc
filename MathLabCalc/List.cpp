#include "List.h"


#include <algorithm>


namespace calc {

void calc::List::optimize() {
    std::vector<size_t> del;
    for (size_t i = 0; i < data.size(); ++i)
        if (data[i].index() == 0)
            del.push_back(i);

    if (!del.empty()) {
        size_t i = 0;
        size_t j = 0;
        size_t k = 0;
        while (i < data.size() && j < data.size()) {
            while (k < del.size() && del[k] <= j)
                ++j;

            if (j < data.size()) {
                data[i++] = data[j++];
            }
        }
        data.resize(data.size() - del.size());
    }
}

List::List(const std::initializer_list<MathType>& val) : data(val) {}

List::List(const MathType& val) : data(1, val) {}

const List List::operator+() const {
    List res = *this;
    for (auto& t : res.data)
        t = +t;
    res.optimize();
    return res;
}

const List List::operator-() const {
    List res = *this;
    for (auto& t : res.data)
        t = -t;
    res.optimize();
    return res;
}

const List List::operator~() const {
    List res = *this;
    for (auto& t : res.data)
        t = ~t;
    res.optimize();
    return res;
}

const List List::operator+(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i] = t + q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator-(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t - q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator*(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t * q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator/(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t / q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator%(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t % q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::intDiv(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t.intDiv(q);
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator&(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t & q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator|(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t | q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator^(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t ^ q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator<<(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t << q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator>>(const List& val) const {
    List res;
    res.data.resize(data.size() * val.data.size());

    size_t i = 0;
    for (auto& t : data) {
        for (auto& q : val.data) {
            res.data[i++] = t >> q;
            if (res.data[i].index() != 0)
                ++i;
        }
    }
    res.optimize();
    return res;
}

const List List::operator||(const List& val) const {
    List res;
    res.data.resize(data.size() + val.data.size());
    std::copy(data.begin(), data.end(), res.data.begin());
    std::copy(val.data.begin(), val.data.end(), res.data.begin() + data.size());
    std::sort(res.data.begin(), res.data.end());
    res.data.resize(std::unique(res.data.begin(), res.data.end()) - res.data.begin());
    res.optimize();
    return res;
}

const List List::operator&&(const List& val) const {
    List res;

    auto a = val.data;
    std::sort(a.begin(), a.end());

    for (auto& t : data) {
        if (std::binary_search(a.begin(), a.end(), t))
            res.data.push_back(t);
    }
    res.optimize();
    return res;
}

const bool List::operator==(const List& val) const {
    if (data.size() != val.data.size())
        return false;
    for (size_t i = 0; i < data.size(); ++i)
        if (data[i] != val.data[i])
            return false;
    return true;
}

const bool List::operator!=(const List& val) const {
    return !(*this == val);
}

const bool List::operator<(const List& val) const {
    for (size_t i = 0; i < data.size() && i < val.data.size(); ++i) {
        if (data[i] < val.data[i])
            return true;
        else if (data[i] == val.data[i])
            continue;
        else
            return false;
    }
    return data.size() < val.data.size();
}

const bool List::operator<=(const List& val) const {
    for (size_t i = 0; i < data.size() && i < val.data.size(); ++i) {
        if (data[i] < val.data[i])
            return true;
        else if (data[i] == val.data[i])
            continue;
        else
            return false;
    }
    return data.size() <= val.data.size();
}

const bool List::operator>(const List& val) const {
    for (size_t i = 0; i < data.size() && i < val.data.size(); ++i) {
        if (data[i] > val.data[i])
            return true;
        else if (data[i] == val.data[i])
            continue;
        else
            return false;
    }
    return data.size() > val.data.size();
}

const bool List::operator>=(const List& val) const {
    for (size_t i = 0; i < data.size() && i < val.data.size(); ++i) {
        if (data[i] > val.data[i])
            return true;
        else if (data[i] == val.data[i])
            continue;
        else
            return false;
    }
    return data.size() >= val.data.size();
}

}  // namespace calc
