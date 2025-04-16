extends TrafficLight

func _get_next_light(current : TrafficLightType) -> TrafficLightType:
	if(current == TrafficLightGo):
		return TrafficLightCaution;
	if(current == TrafficLightCaution):
		return TrafficLightStop;
	if(current == TrafficLightStop):
		return TrafficLightGo;
	return TrafficLightStop
