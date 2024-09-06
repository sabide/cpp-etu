#include <cassert>
template <typename T>
class CSRMatrix : public MatrixBase<T> {
public:
    CSRMatrix(int rows, int cols)
        : rows_(rows), cols_(cols) {
        row_ptrs_.resize(rows + 1, 0);
    }

    void add_value(int row, int col, T value) {
        assert(row >= 0 && row < rows_);
        assert(col >= 0 && col < cols_);
        values_.push_back(value);
        col_indices_.push_back(col);
        row_ptrs_[row + 1]++;
    }

    void finalize() {
        for (int i = 1; i <= rows_; ++i) {
            row_ptrs_[i] += row_ptrs_[i - 1];
        }
    }

    std::vector<T> operator*(const std::vector<T>& x) const override {
        assert(cols_ == x.size());
        std::vector<T> result(rows_, 0.0);

        for (int i = 0; i < rows_; ++i) {
            for (int j = row_ptrs_[i]; j < row_ptrs_[i + 1]; ++j) {
                result[i] += values_[j] * x[col_indices_[j]];
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
    std::vector<T> values_;
    std::vector<int> col_indices_;
    std::vector<int> row_ptrs_;
};

