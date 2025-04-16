#include "TrafficLight.h"

TrafficLight::TrafficLight()
{
	TextureRect_ = memnew(TextureRect);
	add_child(TextureRect_);
	TextureRect_->set_anchors_preset(PRESET_FULL_RECT);
	LightType_ = TrafficLightGo;
}

void TrafficLight::SetGoTexture(const Ref<Texture2D> &Texture)
{
	GoTexture = Texture;
}

Ref<Texture2D> TrafficLight::GetGoTexture() const
{
	return GoTexture;
}

void TrafficLight::SetStopTexture(const Ref<Texture2D> &Texture)
{
	StopTexture = Texture;
}

Ref<Texture2D> TrafficLight::GetStopTexture() const
{
	return StopTexture;
}

void TrafficLight::SetCautionTexture(const Ref<Texture2D> &Texture)
{
	CautionTexture = Texture;
}

Ref<Texture2D> TrafficLight::GetCautionTexture() const
{
	return CautionTexture;
}

void TrafficLight::SetTrafficLightType(TrafficLightType LightType)
{
	LightType_ = LightType;

	switch (LightType_) {
		case TrafficLightGo: {
			TextureRect_->set_texture(GoTexture);
			break;
		}
		case TrafficLightCaution: {
			TextureRect_->set_texture(CautionTexture);
			break;
		}
		case TrafficLightStop: {
			TextureRect_->set_texture(StopTexture);
			break;
		}
	}
	emit_signal("light_changed", LightType_);
}

TrafficLightType TrafficLight::GetTrafficLightType() const
{
	return LightType_;
}

TrafficLightType TrafficLight::ShowNextLight(TrafficLightType CurrentType)
{
	TrafficLightType NextType;
	if(GDVIRTUAL_CALL(_get_next_light, LightType_, NextType)) {
		SetTrafficLightType(NextType);
	}
	return NextType;
}

void TrafficLight::_notification(int p_what)
{
	switch (p_what) {
		case NOTIFICATION_READY: {
			NativeReady();
			break;
		}
		default: ;
	}
}

void TrafficLight::NativeReady() {
	SetTrafficLightType(LightType_);
}

void TrafficLight::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("set_go_texture", "texture"),  &TrafficLight::SetGoTexture);
	ClassDB::bind_method(D_METHOD("set_caution_texture", "texture"), &TrafficLight::SetCautionTexture);
	ClassDB::bind_method(D_METHOD("set_stop_texture", "texture"), &TrafficLight::SetStopTexture);
	ClassDB::bind_method(D_METHOD("get_go_texture"), &TrafficLight::GetGoTexture);
	ClassDB::bind_method(D_METHOD("get_caution_texture"), &TrafficLight::GetCautionTexture);
	ClassDB::bind_method(D_METHOD("get_stop_texture"), &TrafficLight::GetStopTexture);
	ClassDB::bind_method(D_METHOD("set_traffic_light_type", "type"), &TrafficLight::SetTrafficLightType);
	ClassDB::bind_method(D_METHOD("get_traffic_light_type"), &TrafficLight::GetTrafficLightType);
	ClassDB::bind_method(D_METHOD("show_next_light", "current_light"), &TrafficLight::ShowNextLight);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "go_texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_go_texture", "get_go_texture");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "caution_texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_caution_texture", "get_caution_texture");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "stop_texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"), "set_stop_texture", "get_stop_texture");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "traffic_light_type", PROPERTY_HINT_ENUM, "Go,Caution,Stop"), "set_traffic_light_type", "get_traffic_light_type");

	BIND_ENUM_CONSTANT(TrafficLightGo);
	BIND_ENUM_CONSTANT(TrafficLightCaution);
	BIND_ENUM_CONSTANT(TrafficLightStop);

	GDVIRTUAL_BIND(_get_next_light, "current_light");
	ADD_SIGNAL(MethodInfo("light_changed", PropertyInfo(Variant::INT, "new_light", PROPERTY_HINT_ENUM, "Go,Caution,Stop")));
}
