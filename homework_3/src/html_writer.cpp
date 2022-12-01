#include <experimental/filesystem>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "homework_3.h"

using namespace std;
namespace html_writer {

void OpenDocument() {
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html>" << endl;
}

void CloseDocument() { cout << "</html>" << endl; }

void AddCSSStyle(const std::string &stylesheet) {
    cout << "<head>" << endl;
    cout << R"(<link rel="stylesheet" type="text/css" href=")" << stylesheet << R"(" />)" << endl;
    cout << "</head>" << endl;
}

void AddTitle(const std::string &title) { cout << "<title>" << title << "</title>" << endl; }

void OpenBody() { cout << "<body>" << endl; }

void CloseBody() { cout << "</body>" << endl; }

void OpenRow() { cout << R"(<div class="row">)" << endl; }
void CloseRow() { cout << "</div>" << endl; }
void AddImage(const std::string &img_path, float score, bool highlight) {
    if (0 <= score && score <= 1) {
        string extension = filesystem::path(img_path).extension();
        string file_name = filesystem::path(img_path).filename();
        if ((extension == ".png" || extension == ".jpg")) {
            if (highlight) {
                cout << R"(<div class="column" )"
                     << R"(style="border: 5px solid green;)"
                     << "\">" << endl;
                cout << "<h2>" << file_name << "</h2>" << endl;
                cout << "<img src=\"" << img_path << "\"/>" << endl;
                cout << "<p>score = " << setprecision(2) << fixed << score << "</p>" << endl;
                cout << "</div>" << endl;
            } else {
                cout << R"(<div class="column")"
                     << ">" << endl;
                cout << "<h2>" << file_name << "</h2>" << endl;
                cout << "<img src=\"" << img_path << "\"/>" << endl;
                cout << "<p>score = " << setprecision(2) << fixed << score << "</p>" << endl;
                cout << "</div>" << endl;
            }
        } else {
            cerr << "ERROR" << endl;
        }

    } else {
        cerr << "ERROR" << endl;
    }
}
}  // namespace html_writer
