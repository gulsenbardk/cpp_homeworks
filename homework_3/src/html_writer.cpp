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
    // ---------------------------------------------------------
    /*stringstream ss;
    int filename = 0;
    string extension;
    ss >> filename >> extension;*/

    /*size_t lastindex_1 = img_path.find_last_of(".");
    string fn_1 = img_path.substr(0, lastindex_1);
    string extension = img_path.substr(lastindex_1 + 1);
    stringstream s1i(img_path);*/

    // ---------------------------------------------------------
    if (0 <= score && score <= 1) {
        // size_t index_slash = img_path.find_last_of("//");  // extract 000100.png
        // string file_name = img_path.substr(index_slash + 1);
        // size_t index_period = file_name.find_last_of("/.");
        // string file = file_name.substr(0, index_period);
        // string extension = file_name.substr(file_name.size() - 3);
        string extension = filesystem::path(img_path).extension();
        string file_name = filesystem::path(img_path).filename();
        if (((highlight) && (extension == ".png" || extension == ".jpg"))) {
            cout << R"(<div class="column" )"
                 << R"(style="border: 5px solid green;)"
                 << "\">" << endl;
            cout << "<h2>" << file_name << "</h2>" << endl;
            cout << "<img src=\"" << img_path << "\"/>" << endl;
            cout << "<p>score = " << setprecision(2) << fixed << score << "</p>" << endl;
            cout << "</div>" << endl;
        } else if (((!highlight) && (extension == ".png" || extension == ".jpg"))) {
            cout << R"(<div class="column")"
                 << ">" << endl;
            cout << "<h2>" << file_name << "</h2>" << endl;
            cout << "<img src=\"" << img_path << "\"/>" << endl;
            cout << "<p>score = " << setprecision(2) << fixed << score << "</p>" << endl;
            cout << "</div>" << endl;
        } else {
            cerr << "ERROR" << endl;
        }

    } else {
        cerr << "ERROR" << endl;
    }
}
}  // namespace html_writer
// ? How can i check clang-  things, is it automatic? if yes, can i control it xd.
