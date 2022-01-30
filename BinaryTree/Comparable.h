#pragma once

template<class T>
class Comparable
{
public:
    inline virtual bool equals(T* item) const noexcept { return false; }

    inline virtual long hashCode() const noexcept { return 0; }
};