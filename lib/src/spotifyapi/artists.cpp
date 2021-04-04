#include "lib/spotify/spotifyapi.hpp"

using namespace lib::spt;

// Currently unavailable:
// artists

void spotify_api::artist(const std::string &artistId,
	lib::callback<lib::spt::artist> &callback)
{
	get(lib::fmt::format("artists/{}", artistId), callback);
}

void spotify_api::top_tracks(const lib::spt::artist &artist,
	lib::callback<std::vector<lib::spt::track>> &callback)
{
	get(lib::fmt::format("artists/{}/top-tracks?country=from_token",
		artist.id), "tracks", callback);
}

void spotify_api::related_artists(const lib::spt::artist &artist,
	lib::callback<std::vector<lib::spt::artist>> &callback)
{
	lib::spt::spotify_api::get(lib::fmt::format("artists/{}/related-artists",
		artist.id), "artists", callback);
}

void spotify_api::albums(const lib::spt::artist &artist,
	lib::callback<std::vector<lib::spt::album>> &callback)
{
	lib::spt::spotify_api::get(lib::fmt::format("artists/{}/albums?country=from_token",
		artist.id), "items", callback);
}