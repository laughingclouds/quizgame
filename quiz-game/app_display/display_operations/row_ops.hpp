/** To be included in *.cpp or *.hpp files in the same directory **/
#pragma once

#include <cstddef>
#include "../../custom_types.hpp"


namespace app_display_op {
namespace _row {
int _CxToRx(erow *row, int cx);
void insert(int at, char *s, size_t len);
void update(erow *row);
void insertChar(erow *row, int at, int c);
void insertNewline();
void delChar();
} // namespace row
} // namespace app_display_op