//реализация ветктора
//выбрана реализация на динамическом массиве
#include <algorithm>

template <typename T>
class Vector {
private:
	T* pMem; //указатель на начало массива
	size_t sz; //количество элементов в векторе
	size_t capacity; //размер выделенной в данный момент памяти(максимальное кол-во элементов до перевыделения памяти)

public:
	Vector(size_t _capacity = 0) :sz(0), capacity(_capacity) {
		if (_capacity < 0) throw std::bad_alloc();
		if (capacity == 0) capacity = 10;
		pMem = new T[capacity];
		if (pMem == nullptr) throw std::bad_alloc();
	}

    Vector(Vector const &v) :sz(v.sz), capacity(v.capacity) {
		pMem = new T[capacity];
		if (pMem == nullptr) throw std::bad_alloc();
		copy(v.pMem, v.pMem+(sz * sizeof(T)), v.pMem);
	}

	Vector(T* arr, size_t size_array):sz(size_array), capacity(size_array) {
		if (capacity <= 0) throw std::bad_alloc();
		pMem = new T[capacity];
		if (pMem == nullptr) throw std::bad_alloc();
		std::copy(arr, arr + (sz * sizeof(T)), pMem);
	}

    ~Vector(){
        delete[] pMem;
        pMem=nullptr;
    }
    
	//перевыделение памяти
	void Overexpression() {
		T* temp_pMem = new T[(capacity * 2)];
		if (temp_pMem == nullptr) throw std::bad_alloc();
		std::copy(pMem, pMem + (sz * sizeof(T)), temp_pMem); //копирование из pMem в temp_pMem
		std::swap(pMem, temp_pMem);
		capacity *= 2;
		delete[] temp_pMem;
	}

	bool IsFull(){
		if (sz == capacity) return true;
		else return false;
	}

	bool IsEmpty() {
		if (sz == 0) return true;
		else return false;
	}

	virtual void push_back(T el) {
		if (IsFull()) Overexpression();
		pMem[sz++] = el;
	}

    virtual void push_front(T el) {
		if (IsFull()) Overexpression();
		for (size_t i = 0; i < sz; ++i) pMem[i + 1] = pMem[i];
		pMem[0] = el;
		++sz;
	}

    virtual T back() {
		if (IsEmpty()) throw std::logic_error("error");
		return pMem[sz - 1];
	}

    virtual T front() {
		if (IsEmpty()) throw std::logic_error("error");
		return pMem[0];
	}

    virtual void pop_back() {
		if (IsEmpty()) std::logic_error("error");
		--sz;
	}

    virtual void pop_front() {
		if (IsEmpty()) std::logic_error("error");
		sz--;
		for (size_t i = 0; i < (sz); ++i) pMem[i] = pMem[i + 1];
	}
	
};



template <typename T>
class Stack: public Vector<T> {
private:
	//переопределение незадействованных методов
	void push_front(T el) override{};
	void pop_front() override {};
	T front() override { return T(); };
};
