
#include <InputPin.hpp>
#include <Device.hpp>

namespace gpio
{
	InputPin::InputPin(std::uint8_t pin)
		:
		m_pin(pin)
	{
		Device::instance->RegisterPin(pin, Device::PinMode::Input);
	}

	bool InputPin::ReadValue() const
	{
		return Device::instance->ReadPinValue(m_pin);
	}
}