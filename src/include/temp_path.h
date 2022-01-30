#ifndef KY_TEMP_PATH__H
#define KY_TEMP_PATH__H

#include <filesystem>

namespace ky {

class TempPath final {
  std::filesystem::path path_;
  bool keep_;

public:
  TempPath();

  TempPath(const std::filesystem::path &parent_path, bool keep);

  ~TempPath();

  [[nodiscard]] std::filesystem::path GetPath() const;
};

}  // namespace ky

#endif  // KY_TEMP_PATH__H
