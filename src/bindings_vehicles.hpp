PHP_FUNCTION(CreateVehicle)
{
	int vehicletype, color1, color2, respawn_delay;
	double x, y, z, rotation;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddddlll", &vehicletype, &x, &y, &z, &rotation, &color1, &color2, &respawn_delay) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay));
}

PHP_FUNCTION(DestroyVehicle)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	DestroyVehicle(vehicleid);
}

PHP_FUNCTION(IsVehicleStreamedIn)
{
	int vehicleid, forplayerid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &forplayerid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_BOOL(IsVehicleStreamedIn(vehicleid, forplayerid));
}

PHP_FUNCTION(GetVehiclePos)
{
	int vehicleid;
	float x, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetVehiclePos(vehicleid, &x, &y, &z);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(SetVehiclePos)
{
	int vehicleid;
	double x, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &vehicleid, &x, &y, &z) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehiclePos(vehicleid, x, y, z);
}

PHP_FUNCTION(GetVehicleZAngle)
{
	int vehicleid;
	float z_angle;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetVehicleZAngle(vehicleid, &z_angle);

	RETVAL_DOUBLE(z_angle);
}

PHP_FUNCTION(GetVehicleRotationQuat)
{
	int vehicleid;
	float w = 1.0, x = 1.0, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetVehicleRotationQuat(vehicleid, &w, &x, &y, &z);

	// return array

    array_init(return_value);
    add_assoc_double(return_value, "w", w);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(GetVehicleDistanceFromPoint)
{
	int vehicleid;
	double X, Y, Z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &vehicleid, &X, &Y, &Z) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_DOUBLE(GetVehicleDistanceFromPoint(vehicleid, X, Y, Z));
}

PHP_FUNCTION(SetVehicleZAngle)
{
	int vehicleid;
	double z_angle;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ld", &vehicleid, &z_angle) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehicleZAngle(vehicleid, z_angle);
}

PHP_FUNCTION(SetVehicleParamsForPlayer)
{
	int vehicleid, playerid, objective, doorslocked;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llll", &vehicleid, &playerid, &objective, &doorslocked) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehicleParamsForPlayer(vehicleid, playerid, objective, doorslocked);
}

PHP_FUNCTION(ManualVehicleEngineAndLights)
{
	
	RETVAL_LONG(ManualVehicleEngineAndLights());
}

PHP_FUNCTION(SetVehicleParamsEx)
{
	int vehicleid, engine, lights, alarm, doors, bonnet, boot, objective;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llllllll", &vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
}

PHP_FUNCTION(GetVehicleParamsEx)
{
	int vehicleid;
	bool engine, lights, alarm, doors, bonnet, boot, objective;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetVehicleParamsEx(vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective);

	array_init(return_value);
    add_assoc_bool(return_value, "engine", engine);
    add_assoc_bool(return_value, "lights", lights);
    add_assoc_bool(return_value, "alarm", alarm);
    add_assoc_bool(return_value, "doors", doors);
    add_assoc_bool(return_value, "bonnet", bonnet);
    add_assoc_bool(return_value, "boot", boot);
    add_assoc_bool(return_value, "objective", objective);
}

PHP_FUNCTION(SetVehicleToRespawn)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehicleToRespawn(vehicleid);
}

PHP_FUNCTION(LinkVehicleToInterior)
{
	int vehicleid, interiorid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &interiorid) == FAILURE)
	{
        RETURN_NULL();
    }

	LinkVehicleToInterior(vehicleid, interiorid);
}

PHP_FUNCTION(AddVehicleComponent)
{
	int vehicleid, componentid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &componentid) == FAILURE)
	{
        RETURN_NULL();
    }

	AddVehicleComponent(vehicleid, componentid);
}

PHP_FUNCTION(RemoveVehicleComponent)
{
	int vehicleid, componentid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &componentid) == FAILURE)
	{
        RETURN_NULL();
    }

	RemoveVehicleComponent(vehicleid, componentid);
}

PHP_FUNCTION(ChangeVehicleColor)
{
	int vehicleid, color1, color2;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &vehicleid, &color1, &color2) == FAILURE)
	{
        RETURN_NULL();
    }

	ChangeVehicleColor(vehicleid, color1, color2);
}

