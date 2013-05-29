PHP_FUNCTION(SetSpawnInfo)
{
    int playerid, team, skin, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo;
    double x, y, z, rotation;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lllddddllllll", &playerid, &team, &skin, &x, &y, &z, &rotation, &weapon1, &weapon1_ammo, &weapon2, &weapon2_ammo, &weapon3, &weapon3_ammo) == FAILURE)
    {
        RETURN_NULL();
    }

    SetSpawnInfo(playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

PHP_FUNCTION(SpawnPlayer)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    SpawnPlayer(playerid);
}

PHP_FUNCTION(SetPlayerPos)
{
	int playerId;
	double x, y, z;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &playerId, &x, &y, &z) == FAILURE)
	{
        RETURN_NULL();
    }

    SetPlayerPos(playerId, x, y, z);
}

PHP_FUNCTION(SetPlayerPosFindZ)
{
    int playerid;
    double x, y, z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &playerid, &x, &y, &z) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerPosFindZ(playerid, x, y, z);
}

PHP_FUNCTION(GetPlayerPos)
{
    int playerid;
    float x, y, z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerPos(playerid, &x, &y, &z);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(SetPlayerFacingAngle)
{
    int playerId;
    double angle;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ld", &playerId, &angle) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerFacingAngle(playerId, angle);
}

PHP_FUNCTION(GetPlayerFacingAngle)
{
    int playerid;
    float ang;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerFacingAngle(playerid, &ang);

    RETVAL_DOUBLE(ang);
}

PHP_FUNCTION(IsPlayerInRangeOfPoint)
{
    int playerid;
    double range, x, y, z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ldddd", &playerid, &range, &x, &y, &z) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsPlayerInRangeOfPoint(playerid, range, x, y, z));
}

PHP_FUNCTION(GetPlayerDistanceFromPoint)
{
    int playerid;
    double X, Y, Z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &playerid, &X, &Y, &Z) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_DOUBLE(GetPlayerDistanceFromPoint(playerid, X, Y, Z));
}

PHP_FUNCTION(IsPlayerStreamedIn)
{
    int playerid, forplayerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &forplayerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsPlayerStreamedIn(playerid, forplayerid));
}

PHP_FUNCTION(SetPlayerInterior)
{
    int playerId, interiorId;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerId, &interiorId) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerInterior(playerId, interiorId);
}

PHP_FUNCTION(GetPlayerInterior)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerInterior(playerid));
}

PHP_FUNCTION(SetPlayerHealth)
{
    int playerid;
    double health;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ld", &playerid, &health) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerHealth(playerid, health);
}

PHP_FUNCTION(GetPlayerHealth)
{
    int playerid;
    float health;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerHealth(playerid, &health);

    RETVAL_DOUBLE(health);
}

PHP_FUNCTION(SetPlayerArmour)
{
    int playerid;
    double armour;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ld", &playerid, &armour) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerArmour(playerid, armour);
}

PHP_FUNCTION(GetPlayerArmour)
{
    int playerid;
    float armour;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerArmour(playerid, &armour);

    RETVAL_DOUBLE(armour);
}

PHP_FUNCTION(SetPlayerAmmo)
{
    int playerid, weaponslot, ammo;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &weaponslot, &ammo) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerAmmo(playerid, weaponslot, ammo);
}

PHP_FUNCTION(GetPlayerAmmo)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerAmmo(playerid));
}

PHP_FUNCTION(GetPlayerWeaponState)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerWeaponState(playerid));
}

PHP_FUNCTION(GetPlayerTargetPlayer)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerTargetPlayer(playerid));
}

PHP_FUNCTION(SetPlayerTeam)
{
    int playerid, teamid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &teamid) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerTeam(playerid, teamid);
}

PHP_FUNCTION(GetPlayerTeam)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerTeam(playerid));
}

PHP_FUNCTION(SetPlayerScore)
{
    int playerId, score;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "ll", &playerId, &score) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerScore(playerId, score);
}

PHP_FUNCTION(GetPlayerScore)
{
	int playerId;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "l", &playerId) == FAILURE)
	{
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerScore(playerId));
}

PHP_FUNCTION(GetPlayerDrunkLevel)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerDrunkLevel(playerid));
}

PHP_FUNCTION(SetPlayerDrunkLevel)
{
    int playerid, level;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &level) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerDrunkLevel(playerid, level);
}

PHP_FUNCTION(SetPlayerColor)
{
    int playerid, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerColor(playerid, color);
}

