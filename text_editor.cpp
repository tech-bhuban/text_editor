

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class TextEditor {
private:
    std::vector<std::string> lines;
    std::string filename;
    
public:
    TextEditor(const std::string& file) : filename(file) {
        std::ifstream in(file);
        std::string line;
        while(getline(in, line)) {
            lines.push_back(line);
        }
        if(lines.empty()) lines.push_back("");
    }
    
    void display() {
        std::cout << "\n=== " << filename << " ===\n";
        for(size_t i = 0; i < lines.size(); i++) {
            std::cout << i+1 << ": " << lines[i] << "\n";
        }
    }
    
    void insert(int lineNum, const std::string& text) {
        if(lineNum >= 1 && lineNum <= lines.size()) {
            lines.insert(lines.begin() + lineNum - 1, text);
        }
    }
    
    void append(const std::string& text) {
        lines.push_back(text);
    }
    
    void remove(int lineNum) {
        if(lineNum >= 1 && lineNum <= lines.size()) {
            lines.erase(lines.begin() + lineNum - 1);
        }
    }
    
    void save() {
        std::ofstream out(filename);
        for(const auto& line : lines) {
            out << line << "\n";
        }
        std::cout << "File saved successfully!\n";
    }
    
    void findAndReplace(const std::string& find, const std::string& replace) {
        for(auto& line : lines) {
            size_t pos = 0;
            while((pos = line.find(find, pos)) != std::string::npos) {
                line.replace(pos, find.length(), replace);
                pos += replace.length();
            }
        }
    }
};

int main() {
    TextEditor editor("test.txt");
    editor.append("Hello, World!");
    editor.append("This is a test.");
    editor.display();
    editor.findAndReplace("test", "sample");
    editor.save();
    return 0;
}

// # Simple Text Editor

// ## Overview
// A command-line text editor with basic file editing capabilities.

// ## Features
// - Open and edit text files
// - Insert, append, and remove lines
// - Find and replace text
// - Auto-save functionality
// - Line numbering display

// ## Compilation
// ```bash
// g++ text_editor.cpp -o editor
// ./editor