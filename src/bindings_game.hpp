
PHP_FUNCTION(SetGameModeText)
{
	char *buffer;
	int buffer_len;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "s", &buffer, &buffer_len) == FAILURE)
	{
        RETURN_NULL();
    }

    SetGameModeText(buffer);
}

PHP_FUNCTION(SetTeamCount)
{
    int count;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &count) == FAILURE)
    {
        RETURN_NULL();
    }

    SetTeamCount(count);
}

PHP_FUNCTION(AddPlayerClass)
{
	int skin, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo;
	double x, y, z, angle;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddddllllll", &skin, &x, &y, &z, &angle, &weapon1, &weapon1_ammo, &weapon2, &weapon2_ammo, &weapon3, &weapon3_ammo) == FAILURE)
	{
        RETURN_NULL();
    }

    AddPlayerClass(skin, x, y, z, angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

PHP_FUNCTION(AddPlayerClassEx)
{
    int teamid, modelid, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo;
    double spawn_x, spawn_y, spawn_z, z_angle;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddddllllll", &teamid, &modelid, &spawn_x, &spawn_y, &spawn_z, &z_angle, &weapon1, &weapon1_ammo, &weapon2, &weapon2_ammo, &weapon3, &weapon3_ammo) == FAILURE)
    {
        RETURN_NULL();
    }

    AddPlayerClassEx(teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

PHP_FUNCTION(AddStaticVehicle)
{
	int modelId, color1, color2;
	double x, y, z, angle;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddddll", &modelId, &x, &y, &z, &angle, &color1, &color2) == FAILURE)
	{
        RETURN_NULL();
    }

    int result = AddStaticVehicle(modelId, x, y, z, angle, color1, color2);
    
    RETVAL_LONG(result);
}

PHP_FUNCTION(AddStaticVehicleEx)
{
    int modelid, color1, color2, respawn_delay;
    double spawn_x, spawn_y, spawn_z, z_angle;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddddlll", &modelid, &spawn_x, &spawn_y, &spawn_z, &z_angle, &color1, &color2, &respawn_delay) == FAILURE)
    {
        RETURN_NULL();
    }

    AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay);
}

PHP_FUNCTION(AddStaticPickup)
{
	int modelId, type, virtualWorld = 0;
	double x, y, z, angle;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddd|l", &modelId, &type, &x, &y, &z, &virtualWorld) == FAILURE)
	{
        RETURN_NULL();
    }

    int result = AddStaticPickup(modelId, type, x, y, z, virtualWorld);

    RETVAL_LONG(result);
}

PHP_FUNCTION(CreatePickup)
{
    int model, type, virtualworld = 0;
    double X, Y, Z;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddd|l", &model, &type, &X, &Y, &Z, &virtualworld) == FAILURE)
    {
        RETURN_NULL();
    }

    int ret = CreatePickup(model, type, X, Y, Z, virtualworld);

    RETVAL_LONG(ret);
}

PHP_FUNCTION(DestroyPickup)
{
    int pickup;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &pickup) == FAILURE)
    {
        RETURN_NULL();
    }

    DestroyPickup(pickup);
}

PHP_FUNCTION(ShowNameTags)
{
	int buffer;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &buffer) == FAILURE)
	{
        RETURN_NULL();
    }

    ShowNameTags(buffer);
}

PHP_FUNCTION(ShowPlayerMarkers)
{
	int buffer;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &buffer) == FAILURE)
	{
        RETURN_NULL();
    }

    ShowPlayerMarkers(buffer);
}

PHP_FUNCTION(GameModeExit)
{
    GameModeExit();
}

PHP_FUNCTION(SetWorldTime)
{
    int hour;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &hour) == FAILURE)
    {
        RETURN_NULL();
    }

    SetWorldTime(hour);
}

PHP_FUNCTION(GetWeaponName)
{
    int weaponid;
    char weapon[50];
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &weaponid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetWeaponName(weaponid, weapon, 50);

    RETVAL_STRING(weapon, 50);
}

PHP_FUNCTION(EnableTirePopping)
{
    bool enable;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "b", &enable) == FAILURE)
    {
        RETURN_NULL();
    }

    EnableTirePopping(enable);
}

