#include <iostream>
#include <exception>

class smart_array {
public:
	smart_array(int size) {
		if (size <= 0) {
			throw std::exception("Некорректный размер массива");
		}
		m_size = size;
		m_count = 0;
		m_data = new int[m_size];
	}

	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;

	void add_element(int value) {
		if (m_count >= m_size) {
			int new_size = m_size * 2;
			int* new_data = new int[new_size];
			for (int i = 0; i < m_count; i++) {
				new_data[i] = m_data[i];
			}
			delete[] m_data;
			m_data = new_data;
			m_size = new_size;
		}
		m_data[m_count] = value;
		m_count++;
	}

	int get_element(int index) {
		if (index < 0 || index >= m_count) {
			throw std::exception("Некорректный индекс");
		}
		return m_data[index];
	}

	~smart_array() {
		delete[] m_data;
	}

private:
	int* m_data;
	int m_size;
	int m_count;
};

int main() {
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
