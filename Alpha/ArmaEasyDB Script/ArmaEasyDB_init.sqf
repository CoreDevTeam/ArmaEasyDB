//
// Scriptfile compatible with Version 0.4
//
_debug = true;

if ( _debug ) then { hint "Started loading ArmaEasyDB"; };

ArmaEasyDB_getDLLVersion = 
{
// Description	: Returns the current Version of the DLL
// Parameters		:  -
// Return		: string 
	private["_databaseName","_tempFunctionString"];

	_databaseName = _this select 0;

	_tempFunctionString = format ["getDLLVersion"];

	_AEDB_hnd = "ArmaEasyDB" callExtension _tempFunctionString;
	
	_AEDB_hnd
};

ArmaEasyDB_addEntry = 
{
// Description	: Deletes a Database with the given Name
// Parameters		: String with entrys separated by ";"
// Return		:	-
	private["_databaseName","_tempFunctionString"];

	_databaseName = _this select 0;

	_tempFunctionString = format ["clearDatabase %1",_databaseName];

	_AEDB_hnd = "ArmaEasyDB" callExtension _tempFunctionString;
};

ArmaEasyDB_clearDatabase = 
{
// Description	: Deletes a Database with the given Name
// Parameters		: Database name 
// Return		:	-
	private["_databaseName","_tempFunctionString"];

	_databaseName = _this select 0;

	_tempFunctionString = format ["clearDatabase %1",_databaseName];

	_AEDB_hnd = "ArmaEasyDB" callExtension _tempFunctionString;
};

ArmaEasyDB_deleteDatabase = 
{
// Description	: Deletes a Database with the given Name
// Parameters		: Database name 
// Return		:	-
	private["_databaseName","_tempFunctionString"];

	_databaseName = _this select 0;

	_tempFunctionString = format ["deleteDatabase %1",_databaseName];

	_AEDB_hnd = "ArmaEasyDB" callExtension _tempFunctionString;
};

ArmaEasyDB_createDatabase = 
{
// Description	: Creates a Database with the given Name
// Parameters		: Database name 
// Return		:	-
	private["_databaseName","_tempFunctionString"];
	
	_databaseName = _this select 0;
	
	_tempFunctionString = format ["createDatabase %1",_databaseName];
	
	_AEDB_hnd = "ArmaEasyDB" callExtension _tempFunctionString;
};

// Expirimental
ArmaEasyDB_setWorkingDatabaseVariable = 
{
	//Set the ArmaEasyDB currentDatabase Variable
	//Its the name of the Database we are working with
	private["_currentDatabaseVariable","_tempFunctionString"];

	_currentDatabaseVariable = _this select 0;
	_tempFunctionString = format ["setWorkingDatabaseVariable %1",_currentDatabaseVariable];
	
	_AEDB_hnd = "ArmaEasyDB" callExtension _tempFunctionString;
};

if ( _debug ) then { hint "Finished loading ArmaEasyDB"; };