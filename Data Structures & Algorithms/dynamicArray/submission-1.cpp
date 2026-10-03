class DynamicArray {
public:
    int *arr;
    int CurrSize;
    int Capacity;
    DynamicArray(int capacity):Capacity(capacity) {
        arr = new int[Capacity];
        CurrSize = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(CurrSize == Capacity){
            DynamicArray::resize();
        }

        arr[CurrSize] = n;
        CurrSize++;
    }

    int popback() {
        CurrSize--;
        return arr[CurrSize];
    }

    void resize() {
        int *temp = new int[2 * Capacity];
        copy(arr, arr + CurrSize, temp);
        delete[] arr;
        arr = temp;
        Capacity *= 2;
    }

    int getSize() {
        return CurrSize;
    }

    int getCapacity() {
        return Capacity;
    }
};
