#include "shelljam/CurlUtil.hpp"
#include <cstdlib>
#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>

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
    } else {
        std::cerr << "Failed to get handle exiting function...\n";
    }

    return encodedString; // Encoded string will be empty on failure
}

bool CurlUtil::httpGET(const std::string &url, const std::string &query, const std::string &token) {
    CURL *p_curl = curl_easy_init();
    CURLcode res;

    // Checks if we were able to get a handle
    if (p_curl == nullptr) {
        std::cerr << "Failed to get handle exiting function...\n";
        return false;
    }

    // Sets up request and sends it
    curl_easy_setopt(p_curl, CURLOPT_URL, (url + query).c_str());
    // Sets the token if it is provided
    if (!token.empty()) {
        curl_easy_setopt(p_curl, CURLOPT_XOAUTH2_BEARER, token.c_str());
    }

    res = curl_easy_perform(p_curl);

    // Checks if request was successful
    if (res != CURLE_OK) {
        std::cerr << "GET request failed\n";
        return false;
    }

    return true;
}

bool CurlUtil::postRequest(const std::string &url, const std::string &data, const std::string &token) {
    CURL *p_curl = curl_easy_init();
    CURLcode res;

    // Checks if we were able to get a handle
    if (p_curl == nullptr) {
        std::cerr << "Failed to get handle exiting function...\n";
        return false;
    }

    // Sets up request and sends it
    curl_easy_setopt(p_curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(p_curl, CURLOPT_POST, 1U);
    curl_easy_setopt(p_curl, CURLOPT_XOAUTH2_BEARER, token.c_str());

    // Checks if there is data to send
    if (!data.empty()) {
        curl_easy_setopt(p_curl, CURLOPT_POSTFIELDS, data.c_str());
    }

    res = curl_easy_perform(p_curl);

    // Checks if request was successful
    if (res != CURLE_OK) {
        std::cerr << "POST request failed\n";
        return false;
    }

    return true;
}

size_t CurlUtil::write_callback(void *contents, size_t size, size_t nmemb, std::string *p_buffer) {
    p_buffer->append(static_cast<char *>(contents), size * nmemb);
    return size * nmemb;
}