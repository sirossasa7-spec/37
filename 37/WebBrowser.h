#pragma once
#include <string>
#include "MyStack.h"

class WebBrowser
{
private:
    MyStack<std::string> history;
    MyStack<std::string> forwardStack;

public:
    void visit(const std::string& url);
    std::string back();
    std::string forward();
    void showCurrentPage() const;
};