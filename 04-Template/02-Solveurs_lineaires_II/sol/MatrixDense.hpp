template <typename T>
class DenseMatrix : public MatrixBase<T> {
public:
    DenseMatrix(int rows, int cols)
        : rows_(rows), cols_(cols), data_(new T[rows * cols]()) {}

    ~DenseMatrix() {
        delete[] data_;
    }

    T operator()(int row, int col) const {
        assert(row >= 0 && row < rows_);
        assert(col >= 0 && col < cols_);
        return data_[row * cols_ + col];
    }

    T& operator()(int row, int col) {
        assert(row >= 0 && row < rows_);
        assert(col >= 0 && col < cols_);
        return data_[row * cols_ + col];
    }

    std::vector<T> operator*(const std::vector<T>& x) const override {
        assert(cols_ == x.size());
        std::vector<T> result(rows_, 0.0);

        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result[i] += (*this)(i, j) * x[j];
            }
        }

        return result;
    }

    int rows() const override {
        return rows_;
    }

    int cols() const override {
        return cols_;
    }

private:
    int rows_, cols_;
    T* data_;
};

