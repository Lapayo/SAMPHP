PHP_FUNCTION(CreateObject)
{
	int modelid;
	double X, Y, Z, rX, rY, rZ, DrawDistance = 0.0;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddddddd", &modelid, &X, &Y, &Z, &rX, &rY, &rZ, &DrawDistance) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(CreateObject(modelid, X, Y, Z, rX, rY, rZ, DrawDistance));
}

PHP_FUNCTION(AttachObjectToVehicle)
{
	int objectid, vehicleid;
	double OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lldddddd", &objectid, &vehicleid, &OffsetX, &OffsetY, &OffsetZ, &RotX, &RotY, &RotZ) == FAILURE)
	{
        RETURN_NULL();
    }

	AttachObjectToVehicle(objectid, vehicleid, OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ);
}

PHP_FUNCTION(AttachObjectToObject)
{
	int objectid, attachtoid, SyncRotation = 1;
	double OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddddddl", &objectid, &attachtoid, &OffsetX, &OffsetY, &OffsetZ, &RotX, &RotY, &RotZ, &SyncRotation) == FAILURE)
	{
        RETURN_NULL();
    }

	AttachObjectToObject(objectid, attachtoid, OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ, SyncRotation);
}

PHP_FUNCTION(AttachObjectToPlayer)
{
	int objectid, playerid;
	double OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lldddddd", &objectid, &playerid, &OffsetX, &OffsetY, &OffsetZ, &RotX, &RotY, &RotZ) == FAILURE)
	{
        RETURN_NULL();
    }

	AttachObjectToPlayer(objectid, playerid, OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ);
}

PHP_FUNCTION(SetObjectPos)
{
	int objectid;
	double X, Y, Z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &objectid, &X, &Y, &Z) == FAILURE)
	{
        RETURN_NULL();
    }

	SetObjectPos(objectid, X, Y, Z);
}

PHP_FUNCTION(GetObjectPos)
{
	int objectid;
	float x, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetObjectPos(objectid, &x, &y, &z);


    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(SetObjectRot)
{
	int objectid;
	double RotX, RotY, RotZ;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &objectid, &RotX, &RotY, &RotZ) == FAILURE)
	{
        RETURN_NULL();
    }

	SetObjectRot(objectid, RotX, RotY, RotZ);
}

PHP_FUNCTION(GetObjectRot)
{
	int objectid;
	float x, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetObjectRot(objectid, &x, &y, &z);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(IsValidObject)
{
	int objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_BOOL(IsValidObject(objectid));
}

PHP_FUNCTION(DestroyObject)
{
	int objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	DestroyObject(objectid);
}

PHP_FUNCTION(MoveObject)
{
	int objectid;
	double X, Y, Z, Speed, RotX = -1000.0, RotY = -1000.0, RotZ = -1000.0;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ldddd|ddd", &objectid, &X, &Y, &Z, &Speed, &RotX, &RotY, &RotZ) == FAILURE)
	{
        RETURN_NULL();
    }

	MoveObject(objectid, X, Y, Z, Speed, RotX, RotY, RotZ);
}

PHP_FUNCTION(StopObject)
{
	int objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	StopObject(objectid);
}

PHP_FUNCTION(IsObjectMoving)
{
	int objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_BOOL(IsObjectMoving(objectid));
}

PHP_FUNCTION(EditObject)
{
	int playerid, objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	EditObject(playerid, objectid);
}

PHP_FUNCTION(EditPlayerObject)
{
	int playerid, objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	EditPlayerObject(playerid, objectid);
}

PHP_FUNCTION(SelectObject)
{
	int playerid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
	{
        RETURN_NULL();
    }

	SelectObject(playerid);
}

PHP_FUNCTION(CancelEdit)
{
	int playerid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &playerid) == FAILURE)
	{
        RETURN_NULL();
    }

	CancelEdit(playerid);
}

PHP_FUNCTION(CreatePlayerObject)
{
	int playerid, modelid;
	double X, Y, Z, rX, rY, rZ, DrawDistance = 0.0;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lldddddd|d", &playerid, &modelid, &X, &Y, &Z, &rX, &rY, &rZ, &DrawDistance) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(CreatePlayerObject(playerid, modelid, X, Y, Z, rX, rY, rZ, DrawDistance));
}

PHP_FUNCTION(AttachPlayerObjectToVehicle)
{
	int playerid, objectid, vehicleid;
	double fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, RotZ;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llldddddd", &playerid, &objectid, &vehicleid, &fOffsetX, &fOffsetY, &fOffsetZ, &fRotX, &fRotY, &RotZ) == FAILURE)
	{
        RETURN_NULL();
    }

	AttachPlayerObjectToVehicle(playerid, objectid, vehicleid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, RotZ);
}