PHP_FUNCTION(GetPlayerColor)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerColor(playerid));
}

PHP_FUNCTION(SetPlayerSkin)
{
    int playerid, skinid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &skinid) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerSkin(playerid, skinid);
}

PHP_FUNCTION(GetPlayerSkin)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerSkin(playerid));
}

PHP_FUNCTION(GivePlayerWeapon)
{
    int playerid, weaponid, ammo;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &weaponid, &ammo) == FAILURE)
    {
        RETURN_NULL();
    }

    GivePlayerWeapon(playerid, weaponid, ammo);
}

PHP_FUNCTION(ResetPlayerWeapons)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    ResetPlayerWeapons(playerid);
}

PHP_FUNCTION(SetPlayerArmedWeapon)
{
    int playerid, weaponid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &weaponid) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerArmedWeapon(playerid, weaponid);
}

PHP_FUNCTION(GetPlayerWeaponData)
{
    int playerid, slot, weapons, ammo;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &slot) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerWeaponData(playerid, slot, &weapons, &ammo);

    array_init(return_value);
    add_assoc_long(return_value, "weapons", weapons);
    add_assoc_long(return_value, "ammo", ammo);
}

PHP_FUNCTION(GetPlayerMoney)
{
	int playerId;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "l", &playerId) == FAILURE)
	{
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerMoney(playerId));
}

PHP_FUNCTION(GivePlayerMoney)
{
	int playerId, amount;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "ll", &playerId, &amount) == FAILURE)
	{
        RETURN_NULL();
    }

    GivePlayerMoney(playerId, amount);
}

PHP_FUNCTION(ResetPlayerMoney)
{
	int playerId;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "l", &playerId) == FAILURE)
	{
        RETURN_NULL();
    }

    ResetPlayerMoney(playerId);
}

PHP_FUNCTION(SetPlayerName)
{
    int playerid, name_len;
    char *name;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ls", &playerid, &name, &name_len) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerName(playerid, name);
}

PHP_FUNCTION(GetPlayerState)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerState(playerid));
}

PHP_FUNCTION(GetPlayerIp)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }


    const int buffer_len = 50;
    char buffer[buffer_len];

    GetPlayerIp(playerid, buffer, buffer_len);

    RETVAL_STRING(buffer, buffer_len);
}

PHP_FUNCTION(GetPlayerPing)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerPing(playerid));
}

PHP_FUNCTION(GetPlayerWeapon)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerWeapon(playerid));
}

PHP_FUNCTION(GetPlayerKeys)
{
    int playerid, keys, updown, leftright;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerKeys(playerid, &keys, &updown, &leftright);

    array_init(return_value);
    add_assoc_long(return_value, "keys", keys);
    add_assoc_long(return_value, "updown", updown);
    add_assoc_long(return_value, "leftright", leftright);
}

PHP_FUNCTION(GetPlayerName)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    const int buffer_len = 50;
    char buffer[buffer_len];

    GetPlayerName(playerid, buffer, buffer_len);

    RETVAL_STRING(buffer, buffer_len);
}

PHP_FUNCTION(SetPlayerTime)
{
    int playerid, hour, minute;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &hour, &minute) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerTime(playerid, hour, minute);
}

PHP_FUNCTION(GetPlayerTime)
{
    int playerid, hour, minute;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerTime(playerid, &hour, &minute);

    array_init(return_value);
    add_assoc_long(return_value, "hour", hour);
    add_assoc_long(return_value, "minute", minute);
}

PHP_FUNCTION(TogglePlayerClock)
{
	int playerId, toggle;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "ll", &playerId, &toggle) == FAILURE)
	{
        RETURN_NULL();
    }

    TogglePlayerClock(playerId, toggle);
}

PHP_FUNCTION(SetPlayerWeather)
{
    int playerid, weather;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &weather) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerWeather(playerid, weather);
}

PHP_FUNCTION(ForceClassSelection)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    ForceClassSelection(playerid);
}

PHP_FUNCTION(SetPlayerWantedLevel)
{
    int playerid, level;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &level) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerWantedLevel(playerid, level);
}

PHP_FUNCTION(GetPlayerWantedLevel)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerWantedLevel(playerid));
}

PHP_FUNCTION(SetPlayerFightingStyle)
{
    int playerid, style;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &style) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerFightingStyle(playerid, style);
}

PHP_FUNCTION(GetPlayerFightingStyle)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerFightingStyle(playerid));
}

