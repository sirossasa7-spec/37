#include "WebBrowser.h"
#include <iostream>

void WebBrowser::visit(const std::string& url)
{
    history.push(url);
    forwardStack.clear();

    std::cout << "Visit: " << url << std::endl;
}

std::string WebBrowser::back()
{
    if (history.isEmpty())
        return "History is empty";

    std::string current = history.top();
    history.pop();

    forwardStack.push(current);

    if (history.isEmpty())
        return "No previous page";

    return history.top();
}

std::string WebBrowser::forward()
{
    if (forwardStack.isEmpty())
        return "No forward page";

    std::string page = forwardStack.top();
    forwardStack.pop();

    history.push(page);

    return page;
}

void WebBrowser::showCurrentPage() const
{
    if (history.isEmpty())
        std::cout << "No page opened\n";
    else
        std::cout << "Current page: " << history.top() << std::endl;
}