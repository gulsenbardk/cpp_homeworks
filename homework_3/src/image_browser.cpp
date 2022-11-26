
#include <iostream>
#include <tuple>

#include "../api/homework_3.h"
// using namespace html_writer;

namespace image_browser {

void AddFullRow(const ImageRow &row, bool first_row) {
    html_writer::OpenRow();
    bool hl = false;  // default
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            hl = first_row;
        } else {
            hl = false;
        }
        html_writer::AddImage(std::get<0>(row[i]), std::get<1>(row[i]), hl);
    }
    // std::get<0>(row);
    html_writer::CloseRow();
}  // namespace image_browservoid AddFullRow(constImageRow&row,boolfirst_row)

void CreateImageBrowser(const std::string &title,
                        const std::string &stylesheet,
                        const std::vector<ImageRow> &rows) {
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();

    for (int i = 0; i < rows.size(); i++) {
        if (i == 0) {
            AddFullRow(rows.at(0), true);
        } else {
            AddFullRow(rows.at(i), false);
        }
    }

    html_writer::CloseBody();
    html_writer::CloseDocument();
}
}  // namespace image_browser
   /* using ScoredImage = std::tuple<std::string, float>;
   using ImageRow = std::array<ScoredImage, 3>;
   --How can i use those, are they also declarations, or other way should be use?*/