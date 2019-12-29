// class RemoteServiceEntry final {
//  public:
//   RemoteServiceEntry() = delete;
//   RemoteServiceEntry(const std::string &ip, int port, const std::string &api)
//       : entry_(ip, port, api) {}

//   inline const char *Ip() const { return std::get<0>(entry_).c_str(); }
//   inline int Port() const { return std::get<1>(entry_); }
//   inline const char *Api() const { return std::get<2>(entry_).c_str(); }

//  private:
//   std::tuple<std::string, int, std::string> entry_;
// };

// class RemoteService final {
//  public:
//   static std::string GetString(const RemoteServiceEntry &entry) {
//     httplib::Client client(entry.Ip(), entry.Port());
//     const auto &res = client.Get(entry.Api());
//     if (res) {
//       if (res->status != 200) {
//         // return false;
//       }
//       return res->body;
//     } else {
//       return std::string();
//     }
//   }

//   static bool PostString(const RemoteServiceEntry &entry,
//                          const std::string &json_str) {
//     httplib::Client client(entry.Ip(), entry.Port());
//     const auto &res = client.Post(entry.Api(), json_str, "application/json");
//     if (res == nullptr) {
//       ROS_ERROR("response empty!");
//       return false;
//     }

//     ROS_INFO_STREAM("res: " << res->status << ", " << res->body);
//     if (!std::strcmp((res->body).c_str(),
//                      "{\"code\":0,\"message\":\"success\"}")) {
//       ROS_INFO_STREAM("post succeed !!!");
//       return true;
//     } else {
//       ROS_INFO_STREAM("post failed !!!");
//       return false;
//     }
//   }
// };

// class LocalService final {
//  public:
//   static std::string GetStringFromFile(const std::string &file_path) {
//     std::ifstream ifs(file_path);
//     if (!ifs.is_open()) {
//       ifs.close();
//       return std::string();
//     }

//     std::stringstream ss;
//     ss << ifs.rdbuf();
//     ifs.close();
//     return ss.str();
//   }
// };