PHP_FUNCTION(ChangeVehiclePaintjob)
{
	int vehicleid, paintjobid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &paintjobid) == FAILURE)
	{
        RETURN_NULL();
    }

	ChangeVehiclePaintjob(vehicleid, paintjobid);
}

PHP_FUNCTION(SetVehicleHealth)
{
	int vehicleid;
	double health;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ld", &vehicleid, &health) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehicleHealth(vehicleid, health);
}

PHP_FUNCTION(GetVehicleHealth)
{
	int vehicleid;
	float health;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetVehicleHealth(vehicleid, &health);

	RETVAL_DOUBLE(health);
}

PHP_FUNCTION(AttachTrailerToVehicle)
{
	int trailerid, vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &trailerid, &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	AttachTrailerToVehicle(trailerid, vehicleid);
}

PHP_FUNCTION(DetachTrailerFromVehicle)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	DetachTrailerFromVehicle(vehicleid);
}

PHP_FUNCTION(IsTrailerAttachedToVehicle)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_BOOL(IsTrailerAttachedToVehicle(vehicleid));
}

PHP_FUNCTION(GetVehicleTrailer)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(GetVehicleTrailer(vehicleid));
}

PHP_FUNCTION(SetVehicleNumberPlate)
{
	int vehicleid, numberplate_len;
	char *numberplate;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ls", &vehicleid, &numberplate, &numberplate_len) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehicleNumberPlate(vehicleid, numberplate);
}

PHP_FUNCTION(GetVehicleModel)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(GetVehicleModel(vehicleid));
}

PHP_FUNCTION(GetVehicleComponentInSlot)
{
	int vehicleid, slot;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &slot) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(GetVehicleComponentInSlot(vehicleid, slot));
}

PHP_FUNCTION(GetVehicleComponentType)
{
	int component;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &component) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(GetVehicleComponentType(component));
}

PHP_FUNCTION(RepairVehicle)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	RepairVehicle(vehicleid);
}

PHP_FUNCTION(GetVehicleVelocity)
{
	int vehicleid;
	float x, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetVehicleVelocity(vehicleid, &x, &y, &z);


    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(SetVehicleVelocity)
{
	int vehicleid;
	double x, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &vehicleid, &x, &y, &z) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehicleVelocity(vehicleid, x, y, z);
}

PHP_FUNCTION(SetVehicleAngularVelocity)
{
	int vehicleid;
	double X, Y, Z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddd", &vehicleid, &X, &Y, &Z) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehicleAngularVelocity(vehicleid, X, Y, Z);
}

PHP_FUNCTION(GetVehicleDamageStatus)
{
	int vehicleid, panels, doors, lights, tires;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	GetVehicleDamageStatus(vehicleid, &panels, &doors, &lights, &tires);

	array_init(return_value);
    add_assoc_double(return_value, "panels", panels);
    add_assoc_double(return_value, "doors", doors);
    add_assoc_double(return_value, "lights", lights);
    add_assoc_double(return_value, "tires", tires);
}

PHP_FUNCTION(UpdateVehicleDamageStatus)
{
	int vehicleid, panels, doors, lights, tires;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lllll", &vehicleid, &panels, &doors, &lights, &tires) == FAILURE)
	{
        RETURN_NULL();
    }

	UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
}

PHP_FUNCTION(GetVehicleModelInfo)
{
	int vehiclemodel, infotype;
	float x, y, z;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehiclemodel, &infotype) == FAILURE)
	{
        RETURN_NULL();
    }

	GetVehicleModelInfo(vehiclemodel, infotype, &x, &y, &z);

	array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "z", z);
}

PHP_FUNCTION(SetVehicleVirtualWorld)
{
	int vehicleid, worldid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &worldid) == FAILURE)
	{
        RETURN_NULL();
    }

	SetVehicleVirtualWorld(vehicleid, worldid);
}

PHP_FUNCTION(GetVehicleVirtualWorld)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(GetVehicleVirtualWorld(vehicleid));
}