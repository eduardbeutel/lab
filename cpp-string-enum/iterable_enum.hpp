#ifndef _ITERABLE_ENUM_HPP
#define _ITERABLE_ENUM_HPP

/* 
iterable_enum declares a C++11 enum class over which you can iterate with a range based for loop. 
You can get the number of entries by calling size(EnumName()). 
You can also cast each entry to int. 
For internal use it declares an extra entry at the end: EnumName::_end.

usage: 
    iterable_enum(EnumName,Entries...)

example:
    iterable_enum(Color,
        Red,
        Green,
        Blue,
        White
    );

    std::cout << size(Color());
    for (auto& color : Color()) {
        std::cout << int(color);
    }
*/
#define iterable_enum(name, first_entry, ... ) \
enum class name { first_entry = 0 , __VA_ARGS__ , _end }; \
	inline name operator++(name& current_entry) { return current_entry = (name)(((int)(current_entry)+1)); } \
	inline name operator*(name entry) { return entry; } \
	inline name begin(name entry) { return name::first_entry; } \
	inline name end(name entry)   { return name::_end; } \
    inline unsigned int size(name entry) { return static_cast<unsigned int>(name::_end); }

#endif // _ITERABLE_ENUM_HPP