PHP_FUNCTION(SetPlayerObjectPos)
{
	int playerid, objectid;
	double X, Y, Z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddd", &playerid, &objectid, &X, &Y, &Z) == FAILURE)
	{
        RETURN_NULL();
    }

	SetPlayerObjectPos(playerid, objectid, X, Y, Z);
}

PHP_FUNCTION(GetPlayerObjectPos)
{
	int playerid, objectid;
	float x, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetPlayerObjectPos(playerid, objectid, &x, &y, &z);

	array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(SetPlayerObjectRot)
{
	int playerid, objectid;
	double RotX, RotY, RotZ;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddd", &playerid, &objectid, &RotX, &RotY, &RotZ) == FAILURE)
	{
        RETURN_NULL();
    }

	SetPlayerObjectRot(playerid, objectid, RotX, RotY, RotZ);
}

PHP_FUNCTION(GetPlayerObjectRot)
{
	int playerid, objectid;
	float x, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetPlayerObjectRot(playerid, objectid, &x, &y, &z);

	array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(IsValidPlayerObject)
{
	int playerid, objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_BOOL(IsValidPlayerObject(playerid, objectid));
}

PHP_FUNCTION(DestroyPlayerObject)
{
	int playerid, objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	DestroyPlayerObject(playerid, objectid);
}

PHP_FUNCTION(MovePlayerObject)
{
	int playerid, objectid;
	double X, Y, Z, Speed, RotX = -1000.0, RotY = -1000.0, RotZ = -1000.0;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llddddddd", &playerid, &objectid, &X, &Y, &Z, &Speed, &RotX, &RotY, &RotZ) == FAILURE)
	{
        RETURN_NULL();
    }

	MovePlayerObject(playerid, objectid, X, Y, Z, Speed, RotX, RotY, RotZ);
}

PHP_FUNCTION(StopPlayerObject)
{
	int playerid, objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	StopPlayerObject(playerid, objectid);
}

PHP_FUNCTION(IsPlayerObjectMoving)
{
	int playerid, objectid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &playerid, &objectid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_BOOL(IsPlayerObjectMoving(playerid, objectid));
}

PHP_FUNCTION(AttachPlayerObjectToPlayer)
{
	int objectplayer, objectid, attachplayer;
	double OffsetX, OffsetY, OffsetZ, rX, rY, rZ;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llldddddd", &objectplayer, &objectid, &attachplayer, &OffsetX, &OffsetY, &OffsetZ, &rX, &rY, &rZ) == FAILURE)
	{
        RETURN_NULL();
    }

	AttachPlayerObjectToPlayer(objectplayer, objectid, attachplayer, OffsetX, OffsetY, OffsetZ, rX, rY, rZ);
}

PHP_FUNCTION(SetObjectMaterial)
{
	int objectid, materialindex, modelid, txdname_len, texturename_len, materialcolor = 0;
	char *txdname, *texturename;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lllss|l", &objectid, &materialindex, &modelid, &txdname, &txdname_len, &texturename, &texturename_len, &materialcolor) == FAILURE)
	{
        RETURN_NULL();
    }

	SetObjectMaterial(objectid, materialindex, modelid, txdname, texturename, materialcolor);
}

PHP_FUNCTION(SetPlayerObjectMaterial)
{
	int playerid, objectid, materialindex, modelid, txdname_len, texturename_len, materialcolor = 0;
	char *txdname, *texturename;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llllss|l", &playerid, &objectid, &materialindex, &modelid, &txdname, &txdname_len, &texturename, &texturename_len, &materialcolor) == FAILURE)
	{
        RETURN_NULL();
    }

	SetPlayerObjectMaterial(playerid, objectid, materialindex, modelid, txdname, texturename, materialcolor);
}

PHP_FUNCTION(SetObjectMaterialText)
{
	int objectid, text_len, materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, fontface_len, fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0;
	char *text, fontface[] = "Arial";
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ls|llslllll", &objectid, &text, &text_len, &materialindex, &materialsize, &fontface, &fontface_len, &fontsize, &bold, &fontcolor, &backcolor, &textalignment) == FAILURE)
	{
        RETURN_NULL();
    }

	SetObjectMaterialText(objectid, text, materialindex, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment);
}

PHP_FUNCTION(SetPlayerObjectMaterialText)
{
	int playerid, objectid, text_len, materialindex = 0, materialsize = OBJECT_MATERIAL_SIZE_256x128, fontface_len, fontsize = 24, bold = 1, fontcolor = 0xFFFFFFFF, backcolor = 0, textalignment = 0;
	char *text, fontface[] = "Arial";
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll|sllslllll", &playerid, &objectid, &text, &text_len, &materialindex, &materialsize, &fontface, &fontface_len, &fontsize, &bold, &fontcolor, &backcolor, &textalignment) == FAILURE)
	{
        RETURN_NULL();
    }

	SetPlayerObjectMaterialText(playerid, objectid, text, materialindex, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment);
}