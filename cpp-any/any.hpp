#ifndef _PIECES_ANY_HPP
#define _PIECES_ANY_HPP

#include <memory>

/*
any can store one value of any type. 
Once the type is set you can not change it. 
You can set a new value using setValue(value). 
You can retrieve a copy of the stored value by calling value(). 
You can retrieve a reference to the stored value using valureRef(). 
If it is empty (you haven't stored anything) and you try to access the value it throws any::no_data. 
any is type safe, if you try to access the value with the wrong type it throws any::wrong_data.
    
example:
    any var = 2.0;
    double value = var.value<double>();
    var = 4.0;
    double& reference = var.valueRef<double>();
*/
class any final {
public:

	class no_data : public std::exception {};
	class wrong_type : public std::exception {};

    any() = default;
    virtual ~any() = default;
    
    // no copying
    any(any const& other) = delete;
    any& operator=(any const& other) = delete;

    // move constructor
    any(any&& other) {
        auto other_data = other.data.release();
        data.reset(other_data);
    }

    // set constructor
    template<typename T>
    any(T const& value) {
        setValue(value);
    }

    // set operator 
    // throws wrong_type when called with wrong type
    template<typename T>
    void operator=(T const& value) {
        setValue(value);
    }

    // set function
    // throws wrong_type when called with wrong type
    template<typename T>
    void setValue(T const& value) {
        if (empty()) {
            data = std::unique_ptr<Interface>(new Storage<T>());
        }
        try_cast<T>(data)->value = value;
    }
    
    // get copy  
    // throws no_data when empty
    // throws wrong_type when called with wrong type
    template<typename T>
    T value() {
		return valueRef<T>();
    }

    // get reference
    // throws no_data when empty
    // throws wrong_type when called with wrong type
    template<typename T>
    T& valueRef() {
        if (empty()) throw no_data();   
        return try_cast<T>(data)->value;
    }

    bool empty() const {
        return !bool(data);
    }
    
    std::type_info const& type() const {
        if(empty()) return typeid(void);
        return data->type();
    }
     
private:

    class Interface {
    public:
        virtual ~Interface() {}
        virtual std::type_info const& type() = 0;
    };
    
    template<typename T>
    class Storage : public Interface {
    public:
    
        std::type_info const& type() override {
            return typeid(T);
        }
        
        T value;
    };
    
    std::unique_ptr<Interface> data;
    
    template<typename T> 
    Storage<T>* try_cast(std::unique_ptr<Interface>& data) {
		assert(type() == typeid(T));
		if(type() != typeid(T)) throw wrong_type();
        return dynamic_cast<Storage<T>*>(data.get());
    }

};

#endif // _PIECES_ANY_HPP
