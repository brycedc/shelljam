#ifndef SPOTIFY_API_HPP
#define SPOTIFY_API_HPP

#include <string>
#include <curl/curl.h>

class SpotifyAPI {
    public:
        /**
         * @brief Grabs the instance of the Spotify API singleton
         * 
         * @return Returns an instance
         */
        static SpotifyAPI& GetInstance() {
            return s_pInstance;
        }

        // Deletes the copy constructor
        SpotifyAPI(const SpotifyAPI&) = delete;

    private:
        // Private Members
        static SpotifyAPI s_pInstance;

        // Private Methods
        SpotifyAPI();
        ~SpotifyAPI();
};

#endif