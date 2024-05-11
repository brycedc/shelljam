#include "shelljam/CurlUtil.hpp"
#include <curl/curl.h>
#include <curl/easy.h>

CurlUtil::CurlUtil() {
    // Sets up program environment for libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

CurlUtil::~CurlUtil() {
    // Release resources acquired by libcurl
    curl_global_cleanup();
}

std::string CurlUtil::encodeURL(const std::string &stringToEncode) {
    CURL *p_curl = curl_easy_init();
    std::string encodedString{};

    if (p_curl) {
        encodedString = curl_easy_escape(p_curl, stringToEncode.c_str(), stringToEncode.size());
        curl_easy_cleanup(p_curl);
    }

    return encodedString; // Encoded string will be empty on failure
}

void CurlUtil::getRequest(const std::string &url, const std::string &query, const std::string &token) {}