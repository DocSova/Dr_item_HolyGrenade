[] spawn {
	waitUntil {!isNull player};
	player addEventHandler ["Fired",{_this spawn Dr_fnc_throwHolyGrenade}];
	player addEventHandler ["Respawn",{player addEventHandler ["Fired",{_this spawn Dr_fnc_throwHolyGrenade}]}];
};