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

Getting started
===
Getting started with SAMPHP isnt hard, but actually only works on linux x86 machines.
At first you need the SAMPHP plugin for the server.
You can compile SAMPHP yourself using the build.sh or you can later download a binary release.

Additionally you will need the php5 shared library. You can install it using the install_libphp5.sh script. You have to run it as root.

Now simply copy the SAMPHP binary to the plugins folder of you SA:MP server, add "plugins=samphp" to your server configuration and create a folder called "php".
Inside this folder you create a gamemode.php file, which will contain your gamemode logic.

That's it. If you start your server, SAMPHP will do the rest and load your PHP script. ;-)

Thanks to
===
- SA:MP Team for developing SA:MP
- Zeex for developing the SAMPGDK which is used by SAMPHP
- All the PHP Core developers

