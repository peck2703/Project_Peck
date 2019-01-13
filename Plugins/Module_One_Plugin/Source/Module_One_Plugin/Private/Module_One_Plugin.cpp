// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Module_One_Plugin.h"

#define LOCTEXT_NAMESPACE "FModule_One_PluginModule"

void FModule_One_PluginModule::StartupModule()
{
	UE_LOG(LogTemp, Error, TEXT("Hello World"));
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FModule_One_PluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FModule_One_PluginModule, Module_One_Plugin)