#include "bindings.h"
#include <sstream>
#include <iostream>

// Callbacks
#include "bindings_callbacks.hpp"


// Functions:
// Server settings:
#include "bindings_samphp.hpp"
#include "bindings_util.hpp"
#include "bindings_game.hpp"
#include "bindings_vehicles.hpp"
#include "bindings_player.hpp"
#include "bindings_objects.hpp"

ZEND_BEGIN_ARG_INFO(AllButFirstThreeArgsByReference, true)
	ZEND_ARG_PASS_INFO(false)
	ZEND_ARG_PASS_INFO(false)
	ZEND_ARG_PASS_INFO(false)
ZEND_END_ARG_INFO()

// Export functions to module
static zend_function_entry php_samphp_functions[] = {
	// samphp functions
    PHP_FE(CallAMXNative, AllButFirstThreeArgsByReference)
    PHP_FE(DebugFunction, NULL)

    // Util
    PHP_FE(SendClientMessage, NULL)
	PHP_FE(SendClientMessageToAll, NULL)
	PHP_FE(SendPlayerMessageToPlayer, NULL)
	PHP_FE(SendPlayerMessageToAll, NULL)
    PHP_FE(SendDeathMessage, NULL)
    PHP_FE(GameTextForAll, NULL)
    PHP_FE(GameTextForPlayer, NULL)
    PHP_FE(SetTimer, NULL)
    PHP_FE(KillTimer, NULL)
    PHP_FE(GetTickCount, NULL)
	PHP_FE(GetMaxPlayers, NULL)

    // Game
    PHP_FE(SetGameModeText, NULL)
    PHP_FE(SetTeamCount, NULL)
    PHP_FE(AddPlayerClass, NULL)
	PHP_FE(AddPlayerClassEx, NULL)
    PHP_FE(AddStaticVehicle, NULL)
    PHP_FE(AddStaticVehicleEx, NULL)
    PHP_FE(AddStaticPickup, NULL)
    PHP_FE(CreatePickup, NULL)
    PHP_FE(DestroyPickup, NULL)
    PHP_FE(ShowPlayerMarkers, NULL)
    PHP_FE(ShowNameTags, NULL)
    PHP_FE(GameModeExit, NULL)
    PHP_FE(SetWorldTime, NULL)
    PHP_FE(GetWeaponName, NULL)
    PHP_FE(EnableTirePopping, NULL)
    PHP_FE(EnableVehicleFriendlyFire, NULL)
	PHP_FE(AllowInteriorWeapons, NULL)
	PHP_FE(SetWeather, NULL)
	PHP_FE(SetGravity, NULL)
	PHP_FE(AllowAdminTeleport, NULL)
	PHP_FE(SetDeathDropAmount, NULL)
	PHP_FE(CreateExplosion, NULL)
	PHP_FE(EnableZoneNames, NULL)
	PHP_FE(UsePlayerPedAnims, NULL)
	PHP_FE(DisableInteriorEnterExits, NULL)
	PHP_FE(SetNameTagDrawDistance, NULL)
	PHP_FE(DisableNameTagLOS, NULL)
	PHP_FE(LimitGlobalChatRadius, NULL)
	PHP_FE(LimitPlayerMarkerRadius, NULL)
    PHP_FE(EnableStuntBonusForAll, NULL)
	PHP_FE(EnableStuntBonusForPlayer, NULL)

	// NPC
    PHP_FE(ConnectNPC, NULL)
	PHP_FE(IsPlayerNPC, NULL)

	// Admin
	PHP_FE(IsPlayerAdmin, NULL)
	PHP_FE(Kick, NULL)
	PHP_FE(Ban, NULL)
	PHP_FE(BanEx, NULL)
	PHP_FE(SendRconCommand, NULL)
	PHP_FE(GetServerVar, NULL)
	PHP_FE(GetServerVarAsString, NULL)
	PHP_FE(GetServerVarAsInt, NULL)
	PHP_FE(GetServerVarAsBool, NULL)
	PHP_FE(GetPlayerNetworkStats, NULL)
	PHP_FE(GetNetworkStats, NULL)
	PHP_FE(GetPlayerVersion, NULL)

	// Menu
	PHP_FE(CreateMenu, NULL)
	PHP_FE(DestroyMenu, NULL)
	PHP_FE(AddMenuItem, NULL)
	PHP_FE(SetMenuColumnHeader, NULL)
	PHP_FE(ShowMenuForPlayer, NULL)
	PHP_FE(HideMenuForPlayer, NULL)
	PHP_FE(IsValidMenu, NULL)
	PHP_FE(DisableMenu, NULL)
	PHP_FE(DisableMenuRow, NULL)
	PHP_FE(GetPlayerMenu, NULL)

	// Text Draw
	PHP_FE(TextDrawCreate, NULL)
	PHP_FE(TextDrawDestroy, NULL)
	PHP_FE(TextDrawLetterSize, NULL)
	PHP_FE(TextDrawTextSize, NULL)
	PHP_FE(TextDrawAlignment, NULL)
	PHP_FE(TextDrawColor, NULL)
	PHP_FE(TextDrawUseBox, NULL)
	PHP_FE(TextDrawBoxColor, NULL)
	PHP_FE(TextDrawSetShadow, NULL)
	PHP_FE(TextDrawSetOutline, NULL)
	PHP_FE(TextDrawBackgroundColor, NULL)
	PHP_FE(TextDrawFont, NULL)
	PHP_FE(TextDrawSetProportional, NULL)
	PHP_FE(TextDrawSetSelectable, NULL)
	PHP_FE(TextDrawShowForPlayer, NULL)
	PHP_FE(TextDrawHideForPlayer, NULL)
	PHP_FE(TextDrawShowForAll, NULL)
	PHP_FE(TextDrawHideForAll, NULL)
	PHP_FE(TextDrawSetString, NULL)
	PHP_FE(TextDrawSetPreviewModel, NULL)
	PHP_FE(TextDrawSetPreviewRot, NULL)
	PHP_FE(TextDrawSetPreviewVehCol, NULL)

	// Gangzone
	PHP_FE(GangZoneCreate, NULL)
	PHP_FE(GangZoneDestroy, NULL)
	PHP_FE(GangZoneShowForPlayer, NULL)
	PHP_FE(GangZoneShowForAll, NULL)
	PHP_FE(GangZoneHideForPlayer, NULL)
	PHP_FE(GangZoneHideForAll, NULL)
	PHP_FE(GangZoneFlashForPlayer, NULL)
	PHP_FE(GangZoneFlashForAll, NULL)
	PHP_FE(GangZoneStopFlashForPlayer, NULL)
	PHP_FE(GangZoneStopFlashForAll, NULL)

	// Global 3D Text Labels
	PHP_FE(Create3DTextLabel, NULL)
	PHP_FE(Delete3DTextLabel, NULL)
	PHP_FE(Attach3DTextLabelToPlayer, NULL)
	PHP_FE(Attach3DTextLabelToVehicle, NULL)
	PHP_FE(Update3DTextLabelText, NULL)

	// Player Text 3D
	PHP_FE(CreatePlayer3DTextLabel, NULL)
	PHP_FE(DeletePlayer3DTextLabel, NULL)
	PHP_FE(UpdatePlayer3DTextLabelText, NULL)

	// GUI Dialog
	PHP_FE(ShowPlayerDialog, NULL)

	// Vehicle
	PHP_FE(CreateVehicle, NULL)
	PHP_FE(DestroyVehicle, NULL)
	PHP_FE(IsVehicleStreamedIn, NULL)
	PHP_FE(GetVehiclePos, NULL)
	PHP_FE(SetVehiclePos, NULL)
	PHP_FE(GetVehicleZAngle, NULL)
	PHP_FE(GetVehicleRotationQuat, NULL)
	PHP_FE(GetVehicleDistanceFromPoint, NULL)
	PHP_FE(SetVehicleZAngle, NULL)
	PHP_FE(SetVehicleParamsForPlayer, NULL)
	PHP_FE(ManualVehicleEngineAndLights, NULL)
	PHP_FE(SetVehicleParamsEx, NULL)
	PHP_FE(GetVehicleParamsEx, NULL)
	PHP_FE(SetVehicleToRespawn, NULL)
	PHP_FE(LinkVehicleToInterior, NULL)
	PHP_FE(AddVehicleComponent, NULL)
	PHP_FE(RemoveVehicleComponent, NULL)
	PHP_FE(ChangeVehicleColor, NULL)
	PHP_FE(ChangeVehiclePaintjob, NULL)
	PHP_FE(SetVehicleHealth, NULL)
	PHP_FE(GetVehicleHealth, NULL)
	PHP_FE(AttachTrailerToVehicle, NULL)
	PHP_FE(DetachTrailerFromVehicle, NULL)
	PHP_FE(IsTrailerAttachedToVehicle, NULL)
	PHP_FE(GetVehicleTrailer, NULL)
	PHP_FE(SetVehicleNumberPlate, NULL)
	PHP_FE(GetVehicleModel, NULL)
	PHP_FE(GetVehicleComponentInSlot, NULL)
	PHP_FE(GetVehicleComponentType, NULL)
	PHP_FE(RepairVehicle, NULL)
	PHP_FE(GetVehicleVelocity, NULL)
	PHP_FE(SetVehicleVelocity, NULL)
	PHP_FE(SetVehicleAngularVelocity, NULL)
	PHP_FE(GetVehicleDamageStatus, NULL)
	PHP_FE(UpdateVehicleDamageStatus, NULL)
	PHP_FE(GetVehicleModelInfo, NULL)
	PHP_FE(SetVehicleVirtualWorld, NULL)
	PHP_FE(GetVehicleVirtualWorld, NULL)

    // Player functions
    PHP_FE(SetSpawnInfo, NULL)
    PHP_FE(SpawnPlayer, NULL)
    PHP_FE(SetPlayerPos, NULL)
    PHP_FE(SetPlayerPosFindZ, NULL)
    PHP_FE(GetPlayerPos, NULL)
    PHP_FE(SetPlayerFacingAngle, NULL)
    PHP_FE(GetPlayerFacingAngle, NULL)
    PHP_FE(IsPlayerInRangeOfPoint, NULL)
    PHP_FE(GetPlayerDistanceFromPoint, NULL)
    PHP_FE(IsPlayerStreamedIn, NULL)
    PHP_FE(SetPlayerInterior, NULL)
    PHP_FE(GetPlayerInterior, NULL)
    PHP_FE(SetPlayerHealth, NULL)
    PHP_FE(GetPlayerHealth, NULL)
    PHP_FE(SetPlayerArmour, NULL)
    PHP_FE(GetPlayerArmour, NULL)
    PHP_FE(SetPlayerAmmo, NULL)
    PHP_FE(GetPlayerAmmo, NULL)
    PHP_FE(GetPlayerWeaponState, NULL)
    PHP_FE(GetPlayerTargetPlayer, NULL)
    PHP_FE(SetPlayerTeam, NULL)
    PHP_FE(GetPlayerTeam, NULL)
    PHP_FE(SetPlayerScore, NULL)
    PHP_FE(GetPlayerScore, NULL)
    PHP_FE(GetPlayerDrunkLevel, NULL)
    PHP_FE(SetPlayerDrunkLevel, NULL)
    PHP_FE(SetPlayerColor, NULL)
    PHP_FE(GetPlayerColor, NULL)
    PHP_FE(SetPlayerSkin, NULL)
    PHP_FE(GetPlayerSkin, NULL)
    PHP_FE(GivePlayerWeapon, NULL)
    PHP_FE(ResetPlayerWeapons, NULL)
    PHP_FE(SetPlayerArmedWeapon, NULL)
    PHP_FE(GetPlayerWeaponData, NULL)
    PHP_FE(GetPlayerMoney, NULL)
    PHP_FE(GivePlayerMoney, NULL)
    PHP_FE(ResetPlayerMoney, NULL)
    PHP_FE(SetPlayerName, NULL)
    PHP_FE(GetPlayerState, NULL)
    PHP_FE(GetPlayerIp, NULL)
    PHP_FE(GetPlayerPing, NULL)
    PHP_FE(GetPlayerWeapon, NULL)
    PHP_FE(GetPlayerKeys, NULL)
    PHP_FE(GetPlayerName, NULL)
    PHP_FE(SetPlayerTime, NULL)
    PHP_FE(GetPlayerTime, NULL)
    PHP_FE(TogglePlayerClock, NULL)
    PHP_FE(SetPlayerWeather, NULL)
    PHP_FE(ForceClassSelection, NULL)
    PHP_FE(SetPlayerWantedLevel, NULL)
    PHP_FE(GetPlayerWantedLevel, NULL)
    PHP_FE(SetPlayerFightingStyle, NULL)
    PHP_FE(GetPlayerFightingStyle, NULL)
    PHP_FE(SetPlayerVelocity, NULL)
    PHP_FE(GetPlayerVelocity, NULL)
    PHP_FE(PlayCrimeReportForPlayer, NULL)
    PHP_FE(PlayAudioStreamForPlayer, NULL)
    PHP_FE(StopAudioStreamForPlayer, NULL)
    PHP_FE(SetPlayerShopName, NULL)
    PHP_FE(SetPlayerSkillLevel, NULL)
    PHP_FE(GetPlayerSurfingVehicleID, NULL)
    PHP_FE(GetPlayerSurfingObjectID, NULL)
    PHP_FE(RemoveBuildingForPlayer, NULL)
    PHP_FE(SetPlayerAttachedObject, NULL)
    PHP_FE(RemovePlayerAttachedObject, NULL)
    PHP_FE(IsPlayerAttachedObjectSlotUsed, NULL)
    PHP_FE(EditAttachedObject, NULL)

    // Per-player TextDraws
    PHP_FE(CreatePlayerTextDraw, NULL)
    PHP_FE(PlayerTextDrawDestroy, NULL)
    PHP_FE(PlayerTextDrawLetterSize, NULL)
    PHP_FE(PlayerTextDrawTextSize, NULL)
    PHP_FE(PlayerTextDrawAlignment, NULL)
    PHP_FE(PlayerTextDrawColor, NULL)
    PHP_FE(PlayerTextDrawUseBox, NULL)
    PHP_FE(PlayerTextDrawBoxColor, NULL)
    PHP_FE(PlayerTextDrawSetShadow, NULL)
    PHP_FE(PlayerTextDrawSetOutline, NULL)
    PHP_FE(PlayerTextDrawBackgroundColor, NULL)
    PHP_FE(PlayerTextDrawFont, NULL)
    PHP_FE(PlayerTextDrawSetProportional, NULL)
    PHP_FE(PlayerTextDrawSetSelectable, NULL)
    PHP_FE(PlayerTextDrawShow, NULL)
    PHP_FE(PlayerTextDrawHide, NULL)
    PHP_FE(PlayerTextDrawSetString, NULL)
    PHP_FE(PlayerTextDrawSetPreviewModel, NULL)
    PHP_FE(PlayerTextDrawSetPreviewRot, NULL)
    PHP_FE(PlayerTextDrawSetPreviewVehCol, NULL)
    PHP_FE(SetPlayerChatBubble, NULL)

	// Player controls
	PHP_FE(PutPlayerInVehicle, NULL)
	PHP_FE(GetPlayerVehicleID, NULL)
	PHP_FE(GetPlayerVehicleSeat, NULL)
	PHP_FE(RemovePlayerFromVehicle, NULL)
	PHP_FE(TogglePlayerControllable, NULL)
	PHP_FE(PlayerPlaySound, NULL)
	PHP_FE(ApplyAnimation, NULL)
	PHP_FE(ClearAnimations, NULL)
	PHP_FE(GetPlayerAnimationIndex, NULL)
	PHP_FE(GetAnimationName, NULL)
	PHP_FE(GetPlayerSpecialAction, NULL)
	PHP_FE(SetPlayerSpecialAction, NULL)

	// Player world/map related
	PHP_FE(SetPlayerCheckpoint, NULL)
	PHP_FE(DisablePlayerCheckpoint, NULL)
	PHP_FE(SetPlayerRaceCheckpoint, NULL)
	PHP_FE(DisablePlayerRaceCheckpoint, NULL)
	PHP_FE(SetPlayerWorldBounds, NULL)
	PHP_FE(SetPlayerMarkerForPlayer, NULL)
	PHP_FE(ShowPlayerNameTagForPlayer, NULL)
	PHP_FE(SetPlayerMapIcon, NULL)
	PHP_FE(RemovePlayerMapIcon, NULL)
	PHP_FE(AllowPlayerTeleport, NULL)

	// Player Camera
    PHP_FE(SetPlayerCameraPos, NULL)
    PHP_FE(SetPlayerCameraLookAt, NULL)
	PHP_FE(SetCameraBehindPlayer, NULL)
	PHP_FE(GetPlayerCameraPos, NULL)
	PHP_FE(GetPlayerCameraFrontVector, NULL)
	PHP_FE(GetPlayerCameraMode, NULL)
	PHP_FE(AttachCameraToObject, NULL)
	PHP_FE(AttachCameraToPlayerObject, NULL)
	PHP_FE(InterpolateCameraPos, NULL)
	PHP_FE(InterpolateCameraLookAt, NULL)

	// Player conditionals
	PHP_FE(IsPlayerConnected, NULL)
	PHP_FE(IsPlayerInVehicle, NULL)
	PHP_FE(IsPlayerInAnyVehicle, NULL)
	PHP_FE(IsPlayerInCheckpoint, NULL)
	PHP_FE(IsPlayerInRaceCheckpoint, NULL)

	// Virtual Worlds
	PHP_FE(SetPlayerVirtualWorld, NULL)
	PHP_FE(GetPlayerVirtualWorld, NULL)

	// Spectating
	PHP_FE(TogglePlayerSpectating, NULL)
	PHP_FE(PlayerSpectatePlayer, NULL)
	PHP_FE(PlayerSpectateVehicle, NULL)

	// Recording for NPC playback
	PHP_FE(StartRecordingPlayerData, NULL)
	PHP_FE(StopRecordingPlayerData, NULL)

	// Mouse control
	PHP_FE(SelectTextDraw, NULL)
	PHP_FE(CancelSelectTextDraw, NULL)

	//Objects
	PHP_FE(CreateObject, NULL)
	PHP_FE(AttachObjectToVehicle, NULL)
	PHP_FE(AttachObjectToObject, NULL)
	PHP_FE(AttachObjectToPlayer, NULL)
	PHP_FE(SetObjectPos, NULL)
	PHP_FE(GetObjectPos, NULL)
	PHP_FE(SetObjectRot, NULL)
	PHP_FE(GetObjectRot, NULL)
	PHP_FE(IsValidObject, NULL)
	PHP_FE(DestroyObject, NULL)
	PHP_FE(MoveObject, NULL)
	PHP_FE(StopObject, NULL)
	PHP_FE(IsObjectMoving, NULL)
	PHP_FE(EditObject, NULL)
	PHP_FE(EditPlayerObject, NULL)
	PHP_FE(SelectObject, NULL)
	PHP_FE(CancelEdit, NULL)
	PHP_FE(CreatePlayerObject, NULL)
	PHP_FE(AttachPlayerObjectToVehicle, NULL)
	PHP_FE(SetPlayerObjectPos, NULL)
	PHP_FE(GetPlayerObjectPos, NULL)
	PHP_FE(SetPlayerObjectRot, NULL)
	PHP_FE(GetPlayerObjectRot, NULL)
	PHP_FE(IsValidPlayerObject, NULL)
	PHP_FE(DestroyPlayerObject, NULL)
	PHP_FE(MovePlayerObject, NULL)
	PHP_FE(StopPlayerObject, NULL)
	PHP_FE(IsPlayerObjectMoving, NULL)
	PHP_FE(AttachPlayerObjectToPlayer, NULL)

	PHP_FE(SetObjectMaterial, NULL)
	PHP_FE(SetPlayerObjectMaterial, NULL)

	PHP_FE(SetObjectMaterialText, NULL)
	PHP_FE(SetPlayerObjectMaterialText, NULL)

    { NULL, NULL, NULL }
};

PHP_MINIT_FUNCTION(samphp_minit)
{
	#include "samphp_consts.hpp"
	
    return SUCCESS;
}

zend_module_entry  samphp_module_entry = {
    STANDARD_MODULE_HEADER,
    "samphp", /* extension name */
    php_samphp_functions, /* function entries */
    PHP_MINIT(samphp_minit), /* MINIT */
    NULL, /* MSHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    "1.0", /* version */
    STANDARD_MODULE_PROPERTIES
};