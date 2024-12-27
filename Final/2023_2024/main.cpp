#include <iostream>

int main()
{
    // Code fragment from the main function...
    const char *url = "mobiles.com/iphone";
    Crawler *task = new Crawler(url);
    std::vector<Mobile *> items = task->execute();

    std::cout << "Crawled " << items.size() << " phones from " << url << "\n";

    for (Mobile *mobile: items) {
    mobile->print();
    std::cout << "\n";
    }
}