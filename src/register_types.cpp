#include "register_types.h"

#include "Summator.h"
#include "TrafficLight.h"

#include <gdextension_interface.h>
#include <godot_cpp\core\class_db.hpp>
#include <godot_cpp\core\defs.hpp>
#include <godot_cpp\godot.hpp>

using namespace godot;

void InitializeGDExtensionTypes(ModuleInitializationLevel p_level)
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	GDREGISTER_CLASS(Summator);
	GDREGISTER_CLASS(TrafficLight);

}

void UninitializeGDExtensionTypes(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C"
{
	// Initialization
	GDExtensionBool GDE_EXPORT AshCoreGameplayLibraryInit(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
	{
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
		init_obj.register_initializer(InitializeGDExtensionTypes);
		init_obj.register_terminator(UninitializeGDExtensionTypes);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
