#include <iostream>
#include <tuple>

#include "homework_3.h"
//  using namespace html_writer;

namespace image_browser {

void AddFullRow(const ImageRow &row, bool first_row) {
    html_writer::OpenRow();
    int row_size = row.size();
    for (int i = 0; i <= row_size - 1; i++) {
        html_writer::AddImage(std::get<0>(row[i]), std::get<1>(row[i]), first_row);
    }
    html_writer::CloseRow();
}  // namespace image_browser

void CreateImageBrowser(const std::string &title,
                        const std::string &stylesheet,
                        const std::vector<ImageRow> &rows) {
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();
    for (int i = 0; i <= rows.size() - 1; i++) {
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
