_mag 	= _this # 5;
_proj 	= _this # 6;

if !(_mag == "Dr_HolyGrenade") exitWith {};
[player,selectRandom ["Dr_hallelujah_man_1","Dr_hallelujah_man_2","Dr_hallelujah_man_3"]] remoteExec ["say3D",0];
[] spawn {
	player setRandomLip true;
	UISleep 1;
	player setRandomLip false;
};
UiSleep 2.62;
_pos = getPos _proj;
_particles = "#particlesource" createVehicle _pos;
_particles setPos _pos;
[_particles,[["\A3\data_f\ParticleEffects\Universal\Universal.p3d",16,12,13,0],"","Billboard",1,4,[0,0,0],[0,0,0.05],12,11,8.63,0,[0.7,0.7,0.7,0.7],[[1,1,1,0],[1,1,1,1],[1,1,1,0.512711],[1,1,1,0]],[1000,1000,1000,1000],1,0,"","",_proj,1,false,-1,[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]]] remoteExec ["setParticleParams",0];
[_particles,[0,[-1,-1,0],[0,0,0],50,0,[0,0,0,0],0,0,90,0]] remoteExec ["setParticleRandom",0];
[_particles,[3,[0,0,0]]] remoteExec ["setParticleCircle",0];
[_particles,0.01] remoteExec ["setDropInterval",0];
_particles attachTo [_proj];

_pos set [2,(_pos # 2) + 10];
_lighting = "#lightpoint" createVehicle _pos;
_lighting setPos _pos;

[_lighting,[1,1,1]] remoteExec ["setLightColor",0];
[_lighting,[0,0,0]] remoteExec ["setLightAmbient",0];
[_lighting,20000] remoteExec ["setLightIntensity",0];
[_lighting,true] remoteExec ["setLightUseFlare",0];
[_lighting,10] remoteExec ["setLightFlareSize",0];
[_lighting,200] remoteExec ["setLightFlareMaxDistance",0];
[_lighting,true] remoteExec ["setLightDayLight",0];
[_lighting,[5,50,1,1,10000,20000]] remoteExec ["setLightAttenuation",0];
//_lighting attachTo [_proj];

[_proj,"Dr_angelsSinging"] remoteExec ["say3D",0];
UiSleep 5;
deleteVehicle _particles;
waitUntil {!alive _proj};
deleteVehicle _lighting;