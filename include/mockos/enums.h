#pragma once

/*
* Lab 5
* File: enums.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file enumerates all possible return values for our program. It is included in all .cpp files.
*/

using namespace std;

enum returns {
	SUCCESS,
	NO_FILE_CREATED,
	FILE_NOT_ADDED,
	INVALID_COMMAND,
	FILE_ALREADY_EXISTS,
	FILENAME_TAKEN,
	FILE_NOT_OPEN,
	FILE_OPEN,
	FILE_DOES_NOT_EXIST,
	INCORRECT_PASSWORD,
	APPEND_FAILED,
	INVALID_IMAGE,
	CANNOT_APPEND_IMAGES,
	INVALID_DS_USE,
	INVALID_CAT_USE,
	INVALID_CP_USE,
	COMMAND_INSERT_FAIL,
	COMMAND_FAIL,
	NULL_PTR,
	QUIT
};