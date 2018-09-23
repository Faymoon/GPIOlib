
#include <OutputPin.hpp>
#include <Device.hpp>

namespace gpio
{
	inline std::uint8_t OutputPin::GetPin() const
	{
		return m_pin;
	}

	inline void OutputPin::On()
	{
		SetValue(true);
	}

	inline void OutputPin::Off()
	{
		SetValue(false);
	}
}