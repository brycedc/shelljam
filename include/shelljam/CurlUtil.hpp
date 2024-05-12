#ifndef CURL_UTIL_HPP
#define CURL_UTIL_HPP

#include <curl/curl.h>
#include <string>

class CurlUtil {
  public:
    // Deleted copy constructor
    // Only the instance method is allowed to give CurlUtil
    CurlUtil(const CurlUtil &) = delete;
    // Deleted copy assignment
    // Only the instance method is allowed to give CurlUtil
    void operator=(const CurlUtil &) = delete;
    // Default move constructor
    CurlUtil(CurlUtil &&) noexcept = default;
    // Default move assignment
    CurlUtil &operator=(CurlUtil &&) noexcept = default;

    /**
     * @brief Gets an instance of the CurlUtil class
     *
     * @return Returns a single instance of the CurlUtil class
     */
    static CurlUtil &instance() {
        static auto &&INSTANCE = CurlUtil();
        return INSTANCE;
    }

  public:
    enum RequestMethods { GET, HEAD, POST, PUT, DELETE, CONNECT, OPTIONS, TRACE, PATCH };

    std::string encodeURL(const std::string &stringToEncode);

    void getRequest(const std::string &url, const std::string &query, const std::string &token);

  private:
    /**
     * @brief Constructor for CurlUtil
     * @note Declared private for singleton design pattern
     */
    CurlUtil();
    /**
     * @brief Destructor for CurlUtil
     * @note Declared private for singleton design pattern
     */
    ~CurlUtil();
};

#endif
