class CfgPatches
{
	class VRM_tutorial_terrain
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] =
		{
			"A3_Map_Stratis"
		};
	};
};

class CfgWorldList
{
	class VRM_tutorial_terrain{};
};

class CfgWorlds
{
	class Stratis;
	class VRM_tutorial_terrain: Stratis
	{
		cutscenes[] = {};
		description = "VRM Tutorial Terrain";
		worldName = "\VRM\VRM_tutorial\VRM_tutorial_terrain.wrp";
		author = "Gorman";
		icon = "";
		previewVideo = "";
		pictureMap = "";
		pictureShot = "";

		newRoadsShape = "";

		centerPosition[] =
		{
			2560, 2560
		};
		ilsDirection[] =
		{
			0, 0.08, 1
		};
		ilsPosition[] =
		{
			0, 0
		};
		ilsTaxiIn[] = {};
		ilsTaxiOff[] = {};
		drawTaxiway = 0;
		class SecondaryAirports{};
		class ReplaceObjects{};

		class Sounds
		{
			sounds[] = {};
		};

		class Animation
		{
			vehicles[] = {};
		};

		minTreesInForestSquare = 2;
		minRocksInRockSquare = 2;

		class Subdivision{};
		class Names{};
	};
};
