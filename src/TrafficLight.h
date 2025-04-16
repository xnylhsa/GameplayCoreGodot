#pragma once
#include <godot_cpp\classes\control.hpp>
#include <godot_cpp\classes\texture_rect.hpp>
#include <godot_cpp\classes\texture2d.hpp>
#include <godot_cpp\core\gdvirtual.gen.inc>

using namespace godot;

enum TrafficLightType {
	TrafficLightGo,
	TrafficLightCaution,
	TrafficLightStop,
};
VARIANT_ENUM_CAST(TrafficLightType);

class TrafficLight: public Control {
	GDCLASS(TrafficLight, Control);
public:
	TrafficLight();
	void SetGoTexture(const Ref<Texture2D>& Texture);
	Ref<Texture2D> GetGoTexture() const;

	void SetStopTexture(const Ref<Texture2D>& Texture);
	Ref<Texture2D> GetStopTexture() const;

	void SetCautionTexture(const Ref<Texture2D>& Texture);
	Ref<Texture2D> GetCautionTexture() const;

	void SetTrafficLightType(TrafficLightType LightType);
	TrafficLightType GetTrafficLightType() const;

	virtual TrafficLightType ShowNextLight(TrafficLightType CurrentType);
	GDVIRTUAL1RC(TrafficLightType, _get_next_light, TrafficLightType);

protected:
	static void _bind_methods();
	void _notification(int p_what);
	Ref<Texture2D> GoTexture;
	Ref<Texture2D> StopTexture;
	Ref<Texture2D> CautionTexture;
	void NativeReady();

private:
	TrafficLightType LightType_;
	TextureRect* TextureRect_;
};