PHP_FUNCTION(EnableVehicleFriendlyFire)
{
    EnableVehicleFriendlyFire();
}

PHP_FUNCTION(AllowInteriorWeapons)
{
    bool allow;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "b", &allow) == FAILURE)
    {
        RETURN_NULL();
    }

    AllowInteriorWeapons(allow);
}

PHP_FUNCTION(SetWeather)
{
    int weatherid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &weatherid) == FAILURE)
    {
        RETURN_NULL();
    }

    SetWeather(weatherid);
}

PHP_FUNCTION(SetGravity)
{
    double gravity;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "d", &gravity) == FAILURE)
    {
        RETURN_NULL();
    }

    SetGravity(gravity);
}

PHP_FUNCTION(AllowAdminTeleport)
{
    bool allow;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "b", &allow) == FAILURE)
    {
        RETURN_NULL();
    }

    AllowAdminTeleport(allow);
}

PHP_FUNCTION(SetDeathDropAmount)
{
    int amount;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &amount) == FAILURE)
    {
        RETURN_NULL();
    }

    SetDeathDropAmount(amount);
}

PHP_FUNCTION(CreateExplosion)
{
    double X, Y, Z, Radius;
    int type;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "dddld", &X, &Y, &Z, &type, &Radius) == FAILURE)
    {
        RETURN_NULL();
    }

    CreateExplosion(X, Y, Z, type, Radius);
}

PHP_FUNCTION(EnableZoneNames)
{
    bool enable;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "b", &enable) == FAILURE)
    {
        RETURN_NULL();
    }

    EnableZoneNames(enable);
}

PHP_FUNCTION(UsePlayerPedAnims)
{
    UsePlayerPedAnims();
}

PHP_FUNCTION(DisableInteriorEnterExits)
{
    DisableInteriorEnterExits();
}

PHP_FUNCTION(SetNameTagDrawDistance)
{
    double distance;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "d", &distance) == FAILURE)
    {
        RETURN_NULL();
    }

    SetNameTagDrawDistance(distance);
}

PHP_FUNCTION(DisableNameTagLOS)
{
    DisableNameTagLOS();
}

PHP_FUNCTION(LimitGlobalChatRadius)
{
    double chat_radius;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "d", &chat_radius) == FAILURE)
    {
        RETURN_NULL();
    }

    LimitGlobalChatRadius(chat_radius);
}

PHP_FUNCTION(LimitPlayerMarkerRadius)
{
    double marker_radius;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "d", &marker_radius) == FAILURE)
    {
        RETURN_NULL();
    }

    LimitPlayerMarkerRadius(marker_radius);
}

PHP_FUNCTION(EnableStuntBonusForAll)
{
	int buffer;
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &buffer) == FAILURE)
	{
        RETURN_NULL();
    }

    EnableStuntBonusForAll(buffer);
}

PHP_FUNCTION(EnableStuntBonusForPlayer)
{
    int playerid;
    bool enable;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lb", &playerid, &enable) == FAILURE)
    {
        RETURN_NULL();
    }

    EnableStuntBonusForPlayer(playerid, enable);
}

// NPC
PHP_FUNCTION(ConnectNPC)
{
    char *name, *script;
    int name_len, script_len;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ss", &name, &name_len, &script, &script_len) == FAILURE)
    {
        RETURN_NULL();
    }

    ConnectNPC(name, script);
}

PHP_FUNCTION(IsPlayerNPC)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    bool result = IsPlayerNPC(playerid);

    RETVAL_BOOL(result);
}

// Admin
PHP_FUNCTION(IsPlayerAdmin)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsPlayerAdmin(playerid));
}

PHP_FUNCTION(Kick)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    Kick(playerid);
}

PHP_FUNCTION(Ban)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    Ban(playerid);
}

PHP_FUNCTION(BanEx)
{
    int playerid, reason_len;
    char *reason;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ls", &playerid, &reason, &reason_len) == FAILURE)
    {
        RETURN_NULL();
    }

    BanEx(playerid, reason);
}

PHP_FUNCTION(SendRconCommand)
{
    char *command;
    int command_len;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "s", &command, &command_len) == FAILURE)
    {
        RETURN_NULL();
    }

    SendRconCommand(command);
}

