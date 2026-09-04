#pragma once

class Element {
public:
    explicit Element(int id);

    int id() const;
    double area() const;  // TODO : rendre virtuelle, puis virtuelle pure
    ~Element() = default; // TODO : rendre virtuelle

private:
    int id_;
};
