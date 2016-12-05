#ifndef _STRING_ENUM_HPP
#define _STRING_ENUM_HPP

#include <iterable_enum.hpp>
#include <vector>
#include <algorithm> 
#include <string>
#include <sstream>
#include <unordered_map>

/* 
string_enum declares a C++11 enum class which has built-in std::string conversion. 
string_enum is an iterable_enum so it "inherits" all the functionality. See iterable_enum.hpp.
If you call from_string with a wrong argument it returns EnumName::_end. 
If you call to_string with EnumName::_end as an argument it returns an empty string: "".
Due to implementation constraints the creation of the strings occurs at runtime,
BUT it only runs once at program start.

usage:
    string_enum(EnumName,Entries...)
    
example:
    string_enum(State, 
        Connected, 
        Connecting, 
        NotConnected, 
        Error
    );

    for (auto& state : State()) {
        std::cout << to_string(state);
        auto same_state = from_string(to_string(state));
    }   
*/
#define string_enum(name, first_entry, ... ) \
	iterable_enum(name, first_entry, __VA_ARGS__) \
	inline std::string to_string(name const entry) { \
		if (entry == name::_end) return ""; \
        static auto mapping = _internal::create_int_to_string_mapping(#first_entry, #__VA_ARGS__); \
        return mapping[static_cast<unsigned int>(entry)]; \
	} \
    inline name from_string(std::string const& string) { \
        static auto mapping = _internal::create_string_to_int_mapping(#first_entry, #__VA_ARGS__); \
        if(mapping.find(string) == mapping.end()) return name::_end; \
        return name(mapping[string]); \
    }\
    inline name from_string(std::string const&& string) {\
        return from_string(string);\
    }

namespace _internal {

typedef std::vector<std::string> string_vector;
typedef std::unordered_map<std::string, unsigned int> string_int_map;

/* Helper function for int to std::string conversion. Only called once. Add first split second. */
inline string_vector create_int_to_string_mapping(std::string const& first, std::string const& second) {
    string_vector strings;
    string_vector::size_type size = 2;
	size += std::count(second.begin(), second.end(), ',');
	strings.resize(size);
	strings[0] = first;

	std::stringstream stream(second);
	for (unsigned int i = 1; i < size; i++) {
		std::getline(stream, strings[i], ',');
		stream.ignore(1);
	}
	return strings;   
}

/* Helper function for std::string to int conversion. Only called once. Add first split second.*/
inline string_int_map create_string_to_int_mapping(std::string const& first, std::string const& second) {
    string_int_map map;
	map[first] = 0;
    
    string_int_map::size_type size = 2;
	size += std::count(second.begin(), second.end(), ',');
	std::stringstream stream(second);
    std::string tmp;
	for (unsigned int i = 1; i < size; i++) {     
		std::getline(stream, tmp, ',');
        map[tmp]= i;
		stream.ignore(1);
	}
	return map;   
}

} // namespace _internal
#endif // _STRING_ENUM_HPP
