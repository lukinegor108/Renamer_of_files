#include <string>
#include <iostream>
#include <filesystem>

int main()
{
	//Contains the names of albums of 2pac
	std::string albums[8] = {
				 "2Pacalypse Now",
	       			 "All Eyez on Me",
				 "Better Dayz",
				 "Greatest Hits",
				 "Pac's Life",
				 "Me Against the World",
				 "R U Still Down? (Remember Me)",
				 "Loyal To The Game"
				};
	//All names of songs in all albums are looking like this: "2pac - *.mp3"
	//I want to delete first seven characters from all songs
	//This is the number(7)
	auto number_of_chars = 7;

	for(auto album : albums)
	{
		//"path" - full path to album dir, we are iterating over albums in "albums[]"
		auto path = "/home/egor/Music/2pac/" + album;
		
		//Iterating over all files in "album"
		for(const auto &entry : std::filesystem::directory_iterator(path))
		{
			auto old_name = static_cast<std::string>(entry.path());
			auto new_name = (static_cast<std::string>(entry.path())).erase(old_name.find_last_of("/") + 1, number_of_chars);

			std::filesystem::rename(old_name, new_name);
		}
	}

	return 0;
}
