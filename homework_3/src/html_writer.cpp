#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "../homework_3.h"

using namespace std;

namespace html_writer {

void OpenDocument() {
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html>" << endl;
}

void CloseDocument() { cout << "</html>" << endl; }

void AddCSSStyle(const std::string &stylesheet) {
    cout << "<head>" << endl;
    cout << "<link rel=\"stylesheet\""
         << " type ="
         << "\"text/css\""
         << R"( href =")" << stylesheet << "\""
         << "/>" << endl;
    cout << "</head>" << endl;
}

void AddTitle(const std::string &title) { cout << "<title>" << title << "</title>" << endl; }

void OpenBody() { cout << "<body>" << endl; }

void CloseBody() { cout << "</body>" << endl; }

void OpenRow() { cout << R"(<div class="row">)" << endl; }
void CloseRow() { cout << "</div>" << endl; }
void AddImage(const std::string &img_path, float score, bool highlight) {
    if (highlight) {
        cout << R"(<div class="column" )"
             << R"(style="border: 5px solid green;)"
             << "\">" << endl;
    } else {
        cout << R"(<div class="column")"
             << ">" << endl;
    }
    // ---------------------------------------------------------
    /*stringstream ss;
    int filename = 0;
    string extension;
    ss >> filename >> extension;*/

    /*size_t lastindex_1 = img_path.find_last_of(".");
    string fn_1 = img_path.substr(0, lastindex_1);
    string extension = img_path.substr(lastindex_1 + 1);
    stringstream s1i(img_path);*/
    size_t index_slash = img_path.find_last_of("//");  // extract 000100.png
    string file_name = img_path.substr(index_slash + 1);
    size_t index_period = file_name.find_last_of("/.");
    string file = file_name.substr(0, index_period);
    string extension = file_name.substr(file_name.size() - 3);

    // ---------------------------------------------------------
    if (extension == "png" || extension == "jpg") {
        cout << "<h2>" << file_name << "</h2>" << endl;
        cout << "<img src=\"" << img_path << "\"/>" << endl;
        if (0 < score && score < 1) {
            cout << "<p>score = " << setprecision(2) << fixed << score << "</p>" << endl;
        } else {
            cerr << "Score should be between 0-1" << endl;
        }
    } else {
        cerr << "This file type doesn't supported by program" << endl;
    }
    cout << "</div>" << endl;
}
}  // namespace html_writer
// ? How can i check clang-  things, is it automatic? if yes, can i control it xd.
