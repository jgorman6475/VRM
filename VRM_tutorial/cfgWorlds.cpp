class CfgWorlds {

	#include "cfgLight.hpp"

	class DefaultWorld
	{
		access = ReadAndWrite;

		/// unique world ID used for Xbox 360 Matchmaking
		worldId = 0;

		plateFormat="$$$  ## - ##";
		plateLetters="ABCDEFHIKLMOPRSTVXYZ";

		//default center position
		centerPosition[] = {6400, 6400, 0};

		latitude = -40; // positive is south
		longitude = +15; // positive is east

		class Music: CfgMusic {};
		class EnvSounds: CfgEnvSounds {};

		cutscenes[] = {intro};

		/*Here you are able to replace objects placed in the world in Visitor by other models.
			This was used to replace generic forest models to the proper in-game models for example.
			You can either replace a model with a single other model or a set of other models.
			Example:
			class ForestTriangle
			{
			replace = PathDModelAbs;
			with[] = {};
			};
		center = true can be used as well to center all new objects.*/

		class ReplaceObjects {};

		// grid size
		landGrid = 50;
		// landRange is stored directly in WRP file

		//displays Numbering over Grid lines instead between
		gridNumbersOverLines = 0;

		class Grid
		{
			offsetX = 0;
			offsetY = 0;

			class Zoom1
			{
				zoomMax = 0.1;
				format = "XY";
				formatX = "Aa";
				formatY = "00";
				stepX = 128;
				stepY = 128;
			};
			class Zoom2
			{
				zoomMax = 1e30;
				format = "XY";
				formatX = "A";
				formatY = "0";
				stepX = 1280;
				stepY = 1280;
			};
		};

		startTime = 08:00; //Start time (military time)
		startDate = 01/01/2022; //Start date when terrain is loaded without a date preset (e.g. loading into editor)
		startWeather = 0.12;
		startFog = 0.0;

		// these parameters have been added with _VBS3_PHYSICAL_FOG_MODEL
		// base altitude for fog computations (in meters)
		startFogBase = 0.0;
		forecastFogBase = 0.0;
		// decay coefficient - decay of fog with altitude
		startFogDecay = 0.005;
		forecastFogDecay = 0.005;
		// beta0 (macroscopic cross-section of atmospheric scatterers at base level) for fog value 0
		fogBeta0Min = 0.0001;
		// beta0 (macroscopic cross-section of atmospheric scatterers at base level) for fog value 1
		fogBeta0Max = 0.02;

		// base height for haze computation (in meters)
		hazeBaseHeight = 0;
		// beta0 in base height (see https://confluence.bistudio.com/display/ARMA3/Improved+fog)
		hazeBaseBeta0 = 0;
		// density decay based on height
		hazeDensityDecay = 0.005;

		// parameters used for weather settings on terrain when map initialised.
		startWind = 0.1;
		startWindDir = 0.0;
		startWaves = 0.1;
		startRain = 0.0;
		startLightnings = 0.0;
		startGusts = 0.0;
		forecastWeather = 0.3;
		forecastFog = 0.0;
		forecastWind = 0.1;
		forecastWaves = 0.1;
		forecastRain = 0.0;
		forecastLightnings = 0.0;
		forecastGusts = 0.0;
		forecastWindDir = 0.0;
		timeOfChanges = 1800;
		rainForced = 0; // 0 = false | 1 = true
		lightningsForced = 0; // 0 = false | 1 = true
		wavesForced = 0; // 0 = false | 1 = true
		windForced = 0; // 0 = false | 1 = true


		class Lighting : DefaultLighting {};

		/** all DayLigthing values consist of 6 values:
			angle of the sun above the horizon
			max. direct light and min. direct light when not hidden by a cloud
			max. direct light and min. direct light when hidden by a cloud
			diffuse is sun or moon? (1=sun, 0=moon)
		*/

		// offset to set a basic for luminance values
		#define LV (-4)

		class DayLightingBrightAlmost
		{
			// note: during the nighttime we want the moon to be used instead
			// moon only
			deepNight[]={
				// sun angle
				-15,
				// max/min direct light
				{0.05,0.05,0.06},{0.001,0.001,0.002},
				// max/min direct light (sun hidden by a cloud, the cloud is shinning)
				{0.02,0.02,0.05},{0.003,0.003,0.003},
				// sky, sky around sun
				{0.003,0.003,0.006},{0.003,0.003,0.006},
				// sun - moon weighting
				0
			};
			fullNight[]={
				// sun angle
				-5,
				// max/min direct light
				{0.05,0.05,0.06},{0.02,0.02,0.02},
				// max/min direct light (sun hidden by a cloud, the cloud is shinning)
				{0.04,0.04,0.04},{0.04,0.04,0.04},
				// sky, sky around sun
				{0.01,0.01,0.02},{0.08,0.06,0.06},
				// sun - moon weighting
				0
			};
			// moon-sun crossing - no diffuse lighting used, only ambient
			sunMoon[]={
				-3.75,
				{0.04,0.04,0.05},{0.04,0.04,0.05},
				{0.04,0.04,0.05},{0.04,0.04,0.05},
				{0.04,0.035,0.04},{0.11,0.08,0.09},
				0.5
			};
			// early sun - most light is in ambient, diffuse visible
			earlySun[]={
				-2.5,
				{0.32,0.24,0.28},{0.08,0.06,0.07},
				{0.32,0.24,0.28},{0.08,0.06,0.07},
				{0.08,0.07,0.08},{0.14,0.10,0.12},
				1
			};
			// sun only
			sunrise[]={
				0,
				{{0.7,0.45,0.45},5.5+LV},{{0.07,0.09,0.12},4.5+LV},
				{{0.6,0.47,0.25},4.7+LV}, {{0.10,0.09,0.10},4.4+LV},
				{{0.5,0.4,0.4},4.5+LV}, {{0.88,0.51,0.24},6+LV},
				1
			};
			earlyMorning[]={
				5,
				{{0.65,0.55,0.55},6+LV},{{0.08,0.09,0.11},5+LV},
				{{0.55,0.47,0.25},5.75+LV}, {{0.10,0.09,0.10},4.75+LV},
				{{0.5,0.4,0.4},7.5+LV}, {{0.88,0.51,0.24},8.75+LV},
				1
			};
			midMorning[]={
				15,
				{{0.98,0.85,0.8},10.5+LV},{{0.08,0.09,0.11},6.5+LV},
				{{0.87,0.47,0.25},9.5+LV}, {{0.09,0.09,0.10},7.5+LV},
				{{0.5,0.4,0.4},9.5+LV}, {{0.88,0.51,0.24},9.75+LV},
				1
			};
			morning[]={
				25,
				{{1,1,0.9},15.5+LV}, {{0.17,0.18,0.19},12.5+LV},
				{{1,1,0.9},14.5+LV}, {{0.17,0.18,0.19},13+LV},
				{{0.15,0.15,0.15},14.5+LV},{{0.17,0.17,0.15},15.5+LV},
				1
			};
			noon[]={
				70,
				{{0.96,0.98,1},15.75+LV},{{0.36,0.49,0.61},13+LV},
				{{1,1,1},15+LV},{{0.36,0.37,0.38},13.5+LV},
				{{0.9,0.9,0.9},15+LV},{{1.0,1.0,0.9},16+LV},
				1
			};
		};

		// class DayLightingCloudy

		class DayLightingRainy
		{
			// so many clouds there is little difference between cloud or clear
			deepNight[]={
				// sun angle
				-15,
				// max/min direct light
				{0.0034,0.0034,0.004},{0.003,0.003,0.003},
				// max/min direct light (sun hidden by a cloud, the cloud is shinning)
				{0.0034,0.0034,0.004},{0.003,0.003,0.003},
				// sky, sky around sun
				{0.003,0.003,0.006},{0.003,0.003,0.006},
				// sun - moon weighting
				0
			};
			fullNight[]={
				// sun angle
				-5,
				// max/min direct light
				{0.023,0.023,0.023},{0.02,0.02,0.02},
				// max/min direct light (sun hidden by a cloud, the cloud is shinning)
				{0.023,0.023,0.023},{0.02,0.02,0.02},
				// sky, sky around sun
				{0.01,0.01,0.02},{0.08,0.06,0.06},
				// sun - moon weighting
				0
			};

			// moon-sun crossing - no diffuse lighting used, only ambient
			sunMoon[]={
				-3.75,
				{0.04,0.04,0.05},{0.04,0.04,0.05},
				{0.04,0.04,0.05},{0.04,0.04,0.05},
				{0.04,0.035,0.04},{0.11,0.08,0.09},
				0.5
			};
			// early sun - most light is in ambient, diffuse visible
			earlySun[]={
				-2.5,
				{0.0689,0.0689,0.0804},{0.06,0.06,0.07},
				{0.0689,0.0689,0.0804},{0.06,0.06,0.07},
				{0.08,0.07,0.08},{0.14,0.10,0.12},
				0.5
			};
			// sun only
			#define RainlyLight {1,1,1}
			//#define RainlyLightColor {0.8,0.9,1}
			earlyMorning[]={
				0,
				{RainlyLight,LV+3.95},{RainlyLight,LV+3.75},
				{RainlyLight,LV+3.95},{RainlyLight,LV+3.75},
				{RainlyLight,LV+4},{RainlyLight,LV+4.5},
				1
			};
			morning[]={
				5,
				{RainlyLight,LV+5.7},{RainlyLight,LV+5.5},
				{RainlyLight,LV+5.7},{RainlyLight,LV+5.5},
				{RainlyLight,LV+7},{RainlyLight,LV+7.5},
				1
			};
			lateMorning[]={
				25,
				{RainlyLight,LV+10.45},{RainlyLight,LV+10.25},
				{RainlyLight,LV+10.45},{RainlyLight,LV+10.25},
				{RainlyLight,LV+12},{RainlyLight,LV+12.5},
				1
			};
			noon[]={
				70,
				{RainlyLight,LV+10.7},{RainlyLight,LV+10.5},
				{RainlyLight,LV+10.7},{RainlyLight,LV+10.5},
				{RainlyLight,LV+12.25},{RainlyLight,LV+12.75},
				1
			};
		};

		class Weather
		{
			rainEnabled = true;

			class RainConfig
			{
				minCloudiness       = 0.5;
				averageCloudLimit   = 0.6;
				minProbability      = 0.02;
				maxProbability      = 0.9;
				minRainDensity      = 0.2;
				maxRainDensity      = 1.0;
				rainChange          = 60.0;
				rainFading          = 30;
				squareLength        = 0.5;
			};

			class LightningsConfig
			{
				minCloudiness   = 0.85;
				minProbability  = 0.0;
				maxProbability  = 0.25;
				minCount        = 3;
				maxCount        = 6;
				scatter         = 120;
			}

			class WindConfig
			{
				windChange        = 5.0;
				minForce          = 0.0;
				maxForce          = 10.0;
				minForceScatter   = 2.0;
				maxForceScatter   = 5.0;
				minGustCount      = 0.0;
				maxGustCount      = 10.0;
				gustTimeScatter   = 120.0;
				minGustScatter    = 10.0;
				maxGustScatter    = 20.0;
				gustInfluenceMin  = 0.2;
				gustInfluenceMax  = 0.4;
				speedOfWindChange = 2.0;
				minGustValue      = 0.0;
				maxGustValue      = 0.7;
			}

			class RainbowConfig
			{
				distance      = 10;
				intensityCoef = 0.35;
				maxCloudiness = 0.55;
			}

			/// various parameters depending on "overcast" variable
			class Overcast
			{
				class Weather1
				{
					/// what overcast value is this item for
					overcast = 0;
					/// sky texture
					sky = ProcTextSkybox2;
					//! Sky reflection texture
					skyR = ProcTextSkybox2;
					//! Sky horizon texture
					horizon = ProcTextSkybox2;
					/// cloud alpha, brightness and speed
					alpha = 0;
					bright = 0.5;
					speed = 0.20;
					// relative size of the individual clouds
					size=0.2;
					// relative height of the clouds
					height=1.0;
					/// how much sun, moon and stars are visible through the sky box
					through = 1.0;
					// overcast value used for lighting
					lightingOvercast = 0;
					/// how much of the diffuse light will go through the sky box
					diffuse = 1.0;
					/// how much of the diffuse light will go through the cloud when occluded by it
					cloudDiffuse = 1.0;
					/// sea wave size
					waves = 0.15;
				};

				class Weather2
				{
					/// what overcast value is this item for
					overcast = 0.1;
					sky = ProcTextSkybox2;
					//! Sky reflection texture
					skyR = ProcTextSkybox2;
					//! Sky horizon texture
					horizon = ProcTextSkybox2;
					alpha = 0.3;
					size=0.3;
					height=0.9;
					bright = 0.5;
					speed = 0.25;
					through = 1.0;
					lightingOvercast = 0.1;
					diffuse = 1.0;
					cloudDiffuse = 0.9;
					waves = 0.22;
				};
				class Weather3
				{
					overcast = 0.4;
					sky = ProcTextSkybox3;
					//! Sky reflection texture
					skyR = ProcTextSkybox3;
					//! Sky horizon texture
					horizon = ProcTextSkybox2;
					alpha = 0.98;
					size=0.5;
					height=0.8;
					bright = 0.45;
					speed = 0.40;
					through = 0.8;

					lightingOvercast = 0.6;
					//class Lighting: DayLightingCloudy {};
					diffuse = 0.7;
					cloudDiffuse = 0.4;
					waves = 0.5;
				};
				class Weather4
				{
					overcast = 0.7;
					sky = ProcTextSkybox4;
					//! Sky reflection texture
					skyR = ProcTextSkybox4;
					//! Sky horizon texture
					horizon = ProcTextSkybox2;
					alpha = 0.97;
					size=0.75;
					height=0.75;
					bright = 0.45;
					speed = 0.7;
					through = 0.2;
					diffuse = 0.4;
					lightingOvercast = 0.9;
					// many clouds in the skybox - dynamic clouds do not change much
					cloudDiffuse = 0.75;
					waves = 0.6;
				};
				class Weather5
				{
					overcast = 1.0;
					sky = ProcTextSkybox5;
					//! Sky reflection texture
					skyR = ProcTextSkybox5;
					//! Sky horizon texture
					horizon = ProcTextSkybox2;
					alpha = 0.98;
					size=0.9;
					height=0.7;
					bright = 0.45;
					speed = 1.00;
					through = 0.0;
					diffuse = 0.2;
					// many clouds in the skybox - dynamic clouds do not change much
					cloudDiffuse = 0.95;
					waves = 0.7;
					lightingOvercast = 1.0;
				};
			};
			class Lighting
			{
				class BrightAlmost: DayLightingBrightAlmost
				{
					overcast = 0;
				};

				class Rainy: DayLightingRainy
				{
					overcast = 1.0;
				};
			};
			class ThunderboltNorm
			{
				model = PathDModel;
				soundNear[] = {"", db-10, 1};
				soundFar[] = {"", db-10, 1};
			};
			class ThunderboltHeavy
			{
				model = PathDModel;
				soundNear[] = {"", db-10, 1};
				soundFar[] = {"", db-10, 1};
			};

			// Maximum and minimum temperatures (night and day) specified for every month - the game temperatures will vary in those limits // _VBS3_TI
			temperatureDayMax[]  ={ 10,  12,  15, 20, 25, 35, 35, 35, 25, 20,  10,  10};
			temperatureDayMin[]  ={-10, -6, -5, -1,  5,  6,  7, 10,  5,  2, -5, -10};

			temperatureNightMax[]={  5,   6,   8, 10, 13, 18, 26, 25, 15, 13,   8,   4};
			temperatureNightMin[]={-10, -10, -10, -5,  0,  4,  5,  6,  5,  0,  -5, -10};

			// How much we limit the minimum (resp. maximum) temperature during the day (resp. night) if the sky is clear  // _VBS3_TI
			// 0 means no limit (the max and min will stay as stated above), 1 means full limit (the min and max will be equal)
			overcastTemperatureFactor = 0.4;

			// How much can be black and white surfaces heated up on a direct sunlight  // _VBS3_TI
			blackSurfaceTemperatureDelta = +5;
			whiteSurfaceTemperatureDelta = -2;
		};
		class Rain
		{
			texture = PathDTextureAbs;
			speed = 1;
			levels[]={8, 2};
			raindrop = PathDModel;
		}

		class RainParticles
		{
			// Parameters for the new particle rain
			// texture of the particle (r = alpha; g = normalX; b = normalY; a = color;)
			rainDropTexture=PathDTextureAbs;
			// dropsInTexture - the number of drops that are present in the drop texture
			texDropCount=4;
			// minimum rain strength when the effect starts to be rendered
			minRainDensity = 0.01;
			// distance of the effect
			effectRadius=15;
			// coefficient of how much the wind influences water drops
			windCoef=0.05;
			// fall speed of the drops
			dropSpeed=15.0;
			// random part of the fall speed
			rndSpeed=0.2;
			// coefficient of how much the drop could randomly change direction
			rndDir=0.1;
			// width of the single drop
			dropWidth=0.04;
			// height of the single drop
			dropHeight=0.8;
			// color of the drop
			dropColor[]={0.1, 0.1, 0.1, 0.1};
			// luminescence of the drop facing to sun
			lumSunFront=0.3;
			// luminescence of the drop opposite to sun
			lumSunBack=0.1;
			// coefficient that tells us how much "refracted" light from the scene is added to the drop color
			refractCoef=0.3;
			// coefficient to tune color saturation of the refraction effect (0=BW, 1=original color)
			refractSaturation = 0.3;
		};


		humidityUpCoef = 0.1;
		humidityDownCoef = 0.05;

		class SimulWeather
		{
			// Texture used for cloud noise
			// Use _raw for uncompressed paa or uncompressed dds file (compression caused artefacts)
			noiseTexture = ""; /// path should be redefined in data

			//=========================================================
			// General values
			//=========================================================
			// Number of keyframes per day. More keyframes = slower game (because of tables generation for each keyframe)
			numKeyframesPerDay = 48;  //48 = keyframe every 30 minutes
			// multiplier for wind speed
			windSpeedCoef = 10.0;
			// coef that is used to multiply moon irradiance
			moonIrradianceCoef = 10.0;

			//=========================================================
			// Values used for fade and sky color calculations
			//=========================================================
			// The maximum distance for the fade
			fadeMaxDistanceKm = 300.0;
			// The maximum altitude that will be used for fade and sky colour calculations. Few aircraft can fly higher than 15km
			fadeMaxAltitudeKm = 15.0;
			// How many altitudes to calculate fade and sky colours for - minimum 1, maximum 64.
			fadeNumAltitudes = 4;
			// How many elevation steps are used to calculate fade and sky colours (height of the fade table)
			fadeNumElevations = 8;
			// How many distance steps are used to calculate fade and sky colours (width of the fade table)
			fadeNumDistances = 8;
			// Whether light should stop at the planet's surface - normally false
			fadeEarthTest = false;

			//=========================================================
			// Values for sky keyframer
			//=========================================================
			// Whether the brightness of each keyframe is calculated automatically based on the available, sun, moon, or starlight.
			autoBrightness = true;
			// For AutoBrightness, how strongly the brightness is adjusted for darker skies
			autoBrightnessStrength = 0.1;

			//=========================================================
			// Values for cloud grid
			//=========================================================
			// Width of the cloud grid
			cloudGridWidth = 128;
			// Length of the cloud grid
			cloudGridLength = 128;
			// Height of the cloud grid
			cloudGridHeight = 16;

			//=========================================================
			// Values for Helper for generating cloud geometry
			//=========================================================
			// Helper elevation grid size
			helperGridElevationSteps = 24;
			// Helper azimuth grid size
			helperGridAzimuthSteps = 15;
			//! Set the effective radius of the Earth in metres, for curving the cloud volumes. The actual radius is ~6378000 metres, but
			//! smaller values produce more curvature. If set to zero, the radius will be calculated to make the clouds go to the horizon
			//! at the maximum cloud distance.
			helperEffectiveEarthRadius = 6378000;
			// Specify whether to curve the cloud volume over the Earth's surface, based on the effective radius.
			helperCurvedEarth = true;
			// Not sure about this...
			helperAdjustCurvature = false;
			// Number of layers used for geometry rendering (more layers = lower fps, values should be between 12-120)
			helperNumLayers = 100;
			// Distance where the furthest rendered layer is placed
			helperMaxDistance = 200000;
			//! Set a value, usually between 0 and 1, that determines how close cloud layers must be to the camera before starting to fade out.
			//! This value is a multiple for the distance between cloud layers at the nearest point.
			helperNearCloudFade = 0.5;
			//! Set the texture churn - how much the texture churns per frame - zero gives a static appearance,
			//! values up to 1 and over make the texture animate.
			helperChurn = 10;

			//=========================================================
			// Values for cloud generation
			//=========================================================
			// Width (East-West) of the whole area covered with clouds (in metres)
			cloudWidth = 60000;
			// Length (North-South) of the whole area covered with clouds (in metres)
			cloudLength = 60000;
			// If wrapping of clouds is enabled
			wrapClouds = true;

			// Resolution of the 3D Perlin noise used to generate clouds
			noiseResolution = 8;
			// Period (in daytime units) over which noise changes
			noisePeriod = 4.0;

			// density of clouds
			opticalDensity = 1.8;

			// How sharply defined the cloud edges are (0-1 (1=sharpest))
			alphaSharpness = 0.15;
			// Scale of self-shadowing, zero=complete,one=none
			selfShadowScale = 0.001;
			// Asymmetry parameter, between -1 and 1, for scattering. For clouds, values between 0.5 and 0.9 are most common.
			mieAsymmetry = 0.87;
			// Minimum elevation for lighting - if light direction is below this angle, it will be raised - useful for sunsets
			minimumLightElevationDegrees = 3.0;

			// global coef, that is used to multiply direct lighting of clouds
			directLightCoef = 0.25;
			// global coef, that is used to multiply indirect lighting of clouds
			indirectLightCoef = 0.01;

			// start of the Arma fog for clouds (im meters)
			fogStart = 10000;
			// end of the Arma fog for clouds (in meters)
			fogEnd = 30000;
			// max height of the Arma fog for clouds (in meters)
			fogHeight = 1000;

			// default keyframe values - will be overriden by keyframe values set in Overcast class
			class DefaultKeyframe
			{
				// Sequencer file name (use this to load values from specific keyframe within sequencer file)
				// seqFile = "";
				// Number of keyframe in sequencer file (beginning with 0) (use this to load values from specific keyframe within sequencer file)
				// seqFileKeyframe = 0;

				// =========================
				// Sky keyframe
				// =========================
				// The Rayleigh scattering coefficients (x=red,y=green,z=blue).
				rayleigh[] = {0.00749, 0.01388, 0.02878};
				// The Mie scattering coefficients (x=red,y=green,z=blue).
				mie[] ={0.0046, 0.0046, 0.0046};

				// The amount of haze, mist or fog.
				haze = 1.0;
				// The base altitude, above which haze starts to decrease in density.
				hazeBaseKm = 1.0;
				// The vertical scale over which haze reduces with altitude.
				hazeScaleKm = 0.5;
				// The anisotropy of Mie scattering.
				hazeEccentricity = 0.82;
				// Brightness adjustment of the keyframe - this value is used only if autoBrightness is disabled
				brightnessAdjustment = 1.0;

				// =========================
				// Cloud keyframe
				// =========================
				// The density of the cloud layer at this time (0-1)
				cloudiness = 0.5;
				// The base altitude of this cloud layer.
				cloudBaseKm = 3.2;
				// The height of the cloud layer, above its base altitude.
				cloudHeightKm = 6;

				// The amount of direct light to be used for rendering.
				directLight = 1.0;
				// The amount of indirect or secondary light to be used for rendering.
				indirectLight = 1.0;
				// The amount of ambient light to be used for rendering
				ambientLight = 1.0;

				// The number of noise octaves used to generate the clouds; default 3.
				noiseOctaves = 3;
				// The fractal persistence for generating the clouds, default 0.45.
				noisePersistence = 0.55;
				// The strength of the fractal edge effect, default 1.8.
				fractalAmplitude = 2.2;
				//  The wavelength of the fractal edge effect - longer wavelengths produce smoother clouds, default 140.
				fractalWavelength = 220.0;

				// The amount of light scattered per unit distance - larger values produce darker clouds, default 1.7.
				extinction = 1.8;
				// How much the edges of clouds should be diffused.
				diffusivity = 0.01;
			};

			class Overcast
			{
				class Weather1 : DefaultKeyframe
				{
					overcast = 0.0;
					cloudiness = 0.0;
				};
				class Weather2 : DefaultKeyframe
				{
					overcast = 0.2;
					cloudiness = 0.1;
				};
				class Weather3 : DefaultKeyframe
				{
					overcast = 0.4;
					cloudiness = 0.2;
				};
				class Weather4 : DefaultKeyframe
				{
					overcast = 0.6;
					cloudiness = 0.4;
				};
				class Weather5 : DefaultKeyframe
				{
					overcast = 0.8;
					cloudiness = 0.5;
				};
				class Weather6 : DefaultKeyframe
				{
					overcast = 1.0;
					cloudiness = 0.6;
				};
			};
		};

		/// sky texture, used only as default when there is no weather
		skyTexture = ProcTextSkybox1;
		//! Sky reflection texture, used only as default when there is no weather
		skyTextureR = ProcTextSkybox1;
		/// texture used for water surface
		// wave detection texture expected by the shaders
		seaTexture = "#(rgb,8,8,3)color(0,0,0,1)";

		midDetailTexture = "#(rgb,1,1,1)color(0.5,0.5,0.5,1,cdt)";
		/// texture used outside of the map (sea bed or infinite desert)
		//outsideMaterial = PathToLandText\pt.bimpas;
		outsideMaterial ="";
		/// height used outside of the map
		outsideHeight = -10;
		/// min. height - used to clamp data inside of the map during rendering
		minHeight = -10;
		/// shore effects - based on water depth (negative means water above the water level)
		// top point where water is considered off-shore
		shoreTop = 0;
		// point where water peaks should be max. visible before going offshore
		peakWaveTop = -1;
		// point where water peaks should start appearing
		peakWaveBottom = -5;


		clouds[] = {PathDModelAbs, PathDModelAbs, PathDModelAbs, PathDModelAbs};

		/// where ground detail texture is no longer visible (end fading out)
		noDetailDist = 50;
		/// where ground detail texture is fully visible (begin fading out)
		fullDetailDist = 20;

		/// define size of soundMap as multiplier of landRange (soundMap.dimX = landRange * soundMapCoef)
		soundMapSizeCoef = 1;

		/// distance, where ground detail normal is starts to blend to satellite normal texture
		satelliteNormalBlendStart = 80;
		/// distance, where blending of detail normal ends (satellite normal is fully visible)
		satelliteNormalBlendEnd = 100;
		/// if the satellite normal map on detail maps is enabled
		satelliteNormalOnDetail = true;

		/// maximal darkening coef for blending of satellite map and detail map on terrain (default = 0.0f, no darkening = 1.0f}
		terrainBlendMaxDarkenCoef = 1.0f;
		/// maximal brightening coef for blending of satellite map and detail map on terrain (default = 1.0f, no brightening = 0.0f)
		terrainBlendMaxBrightenCoef = 0.0f;

		/// if we should use interpolation of clutter coloring coef based on distance of clutter from camera
		interpolateClutterColoring = false;
		/// max coef for clutter coloring at far distance (must be >=1, large coef means we can colorize more)
		clutterColoringFarCoef = 5.0;
		/// distance (in m) when clutterColoringFarCoef when we start to interpolate to clutterColoringFarCoef
		clutterColoringFarStart = 15.0f;
		/// speed of far clutter coloration (1 = linear, 2 = quadratic, etc.)
		clutterColoringFarSpeed = 1.0f;

		/// coefficient for clutter radius to check against roadways (0 = check only center, 1 = check whole radius)
		clutterRoadwayCheckRadiusCoef = 0.0f;

		/// values for new haze computation (see _ARMA3_HAZE_COMPUTATION)
		/// coefficient used to compute haze distance (haze distance = fogFar * hazeDistCoef), can be > 1
		/// if the value is negative, then standard haze computation is used
		hazeDistCoef = -1.0;
		/// fog value, that we want to have at haze distance (=distance computed using hazeDistCoef), 0 = full fog, 1 = no fog
		/// if the value is negative, then standard haze computation is used
		hazeFogCoef = -1.0;

		/// modifiers of around sound coefficient for pixel shader computations
		/// coef = pow(coef * _aroundSunCoefMultiplier, _aroundSunCoefExponent);
		aroundSunCoefMultiplier = 1.0;
		aroundSunCoefExponent = 4.0;

		/// parallax coef used for shifting horizon - the higher the camera, the lower we want the horizon range to be placed
		/// use 0 to switch off shifting
		horizonParallaxCoef = 0.045;

		/// starting vertical texture coordinate for horizon coloration with fog (use 1 to disable coloration)
		horizonFogColorationStart = 0.8;
		/// starting vertical texture coordinate for skybox coloration with fog (use 1 to disable coloration)
		skyFogColorationStart = 0.7;

		/// if sky color influences fog color
		skyColorInfluencesFogColor = true;

		/// scale coefficient for horizon coloration by Sun
		horizonSunColorationScale = 10.0;
		/// intensity coefficient for horizon coloration by Sun
		horizonSunColorationIntensity = 1.0;

		/// modifier for brightness of satellite map textures drawn on the map display view
		mapDrawingBrightnessModifier = 1.0f;

		/// depth of sea bed plane under water
		/// positive value means depth under water, negative value means autodetection
		seaBedUnderwaterDepth = -1.0f;

		/// controls density of clutters (size of square where single clutter is present)
		clutterGrid = 2;
		/// how far clutters are visible
		clutterDist = 50;
		/// maximal size of clutters (for clipping)
		clutterRadius = 1.0;
		class DefaultClutter
		{
			/// Determines the affection of the clutter to the wind (0 - stone, 1 - common grass)
			affectedByWind = 0;
			/// how much is the clutter colored by the ground
			//colorByGround = 0.5; //obsolete
			/// if colored by the ground, desired color relative to the ground
			relativeColor[] = {1, 1, 1, 1};
			/// minimal scale
			scaleMin = 0.5;
			/// maximal scale
			scaleMax = 1.0;
			/// Use default lighting
			swLighting = true;
		};
		class Clutter {};

		skyObject = "core\skyobject\skyobject.p3d";
		starsObject = PathDModelAbs;
		pointObject = PathDModelAbs;
		horizontObject = PathDModelAbs;
		haloObject = PathDModelAbs;
		sunObject = PathDModelAbs;
		rainbowObject = PathDModelAbs;
		moonObject = PathDModelAbs;
		waterTexture = ProcTextSkybox1;
		underwaterOcclusionObject = ""; /// path should be defined in data

		//============================================
		// caustics
		//============================================
		// enable/disable caustics
		causticsEnabled = true;

		// ===========================================
		// DEPRECATED
		// TODO remove
		// only for backward compatibility, use causticsTextureMask

		// caustics texture
		causticsTexture = ""; /// path should be defined in data
		/// number of textures in one row in caustic texture (we suppose that number of rows and columns is the same)
		causticsTextureNumRows = 4;
		// ===========================================

		// mask for caustics textures
		causticsTextureMask = ""; /// path should be defined in data
		/// number of caustics textures
		causticsTextureCount = 32;
		/// length of the side of the rectangle, that covers one caustics texture (in meters) in zero depth
		causticsTextureArea = 4.0;
		/// length of the side of the rectangle, that covers one caustics texture (in meters) in max depth (causticsDepthLimit)
		causticsTextureAreaDeep = 150.0;
		/// interval of texture change (in s)
		causticsTextureChangeInterval = 0.09;
		/// distance limit for caustics drawing (in m)
		causticsDistanceLimit = 200.0;
		/// depth limit (under water) for caustics drawing (in m)
		causticsDepthLimit = 50.0;
		/// coef used for caustics intensity fading with depth (how fast the intensity fades with depth), 1.0 = linear, 2.0 = quadratic,...
		causticsDepthFadeCoef = 1.0;
		/// distance (in meters) over which we interpolate two caustics textures (in different depth)
		causticsTextureDepthGranularity = 3.0;
		/// brightness coefficient
		causticsBrightnessCoef = 4.0;

		//============================================
		// dynamic lights
		//============================================
		// These constants are used to determine the radius of dynamic lights.
		// Radius is computed based on minimal brightness.
		// Minimal brightness is computed: max(dynLightMinBrightnessAbsolute, sceneAmbient * dynLightMinBrightnessAmbientCoef);
		//  where sceneAmbient is current brightness of scene ambient light
		dynLightMinBrightnessAmbientCoef = 0.1;
		dynLightMinBrightnessAbsolute = 0.001;


		//============================================
		// env texture
		//============================================
		/// no env texture by default
		envTexture = "";

		//@{ layered terrain rendering data
		satelliteMap = "";
		layerMask = "";
		//@}

		// Water material is used for sea landscape parts
		seaMaterial = "#water";

		// Shore material is used for sea and landscape interface parts
		shoreMaterial = "#shore";

		// Shore material is used for sea and landscape interface parts - the foam part
		shoreFoamMaterial = "#shoreFoam";

		// Shore wet material is used for sea and landscape interface parts - the wet part
		shoreWetMaterial = "#shoreWet";

		// Terrain material is used for terrain solid ground
		// by default load from CfgMaterials
		terrainMaterial = "#terrain";

		// params for anomalies
		class AnomalyPars
		{
			// outer model (should be sphere with radius of 1 and normals directed outwards)
			outerModel = ""; /// path should be defined in data
			// inner model (should be sphere with radius of 1 and normals directed inwards)
			innerModel = ""; /// path should be defined in data
			// scale of refraction (R, G, B - you can use different values to achieve abberation effect)
			refractScale[] = {0.04, 0.03, 0.05};
			// animation time coef (horizontal, vertical), use {0,0, 0} for no animation (third value not used)
			timeScale[] = {0.03, 0.03, 0.0};
			// distance (in meters) from the anomaly boundary, where the postprocess effect should be used (0 = no postprocess)
			postProcessDistance = 3.0;
		};

		// params for anomalies
		class SpriteRefractionPars
		{
			// scale of refraction (R, G, B - you can use different values to achieve abberation effect)
			refractScale[] = {0.02, 0.02, 0.02};
			// animation time coef (horizontal, vertical), use {0,0, 0} for no animation (third value not used)
			timeScale[] = {0.03, 0.03, 0.0};
		};

		// params for underwater fog
		class Underwater
		{
			/// fog color is changed based on the depth under the water surface
			/// normal fog color  ->   water color      ->    deep water color
			///     ^
			/// noWaterFog        ->   fullWaterFog     ->    deepWaterFog

			/// depth under the water, where water color starts (can be negative = distance above water)
			noWaterFog = -0.3;
			/// depth under the water, where water color is at full strength and deep water color starts
			fullWaterFog = 0.1;
			/// depth under the water, where deep water color is at full strength
			deepWaterFog = 10;

			/// distance of the water fog (fog far)
			waterFogDistance = 20;
			/// distance of the water fog (fog near)
			waterFogDistanceNear = 0;

			/// color of the water fog at fullWaterFog depth
			waterColor[] = {0.02,0.08,0.12};
			/// color of the water fog at deepWaterFog depth
			deepWaterColor[] = {0.01,0.06,0.14};

			/// skyTopColor (zenith) at fullWaterFog depth (reflections on water surface?)
			surfaceColor[] = {0.20,0.30,0.25};
			/// skyTopColor (zenith) at deepWaterFog depth (reflections on water surface?)
			deepSurfaceColor[] = {0.10,0.18,0.22};
		};

		class SeaWaterShaderPars
		{
			// coefficient used to multiply move value of refractions
			refractionMoveCoef = 0.01;
			// minimal water surface opacity, when we are looking from above the water surface down
			minWaterOpacity = 0.65;
			// coef used to multiply square root of distance of pixel from water surface when coputing final opacity of water surface
			// waterOpacity = MinWaterOpacity + sqrt(distance)*WaterOpacityDistCoef;
			waterOpacityDistCoef = 0.07;
			// opacity of water surface when we are under water
			underwaterOpacity = 0.2;
			// distance from object, where we start to fade the water surface to full opacity
			waterOpacityFadeStart = 100;
			// length of water surface opacity fading
			waterOpacityFadeLength = 20;
		};

		/// parameters for water in expansion
		class WaterExPars
		{
			/// base density for water fog (exp coef used for water fog computation) (_A3_MULTI_COMPONENT_FOG)
			fogDensity = 0.04;

			/// color of the water fog when the camera is on or above water surface
			fogColor[] = { 0.003, 0.005, 0.01 };

			/// coefficients for water fog color extinction based on depth of the camera under water (coefs for RGB)
			/// this influences how fast the water fog color darkens when camera moves under water (depends on camera position)
			fogColorExtinctionSpeed[] = { 0.2, 0.1, 0.04 };

			/// defines how light influences fog color (r = ambient influence, g = diffuse (sun) influence, b = overall light influence)
			fogColorLightInfluence[] = { 0.6, 0.15, 0.5 };

			/// coefficient for water fog gradient (MIN coef, MIDDLE coef, MAX coef)
			fogGradientCoefs[] = { 0.4, 1.0, 1.5 };

			/// coefficients for light extinction in water based on the point under water (coefs for RGB)
			/// this influences extinction of ambient light under water (depends on shaded point position)
			ligtExtinctionSpeed[] = { 0.3, 0.1, 0.05 };
			/// coefficients for diffuse light extinction
			diffuseLigtExtinctionSpeed[] = { 0.3, 0.1, 0.05 };

			/// screen space reflections - strength of reflections
			/// [0,1] (0 = no reflections, 1 = full reflections)
			ssReflectionStrength = 0.85;
			/// screen space reflections - max. jitter used when sampling - this is used to randomize artifacts caused by sparse sampling
			/// [0,1] (0 = no jitter, 1 = max jitter)
			ssReflectionMaxJitter = 1.0;
			/// screen space reflections - how much small ripples (from water normal map) influence the reflection
			/// [0,1] (0 = no influence, 1 = max influence)
			ssReflectionRippleInfluence = 0.15;
			/// screen space reflections - coefficient for fading of reflection near screen borders (larger number = faster fading)
			ssReflectionEdgeFadingCoef = 10.0;
			/// screen space reflections - coefficient for fading of reflection based on distance (larger number = faster fading)
			ssReflectionDistFadingCoef = 4.0;

			/// minimal coef for refraction (at water surface)
			refractionMinCoef = 0.02;
			/// maximal coef for refraction (at refractionMaxDist)
			refractionMaxCoef = 0.07;
			/// distance (in meters) of the point from water surface, where refraction coefficient becomes refractionMaxCoef;
			refractionMaxDist = 20.0;

			/// water surface opacity (should be 0 because of multicomponent fog, use higher values for debugging (-> Buldozer))
			surfaceOpacity = 0.0;

			/// intensity of shadow on the water (1 = full shadow, 0 = no shadow)
			shadowIntensity = 0.5;

			/// max intensity of specular on water
			specularMaxIntensity = 25.0;
			/// specular power for overcast 0
			specularPowerOvercast0 = 200.0;
			/// specular power for overcast 1
			specularPowerOvercast1 = 50.0;
			/// how much we modify the normal for specular computation (0 = no modification, 1 = full modification)
			specularNormalModifyCoef = 1.0;


			/// intensity of foam around objects
			foamAroundObjectsIntensity = 0.25;
			/// coef for fading of foam (larger number = faster fade)
			foamAroundObjectsFadeCoef = 8.0;
			/// coef for color of the foam
			foamColorCoef = 2.0;
			/// coef for deformation of foam texture based on normal of water
			foamDeformationCoef = 0.02;
			/// coef for mapping of foam texture based on world coordinates
			foamTextureCoef = 0.2;
			/// speed of movement of foam based on time
			foamTimeMoveSpeed = 0.2;
			/// amount of movement of foam based on time
			foamTimeMoveAmount = 0.1;

			/// darkening of terrain near shore params
			/// maximal darkening coef (1.0 = max darkening, 0.0 = no darkening)
			shoreDarkeningMaxCoef = 0.5;
			/// height offset above water level, where darkening is in its full power
			shoreDarkeningOffset = 0.2;
			/// darkening gradient size
			shoreDarkeningGradient = 0.2;

			// speed of the waves (scaling of time)
			shoreWaveTimeScale = 0.8;
			// offset used to delay when the thick edge of foam appears and dissolves based on wave phase
			shoreWaveShifDerivativeOffset = -0.8;
			// overall shore foam intensity
			shoreFoamIntensity = 0.5;
			// max wave height on shore (in meters)
			shoreMaxWaveHeight = 0.15;
			// reflection intensity on the shore wet layer
			shoreWetLayerReflectionIntensity = 1.0;
		};

		/// parameters for new HDR computation
		class HDRNewPars
		{
			//@{ global aperture settings
			/// global minimal possible aperture
			minAperture = 0.00001;
			/// global maximal possible aperture
			maxAperture = 256;
			/// how many times greater than standard avg luminance must be current avg luminance to reach current max aperture
			apertureRatioMax = 4;
			/// how many times smaller than standard avg luminance must be current avg luminance to reach current min aperture
			apertureRatioMin = 10;
			//@}

			//@{ Bloom settings
			/// image scale for bloom composition
			bloomImageScale = 1.0;
			/// bloom scale for bloom composition
			bloomScale = 0.3;
			/// bloom exponent for bloom computation
			bloomExponent = 1.0;
			/// luminance offset for bloom computation
			bloomLuminanceOffset = 0.8;
			/// luminance scale for bloom computation
			bloomLuminanceScale = 1;
			/// luminance exponent for bloom computation
			bloomLuminanceExponent = 1.2;
			//@}

			//@{ Tone mapping settings

			// tonemapping method (0 = none, 1 = filmic, 2 = Reinhard)
			tonemapMethod = 2;

			// params for filmic tonemapping
			// Uncharted 2 tone mappping filmic curve
			// for more information see http://www.slideshare.net/ozlael/hable-john-uncharted2-hdr-lighting
			tonemapShoulderStrength = 0.22;
			tonemapLinearStrength = 0.30;
			tonemapLinearAngle = 0.10;
			tonemapToeStrength = 0.20;
			tonemapToeNumerator = 0.01;
			tonemapToeDenominator = 0.30;
			tonemapLinearWhite = 11.2;
			tonemapExposureBias = 2.0;

			// params for Reinhard tonemapping
			tonemapLinearWhiteReinhard = 2.5;
			//@}

			//@{ settings for NVG
			/// min aperture when using NVG
			nvgApertureMin = 1;
			/// standard aperture when using NVG
			nvgApertureStandard = 7;
			/// max aperture when using NVG
			nvgApertureMax = 15;
			// average scene luminance for standard aperture when using NVG
			nvgStandardAvgLum = 3;
			/// light gain when using NVG
			nvgLightGain = 100;

			/// use transition effects when going to/from NVG
			nvgTransition = true;
			/// transition coefficient when we are putting NVG on
			nvgTransitionCoefOn = 40.0;
			/// transition coefficient when we are putting NVG off
			nvgTransitionCoefOff = 0.01;
			//@}


			//@{ settings for night eye (blue shift)
			/// min avg intensity (when the night shift is at full effect)
			nightShiftMinAperture = 0;
			/// max avg intensity (when the night shift is at zero effect and begins to take some effect, effect of night shift is then interpolated based on min and max aperture)
			nightShiftMaxAperture = 0.002;
			/// maximal possible effect of night shift (0-1, 0 disables it)
			nightShiftMaxEffect = 0.6;
			/// luminance scale to determine night shift effects for individual pixels
			nightShiftLuminanceScale = 600;
			//@}

			//@{ settings for light adaptation
			/// speed factor for adapting to light (greater number = faster)
			eyeAdaptFactorLight = 0.6;
			/// speed factor for adapting to dark (greater number = faster)
			eyeAdaptFactorDark = 0.2;
			//@}
		};

		class NVGPars
		{
			/// is film grain enabled for NVG?
			filmGrainEnabled = true;
			/// film grain params (intensity, sharpness, grain size, intensityX0, intensityX1, monochromatic (0=mono, 1=color))
			filmGrainPars[] = {0.4, 2.75, 1, 3, 1, 0};
		};

		/// parameters for depth of field
		class DOFPars
		{
			// standard dof parameters
			focusDistance = 25.0;
			blur = 1.0;
			farOnly = true; //blur only far objects?

			// underwater dof parameters (no goggles)
			focusDistanceWater = 1.0;
			blurWater = 1.3;
			farOnlyWater = true; //blur only far objects?

			// underwater dof parameters (with goggles)
			focusDistanceWaterGoggles = 4.0;
			blurWaterGoggles = 1.0;
			farOnlyWaterGoggles = true; //blur only far objects?
		};

		/// colors for LOD diagnostics
		class LODDiagColors
		{
			// default color used when no color is defined for given LOD
			defaultColor[] = { 1, 1, 1 };

			// colors for lods (you can define as many as you want, not defined LODs will be colored by defaultColor)
			// numbers correspond to graphical LOD of the shape
			lod0[] = { 1, 0, 0 };
			lod1[] = { 0, 1, 0 };
			lod2[] = { 0, 0, 1 };
			lod3[] = { 1, 1, 0 };
			lod4[] = { 0, 1, 1 };
			lod5[] = { 1, 0, 1 };

			// color coefficient for terrain
			terrainCoef = 0.4;
			// color coefficient for water
			waterCoef = 0.7;
			// alpha for water
			waterAlpha = 0.5;
		};

		// enable vehicle tracks
		enableTracks = true;
		// enable footsteps
		enableFootsteps = true;
		// enable blood splashes
		enableBloodSplashes = true;


		// fractal and white noise random offset are added
		// white noise generated more "wild" terrain
		// fractal tends to generate smooth, varied terrain
		class Subdivision
		{
			// fractal component of subdivision
			// changes are smaller for smaller rectangles
			class Fractal
			{
				// texture roughness factor
				rougness = 10;
				// max. value for squares containing road
				maxRoad = 0.2;
				// max. value for squares containing track
				maxTrack = 1.0;
				// max. coeficient depending on slope
				maxSlopeFactor = 0.05;
			};
			// white noise component of subdivision
			// change size is independent on rectangle size
			class WhiteNoise
			{
				rougness = 5;
				// max. value for squares containing road
				maxRoad = 0.1;
				// max. value for squares containing track
				maxTrack = 0.5;
				// max. coeficient depending on slope
				maxSlopeFactor = 0.025;
			};

			// do not divide surfaces that are under given limit
			minY = -0.0;
			// do not divide flat surfaces
			minSlope = 0.02;
		};

		/// ambient life configuration
		#include "cfgAmbient.hpp"
	};

	initWorld = "";
	demoWorld = "";
};
