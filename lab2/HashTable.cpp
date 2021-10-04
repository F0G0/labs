#include "HashTable.h"

unsigned long int HashTable::HashFunction(const std::string& key) const
{
    unsigned long long int hashVal = 0;
    for (int i{}; i < key.length(); i++) {
        hashVal = 27 * hashVal + key[i];
    }

    hashVal %= tableSize;

    return hashVal;
}

HashTable::HashTable(const HashTable& b)
{
    hashSize = b.hashSize;
    tableSize = b.tableSize;
    table.resize(tableSize);
    for (int i{}; i < tableSize; i++) {
        table[i] = b.table[i];
    }
}

HashTable::HashTable(HashTable&& b) noexcept
{
    hashSize = b.hashSize;
    tableSize = b.tableSize;
    table = b.table;
}

HashTable& HashTable::operator=(const HashTable& b) {
    this->hashSize = b.hashSize;
    this->tableSize = b.tableSize;
    this->table.resize(b.tableSize);
    for (int i{}; i < b.tableSize; i++) {
        this->table[i] = b.table[i];
    }
    return *this;
}

HashTable& HashTable::operator=(HashTable&& b) noexcept {
    this->hashSize = b.hashSize;
    this->tableSize = b.tableSize;
    this->table = b.table;
    return *this;
}

void HashTable::swap(HashTable& b)
{
    int tmp = tableSize;
    tableSize = b.tableSize;
    b.tableSize = tmp;
    tmp = hashSize;
    hashSize = b.hashSize;
    b.hashSize = tmp;
    table.swap(b.table);
}

void HashTable::clear()
{
    hashSize = 0;
    tableSize = 0;
    table.clear();
}

bool HashTable::erase(const Key& k)
{
    try {
        unsigned long int hashValue = HashFunction(k);
        auto& cell = table[hashValue];
        auto bItr = begin(cell);
        for (; bItr != end(cell); bItr++) {
            if (bItr->first == k) {
                table[hashValue].erase(bItr);
                hashSize--;
                return true;
            }
        }
    }
    catch (const std::invalid_argument& e) {
        return false;
    }
}

void HashTable::resize(const int size) {
    unsigned long int hashVal{};
    int oldSize = tableSize;
    tableSize = size;
    std::vector<std::list<std::pair<Key, Value>>> new_table(size);
    for (int i{}; i < oldSize; i++) {
        auto& cell = table[i];
        auto bItr = begin(cell);
        for (; bItr != end(cell); bItr++) {
            hashVal = HashFunction(bItr->first);
            auto& new_cell = new_table[hashVal];
            new_cell.emplace_back(bItr->first, bItr->second);
        }
    }
    table.swap(new_table);
}


bool HashTable::insert(const Key& k, const Value& v)
{
    hashSize++;
    if (hashSize > table.size() * log2(hashSize)+1) 
        table.resize(hashSize);
    unsigned long int hashValue = HashFunction(k);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == k) {
            return false;
        }
    }
    cell.emplace_back(k, v);
    return true;
}

bool HashTable::contains(const Key& k) const
{
    try {
        unsigned long int hashValue = HashFunction(k);
        auto& cell = table[hashValue];
        auto bItr = begin(cell);
        for (; bItr != end(cell); bItr++) {
            if (bItr->first == k) {
                return true;
            }
        }
    }
    catch (const std::invalid_argument& e) {
        return false;
    }
}

Value& HashTable::at(const Key& k) {
    unsigned long int hashValue = HashFunction(k);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == k) {
            return bItr->second;
        }
    }
    throw std::invalid_argument("No such key");
}
const Value& HashTable::at(const Key& k) const {
    unsigned long int hashValue = HashFunction(k);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == k) {
            return bItr->second;
        }
    }
    throw std::invalid_argument("No such key");
}

Value& HashTable::operator[](const Key& k)
{
    try {
        unsigned long int hashValue = HashFunction(k);
        auto& cell = table[hashValue];
        auto bItr = begin(cell);
        for (; bItr != end(cell); bItr++) {
            if (bItr->first == k) {
                return bItr->second;
            }
        }
    }
    catch (const std::invalid_argument& e) {
        Value* tmp_v = new Value();
        this->insert(k, *tmp_v);
        return *tmp_v;
    }
}

size_t HashTable::size() const
{
    return hashSize;
}

bool HashTable::empty() const
{
    int sum{};
    for (int i{}; i < tableSize; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

bool operator==(const HashTable& a, const HashTable& b)
{
    if (a.hashSize != b.hashSize) return false;
    for (int i{}; i < a.tableSize; i++) {
        auto& cell = a.table[i];
        auto bItr = begin(cell);
        for (; bItr != end(cell); bItr++) {
            if (!b.contains(bItr->first)) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const HashTable& a, const HashTable& b)
{
    if (a.hashSize != b.hashSize) return true;
    for (int i{}; i < a.tableSize; i++) {
        auto& cell = a.table[i];
        auto bItr = begin(cell);
        for (; bItr != end(cell); bItr++) {
            if (!b.contains(bItr->first)) {
                return true;
            }
        }
    }
    return false;
}