PHP_FUNCTION(GetServerVar)
{
    char *varname;
    int varname_len;

    char buffer[100];
    int buffer_len = 100; 
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "s", &varname, &varname_len) == FAILURE)
    {
        RETURN_NULL();
    }

    GetServerVarAsString(varname, buffer, buffer_len);
    RETVAL_STRING(buffer, buffer_len);
}

PHP_FUNCTION(GetServerVarAsString)
{
    char *varname;
    int varname_len;

    char buffer[100];
    int buffer_len = 100; 
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "s", &varname, &varname_len) == FAILURE)
    {
        RETURN_NULL();
    }

    GetServerVarAsString(varname, buffer, buffer_len);
    RETVAL_STRING(buffer, buffer_len);
}

PHP_FUNCTION(GetServerVarAsInt)
{
    char *varname;
    int varname_len;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "s", &varname, &varname_len) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetServerVarAsInt(varname));
}

PHP_FUNCTION(GetServerVarAsBool)
{
    char *varname;
    int varname_len;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "s", &varname, &varname_len) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(GetServerVarAsbool(varname));   // TODO GDK TYPO
}

PHP_FUNCTION(GetPlayerNetworkStats)
{
    int playerid;

    char buffer[200];
    int buffer_len = 200; 
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerNetworkStats(playerid, buffer, buffer_len);
    RETVAL_STRING(buffer, buffer_len);

}

PHP_FUNCTION(GetNetworkStats)
{
    char buffer[200];
    int buffer_len = 200; 
    

    GetNetworkStats(buffer, buffer_len);

    RETVAL_STRING(buffer, buffer_len);
}

PHP_FUNCTION(GetPlayerVersion)
{
    int playerid;

    char buffer[200];
    int buffer_len = 200; 
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l") == FAILURE)
    {
        RETURN_NULL();
    }

    GetPlayerVersion(playerid, buffer, buffer_len);

    RETVAL_STRING(buffer, buffer_len);
}

PHP_FUNCTION(CreateMenu)
{
    char *title;
    int title_len, columns;
    double x, y, col1width, col2width = 0.0;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "slddd|d", &title, &title_len, &columns, &x, &y, &col1width, &col2width) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(CreateMenu(title, columns, x, y, col1width, col2width));
}

PHP_FUNCTION(DestroyMenu)
{
    int menuid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &menuid) == FAILURE)
    {
        RETURN_NULL();
    }

    DestroyMenu(menuid);
}

PHP_FUNCTION(AddMenuItem)
{
    int menuid, column, menutext_len;
    char *menutext;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lls", &menuid, &column, &menutext, &menutext_len) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(AddMenuItem(menuid, column, menutext));
}

PHP_FUNCTION(SetMenuColumnHeader)
{
    int menuid, column, columnheader_len;
    char *columnheader;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lls", &menuid, &column, &columnheader, &columnheader_len) == FAILURE)
    {
        RETURN_NULL();
    }

    SetMenuColumnHeader(menuid, column, columnheader);
}

PHP_FUNCTION(ShowMenuForPlayer)
{
    int menuid, playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &menuid, &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    ShowMenuForPlayer(menuid, playerid);
}

PHP_FUNCTION(HideMenuForPlayer)
{
    int menuid, playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &menuid, &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    HideMenuForPlayer(menuid, playerid);
}

PHP_FUNCTION(IsValidMenu)
{
    int menuid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &menuid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_BOOL(IsValidMenu(menuid));
}

PHP_FUNCTION(DisableMenu)
{
    int menuid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &menuid) == FAILURE)
    {
        RETURN_NULL();
    }

    DisableMenu(menuid);
}

PHP_FUNCTION(DisableMenuRow)
{
    int menuid, row;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &menuid, &row) == FAILURE)
    {
        RETURN_NULL();
    }

    DisableMenuRow(menuid, row);
}

PHP_FUNCTION(GetPlayerMenu)
{
    int playerid;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GetPlayerMenu(playerid));
}

// Text Draw
PHP_FUNCTION(TextDrawCreate)
{
    double x, y;
    char *text;
    int text_len;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "dds", &x, &y, &text, &text_len) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(TextDrawCreate(x, y, text));
}

PHP_FUNCTION(TextDrawDestroy)
{
    int text;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &text) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawDestroy(text);
}

