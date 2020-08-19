#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

int main()
{
	// Path to dir with your albums with the songs.
	auto path_to_albums = "/home/egor/Music/2pac/";

	// Number of chars, which will be erased from the start of songs names.
	// (ex: "2pac - Changes.mp3" -> "Changes.mp3"), 7 chars were erased.
	auto number_of_chars = 7;

	std::vector<std::string> albums;

	for(auto album : std::filesystem::directory_iterator(path_to_albums))
	{
		auto path_to_album = static_cast<std::string>(album.path());
		albums.push_back(path_to_album);
	}	

	for(auto album : albums)
	{
		for(const auto &song : std::filesystem::directory_iterator(album))
		{
			auto path_to_song =  static_cast<std::string>(song.path());
			auto old_path = path_to_song;
			auto new_path = old_path.erase(old_path.find_last_of("/") + 1, number_of_chars);

			std::filesystem::rename(path_to_song, new_path);
		}
	}

	return 0;
}
