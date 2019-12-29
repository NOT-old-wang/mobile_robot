/*
Copyright 2019 undefined

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#ifndef MODULES_COMMON_UTIL_PING_TOOL_H_
#define MODULES_COMMON_UTIL_PING_TOOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>

constexpr uint16_t kMaxDataSize = 1024;

// 用来检查网络是否通畅
class PingTool {
 public:
  PingTool() {}
  ~PingTool() {}
  bool Ping(std::string ip) {
    std::string str_cmd = "ping " + ip + " -w 1";
    std::string str_response = GetResponse(str_cmd);
    if (str_response.find("received") != std::string::npos &&
        str_response.find(", 0 received") == std::string::npos) {
      return true;
    } else {
      return false;
    }
  }

 private:
  inline std::string GetResponse(const std::string &str_cmd) {
    char buf[kMaxDataSize] = {0};
    FILE *pf = NULL;
    if ((pf = popen(str_cmd.c_str(), "r")) == NULL) {
      return "";
    }
    std::string str_result;
    while (fgets(buf, sizeof(buf), pf)) {
      str_result += buf;
    }

    pclose(pf);

    uint32_t i_size = str_result.size();
    if (i_size > 0 && str_result[i_size - 1] == '\n') {
      str_result = str_result.substr(0, i_size - 1);
    }
    return str_result;
  }
};

#endif  // MODULES_COMMON_UTIL_PING_TOOL_H_
