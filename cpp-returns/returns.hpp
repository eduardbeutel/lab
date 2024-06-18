#ifndef _PIECES_RETURNS_HPP
#define _PIECES_RETURNS_HPP

#define _CONCATENATE_WITHOUT_EXPANDING(X,Y) X##Y
#define _CONCATENATE(X,Y) _CONCATENATE_WITHOUT_EXPANDING(X,Y)

/* 
returns is an inline declared and defined anonymous struct which can be used for returning multiple values. 
It can only be used when the function declaration and definition is the same. 
Variables are separed by: ";". Values are separated by: ",".
Another solution for multiple return values is std::tuple but you loose the nice variable names.

usage:
    returns(variables) function() {
        return {values};
    }

example:
    returns(int a; int b;) returns_two_vars() {
        return {2,3};
    }
    
    auto result = returns_two_vars();
    std::cout << result.a << result.b;
*/
#define returns( variables ) \
    typedef struct { variables } _CONCATENATE(_return_struct_at_line_, __LINE__); \
    _CONCATENATE(_return_struct_at_line_, __LINE__)

#endif // _PIECES_RETURNS_HPP
