#include <iostream>
#include <optional>

struct PhoneNumber {
	int codeCountry;
	int codeCity;
	std::string number;
	std::optional<int> extensionNumber;
};