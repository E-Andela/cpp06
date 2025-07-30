#include "../inc/Serializer.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	Data entry;
    entry.index = 42;
    entry.name = "Dave";

    uintptr_t raw = Serializer::serialize(&entry);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Test 1: " << deserialized->name << " (" << deserialized->index << ")" << std::endl;
	std::cout << std::left
          << std::setw(25) << "Original address: " << &entry << std::endl
          << std::setw(25) << "Raw address: " << std::hex << "0x" << raw << std::dec << std::endl
          << std::setw(25) << "Deserialized address: " << deserialized << std::endl;

	std::cout << std::endl;

    // Test 2: Different values
    Data entry2;
    entry2.index = -1;
    entry2.name = "Alice";
    uintptr_t raw2 = Serializer::serialize(&entry2);
    Data* deserialized2 = Serializer::deserialize(raw2);
    std::cout << "Test 2: " << deserialized2->name << " (" << deserialized2->index << ")" << std::endl;
	std::cout << std::left
          << std::setw(25) << "Original address: " << &entry2 << std::endl
          << std::setw(25) << "Raw address: " << std::hex << "0x" << raw2 << std::dec << std::endl
          << std::setw(25) << "Deserialized address: " << deserialized2 << std::endl;
		  
	std::cout << std::endl;

    // Test 3: Empty string
    Data entry3;
    entry3.index = 0;
    entry3.name = "";
    uintptr_t raw3 = Serializer::serialize(&entry3);
    Data* deserialized3 = Serializer::deserialize(raw3);
    std::cout << "Test 3: '" << deserialized3->name << "' (" << deserialized3->index << ")" << std::endl;
	std::cout << std::left
          << std::setw(25) << "Original address: " << &entry3 << std::endl
          << std::setw(25) << "Raw address: " << std::hex << "0x" << raw3 << std::dec << std::endl
          << std::setw(25) << "Deserialized address: " << deserialized3 << std::endl;

	std::cout << std::endl;

    // Test 4: Large index
    Data entry4;
    entry4.index = 1000000;
    entry4.name = "Bob";
    uintptr_t raw4 = Serializer::serialize(&entry4);
    Data* deserialized4 = Serializer::deserialize(raw4);
    std::cout << "Test 4: " << deserialized4->name << " (" << deserialized4->index << ")" << std::endl;
	std::cout << std::left
          << std::setw(25) << "Original address: " << &entry4 << std::endl
          << std::setw(25) << "Raw address: " << std::hex << "0x" << raw4 << std::dec << std::endl
          << std::setw(25) << "Deserialized address: " << deserialized4 << std::endl;
}