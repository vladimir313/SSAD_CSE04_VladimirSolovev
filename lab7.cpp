#include <vector>
#include <stdexcept>

template <typename T>
class CircularBuffer {
private:
    std::vector<T> buffer;
    size_t capacity;
    size_t start;
    size_t end;
    size_t count;

public:
    CircularBuffer(size_t size) : capacity(size), start(0), end(0), count(0) {
        buffer.resize(size);
    }

    void push(const T& value) {
        if (count == capacity) {
            throw std::overflow_error("Buffer is full");
        }
        buffer[end] = value;
        end = (end + 1) % capacity;
        ++count;
    }

    T pop() {
        if (count == 0) {
            throw std::underflow_error("Buffer is empty");
        }
        T value = buffer[start];
        start = (start + 1) % capacity;
        --count;
        return value;
    }

    bool empty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }

    class Iterator {
    private:
        CircularBuffer& buffer;
        size_t index;
        size_t steps;

    public:
        Iterator(CircularBuffer& buf, size_t idx, size_t stp = 0) : buffer(buf), index(idx), steps(stp) {}

        Iterator& operator++() {
            index = (index + 1) % buffer.capacity;
            ++steps;
            return *this;
        }

        T& operator*() {
            return buffer.buffer[index];
        }

        bool operator==(const Iterator& other) const {
            return &buffer == &other.buffer && steps == other.steps;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    Iterator begin() {
        return Iterator(*this, start);
    }

    Iterator end() {
        return Iterator(*this, start, count);
    }
};

int main() {
    CircularBuffer<int> cb(3);
    cb.push(1);
    cb.push(2);
    cb.push(3);

    for (auto it = cb.begin(); it != cb.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
