#ifndef SPOTIFY_API_HPP
#define SPOTIFY_API_HPP

#include <string>

class SpotifyAPI {
  public:
    SpotifyAPI();
    ~SpotifyAPI();

    void setAccessToken(const std::string token);
    void setClientId(const std::string clientId);
    void setClientSecert(const std::string clientSecert);

    bool requestAccessToken();
    bool requestUserAuthorization();

    bool skipToNext();

  private:
    // Private Members
    std::string m_accessToken;
    std::string m_clientId;
    std::string m_clientSecert;

    static inline const std::string API_ENDPOINT{"https://api.spotify.com/v1"};
    static inline const std::string AUTH_URL{"https://accounts.spotify.com/authorize"};
    static inline const std::string TOKEN_URL{"https://accounts.spotify.com/api/token"};
};

#endif