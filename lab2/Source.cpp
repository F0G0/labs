#include <gtest/gtest.h>
#include "HashTable.h"


TEST(test1, TestInsert) {
	Value value1(1, 2);
	Value value2(2, 3);
	Value value3(1, 2);
	Value value4(4, 5);

	HashTable* table = new HashTable(5);

	EXPECT_EQ(true, table->insert("key1", value1));
	EXPECT_EQ(false, table->insert("key1", value1));
	EXPECT_EQ(false, table->insert("key1", value2));

	EXPECT_EQ(true, table->insert("key2", value2));
	EXPECT_EQ(true, table->insert("key3", value3));
	EXPECT_EQ(true, table->insert("key4", value4));
	delete table;
}

TEST(test2, TestContain) {
	Value value1(1, 2);

	HashTable* table = new HashTable(5);

	EXPECT_EQ(false, table->contains("key1"));

	table->insert("key1", value1);
	EXPECT_EQ(true, table->contains("key1"));

	delete table;
}

TEST(test3, TestErase) {
	Value value1(1, 2);

	HashTable* table = new HashTable(5);

	EXPECT_EQ(false, table->erase("key1"));

	table->insert("key1", value1);
	EXPECT_EQ(true, table->erase("key1"));

	delete table;
}

TEST(test4, TestAts) {
	Value value1(1, 2);

	HashTable* table = new HashTable(5);
	try {
		table->at("key1");
	}
	catch (std::invalid_argument& e) {
		table->insert("key1", value1);
		Value v = table->at("key1");
		EXPECT_EQ(1, v.age);
		EXPECT_EQ(2, v.weight);
	}
	delete table;
}

TEST(test5, TestOp) {
	Value value1(1, 2);

	HashTable* table = new HashTable(5);

	try {
		(*table)["key1"];
	}
	catch(std::invalid_argument& e){
		table->insert("key1", value1);
		Value v = (*table)["key1"];
		EXPECT_EQ(1, v.age);
		EXPECT_EQ(2, v.weight);
	}

	delete table;
}

TEST(test6, TestSwap) {
	Value value1(1, 2);
	Value value2(4, 5);

	HashTable table1(3);
	HashTable table2(3);

	table1.insert("key1", value1);
	table2.insert("key2", value2);
	table1.swap(table2);

	Value answ1 = table2["key1"];
	EXPECT_EQ(1, answ1.age);
	EXPECT_EQ(2, answ1.weight);

	Value answ2 = table1["key2"];
	EXPECT_EQ(4, answ2.age);
	EXPECT_EQ(5, answ2.weight);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}