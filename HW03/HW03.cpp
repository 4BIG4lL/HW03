#include <iostream>
#include <algorithm>

template <typename T>

// 클래스의 이름은 SimpleVector 라고 합니다.
// 타입에 의존하지 않고 데이터를 받을 수 있는 배열을 멤버변수로 갖습니다.
// 생성자는 아래와 같이 구현 합니다.
//     기본 생성자는 크기가 10인 배열을 만듭니다.
//     숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.
// 아래와 같은 멤버함수를 구현 합니다.
//     push_back 인자로 받은 원소를 "맨 뒤"에 추가 합니다. 반환값은 없습니다. 배열의 크기가 꽉 찼는데
//     원소가 더 들어올 경우, 아무 동작도 하지 않습니다.
//     pop_back은 벡터의 마지막 원소를 제거 합니다. 만약 제거할 원소가 없다면, 아무런 동작을
//     하지 않고 인자 및 반환값은 없습니다.
//     size는 인자가 없고, 현재 원소의 개수를 반환합니다.
//     capacity는 현재 내부 배열의 크기를 반환합니다.


class SimpleVector {
private:
    T* data;
    int currentSize;
    int currentCapacity;

public:
    // 기본 생성자 (크기가 10인 배열)
    SimpleVector() {
        currentCapacity = 10;
        data = new T[currentCapacity];
        currentSize = 0;
    }

    // 숫자를 하나 받는 생성자 (입력된 숫자의 크기의 배열)
    SimpleVector(int capacity) {
        currentCapacity = capacity;
        data = new T[currentCapacity];
        currentSize = 0;
    }

    // 복사 생성자
    SimpleVector(const SimpleVector& other) {
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
        data = new T[currentCapacity];
        for (int i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }
    }

    // 소멸자!
    ~SimpleVector() {
        delete[] data;
    }

    // push_back으로 맨 뒤에 추가 (if:꽉 차면 동작X)
    // 추가 : 꽉 찼을때 원소가 더 생기면, 크기를 5추가하고 원소 추가
    void push_back(const T& value) {
        if (currentSize >= currentCapacity) {
            resize(currentCapacity + 5);
        }
        data[currentSize++] = value;
    }

    // pop_back으로 마지막 원소 제거 (if:아무것도 없으면 동작X)
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
        }
    }

    // size는 현재 원소 개수 반환
    int size() const {
        return currentSize;
    }

    // 전체 배열 크기 반환
    int capacity() const {
        return currentCapacity;
    }

    // resize는 정수 하나를 받아서, 그 수가 배열크기보다 작으면 동작 X
    // (if: 배열보다 크기가 크면, 해당 정수 값만큼 크기 다시 할당)
    void resize(int newCapacity) {
        if (newCapacity <= currentCapacity) {
            return;
        }

        T* NewData = new T[newCapacity];
        for (int i = 0; i < currentSize; ++i) {
            NewData[i] = data[i];
        }

        delete[] data;
        data = NewData;
        currentCapacity = newCapacity;
    }

    // 내부 데이터 정렬, STL의 sort 사용
    void sortData() {
        std::sort(data, data + currentSize);
    }
};

int main()
{
    return 0;
}
