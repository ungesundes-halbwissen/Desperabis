// PackingTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem>
#include <format>
#include <vector>
#include <cassert>
#include <sstream>
#include <direct.h>

#include "FileLists.h"
#include "Texture.h"
#include "Sound.h"
#include "DatFile.h"
#include "FileUtils.h"

using namespace std;

#define SUCCEED_OR_RETURN(_f) if (!(_f)) return false;


bool ConvertTexturesToText()
{
	Texture t;
	SUCCEED_OR_RETURN(t.Load("GRAFIK\\TUR38.256"));
	SUCCEED_OR_RETURN(t.ToText("IngameKjarthan.txt"));
	SUCCEED_OR_RETURN(t.Load("GRAFIK\\TUR39.256"));
	SUCCEED_OR_RETURN(t.ToText("IngameTrainingInstructions.txt"));

	SUCCEED_OR_RETURN(t.Load("GRAFIK\\HERZ.256"));
	SUCCEED_OR_RETURN(t.ToMissionText("MissionsMenu.txt"));
	return true;
}

bool ConvertTextToTextures()
{
	Texture t;
	SUCCEED_OR_RETURN(t.FromText("IngameKjarthan.txt"));
	SUCCEED_OR_RETURN(t.Save("GRAFIK\\TUR38.256"));
	SUCCEED_OR_RETURN(t.FromText("IngameTrainingInstructions.txt"));
	SUCCEED_OR_RETURN(t.Save("GRAFIK\\TUR39.256"));
	SUCCEED_OR_RETURN(t.FromMissionText("MissionsMenu.txt"));
	SUCCEED_OR_RETURN(t.Save("GRAFIK\\HERZ.256"));
	return true;
}


bool ConvertSMPToWAV()
{
	Sound smp;
//	if (!smp.LoadWAV("SAMP\\MUSIC1.WAV"))
//		return false;

//	if (!smp.LoadSMP("SAMP\\SOUND1.SMP"))
//		return false;

	// Witch sounds (samples 109..116):
	for (int i = 0; i < 8; i++)
	{
		std::ostringstream smpName, wavName;
		smpName << "SAMP\\SOUND" << i + 109 << ".SMP";
		wavName << "Witch" << i << ".wav";
		string s = smpName.str();
		SUCCEED_OR_RETURN(smp.LoadSMP(s.c_str()));
		s = wavName.str();
		SUCCEED_OR_RETURN(smp.SaveWAV(s.c_str()));
	}

	return true;
}

bool ConvertWAVToSMP()
{
	Sound smp;

	// Witch sounds (samples 109..116):
	for (int i = 0; i < 8; i++)
	{
		std::ostringstream smpName, wavName;
		smpName << "SAMP\\SOUND" << i + 109 << ".SMP";
		wavName << "Witch" << i << ".wav";
		string s = wavName.str();
		SUCCEED_OR_RETURN(smp.LoadWAV(s.c_str()));
		s = smpName.str();
		SUCCEED_OR_RETURN(smp.SaveSMP(s.c_str()));
	}

	return true;
}


int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		std::cout << "Command line args: " << std::endl;
		std::cout << "  -s <folder> : adds one source root folder (absolute path) under which the unpacked game assets are located" << std::endl;
		std::cout << "  -d <file> : absolute file path of the destination file (.DAT)." << std::endl;
		return 0;
	}
	else
	{
//		std::cout << "Number of arguments: " << argc - 1 << std::endl;
		// Print each command line argument
		for (int i = 1; i < argc; ++i)
		{
//			std::cout << "  Argument " << i << ": " << argv[i] << std::endl;
			if (_stricmp(argv[i], "-s") == 0 && i < argc - 1)
			{
				FileUtils::AddInputDirectory(argv[i + 1]);
				i++;
			}
			if (_stricmp(argv[i], "-d") == 0 && i < argc - 1)
			{
				FileUtils::SetOutputDirectory(argv[i + 1]);
				i++;
			}
		}
	}

	const bool extractFromOriginal = false;
	if (extractFromOriginal)
	{
		// Some playground code to do the inverse operations, not executed by actual tool
		string snd = DatFile::BuildFileList("SOUNDS.DAT", "SOUNDS");
		string music = DatFile::BuildFileList("MUSIC.DAT", "MUSIC");
		string game = DatFile::BuildFileList("GAME.DAT", "GAME");

		if (!ConvertSMPToWAV())
		{
			cerr << "An error occurred during sound extraction." << endl;
			return 2;
		}
		if (!ConvertTexturesToText())
		{
			cerr << "An error occurred during texture to text extraction." << endl;
			return 3;
		}
		cout << "Extracting localizable files was successful." << endl;;
	}
	else
	{
		cout << "Start packaging of text files...";
		if (!ConvertTextToTextures())
		{
			cerr << "An error occurred during text baking." << endl;
			return 2;
		}
		cout << "success." << endl;

		cout << "Start packaging of sound files...";
		if (!ConvertWAVToSMP())
		{
			cerr << "An error occurred during sound baking." << endl;
			return 3;
		}
		cout << "success." << endl;


		string datOutFile;
		if (!DatFile::Game.PackageAndSave(&datOutFile))
		{
			cerr << "An error occurred during packaging GAME.DAT." << endl;
			return 101;
		}
		cout << "Package successfully written to: " << datOutFile.c_str() << endl;
		if (!DatFile::Sounds.PackageAndSave(&datOutFile))
		{
			cerr << "An error occurred during packaging SOUNDS.DAT." << endl;
			return 101;
		}
		cout << "Package successfully written to : " << datOutFile.c_str() << endl;
		if (!DatFile::Music.PackageAndSave(&datOutFile))
		{
			cerr << "An error occurred during packaging MUSIC.DAT." << endl;
			return 101;
		}
		cout << "Package successfully written to: " << datOutFile.c_str() << endl;
	}

	cout << "All successful." << endl;
	return 0;
}
