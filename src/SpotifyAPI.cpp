#include "shelljam/SpotifyAPI.hpp"
#include "nlohmann/json.hpp"
#include "shelljam/CurlUtil.hpp"

#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <string>

using json = nlohmann::json;

static const std::string EMPTY{""};

SpotifyAPI::SpotifyAPI() {}

SpotifyAPI::~SpotifyAPI() {}

void SpotifyAPI::setAccessToken(const std::string token) { m_accessToken = token; }

void SpotifyAPI::setClientId(const std::string clientId) { m_clientId = clientId; }

void SpotifyAPI::setClientSecert(const std::string clientSecert) { m_clientSecert = clientSecert; }

void SpotifyAPI::requestAccessToken() {
    // // Sets up a handle
    // CURL *p_curl = curl_easy_init();

    // // Set up url
    // curl_easy_setopt(p_curl, CURLOPT_URL, TOKEN_URL.c_str());

    // // Sets up headers
    // struct curl_slist *headers = nullptr;
    // headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    // curl_easy_setopt(p_curl, CURLOPT_HTTPHEADER, headers);

    // // Set up post fields
    // std::string postFields{"grant_type=client_credentials&client_id=" + m_clientId +
    //                        "&client_secret=" + m_clientSecert};
    // curl_easy_setopt(p_curl, CURLOPT_POSTFIELDS, postFields.c_str());

    // // Set up callback function to handle response data
    // std::string response_buffer{};
    // curl_easy_setopt(p_curl, CURLOPT_WRITEFUNCTION, write_callback);
    // curl_easy_setopt(p_curl, CURLOPT_WRITEDATA, &response_buffer);

    // // Sends request
    // CURLcode res = curl_easy_perform(p_curl);

    // // Error checking
    // if (res != CURLE_OK) {
    //     std::cerr << "Token request failed: " << curl_easy_strerror(res) << "\n";
    // } else {
    //     // Sets the access token
    //     auto response = json::parse(response_buffer);
    //     m_accessToken = response["access_token"];
    // }

    // curl_slist_free_all(headers);
    // curl_easy_cleanup(p_curl);
}

bool SpotifyAPI::requestUserAuthorization() {
    std::string query{"?client_id=" + m_clientId + "&response_type=code" + "&redirect_uri=http://localhost:3000"};
    return CurlUtil::instance().httpGET(AUTH_URL, query, EMPTY);
}

bool SpotifyAPI::skipToNext() {
    return CurlUtil::instance().postRequest("https://api.spotify.com/v1/me/player/next", EMPTY, m_accessToken);
}
