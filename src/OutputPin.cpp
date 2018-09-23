
#include <OutputPin.hpp>
#include <Device.hpp>

namespace gpio
{
	OutputPin::OutputPin(std::uint8_t pin)
		:
		m_pin(pin)
	{
		Device::instance->RegisterPin(pin, Device::PinMode::Output);
	}


	void OutputPin::SetValue(bool value)
	{
		Device::instance->WritePinValue(m_pin, value);
	}
}