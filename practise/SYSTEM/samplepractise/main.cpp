#include <iostream>
#include <vector>
#include "./spotifymain.hpp"
using namespace std;

int main()
{

    Song *song1 = new Song("tum hi ho", "arijit singh");
    Song *song2 = new Song("kesariya", "pritam");
    Song *song3 = new Song("ishq", "fateh ali");
    Song *song4 = new Song("tum mere ho", "anuv jain");
    Song *song5 = new Song("gumsoom", "pateek khudad");

    Spotifymain *application = Spotifymain ::getSpotifyinstance();
    application->addSongtoLibrary(song1);
    application->addSongtoLibrary(song2);
    application->addSongtoLibrary(song3);
    application->addSongtoLibrary(song4);
    application->addSongtoLibrary(song5);

    application->createPlayList("lofi");
    application->addsongtoplaylist("lofi", song1);
    application->addsongtoplaylist("lofi", song2);
    application->addsongtoplaylist("lofi", song3);
    application->addsongtoplaylist("lofi", song4);
    application->addsongtoplaylist("lofi", song5);

    application->connectdevice(deviceType ::BLUETOOTH);
    application->setPlayliststrategy(stratergyType ::SEQUENCE);
    application->loadPlaylist("lofi");
    application->playsong(song1);


};