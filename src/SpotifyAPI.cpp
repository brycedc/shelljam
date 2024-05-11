#include "shelljam/SpotifyAPI.hpp"
#include "nlohmann/json.hpp"

#include <curl/curl.h>
#include <curl/easy.h>
#include <iostream>
#include <string>

using json = nlohmann::json;

// Private Function Prototypes
size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *p_buffer);

SpotifyAPI::SpotifyAPI() { curl_global_init(CURL_GLOBAL_ALL); }

SpotifyAPI::~SpotifyAPI() { curl_global_cleanup(); }

void SpotifyAPI::setAccessToken(const std::string token) { m_accessToken = token; }

void SpotifyAPI::setClientId(const std::string clientId) { m_clientId = clientId; }

void SpotifyAPI::setClientSecert(const std::string clientSecert) { m_clientSecert = clientSecert; }

void SpotifyAPI::requestAccessToken() {
    // Sets up a handle
    CURL *p_curl = curl_easy_init();

    // Set up url
    curl_easy_setopt(p_curl, CURLOPT_URL, TOKEN_URL.c_str());

    // Sets up headers
    struct curl_slist *headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    curl_easy_setopt(p_curl, CURLOPT_HTTPHEADER, headers);

    // Set up post fields
    std::string postFields{"grant_type=client_credentials&client_id=" + m_clientId +
                           "&client_secret=" + m_clientSecert};
    curl_easy_setopt(p_curl, CURLOPT_POSTFIELDS, postFields.c_str());

    // Set up callback function to handle response data
    std::string response_buffer{};
    curl_easy_setopt(p_curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(p_curl, CURLOPT_WRITEDATA, &response_buffer);

    // Sends request
    CURLcode res = curl_easy_perform(p_curl);

    // Error checking
    if (res != CURLE_OK) {
        std::cerr << "Token request failed: " << curl_easy_strerror(res) << "\n";
    } else {
        // Sets the access token
        auto response = json::parse(response_buffer);
        m_accessToken = response["access_token"];
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(p_curl);
}

void SpotifyAPI::requestUserAuthorization() {

    // Sets up a handle
    CURL *p_curl = curl_easy_init();

    // Sets up URL
    std::string queryString{"?client_id=" + m_clientId +"&response_type=code" + "&redirect_uri=http://localhost:3000"};
    curl_easy_setopt(p_curl, CURLOPT_URL, (AUTH_URL + queryString).c_str());

    // Set up callback function to handle response data
    std::string respone_buffer{};
    curl_easy_setopt(p_curl, CURLOPT_HEADERFUNCTION, write_callback);
    curl_easy_setopt(p_curl, CURLOPT_HEADERDATA, &respone_buffer);

    // Send request
    CURLcode res = curl_easy_perform(p_curl);

    // Error Checking
    if (res != CURLE_OK) {
        std::cerr << "Token request failed: " << curl_easy_strerror(res) << "\n";
    } else {
        std::cout << respone_buffer << std::endl;
    }

    curl_easy_cleanup(p_curl);
}

void SpotifyAPI::skipToNext() {
    // Sets up a handle
    CURL *p_curl = curl_easy_init();

    // Set up headers
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, ("Authorization: Bearer " + m_accessToken).c_str());
    curl_easy_setopt(p_curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(p_curl, CURLOPT_URL, "https://api.spotify.com/v1/me/player/next");
    curl_easy_setopt(p_curl, CURLOPT_POST, 1L); // Set the request to POST
    CURLcode res = curl_easy_perform(p_curl);

    curl_slist_free_all(headers);
    curl_easy_cleanup(p_curl);
}

size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *p_buffer) {
    p_buffer->append(static_cast<char *>(contents), size * nmemb);
    return size * nmemb;
}
