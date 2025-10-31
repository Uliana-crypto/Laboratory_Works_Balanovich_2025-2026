#ifndef BOOKSTRUCT_H
#define BOOKSTRUCT_H

#include <string>

class Book{
public:
	size_t UDK;
	std::string Author;
	std::string Title;
	size_t Year;
	size_t Count;
};

#endif
