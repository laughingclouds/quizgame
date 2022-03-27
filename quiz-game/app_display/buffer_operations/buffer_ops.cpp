#include <cstdlib>

#include "../ab_struct.hpp"

namespace app_display_op {
namespace buffer {

void append(struct abuf ab, const char *s, int len) {
  ab.b += s;
  ab.len += len;
}
} // namespace buffer
} // namespace app_display_op