PHP_FUNCTION(SetPlayerVelocity)
{
    int playerid;
    double X, Y, Z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &playerid, &X, &Y, &Z) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerVelocity(playerid, X, Y, Z);
}

PHP_FUNCTION(GetPlayerVelocity)
{
    int playerid;
    float x, y, z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerVelocity(playerid, &x, &y, &z);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(PlayCrimeReportForPlayer)
{
    int playerid, suspectid, crime;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &suspectid, &crime) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayCrimeReportForPlayer(playerid, suspectid, crime);
}

PHP_FUNCTION(PlayAudioStreamForPlayer)
{
    int playerid, url_len;
    char *url;
    double posX = 0.0, posY = 0.0, posZ = 0.0, distance = 50.0;
    bool usepos;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ls|ddddb", &playerid, &url, &url_len, &posX, &posY, &posZ, &distance, &usepos) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayAudioStreamForPlayer(playerid, url, posX, posY, posZ, distance, usepos);
}


PHP_FUNCTION(StopAudioStreamForPlayer)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    StopAudioStreamForPlayer(playerid);
}

PHP_FUNCTION(SetPlayerShopName)
{
    int playerid, shopname_len;
    char *shopname;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ls", &playerid, &shopname, &shopname_len) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerShopName(playerid, shopname);
}

PHP_FUNCTION(SetPlayerSkillLevel)
{
    int playerid, skill, level;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &skill, &level) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerSkillLevel(playerid, skill, level);
}

PHP_FUNCTION(GetPlayerSurfingVehicleID)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerSurfingVehicleID(playerid));
}

PHP_FUNCTION(GetPlayerSurfingObjectID)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerSurfingObjectID(playerid));
}

PHP_FUNCTION(RemoveBuildingForPlayer)
{
    int playerid, modelid;
    double fX, fY, fZ, fRadius;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lldddd", &playerid, &modelid, &fX, &fY, &fZ, &fRadius) == FAILURE)
    {
        RETURN_NULL();
    }

    RemoveBuildingForPlayer(playerid, modelid, fX, fY, fZ, fRadius);
}

PHP_FUNCTION(SetPlayerAttachedObject)
{
    int playerid, index, modelid, bone, materialcolor1 = 0, materialcolor2 = 0;
    double fOffsetX = 0.0, fOffsetY = 0.0, fOffsetZ = 0.0, fRotX = 0.0, fRotY = 0.0, fRotZ = 0.0, fScaleX = 1.0, fScaleY = 1.0, fScaleZ = 1.0;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llll|dddddddddll", &playerid, &index, &modelid, &bone, &fOffsetX, &fOffsetY, &fOffsetZ, &fRotX, &fRotY, &fRotZ, &fScaleX, &fScaleY, &fScaleZ, &materialcolor1, &materialcolor2) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerAttachedObject(playerid, index, modelid, bone, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ, materialcolor1, materialcolor2);
}

PHP_FUNCTION(RemovePlayerAttachedObject)
{
    int playerid, index;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &index) == FAILURE)
    {
        RETURN_NULL();
    }

    RemovePlayerAttachedObject(playerid, index);
}

PHP_FUNCTION(IsPlayerAttachedObjectSlotUsed)
{
    int playerid, index;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &index) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsPlayerAttachedObjectSlotUsed(playerid, index));
}

PHP_FUNCTION(EditAttachedObject)
{
    int playerid, index;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &index) == FAILURE)
    {
        RETURN_NULL();
    }

    EditAttachedObject(playerid, index);
}

// Per-player TextDraws
PHP_FUNCTION(CreatePlayerTextDraw)
{
    int playerid, text_len;
    double x, y;
    char *text;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ldds", &playerid, &x, &y, &text, &text_len) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(CreatePlayerTextDraw(playerid, x, y, text));
}

PHP_FUNCTION(PlayerTextDrawDestroy)
{
    int playerid, textid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &textid) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawDestroy(playerid, textid);
}

PHP_FUNCTION(PlayerTextDrawLetterSize)
{
    int playerid, textid;
    double x, y;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lldd", &playerid, &textid, &x, &y) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawLetterSize(playerid, textid, x, y);
}

PHP_FUNCTION(PlayerTextDrawTextSize)
{
    int playerid, textid;
    double x, y;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lldd", &playerid, &textid, &x, &y) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawTextSize(playerid, textid, x, y);
}

PHP_FUNCTION(PlayerTextDrawAlignment)
{
    int playerid, textid, alignment;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &alignment) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawAlignment(playerid, textid, alignment);
}