PHP_FUNCTION(TextDrawLetterSize)
{
    int text;
    double x, y;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ldd", &text, &x, &y) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawLetterSize(text, x, y);
}

PHP_FUNCTION(TextDrawTextSize)
{
    int text;
    double x, y;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ldd", &text, &x, &y) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawTextSize(text, x, y);
}

PHP_FUNCTION(TextDrawAlignment)
{
    int text, alignment;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &alignment) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawAlignment(text, alignment);
}

PHP_FUNCTION(TextDrawColor)
{
    int text, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawColor(text, color);
}

PHP_FUNCTION(TextDrawUseBox)
{
    int text, use;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &use) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawUseBox(text, use);
}

PHP_FUNCTION(TextDrawBoxColor)
{
    int text, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawBoxColor(text, color);
}

PHP_FUNCTION(TextDrawSetShadow)
{
    int text, size;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &size) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawSetShadow(text, size);
}

PHP_FUNCTION(TextDrawSetOutline)
{
    int text, size;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &size) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawSetOutline(text, size);
}

PHP_FUNCTION(TextDrawBackgroundColor)
{
    int text, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawBackgroundColor(text, color);
}

PHP_FUNCTION(TextDrawFont)
{
    int text, font;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &font) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawFont(text, font);
}

PHP_FUNCTION(TextDrawSetProportional)
{
    int text, set;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &set) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawSetProportional(text, set);
}

PHP_FUNCTION(TextDrawSetSelectable)
{
    int text, set;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &set) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawSetSelectable(text, set);
}

PHP_FUNCTION(TextDrawShowForPlayer)
{
    int playerid, text;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &text) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawShowForPlayer(playerid, text);
}

PHP_FUNCTION(TextDrawHideForPlayer)
{
    int playerid, text;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &text) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawHideForPlayer(playerid, text);
}

PHP_FUNCTION(TextDrawShowForAll)
{
    int text;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &text) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawShowForAll(text);
}

PHP_FUNCTION(TextDrawHideForAll)
{
    int text;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &text) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawHideForAll(text);
}

PHP_FUNCTION(TextDrawSetString)
{
    int text, string_len;
    char *string;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ls", &text, &string, &string_len) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawSetString(text, string);
}

PHP_FUNCTION(TextDrawSetPreviewModel)
{
    int text, modelindex;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &text, &modelindex) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawSetPreviewModel(text, modelindex);
}

PHP_FUNCTION(TextDrawSetPreviewRot)
{
    int text;
    double fRotX, fRotY, fRotZ, fZoom = 1.0;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ldddd", &text, &fRotX, &fRotY, &fRotZ, &fZoom) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawSetPreviewRot(text, fRotX, fRotY, fRotZ, fZoom);
}

PHP_FUNCTION(TextDrawSetPreviewVehCol)
{
    int text, color1, color2;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &text, &color1, &color2) == FAILURE)
    {
        RETURN_NULL();
    }

    TextDrawSetPreviewVehCol(text, color1, color2);
}

// Gangzones
PHP_FUNCTION(GangZoneCreate)
{
    double minx, miny, maxx, maxy;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "dddd", &minx, &miny, &maxx, &maxy) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(GangZoneCreate(minx, miny, maxx, maxy));
}

PHP_FUNCTION(GangZoneDestroy)
{
    int zone;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &zone) == FAILURE)
    {
        RETURN_NULL();
    }

    GangZoneDestroy(zone);
}

PHP_FUNCTION(GangZoneShowForPlayer)
{
    int playerid, zone, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &zone, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    GangZoneShowForPlayer(playerid, zone, color);
}

PHP_FUNCTION(GangZoneShowForAll)
{
    int zone, color;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &zone, &color) == FAILURE)
    {
        RETURN_NULL();
    }

    GangZoneShowForAll(zone, color);
}

PHP_FUNCTION(GangZoneHideForPlayer)
{
    int playerid, zone;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &zone) == FAILURE)
    {
        RETURN_NULL();
    }

    GangZoneHideForPlayer(playerid, zone);
}

PHP_FUNCTION(GangZoneHideForAll)
{
    int zone;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &zone) == FAILURE)
    {
        RETURN_NULL();
    }

    GangZoneHideForAll(zone);
}

