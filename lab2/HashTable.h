#pragma once
#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>




// � ���� ������ ��� �������� �� ��������� ������ ��������� ���������,
// ��� ����������� �� �������. ��� ������������ �������, 
// ������ ���� ������ � ��������: ������ ����� ��������� ������ (��������, ���
// ��������, ��������� - ������������ ��������� (��������, ���������
// �������������� ��������.
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


	// ���������� �������� ���� ���-������.
	void swap(HashTable& b);

	// ������� ���������.
	void clear();
	// ������� ������� �� ��������� �����.
	bool erase(const Key& k);
	// ��������� ������� �������.
	void resize(const int size);
	// ������� � ���������. ������������ �������� - ���������� �������.
	bool insert(const Key& k, const Value& v);

	// �������� ������� �������� �� ��������� �����.
	bool contains(const Key& k) const;

	// ���������� �������� �� �����. ������������ �����.
	// � ������ ���������� ����� � ����������, ������� �������� � ���������
	// ��������, ��������� ������������� �� ��������� � ������� ������ �� ����. 
	Value& operator[](const Key& k);

	// ���������� �������� �� �����. ������� ���������� ��� �������.
	Value& at(const Key& k);
	const Value& at(const Key& k) const;

	size_t size() const;
	bool empty() const;

	friend bool operator==(const HashTable& a, const HashTable& b);
	friend bool operator!=(const HashTable& a, const HashTable& b);
};

bool operator==(const HashTable& a, const HashTable& b);
bool operator!=(const HashTable& a, const HashTable& b);