PHP_FUNCTION(PlayerTextDrawColor)
{
    int playerid, textid, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawColor(playerid, textid, color);
}

PHP_FUNCTION(PlayerTextDrawUseBox)
{
    int playerid, textid, use;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &use) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawUseBox(playerid, textid, use);
}

PHP_FUNCTION(PlayerTextDrawBoxColor)
{
    int playerid, textid, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawBoxColor(playerid, textid, color);
}

PHP_FUNCTION(PlayerTextDrawSetShadow)
{
    int playerid, textid, size;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &size) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawSetShadow(playerid, textid, size);
}

PHP_FUNCTION(PlayerTextDrawSetOutline)
{
    int playerid, textid, size;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &size) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawSetOutline(playerid, textid, size);
}

PHP_FUNCTION(PlayerTextDrawBackgroundColor)
{
    int playerid, textid, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawBackgroundColor(playerid, textid, color);
}

PHP_FUNCTION(PlayerTextDrawFont)
{
    int playerid, textid, font;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &font) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawFont(playerid, textid, font);
}

PHP_FUNCTION(PlayerTextDrawSetProportional)
{
    int playerid, textid, set;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &set) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawSetProportional(playerid, textid, set);
}

PHP_FUNCTION(PlayerTextDrawSetSelectable)
{
    int playerid, textid, set;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &set) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawSetSelectable(playerid, textid, set);
}

PHP_FUNCTION(PlayerTextDrawShow)
{
    int playerid, textid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &textid) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawShow(playerid, textid);
}

PHP_FUNCTION(PlayerTextDrawHide)
{
    int playerid, textid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &textid) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawHide(playerid, textid);
}

PHP_FUNCTION(PlayerTextDrawSetString)
{
    int playerid, textid, string_len;
    char *string;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lls", &playerid, &textid, &string, &string_len) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawSetString(playerid, textid, string);
}

PHP_FUNCTION(PlayerTextDrawSetPreviewModel)
{
    int playerid, textid, modelindex;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &textid, &modelindex) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawSetPreviewModel(playerid, textid, modelindex);
}

PHP_FUNCTION(PlayerTextDrawSetPreviewRot)
{
    int playerid, textid;
    double fRotX, fRotY, fRotZ, fZoom = 1.0;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddd|d", &playerid, &textid, &fRotX, &fRotY, &fRotZ, &fZoom) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawSetPreviewRot(playerid, textid, fRotX, fRotY, fRotZ, fZoom);
}

PHP_FUNCTION(PlayerTextDrawSetPreviewVehCol)
{
    int playerid, textid, color1, color2;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llll", &playerid, &textid, &color1, &color2) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerTextDrawSetPreviewVehCol(playerid, textid, color1, color2);
}

PHP_FUNCTION(SetPlayerChatBubble)
{
    int playerid, text_len, color, expiretime;
    char *text;
    double drawdistance;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lsldl", &playerid, &text, &text_len, &color, &drawdistance, &expiretime) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerChatBubble(playerid, text, color, drawdistance, expiretime);
}

// Player controls
PHP_FUNCTION(PutPlayerInVehicle)
{
    int playerid, vehicleid, seatid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &vehicleid, &seatid) == FAILURE)
    {
        RETURN_NULL();
    }

    PutPlayerInVehicle(playerid, vehicleid, seatid);
}

PHP_FUNCTION(GetPlayerVehicleID)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerVehicleID(playerid));
}

PHP_FUNCTION(GetPlayerVehicleSeat)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerVehicleSeat(playerid));
}

PHP_FUNCTION(RemovePlayerFromVehicle)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RemovePlayerFromVehicle(playerid);
}

PHP_FUNCTION(TogglePlayerControllable)
{
    int playerid, toggle;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &toggle) == FAILURE)
    {
        RETURN_NULL();
    }

    TogglePlayerControllable(playerid, toggle);
}

PHP_FUNCTION(PlayerPlaySound)
{
    int playerid, soundid;
    double x, y, z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddd", &playerid, &soundid, &x, &y, &z) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerPlaySound(playerid, soundid, x, y, z);
}

PHP_FUNCTION(ApplyAnimation)
{
    int playerid, animlib_len, animname_len, loop, lockx, locky, freeze, time, forcesync = 0;
    char *animlib, *animname;
    double fDelta;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lssdllllll", &playerid, &animlib, &animlib_len, &animname, &animname_len, &fDelta, &loop, &lockx, &locky, &freeze, &time, &forcesync) == FAILURE)
    {
        RETURN_NULL();
    }

    ApplyAnimation(playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);
}

