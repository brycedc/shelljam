#include "../include/shelljam/SpotifyAPI.hpp"

#include <curl/curl.h>
#include <curl/easy.h>

SpotifyAPI::SpotifyAPI() : p_curl{curl_easy_init()} {}

SpotifyAPI::~SpotifyAPI() { curl_easy_cleanup(p_curl); }

void SpotifyAPI::setAccessToken(const std::string& token) {
    m_accessToken = token;
}

void SpotifyAPI::skipToNext() {
    // Sets up endpoint
    std::string urlEndPoint{API_ENDPOINT + "/me/player/next"};
    curl_easy_setopt(p_curl, CURLOPT_URL, urlEndPoint.c_str());
    curl_easy_setopt(p_curl, CURLOPT_XOAUTH2_BEARER, m_accessToken.c_str());
    curl_easy_perform(p_curl);
}


