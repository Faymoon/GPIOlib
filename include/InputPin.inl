
#include <InputPin.hpp>
#include <Device.hpp>

namespace gpio
{
	inline std::uint8_t InputPin::GetPin() const
	{
		return m_pin;
	}
}