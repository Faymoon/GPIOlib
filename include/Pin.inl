
#include <Pin.hpp>

namespace gpio
{
	inline std::uint8_t Pin::GetPin() const
	{
		return m_pin;
	}
}