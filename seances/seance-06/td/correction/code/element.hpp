#pragma once

class Element {
public:
    int id() const;
    virtual double area() const = 0;
    virtual ~Element() = default;

protected:
    explicit Element(int id);

private:
    int id_;
};
