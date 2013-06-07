SAMPHP - SA:MP Gamemode SDK for PHP
======

SAMPHP provides an API for developing SA:MP Gamemodes using the popular script language PHP.

Nearly every native function and every callback known from SA:MP are implemented.
Most functions have the exact same syntax as their PAWN counterpart.
Every function, that uses reference-passing got changed and either returns an associated array containing the information or if it only returns one information, returns it directly.

Examples
===
PAWN Example
```pawn
public OnPlayerConnect(playerid)
{
    //Get the name of the player that connected and display a join message to other players
 
    new name[MAX_PLAYER_NAME+1], string[24+MAX_PLAYER_NAME+1];
    GetPlayerName(playerid, name, sizeof(name));
 
    format(string, sizeof(string), "%s has joined the server.", name);
    SendClientMessageToAll(0xC4C4C4FF, string);
 
    return 1;
}
```

Same code with SAMPHP
```php
function OnPlayerConnect($playerid)
{
    //Get the name of the player that connected and display a join message to other players
    $playername = GetPlayerName($playerid);
 
    SendClientMessageToAll(0xC4C4C4FF, "$playername has joined the server.");
 
    return true;
}
```

Framework
===
In the near feature there will be a framework for SAMPHP, making it even more easier to develop gamemodes with beautiful code.
The code above might look a bit like the following:
```php
Event::on('PlayerConnect', function($player)
{
    SendClientMessageToAll(0xC4C4C4FF, $player->getName()." has joined the server.");
 
    return true;
});
```

Installation
===
Please look here for installation instructions:
http://forum.sa-mp.com/showthread.php?t=442302

Compiling: Linux
===
1. You need: libxml2-dev, gcc, g++ (x86 environment!)
2. Clone the repository.
3. Run ./install_libphp5.sh as root, this will install php headers and libphp5.so
4. Install SAMPGDK (https://github.com/Zeex/sampgdk#linux)
5. run ./build.sh and copy the created samphp file to your plugins folder

Thanks to
===
- SA:MP Team for developing SA:MP
- Zeex for developing the SAMPGDK which is used by SAMPHP
- All the PHP Core developers

