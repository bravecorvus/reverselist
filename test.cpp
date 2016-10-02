#include <vector>
#include <iostream>
#include <functional>
#include <stdexcept>
#include <string>
#include <boost/any.hpp>


template <typename Ret, typename... Args>
Ret callfunc (std::function<Ret(Args...)> func, std::vector<boost::any> anyargs);

template <typename Ret>
Ret callfunc (std::function<Ret()> func, std::vector<boost::any> anyargs)
{
    if (anyargs.size() > 0)
        throw std::runtime_error("oops, argument list too long");
    return func();
}

template <typename Ret, typename Arg0, typename... Args>
Ret callfunc (std::function<Ret(Arg0, Args...)> func, std::vector<boost::any> anyargs)
{
    if (anyargs.size() == 0)
        throw std::runtime_error("oops, argument list too short");
    Arg0 arg0 = boost::any_cast<Arg0>(anyargs[0]);
    anyargs.erase(anyargs.begin());
    std::function<Ret(Args... args)> lambda =
        ([=](Args... args) -> Ret {
         return func(arg0, args...);
    });
    return callfunc (lambda, anyargs);
}

template <typename Ret, typename... Args>
std::function<boost::any(std::vector<boost::any>)> adaptfunc (Ret (*func)(Args...)) {
    std::function<Ret(Args...)> stdfunc = func;
    std::function<boost::any(std::vector<boost::any>)> result =
        ([=](std::vector<boost::any> anyargs) -> boost::any {
         return boost::any(callfunc(stdfunc, anyargs));
         });
    return result;
}