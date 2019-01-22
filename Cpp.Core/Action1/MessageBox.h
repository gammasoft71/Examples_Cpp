#pragma once

# include <string>

class message_box {
  message_box() = delete;
public:
  using result = int;
  static result show(const std::string& message, const std::string& title="");
};
