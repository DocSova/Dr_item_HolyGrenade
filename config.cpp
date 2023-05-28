class CfgPatches
{
	class Dr_item_HolyGrenade
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_characters_F","A3_Data_F"};
	};
};

class CfgSounds {
	class Dr_angelsSinging {
		name = "angelsSinging";
		sound[] = {"Dr_item_HolyGrenade\data\sounds\angels.ogg", 10, 1, 150};
		titles[] = {};
	};
	class Dr_hallelujah_man_1 : Dr_angelsSinging {
		name = "hallelujah_man";
		sound[] = {"Dr_item_HolyGrenade\data\sounds\hallelujah_man_1.ogg", db+10, 1, 20};
	};
	class Dr_hallelujah_man_2 : Dr_hallelujah_man_1 {
		sound[] = {"Dr_item_HolyGrenade\data\sounds\hallelujah_man_2.ogg", db+10, 1, 20};
	};
	class Dr_hallelujah_man_3 : Dr_hallelujah_man_1 {
		sound[] = {"Dr_item_HolyGrenade\data\sounds\hallelujah_man_3.ogg", db+10, 1, 20};
	};
};

class CfgCloudlets {
	class Default ;
	class HolyGrenadeSmoke: Default
	{
		interval = 0.01;
		circleRadius = 0;
		circleVelocity[] = {0, 0, 0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 13;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 4;
		moveVelocity[] = {0, 0, 0};
		rotationVelocity = 0;
		weight = 10;
		volume = 7.9;
		rubbing = 0.1;
		size[] = {5, 6, 7};
		color[] = {{1,1,1,0}, {1,1,1,0.105055}, {1,1,1,0}};
		animationSpeed[] = {1000};
		randomDirectionPeriod = 0.2;
		randomDirectionIntensity = 0.2;
		onTimerScript = "";
		beforeDestroyScript = "";
		destroyOnWaterSurface = 1;
		destroyOnWaterSurfaceOffset = -1;
		lifeTimeVar = 0;
		positionVar[] = {4,4,3};
		MoveVelocityVar[] = {1,1,1};
		rotationVelocityVar = 3;
		sizeVar = 0;
		colorVar[] = {0, 0, 0, 0};
		randomDirectionPeriodVar = 0.5;
		randomDirectionIntensityVar = 0.02;
	};
};

class HolyGrenadeExplosion
{
	class Light1
	{
		simulation = "light";
		type = "GrenadeExploLight";
		position[] = {0, 0, 0};
		intensity = 0.01;
		interval = 1;
		lifeTime = 1;
	};
	class MortarExp1
	{
		simulation = "particles";
		type = "MortarExp";
		position[] = {0, 0, 0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.5;
	};
	class HolyGrenadeSmoke
	{
		simulation = "particles";
		type = "HolyGrenadeSmoke";
		position[] = {0, 0, 0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};

class ExploHolyGrenadeCrater {};

class cfgAmmo
{
	class GrenadeHand ;
	class Dr_HolyGrenadeAmmo : GrenadeHand {
		explosionTime = 9;
		timeToLive = 10;
		indirectHit = 16;
		indirectHitRange = 12;
		dangerRadiusHit = 70;
		model = "Dr_item_HolyGrenade\holyGrenade.p3d";
		explosionSoundEffect = "DefaultExplosion";
		CraterEffects = "ExploHolyGrenadeCrater";
		CraterWaterEffects = "ImpactEffectsWaterExplosion";
		explosionEffects = "HolyGrenadeExplosion";
		SoundSetExplosion[] = {"Shell155mm_Exp_SoundSet", "Shell155mm_Tail_SoundSet", "Explosion_Debris_SoundSet"};
	};
};

class cfgMagazines
{
	class HandGrenade ;
	class Dr_HolyGrenade: HandGrenade
	{
		scope=2;
		displayName="Holy Hand Grenade";
		model="Dr_item_HolyGrenade\holyGrenade.p3d";
		picture="\Dr_item_HolyGrenade\data\icon_co.paa";
		displayNameShort = "Holy Hand Grenade";
		ammo = "Dr_HolyGrenadeAmmo";
		mass = 15;
		initSpeed = 10;
		nameSound = "handgrenade";
		maxLeadSpeed = 7;
	};
};


class CfgWeapons 
{
	class Default;
	class GrenadeLauncher: Default {};
	class Throw: GrenadeLauncher
	{
		muzzles[] += {"Dr_HG_Muzzle"};
		class ThrowMuzzle;
		class Dr_HG_Muzzle: ThrowMuzzle
		{
			magazines[] = {"Dr_HolyGrenade"};
		};
	};
};

class CfgFunctions
{
	class Dr
	{
		class HolyGrenade {
			class init {
				file = "Dr_item_HolyGrenade\sqf\fn_init.sqf";
				postInit = 1;
			};
			class throwHolyGrenade {
				file = "Dr_item_HolyGrenade\sqf\fn_throwHolyGrenade.sqf";
			};
		};
	};
};

/*class cfgRemoteExec {
	class Commands
	{
		class say3D
		{
			allowedTargets = 0;
			jip = 0;
		};
		class setParticleParams : say3D {};
		class setParticleRandom : say3D {};
		class setParticleCircle : say3D {};
		class setDropInterval : say3D {};
		class setLightColor : say3D {};
		class setLightAmbient : say3D {};
		class setLightIntensity : say3D {};
		class setLightUseFlare : say3D {};
		class setLightFlareSize : say3D {};
		class setLightFlareMaxDistance : say3D {};
		class setLightDayLight : say3D {};
		class setLightAttenuation : say3D {};
	};
};*/