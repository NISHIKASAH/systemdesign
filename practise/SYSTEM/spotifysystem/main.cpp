#include <iostream>
#include "spotifymusic.hpp"
using namespace std;

int main()
{
    try
    {
      auto application = SpotifyApp::getSpotifyAppInstance();

        // Populate library
        application->createSongToLibrary("Kesariya",  "Arijit Singh",  "/music/kesariya.mp3");
        application->createSongToLibrary("Chaiyya Chaiyya",   "Sukhwinder Singh",  "/music/chaiyya_chaiyya.mp3");
        application->createSongToLibrary("Tum Hi Ho",  "Arijit Singh",  "/music/tum_hi_ho.mp3");
        application->createSongToLibrary("Jai Ho",  "A. R. Rahman",  "/music/jai_ho.mp3");
        application->createSongToLibrary("Zinda",  "Siddharth Mahadevan",  "/music/zinda.mp3");

        // Create playlist and add songs
        application->createNewPlayList("Bollywood Vibes");
         application->AddSongToPlaylist("Bollywood Vibes", "Kesariya");
        application->AddSongToPlaylist("Bollywood Vibes", "Chaiyya Chaiyya");
        application->AddSongToPlaylist("Bollywood Vibes", "Tum Hi Ho");
        application->AddSongToPlaylist("Bollywood Vibes", "Jai Ho");


        // Connect device
        application->connectToDevice(DeviceType::BLUETOOTH);

        // //Play/pause a single song
        // application->playSingSong("Zinda");
        // application->pauseCurrentSong("Zinda");
        // application->playSingSong("Zinda");  // resume

        // cout << "\n-- Sequential Playback --\n";
        // application->setPlayListStrategy(StrategyType::SEQUENCETYPE);
        // application->loadingPlaylist("Bollywood Vibes");
        // application->findAllPlayTrack();

        // cout << "\n-- Random Playback --\n";
        // application->setPlayListStrategy(StrategyType::RANDOMTYPE);
        // application->loadingPlaylist("Bollywood Vibes");
        // application->findAllPlayTrack();

        cout << "\n-- Custom Queue Playback --\n";
        application->setPlayListStrategy(StrategyType::CUSTOMTYPE);
        application->loadingPlaylist("Bollywood Vibes");
       
        application->findAllPlayTrack();

        cout << "\n-- Play Previous in Sequential --\n";
        application->setPlayListStrategy(StrategyType::SEQUENCETYPE);
        application->loadingPlaylist("Bollywood Vibes");
        application->findAllPlayTrack();

        application->playPreviousTrack();
        application->playPreviousTrack();

    } catch (const exception& error) {
        cerr << "Error: " << error.what() << endl;
    }
   
}