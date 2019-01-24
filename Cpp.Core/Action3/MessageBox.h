#pragma once

# include <string>

struct message_box {
  message_box() = delete;
  static int show(const std::string& message, const std::string& title="");
};
