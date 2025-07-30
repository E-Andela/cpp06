#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <string>

struct Data
{
	int index;
	std::string name;
};

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();
	Serializer &operator=(const Serializer &other);
};

#endif