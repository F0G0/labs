#pragma once
#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>




// В этой задаче для простоты не требуется делать контейнер шаблонным,
// это допускается по желанию. Для нешаблонного решения, 
// введем типы ключей и значений: ключом будет выступать строка (например, имя
// студента, значением - произвольная структура (например, численные
// характеристики студента.
struct Student {
	unsigned age;
	unsigned weight;
	Student(unsigned a = 0, unsigned w = 0) {
		age = a;
		weight = w;
	};
};

typedef std::string Key;
typedef Student Value;


class HashTable
{
private:
	int tableSize;
	int hashSize;
	std::vector<std::list<std::pair<Key, Value>>> table;

	unsigned long int HashFunction(const std::string& key) const;

public:
	HashTable(int size = 0) {
		table.resize(size);
		tableSize = size;
		hashSize = 0;
	};
	//~HashTable();

	HashTable(const HashTable& b);
	HashTable(HashTable&& b) noexcept;


	HashTable& operator=(const HashTable& b);
	HashTable& operator=(HashTable&& b) noexcept;


	// Обменивает значения двух хэш-таблиц.
	void swap(HashTable& b);

	// Очищает контейнер.
	void clear();
	// Удаляет элемент по заданному ключу.
	bool erase(const Key& k);
	// Изменение размера таблицы.
	void resize(const int size);
	// Вставка в контейнер. Возвращаемое значение - успешность вставки.
	bool insert(const Key& k, const Value& v);

	// Проверка наличия значения по заданному ключу.
	bool contains(const Key& k) const;

	// Возвращает значение по ключу. Небезопасный метод.
	// В случае отсутствия ключа в контейнере, следует вставить в контейнер
	// значение, созданное конструктором по умолчанию и вернуть ссылку на него. 
	Value& operator[](const Key& k);

	// Возвращает значение по ключу. Бросает исключение при неудаче.
	Value& at(const Key& k);
	const Value& at(const Key& k) const;

	size_t size() const;
	bool empty() const;

	friend bool operator==(const HashTable& a, const HashTable& b);
	friend bool operator!=(const HashTable& a, const HashTable& b);
};

bool operator==(const HashTable& a, const HashTable& b);
bool operator!=(const HashTable& a, const HashTable& b);