PHP_FUNCTION(ClearAnimations)
{
    int playerid, forcesync = 0;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &forcesync) == FAILURE)
    {
        RETURN_NULL();
    }

    ClearAnimations(playerid, forcesync);
}

PHP_FUNCTION(GetPlayerAnimationIndex)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerAnimationIndex(playerid));
}

PHP_FUNCTION(GetAnimationName)
{
    int index;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &index) == FAILURE)
    {
        RETURN_NULL();
    }

    const int buffer_lib_len = 50;
    char buffer_lib[buffer_lib_len];
    const int buffer_name_len = 50;
    char buffer_name[buffer_lib_len];

    GetAnimationName(index, buffer_lib, buffer_lib_len, buffer_name, buffer_name_len);

    array_init(return_value);
    add_assoc_string(return_value, "lib", buffer_lib, buffer_lib_len);
    add_assoc_string(return_value, "name", buffer_name, buffer_name_len);
}

PHP_FUNCTION(GetPlayerSpecialAction)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerSpecialAction(playerid));
}

PHP_FUNCTION(SetPlayerSpecialAction)
{
    int playerid, actionid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &actionid) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerSpecialAction(playerid, actionid);
}

PHP_FUNCTION(SetPlayerCheckpoint)
{
    int playerid;
    double x, y, z, size;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ldddd", &playerid, &x, &y, &z, &size) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerCheckpoint(playerid, x, y, z, size);
}

PHP_FUNCTION(DisablePlayerCheckpoint)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    DisablePlayerCheckpoint(playerid);
}

PHP_FUNCTION(SetPlayerRaceCheckpoint)
{
    int playerid, type;
    double x, y, z, nextx, nexty, nextz, size;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddddddd", &playerid, &type, &x, &y, &z, &nextx, &nexty, &nextz, &size) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerRaceCheckpoint(playerid, type, x, y, z, nextx, nexty, nextz, size);
}

PHP_FUNCTION(DisablePlayerRaceCheckpoint)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    DisablePlayerRaceCheckpoint(playerid);
}

PHP_FUNCTION(SetPlayerWorldBounds)
{
    int playerid;
    double x_max, x_min, y_max, y_min;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ldddd", &playerid, &x_max, &x_min, &y_max, &y_min) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerWorldBounds(playerid, x_max, x_min, y_max, y_min);
}

PHP_FUNCTION(SetPlayerMarkerForPlayer)
{
    int playerid, showplayerid, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &showplayerid, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerMarkerForPlayer(playerid, showplayerid, color);
}

PHP_FUNCTION(ShowPlayerNameTagForPlayer)
{
    int playerid, showplayerid, show;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &showplayerid, &show) == FAILURE)
    {
        RETURN_NULL();
    }

    ShowPlayerNameTagForPlayer(playerid, showplayerid, show);
}

PHP_FUNCTION(SetPlayerMapIcon)
{
    int playerid, iconid, markertype, color, style = MAPICON_LOCAL;
    double x, y, z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lldddlll", &playerid, &iconid, &x, &y, &z, &markertype, &color, &style) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerMapIcon(playerid, iconid, x, y, z, markertype, color, style);
}

PHP_FUNCTION(RemovePlayerMapIcon)
{
    int playerid, iconid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &iconid) == FAILURE)
    {
        RETURN_NULL();
    }

    RemovePlayerMapIcon(playerid, iconid);
}

PHP_FUNCTION(AllowPlayerTeleport)
{
    int playerid, allow;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &allow) == FAILURE)
    {
        RETURN_NULL();
    }

    AllowPlayerTeleport(playerid, allow);
}

// Camera
PHP_FUNCTION(SetPlayerCameraPos)
{
    int playerId;
    double x, y, z;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &playerId, &x, &y, &z) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerCameraPos(playerId, x, y, z);
}

PHP_FUNCTION(SetPlayerCameraLookAt)
{
    int playerId, style;
    double x, y, z;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                         "ldddl", &playerId, &x, &y, &z, &style) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerCameraLookAt(playerId, x, y, z, style);
}

PHP_FUNCTION(SetCameraBehindPlayer)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    SetCameraBehindPlayer(playerid);
}

