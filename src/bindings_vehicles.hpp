PHP_FUNCTION(CreateVehicle)
{
	int vehicletype, color1, color2, respawn_delay;
	double x, y, z, rotation;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lddddlll", &vehicletype, &x, &y, &z, &rotation, &color1, &color2, &respawn_delay) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(sampgdk_CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay));
}

PHP_FUNCTION(DestroyVehicle)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_DestroyVehicle(vehicleid);
}

PHP_FUNCTION(IsVehicleStreamedIn)
{
	int vehicleid, forplayerid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &forplayerid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_BOOL(sampgdk_IsVehicleStreamedIn(vehicleid, forplayerid));
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

	sampgdk_GetVehiclePos(vehicleid, &x, &y, &z);

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

	sampgdk_SetVehiclePos(vehicleid, x, y, z);
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

	sampgdk_GetVehicleZAngle(vehicleid, &z_angle);

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

	sampgdk_GetVehicleRotationQuat(vehicleid, &w, &x, &y, &z);

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

	RETVAL_DOUBLE(sampgdk_GetVehicleDistanceFromPoint(vehicleid, X, Y, Z));
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

	sampgdk_SetVehicleZAngle(vehicleid, z_angle);
}

PHP_FUNCTION(SetVehicleParamsForPlayer)
{
	int vehicleid, playerid, objective, doorslocked;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llll", &vehicleid, &playerid, &objective, &doorslocked) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_SetVehicleParamsForPlayer(vehicleid, playerid, objective, doorslocked);
}

PHP_FUNCTION(ManualVehicleEngineAndLights)
{
	
	RETVAL_LONG(sampgdk_ManualVehicleEngineAndLights());
}

PHP_FUNCTION(SetVehicleParamsEx)
{
	int vehicleid, engine, lights, alarm, doors, bonnet, boot, objective;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "llllllll", &vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
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

	sampgdk_GetVehicleParamsEx(vehicleid, &engine, &lights, &alarm, &doors, &bonnet, &boot, &objective);

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

	sampgdk_SetVehicleToRespawn(vehicleid);
}

PHP_FUNCTION(LinkVehicleToInterior)
{
	int vehicleid, interiorid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &interiorid) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_LinkVehicleToInterior(vehicleid, interiorid);
}

PHP_FUNCTION(AddVehicleComponent)
{
	int vehicleid, componentid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &componentid) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_AddVehicleComponent(vehicleid, componentid);
}

PHP_FUNCTION(RemoveVehicleComponent)
{
	int vehicleid, componentid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &componentid) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_RemoveVehicleComponent(vehicleid, componentid);
}

PHP_FUNCTION(ChangeVehicleColor)
{
	int vehicleid, color1, color2;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "lll", &vehicleid, &color1, &color2) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_ChangeVehicleColor(vehicleid, color1, color2);
}

PHP_FUNCTION(ChangeVehiclePaintjob)
{
	int vehicleid, paintjobid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &paintjobid) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_ChangeVehiclePaintjob(vehicleid, paintjobid);
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

	sampgdk_SetVehicleHealth(vehicleid, health);
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

	sampgdk_GetVehicleHealth(vehicleid, &health);

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

	sampgdk_AttachTrailerToVehicle(trailerid, vehicleid);
}

PHP_FUNCTION(DetachTrailerFromVehicle)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_DetachTrailerFromVehicle(vehicleid);
}

PHP_FUNCTION(IsTrailerAttachedToVehicle)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_BOOL(sampgdk_IsTrailerAttachedToVehicle(vehicleid));
}

PHP_FUNCTION(GetVehicleTrailer)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(sampgdk_GetVehicleTrailer(vehicleid));
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

	sampgdk_SetVehicleNumberPlate(vehicleid, numberplate);
}

PHP_FUNCTION(GetVehicleModel)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(sampgdk_GetVehicleModel(vehicleid));
}

PHP_FUNCTION(GetVehicleComponentInSlot)
{
	int vehicleid, slot;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "ll", &vehicleid, &slot) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(sampgdk_GetVehicleComponentInSlot(vehicleid, slot));
}

PHP_FUNCTION(GetVehicleComponentType)
{
	int component;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &component) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(sampgdk_GetVehicleComponentType(component));
}

PHP_FUNCTION(RepairVehicle)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_RepairVehicle(vehicleid);
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

	sampgdk_GetVehicleVelocity(vehicleid, &x, &y, &z);


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

	sampgdk_SetVehicleVelocity(vehicleid, x, y, z);
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

	sampgdk_SetVehicleAngularVelocity(vehicleid, X, Y, Z);
}

PHP_FUNCTION(GetVehicleDamageStatus)
{
	int vehicleid, panels, doors, lights, tires;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	sampgdk_GetVehicleDamageStatus(vehicleid, &panels, &doors, &lights, &tires);

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

	sampgdk_UpdateVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
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

	sampgdk_GetVehicleModelInfo(vehiclemodel, infotype, &x, &y, &z);

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

	sampgdk_SetVehicleVirtualWorld(vehicleid, worldid);
}

PHP_FUNCTION(GetVehicleVirtualWorld)
{
	int vehicleid;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
                        "l", &vehicleid) == FAILURE)
	{
        RETURN_NULL();
    }

	RETVAL_LONG(sampgdk_GetVehicleVirtualWorld(vehicleid));
}
