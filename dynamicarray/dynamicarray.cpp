#include <iostream>
#include <cassert>
using namespace std;

class DynamicArray {
private:
    int size = 0;
    int capacity;
    string* array;

public:
    DynamicArray() {
        capacity = 10;
        array = new string[capacity];
    }

    DynamicArray(int c) {
        capacity = c;
        array = new string[capacity];
    }

    DynamicArray(int c, string* in, int inSize) {
        capacity = c;
        size = inSize;
        array = new string[capacity];

        for (int i = 0; i < inSize; i++) {
            array[i] = in[i];
        }
    }

    bool insert(string newElement, int position) {
        if (position < 0 || position > size) {
            cout << "Error: Invalid position." << endl;
            return false;
        }

        if (capacity <= size) {
            capacity *= 2;
        }

        string* newArray = new string[capacity];
        int i = 0;

        for (; i < position; i++) {
            newArray[i] = array[i];
        }

        newArray[i] = newElement;
        i++;

        for (; i < size + 1; i++) {
            newArray[i] = array[i - 1];
        }

        delete[] array;
        array = newArray;
        size++;
        return true;
    }

    bool remove(int position) {
        if (position < 0 || position >= size) {
            cout << "Error: Invalid position." << endl;
            return false;
        }

        string* newArray = new string[capacity];
        int i = 0;

        for (; i < position; i++) {
            newArray[i] = array[i];
        }

        for (; i < size - 1; i++) {
            newArray[i] = array[i + 1];
        }

        delete[] array;
        array = newArray;
        size--;
        return true;
    }

    void invert() {
        for (int i = 0; i < size / 2; i++) {
            swap(array[i], array[size - i - 1]);
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << ", ";
        }
        cout << endl;
    }

    ~DynamicArray() {
        delete[] array;
    }
};

int main() {
    DynamicArray arr(10);

    arr.insert("aa", 0);
    arr.print();
    arr.insert("ab", 0);
    arr.print();
    arr.insert("ac", 0);
    arr.print();

    cout << "Inverting array:" << endl;
    arr.invert();
    arr.print();

    return 0;
}
