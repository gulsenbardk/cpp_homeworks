#include <fmt/format.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include "homework_3.h"

using namespace std;
namespace hmtl_writer {

void OpenDocument() {
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html>" << endl;
}

void CloseDocument() { cout << "</html>" << endl; }

void AddCSSStyle(const std::string &stylesheet) {
    cout << "<head>" << endl;
    cout << "<link rel=\"" << stylesheet << "\"/>" << endl;  //???
    cout << R"(type="text/css")" << endl;
    cout << R"(href="test_stylesheet.css")" << endl;
    cout << "</head>" << endl;
}

void AddTitle(const std::string &title) { cout << "<title>" << title << "</title>" << endl; }

void OpenBody() { cout << "<body>" << endl; }

void CloseBody() { cout << "</body>" << endl; }

void OpenRow() { cout << R"(<div class="row">)" << endl; }
void CloseRow() { cout << "</div>" << endl; }
void AddImage(const std::string &img_path, float score, bool highlight) {
    if (highlight == true) {
        cout << R"(<div class="column")" << endl;
        cout << R"(style="border: 5px solid green;)" << endl;
    } else {
        cout << R"(<div class="column")" << endl;
    }
    // ---------------------------------------------------------
    stringstream ss;
    int filename;
    string extension;
    ss >> filename >> extension;
    // ---------------------------------------------------------
    if (extension == ".png" || extension == ".jpg") {
        cout << "<h2>" << filename << "</h2>" << endl;
        cout << R"(<img src=")" << img_path << R"(" />)" << endl;
        if (0 < score && score < 1) {
            string s = fmt::format("%.2f", score);
            cout << "<p>score = " << s << "</p>" << endl;
        } else {
            cerr << "Score should be between 0-1" << endl;
        }
    } else {
        cerr << "This file type doesn't supported by program" << endl;
    }
}
}  // namespace hmtl_writer
// ? How can i check clang-  things, is it automatic? if yes, can i control it xd.