PHP_FUNCTION(GetPlayerCameraPos)
{
    int playerid;
    float x, y, z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerCameraPos(playerid, &x, &y, &z);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(GetPlayerCameraFrontVector)
{
    int playerid;
    float x, y, z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerCameraFrontVector(playerid, &x, &y, &z);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(GetPlayerCameraMode)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerCameraMode(playerid));
}

PHP_FUNCTION(AttachCameraToObject)
{
    int playerid, objectid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &objectid) == FAILURE)
    {
        RETURN_NULL();
    }

    AttachCameraToObject(playerid, objectid);
}

PHP_FUNCTION(AttachCameraToPlayerObject)
{
    int playerid, playerobjectid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &playerobjectid) == FAILURE)
    {
        RETURN_NULL();
    }

    AttachCameraToPlayerObject(playerid, playerobjectid);
}

PHP_FUNCTION(InterpolateCameraPos)
{
    int playerid, time, cut = CAMERA_CUT;
    double FromX, FromY, FromZ, ToX, ToY, ToZ;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddddddl|l", &playerid, &FromX, &FromY, &FromZ, &ToX, &ToY, &ToZ, &time, &cut) == FAILURE)
    {
        RETURN_NULL();
    }

    InterpolateCameraPos(playerid, FromX, FromY, FromZ, ToX, ToY, ToZ, time, cut);
}

PHP_FUNCTION(InterpolateCameraLookAt)
{
    int playerid, time, cut = CAMERA_CUT;
    double FromX, FromY, FromZ, ToX, ToY, ToZ;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddddddl|l", &playerid, &FromX, &FromY, &FromZ, &ToX, &ToY, &ToZ, &time, &cut) == FAILURE)
    {
        RETURN_NULL();
    }

    InterpolateCameraLookAt(playerid, FromX, FromY, FromZ, ToX, ToY, ToZ, time, cut);
}

// Player conditionals
PHP_FUNCTION(IsPlayerConnected)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsPlayerConnected(playerid));
}

PHP_FUNCTION(IsPlayerInVehicle)
{
    int playerid, vehicleid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &vehicleid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsPlayerInVehicle(playerid, vehicleid));
}

PHP_FUNCTION(IsPlayerInAnyVehicle)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsPlayerInAnyVehicle(playerid));
}

PHP_FUNCTION(IsPlayerInCheckpoint)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsPlayerInCheckpoint(playerid));
}

PHP_FUNCTION(IsPlayerInRaceCheckpoint)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsPlayerInRaceCheckpoint(playerid));
}

PHP_FUNCTION(SetPlayerVirtualWorld)
{
    int playerid, worldid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &worldid) == FAILURE)
    {
        RETURN_NULL();
    }

    SetPlayerVirtualWorld(playerid, worldid);
}

PHP_FUNCTION(GetPlayerVirtualWorld)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerVirtualWorld(playerid));
}

// Spectating
PHP_FUNCTION(TogglePlayerSpectating)
{
    int playerid, toggle;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &toggle) == FAILURE)
    {
        RETURN_NULL();
    }

    TogglePlayerSpectating(playerid, toggle);
}

PHP_FUNCTION(PlayerSpectatePlayer)
{
    int playerid, targetplayerid, mode = SPECTATE_MODE_NORMAL;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll|l", &playerid, &targetplayerid, &mode) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerSpectatePlayer(playerid, targetplayerid, mode);
}

PHP_FUNCTION(PlayerSpectateVehicle)
{
    int playerid, targetvehicleid, mode = SPECTATE_MODE_NORMAL;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll|l", &playerid, &targetvehicleid, &mode) == FAILURE)
    {
        RETURN_NULL();
    }

    PlayerSpectateVehicle(playerid, targetvehicleid, mode);
}

// Recording for NPC playback
PHP_FUNCTION(StartRecordingPlayerData)
{
    int playerid, recordtype, recordname_len;
    char *recordname;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lls", &playerid, &recordtype, &recordname, &recordname_len) == FAILURE)
    {
        RETURN_NULL();
    }

    StartRecordingPlayerData(playerid, recordtype, recordname);
}

PHP_FUNCTION(StopRecordingPlayerData)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    StopRecordingPlayerData(playerid);
}

// Mouse control
PHP_FUNCTION(SelectTextDraw)
{
    int playerid, hovercolor;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &hovercolor) == FAILURE)
    {
        RETURN_NULL();
    }

    SelectTextDraw(playerid, hovercolor);
}

PHP_FUNCTION(CancelSelectTextDraw)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    CancelSelectTextDraw(playerid);
}