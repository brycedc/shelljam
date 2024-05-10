#ifndef SPOTIFY_API_HPP
#define SPOTIFY_API_HPP

#include <curl/curl.h>

#include <string>

class SpotifyAPI {
  public:
    void setAccessToken(const std::string& token);

    void skipToNext();
    
  public: // Singleton Setup
    static SpotifyAPI &GetInstance() {
        static SpotifyAPI INSTANCE;
        return INSTANCE;
    }

    // Deletes the copy constructor
    SpotifyAPI(const SpotifyAPI &) = delete;

  private:
    // Private Members
    std::string m_accessToken;
    CURL *p_curl;

    static inline const std::string API_ENDPOINT{"https://api.spotify.com/v1"};

    // Private Methods
    SpotifyAPI();
    ~SpotifyAPI();
};

#endif