#include "reverse_string.h"

namespace reverse_string {
  std::string reverse_string(const std::string& in) {
      std::string out = "";
    
      for (int i = in.length() - 1; i >= 0; --i)
          out.push_back(in[i]);
    
      return out;
  }
}  // namespace reverse_string