PHP_FUNCTION(GangZoneFlashForPlayer)
{
    int playerid, zone, flashcolor;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &playerid, &zone, &flashcolor) == FAILURE)
    {
        RETURN_NULL();
    }

    GangZoneFlashForPlayer(playerid, zone, flashcolor);
}

PHP_FUNCTION(GangZoneFlashForAll)
{
    int zone, flashcolor;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &zone, &flashcolor) == FAILURE)
    {
        RETURN_NULL();
    }

    GangZoneFlashForAll(zone, flashcolor);
}

PHP_FUNCTION(GangZoneStopFlashForPlayer)
{
    int playerid, zone;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &zone) == FAILURE)
    {
        RETURN_NULL();
    }

    GangZoneStopFlashForPlayer(playerid, zone);
}

PHP_FUNCTION(GangZoneStopFlashForAll)
{
    int zone;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &zone) == FAILURE)
    {
        RETURN_NULL();
    }

    GangZoneStopFlashForAll(zone);
}

// 3D text
PHP_FUNCTION(Create3DTextLabel)
{
    char *text;
    int text_len, color, virtualworld = 0, testLOS = 0;
    double X, Y, Z, DrawDistance;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "sldddd|ll", &text, &text_len, &color, &X, &Y, &Z, &DrawDistance, &virtualworld, &testLOS) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(Create3DTextLabel(text, color, X, Y, Z, DrawDistance, virtualworld, testLOS));
}

PHP_FUNCTION(Delete3DTextLabel)
{
    int id;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &id) == FAILURE)
    {
        RETURN_NULL();
    }

    Delete3DTextLabel(id);
}

PHP_FUNCTION(Attach3DTextLabelToPlayer)
{
    int id, playerid;
    double OffsetX, OffsetY, OffsetZ;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddd", &id, &playerid, &OffsetX, &OffsetY, &OffsetZ) == FAILURE)
    {
        RETURN_NULL();
    }

    Attach3DTextLabelToPlayer(id, playerid, OffsetX, OffsetY, OffsetZ);
}

PHP_FUNCTION(Attach3DTextLabelToVehicle)
{
    int id, vehicleid;
    double OffsetX, OffsetY, OffsetZ;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddd", &id, &vehicleid, &OffsetX, &OffsetY, &OffsetZ) == FAILURE)
    {
        RETURN_NULL();
    }

    Attach3DTextLabelToVehicle(id, vehicleid, OffsetX, OffsetY, OffsetZ);
}

PHP_FUNCTION(Update3DTextLabelText)
{
    int id, color, text_len;
    char *text;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lls", &id, &color, &text, &text_len) == FAILURE)
    {
        RETURN_NULL();
    }

    Update3DTextLabelText(id, color, text);
}

// Player Text 3D
PHP_FUNCTION(CreatePlayer3DTextLabel)
{
    int playerid, text_len, color, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testLOS = 0;
    char *text;
    double X, Y, Z, DrawDistance;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lsldddd|lll", &playerid, &text, &text_len, &color, &X, &Y, &Z, &DrawDistance, &attachedplayer, &attachedvehicle, &testLOS) == FAILURE)
    {
        RETURN_NULL();
    }

    RETVAL_LONG(CreatePlayer3DTextLabel(playerid, text, color, X, Y, Z, DrawDistance, attachedplayer, attachedvehicle, testLOS));
}

PHP_FUNCTION(DeletePlayer3DTextLabel)
{
    int playerid, id;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &id) == FAILURE)
    {
        RETURN_NULL();
    }

    DeletePlayer3DTextLabel(playerid, id);
}

PHP_FUNCTION(UpdatePlayer3DTextLabelText)
{
    int playerid, id, color, text_len;
    char *text;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llls", &playerid, &id, &color, &text, &text_len) == FAILURE)
    {
        RETURN_NULL();
    }

    UpdatePlayer3DTextLabelText(playerid, id, color, text);
}

// GUI Dialog
PHP_FUNCTION(ShowPlayerDialog)
{
    int playerid, dialogid, style, caption_len, info_len, button1_len, button2_len;
    char *caption, *info, *button1, *button2;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lllssss", &playerid, &dialogid, &style, &caption, &caption_len, &info, &info_len, &button1, &button1_len, &button2, &button2_len) == FAILURE)
    {
        RETURN_NULL();
    }

    ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
}