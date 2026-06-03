#include <iostream>
#include "WebBrowser.h"
#include "PostfixCalculator.h"

int main()
{
    //WebBrowser browser;

    //browser.visit("google.com");
    //browser.visit("youtube.com");
    //browser.visit("github.com");
    //browser.visit("openai.com");

    //browser.showCurrentPage();

    //std::cout << "\nBack -> "
    //    << browser.back() << std::endl;

    //std::cout << "Back -> "
    //    << browser.back() << std::endl;

    //browser.showCurrentPage();

    //std::cout << "\nForward -> "
    //    << browser.forward() << std::endl;

    //browser.showCurrentPage();

    std::string expression;

    std::cout << "Enter postfix expression:\n";
    std::getline(std::cin, expression);

    std::cout << "Result = "
        << PostfixCalculator::calculate(expression)
        << std::endl;

    return 0;
}