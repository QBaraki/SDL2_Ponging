#ifndef LOG_UTILS_H
#define LOG_UTILS_H

#include <thread>

struct Status {
  bool running = true;
  float delta_time = 0.0f;
};

namespace LogUtils {

std::thread thread_status(Status* status);

}  // namespace LogUtils

#endif  // !LOG_UTILS_H