#include <iostream>
#include <vector>

// Abstract Base Class
class Article {
public:
    Article() = default;
    virtual void read() = 0; // Pure virtual function
    virtual ~Article() {}    // Virtual destructor
};

// Derived Class: Scientific Paper
class Scientific_paper : public Article {
public:
    Scientific_paper(std::string title, std::string content)
        : Title(title), Content(content) {}

    void read() override {
        std::cout << "Scientific Paper reading: " << Title << std::endl;
    }

private:
    std::string Title;
    std::string Content;
};

// Derived Class: Book
class Book : public Article {
public:
    Book(std::string title, std::string content)
        : Title(title), Content(content) {}

    void read() override {
        std::cout << "Book reading: " << Title << std::endl;
    }

private:
    std::string Title;
    std::string Content;
};

// Function to display articles
void display(const std::vector<Article*>& articles) {
    for (auto article : articles) {
        article->read();  // Calls the appropriate `read()` method via polymorphism
    }
}

int main() {
    // Creating objects
    Scientific_paper paper("OOP", "Main content");
    Book book("English", "Literature content");

    // Creating a vector of Article pointers
    std::vector<Article*> vec = {&paper, &book};

    // Display articles
    display(vec);

    return 0;
}
